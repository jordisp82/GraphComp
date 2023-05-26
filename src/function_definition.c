#include <assert.h>
#include <stdlib.h>

#include "function_definition.h"
#include "declaration_specifiers.h"
#include "declarator.h"
#include "declaration_list.h"
#include "compound_statement.h"
#include "direct_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct function_definition *
function_definition_1 (void *ptr1, void *ptr2, void *ptr3, void *ptr4)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);
  assert (ptr4 != NULL);

  struct function_definition *buff =
    calloc (1, sizeof (struct function_definition));
  assert (buff != NULL);
  buff->kind = NODE_FUNCTION_DEFINITION;
  buff->fd_kind = FD_K_AND_R;
  buff->ds = ptr1;
  buff->dr = ptr2;
  buff->dl = ptr3;
  buff->cs = ptr4;
  buff->ds->parent_kind = buff->dr->parent_kind = buff->dl->parent_kind =
    buff->cs->parent_kind = NODE_FUNCTION_DEFINITION;
  buff->ds->parent = buff->dr->parent = buff->dl->parent = buff->cs->parent =
    buff;

  return buff;
}

struct function_definition *
function_definition_2 (void *ptr1, void *ptr2, void *ptr3)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);
  assert (ptr3 != NULL);
  struct function_definition *buff =
    calloc (1, sizeof (struct function_definition));
  assert (buff != NULL);
  buff->kind = NODE_FUNCTION_DEFINITION;
  buff->fd_kind = FD_STANDARD_C;
  buff->ds = ptr1;
  buff->dr = ptr2;
  buff->cs = ptr3;
  buff->ds->parent_kind = buff->dr->parent_kind = buff->cs->parent_kind =
    NODE_FUNCTION_DEFINITION;
  buff->ds->parent = buff->dr->parent = buff->cs->parent = buff;

  return buff;
}

void
sem_function_definition (struct function_definition *buff)
{
  assert (buff != NULL);

  /*
   * TODO
   * Section 6.9.1, clauses 2, 3, 4, 5 and 6.
   * Clause 3 not easy. Clause 5 only for standard
   * definitions; clause 6 only for K&R definitions.
   */

  sem_declaration_specifiers (buff->ds);
  /* TODO buff->dr, buff->dl, buff->cs */
}

const char *
get_function_definition_name (struct function_definition *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_FUNCTION_DEFINITION);

  switch (buff->dr->ddclr->n_prod)
    {
    case 12:
    case 13:
    case 14:
      if (buff->dr->ddclr->ddeclr->n_prod == 1)
        return buff->dr->ddclr->ddeclr->id;
      break;

    default:
      return NULL;
    }

  return NULL;
}
