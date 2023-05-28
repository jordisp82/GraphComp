#include <assert.h>
#include <stdlib.h>
#include <stdio.h>              // temp!

#include "translation_unit.h"
#include "external_declaration.h"
#include "function_definition.h"
#include "declaration.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

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
        {
          symbol_t *fd_itself;
          symbol_t **params;
          int n = create_symbols_for_function_definition (ptr->ed->fd,
                                                          &fd_itself,
                                                          &params);
          create_symbol_table_fd (ptr->ed->fd, n, params);
          free (params);
          printf ("[%s] Adding '%s', ordinary namespace\n", __func__,
                  fd_itself->name);
          if (buff->ordinary == NULL)
            buff->ordinary = avl_create (fd_itself);
          else
            avl_add (buff->ordinary, fd_itself);
        }
        break;

      case NODE_DECLARATION:
        {
          symbol_t **syms;
          int n = create_symbols_from_declaration (ptr->ed->d, &syms);
          for (int i = 0; i < n; i++)
            switch (syms[i]->sym_ns)
              {
              case SYM_NS_ORDINARY:
                printf ("[%s] Adding '%s', ordinary namespace\n", __func__,
                        syms[i]->name);
                if (buff->ordinary == NULL)
                  buff->ordinary = avl_create (syms[i]);
                else
                  avl_add (buff->ordinary, syms[i]);
                break;

              case SYM_NS_TAG:
                printf ("[%s] Adding '%s', tag namespace\n", __func__,
                        syms[i]->name);
                if (buff->tags == NULL)
                  buff->tags = avl_create (syms[i]);
                else
                  avl_add (buff->tags, syms[i]);
                break;

              default:
                ;               /* BUG! */
              }
        }
        break;

      default:
        ;                       /* BUG! */
      }
}
