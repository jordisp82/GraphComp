#include <assert.h>
#include <stdio.h>              // temporal

#include "sem_external_declaration.h"
#include "node_kind_t.h"
#include "structs.h"
#include "external_declaration.h"
#include "function_definition.h"
#include "declaration.h"
#include "declaration_specifiers.h"
#include "storage_class_specifier.h"
#include "declarator.h"
#include "direct_declarator.h"
#include "init_declarator_list.h"
#include "init_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sec_6_9_1_clause_2_d (struct external_declaration *buff);
static void sec_6_9_1_clause_2_f (struct external_declaration *buff);
static const char *get_declaration_name (struct declaration *buff, struct idl_node **mem);      /* will disappear */
static const char *get_function_definition_name (struct function_definition *buff);     /* will disappear */
static const char *get_direct_declarator_name (struct direct_declarator *buff); /* will disappear */
static void show_6912_violation (struct declaration *buff,
                                 const char *stg_name);

void
sem_external_declaration (struct external_declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EXTERNAL_DECLARATION);

    /**
     * An external declaration can be either:
     * (a) a declaration
     * (b) a function definition
     */

    /**
     * Clause 6.9:
     * (2) The storage-class specifiers auto and register
     * shall not appear in the declaration specifiers
     * in an external declaration.
     * 
     * (3) (a) There shall be no more than one external definition
     * for each identifier declared with internal linkage in a
     * translation unit.
     * (b) If an identifier declared with internal linkage is used
     * in an expression (other than as a part of the operand of a sizeof or
     * _Alignof operator whose result is an integer constant),
     * there shall be exactly one external definition for the
     * identifier in the translation unit.
     */

  switch (buff->child_kind)
    {
    case NODE_FUNCTION_DEFINITION:
      sec_6_9_1_clause_2_f (buff);
      break;

    case NODE_DECLARATION:
      sec_6_9_1_clause_2_d (buff);
      break;

    default:
      ;                         /* BUG! */
    }
}

static void
sec_6_9_1_clause_2_d (struct external_declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EXTERNAL_DECLARATION);

  for (struct ds_node * ptr = buff->d->ds->first; ptr != NULL;
       ptr = ptr->next)
    if (ptr->ds_kind == NODE_STORAGE_CLASS_SPECIFIER)
      switch (ptr->stg->value)
        {
        case STG_AUTO:
          show_6912_violation (buff->d, "auto");
          break;

        case STG_REGISTER:
          show_6912_violation (buff->d, "register");
          break;

        default:
          ;
        }
}

static void
sec_6_9_1_clause_2_f (struct external_declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EXTERNAL_DECLARATION);

  for (struct ds_node * ptr = buff->fd->ds->first; ptr != NULL;
       ptr = ptr->next)
    if (ptr->ds_kind == NODE_STORAGE_CLASS_SPECIFIER)
      switch (ptr->stg->value)
        {
        case STG_AUTO:
          printf ("6.9.1 (2) violated in %s: auto is present\n",
                  get_function_definition_name (buff->fd));
          break;

        case STG_REGISTER:
          printf ("6.9.1 (2) violated in %s: register is present\n",
                  get_function_definition_name (buff->fd));
          break;

        default:
          ;
        }
}

static const char *
get_declaration_name (struct declaration *buff, struct idl_node **mem)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DECLARATION);

  if (buff->idl == NULL)
    return NULL;                /* useless declaration: no name declared! */

  /* we can get more than one thing being declared */
  struct idl_node *ptr;
  if (mem == NULL || *mem == NULL)
    ptr = buff->idl->first;
  else
    ptr = *mem;

  const char *ret = get_direct_declarator_name (ptr->id->dclr->ddclr);

  if (mem != NULL)
    *mem = ptr->next;

  return ret;
}

static const char *
get_function_definition_name (struct function_definition *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_FUNCTION_DEFINITION);

  struct direct_declarator *ddr = buff->dr->ddclr;

    /**
     * Since this is a function definition,
     * the direct-declarator must follow either
     * rule 12, 13 or 14.
     */

  switch (ddr->n_prod)
    {
    case 12:
    case 13:
    case 14:
      ddr = ddr->ddeclr;
      break;

    default:
      return NULL;              /* BUG! */
    }

  /* We expect this direct declarator to be just an identifier. */
  if (ddr->n_prod != 1)
    return NULL;                /* NOTE is this a bug? */

  return ddr->id;
}

static const char *
get_direct_declarator_name (struct direct_declarator *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DIRECT_DECLARATOR);

  switch (buff->n_prod)
    {
    case 1:
      return buff->id;

    case 2:
      return get_direct_declarator_name (buff->declr->ddclr);

    default:
      return get_direct_declarator_name (buff->ddeclr);
    }

  return NULL;                  /* unreachable */
}

static void
show_6912_violation (struct declaration *buff, const char *stg_name)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_DECLARATION);

  printf ("6.9.1 (2) violated in");

  struct idl_node *aux = NULL;
  do
    printf (" %s", get_declaration_name (buff, &aux));
  while (aux != NULL);

  printf (": %s is present.\n", stg_name);
}
