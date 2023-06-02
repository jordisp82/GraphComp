#include <assert.h>
#include <stdlib.h>
//#include <stdio.h>              // temp!

#include "translation_unit.h"
#include "external_declaration.h"
#include "function_definition.h"
#include "declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void cst_file_fd (struct translation_unit *buff,
                         struct function_definition *fd);
static void cst_file_dl (struct translation_unit *buff,
                         struct declaration *dl);

struct translation_unit *
translation_unit_1 (void *ptr)
{
  assert (ptr != NULL);

  struct translation_unit *buff =
    calloc (1, sizeof (struct translation_unit));
  assert (buff != NULL);
  buff->kind = NODE_TRANSLATION_UNIT;
  buff->first = calloc (1, sizeof (struct tu_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ed = ptr;
  buff->first->ed->parent = buff;
  buff->first->ed->parent_kind = NODE_TRANSLATION_UNIT;

  return buff;
}

struct translation_unit *
translation_unit_2 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct translation_unit *buff = ptr1;
  struct external_declaration *ed = ptr2;

  buff->last->next = calloc (1, sizeof (struct tu_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ed = ed;
  ed->parent = buff;
  ed->parent_kind = NODE_TRANSLATION_UNIT;

  return buff;
}

symbol_t *
look_for_id_in_tu (struct translation_unit *buff, const char *name)
{
  assert (buff != NULL);
  assert (name != NULL);
  assert (buff->kind == NODE_TRANSLATION_UNIT);

  avl_node_t *node = avl_search (buff->ordinary, name);
  if (node == NULL)
    node = avl_search (buff->tags, name);

  return (node != NULL) ? node->value : NULL;
}

/*
 * NOTE beware function definitions after a declaration,
 * or the other way around.
 * Beware what the standard says about redeclaring things,
 * especially regarding the linkage.
 */
void
create_symbol_table_file (struct translation_unit *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_TRANSLATION_UNIT);

  buff->ordinary = NULL;
  buff->tags = NULL;

  for (struct tu_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    switch (ptr->ed->child_kind)
      {
      case NODE_FUNCTION_DEFINITION:
        cst_file_fd (buff, ptr->ed->fd);
        break;

      case NODE_DECLARATION:
        cst_file_dl (buff, ptr->ed->d);
        break;

      default:
        ;                       /* BUG! */
      }
}

static void
cst_file_fd (struct translation_unit *buff, struct function_definition *fd)
{
  assert (buff != NULL);
  assert (fd != NULL);
  assert (buff->kind == NODE_TRANSLATION_UNIT);
  assert (fd->kind == NODE_FUNCTION_DEFINITION);

  symbol_t *fd_itself;
  symbol_t **params;

  /*
   * Function create_symbols_for_function_definition
   * creates all symbols, those that have file-scope
   * and also those who have block-scope (its parameters).
   * file-scope symbols: the name of the function
   * (fd_itself). Added here. The parameters are added
   * by create_symbol_table_fd.
   */

  int n = create_symbols_for_function_definition (fd, &fd_itself, &params);
  create_symbol_table_fd (fd, n, params);
  free (params);

#if 0
  printf ("[%s] Adding '%s', ordinary namespace\n", __func__,
          fd_itself->name);
#endif
  if (buff->ordinary == NULL)
    buff->ordinary = avl_create (fd_itself);
  else
    avl_add (buff->ordinary, fd_itself);
}

static void
cst_file_dl (struct translation_unit *buff, struct declaration *dl)
{
  assert (buff != NULL);
  assert (dl != NULL);
  assert (buff->kind == NODE_TRANSLATION_UNIT);
  assert (dl->kind == NODE_DECLARATION);

  symbol_t **syms;
  int n = create_symbols_from_declaration (dl, &syms);
  for (int i = 0; i < n; i++)
    {
      switch (syms[i]->sym_ns)
        {
        case SYM_NS_ORDINARY:
#if 0
          printf ("[%s] Adding '%s', ordinary namespace\n", __func__,
                  syms[i]->name);
#endif
          if (buff->ordinary == NULL)
            buff->ordinary = avl_create (syms[i]);
          else
            avl_add (buff->ordinary, syms[i]);
          break;

        case SYM_NS_TAG:
#if 0
          printf ("[%s] Adding '%s', tag namespace\n", __func__,
                  syms[i]->name);
#endif
          if (buff->tags == NULL)
            buff->tags = avl_create (syms[i]);
          else
            avl_add (buff->tags, syms[i]);
          break;

        default:
          ;                     /* BUG! */
        }
    }
}
