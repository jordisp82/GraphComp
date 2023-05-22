#include <assert.h>
#include <stdlib.h>
#include <stdio.h>              // temporarily

#include "function_definition.h"
#include "declaration_specifiers.h"
#include "declarator.h"
#include "declaration_list.h"
#include "compound_statement.h"
#include "direct_declarator.h"
#include "declaration_specifiers.h"
#include "storage_class_specifier.h"
#include "parameter_type_list.h"
#include "parameter_list.h"
#include "parameter_declaration.h"
#include "type_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_function_definition_analysis (struct function_definition
                                              *ptr);
static int sec_6_9_1_clause_2 (struct function_definition *ptr);
static int sec_6_9_1_clause_3 (struct function_definition *ptr);
static int sec_6_9_1_clause_4 (struct function_definition *ptr);
static int sec_6_9_1_clause_5 (struct function_definition *ptr);
static int sec_6_9_1_clause_6 (struct function_definition *ptr);
static int check_is_void_alone (struct declaration_specifiers *ptr);

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

  sem_function_definition_analysis (buff);

  return buff;
}

static void
sem_function_definition_analysis (struct function_definition *ptr)
{
  assert (ptr != NULL);
  assert (ptr->kind == NODE_FUNCTION_DEFINITION);

  (void) sec_6_9_1_clause_2 (ptr);
  (void) sec_6_9_1_clause_3 (ptr);
  (void) sec_6_9_1_clause_4 (ptr);
  if (ptr->fd_kind == FD_STANDARD_C)
    (void) sec_6_9_1_clause_5 (ptr);
  else if (ptr->fd_kind == FD_K_AND_R)
    (void) sec_6_9_1_clause_6 (ptr);
}

static int
sec_6_9_1_clause_2 (struct function_definition *ptr)
{
  assert (ptr != NULL);
  assert (ptr->kind == NODE_FUNCTION_DEFINITION);

  /**
   * The identifier declared in a function definition (which is the name of the function) shall
   * have a function type, as specified by the declarator portion of the function definition.
   * Footnote: The intent is that the type category in a function definition cannot be inherited from a typedef.
   * Which means that the direct-declarator shall follow
   * rules 12 or 13 or 14.
   */

  switch (ptr->dr->ddclr->n_prod)
    {
    case 12:
    case 13:
    case 14:
      return 0;

    default:
      printf
        ("[%s]<%s:%d> Clause 2 of section 6.9.1 has been violated (direct-declarator using production %d).\n",
         __func__, __FILE__, __LINE__, ptr->dr->ddclr->n_prod);
      return -1;
    }

  return -1;                    /* unreachable */
}

static int
sec_6_9_1_clause_3 (struct function_definition *ptr)
{
  assert (ptr != NULL);
  assert (ptr->kind == NODE_FUNCTION_DEFINITION);

  /**
   * The return type of a function shall be void or a complete object type other than array type.
   */

  /* TODO this is a pretty complex thing to analyze */

  return 0;
}

static int
sec_6_9_1_clause_4 (struct function_definition *ptr)
{
  assert (ptr != NULL);
  assert (ptr->kind == NODE_FUNCTION_DEFINITION);

  /**
   * The storage-class specifier, if any, in the declaration specifiers shall be
   * either extern or static.
   */

  int ret = 0;

  for (struct ds_node * aux = ptr->ds->first; aux != NULL; aux = aux->next)
    if (aux->ds_kind == NODE_STORAGE_CLASS_SPECIFIER)
      switch (aux->stg->value)
        {
        case STG_TYPEDEF:
        case STG_THREAD_LOCAL:
        case STG_AUTO:
        case STG_REGISTER:
          /* FIXME show a string with the name of the storage class specifier */
          printf
            ("[%s]<%s:%d> Clause 4 of section 6.9.1 has been violated (use of an invalid storage-class-specifier (%d).\n",
             __func__, __FILE__, __LINE__, aux->stg->value);
          ret = -1;
          break;

        default:;              /* to avoid a compiler warning */
        }

  return ret;
}

static int
sec_6_9_1_clause_5 (struct function_definition *ptr)
{
  assert (ptr != NULL);
  assert (ptr->kind == NODE_FUNCTION_DEFINITION);
  assert (ptr->fd_kind == FD_STANDARD_C);

  /**
   * If the declarator includes a parameter type list, the declaration of each parameter shall
   * include an identifier, except for the special case of a parameter list consisting of a single
   * parameter of type void, in which case there shall not be an identifier. No declaration list
   * shall follow.
   */

  assert (ptr->dr != NULL);
  assert (ptr->dr->kind == NODE_DECLARATOR);
  assert (ptr->dr->ddclr != NULL);
  assert (ptr->dr->ddclr->kind == NODE_DIRECT_DECLARATOR);
  if (ptr->dr->ddclr->ptl == NULL)
    return 0;                   /* probably clause 2 was violated */
  assert (ptr->dr->ddclr->ptl != NULL);
  assert (ptr->dr->ddclr->ptl->kind == NODE_PARAMETER_TYPE_LIST);
  assert (ptr->dr->ddclr->ptl->pl != NULL);
  assert (ptr->dr->ddclr->ptl->pl->kind == NODE_PARAMETER_LIST);

  /**
   * A parameter-declaration can be:
   * (1) declaration-specifiers with a declarator, which is what we want
   * (2) declaration-specifiers with an abstract-declarator,
   * which we don't want because it doesn't have an identifier.
   * (3) declaration-specifiers only, which is acceptable if it's only void
   * and is the only parameter the function has.
   */

  int ret = 0;

  for (struct pl_node * aux = ptr->dr->ddclr->ptl->pl->first; aux != NULL;
       aux = aux->next)
    {
      switch (aux->pd->pd_kind)
        {
        case PD_DS_ABS_DECLR:  /* case (2) of above */
          printf
            ("[%s]<%s:%d> Clause 5 of section 6.9.1 has been violated: there is a parameter without identifier.\n",
             __func__, __FILE__, __LINE__);
          ret = -1;
          break;

        case PD_DS:            /* let's see if it's case (3) of above */
          if (check_is_void_alone (aux->pd->ds) == 0
              || ptr->dr->ddclr->ptl->pl->first->next != NULL)
            {
              printf
                ("[%s]<%s:%d> Clause 5 of section 6.9.1 has been violated: only a single parameter of type void is acceptable in this case.\n",
                 __func__, __FILE__, __LINE__);
              ret = -1;
            }
          break;

        default:;              /* case (1) of above */
        }
    }

  return ret;
}

static int
sec_6_9_1_clause_6 (struct function_definition *ptr)
{
  assert (ptr != NULL);
  assert (ptr->kind == NODE_FUNCTION_DEFINITION);
  assert (ptr->fd_kind == FD_K_AND_R);

  /**
   * If the declarator includes an identifier list, each declaration in the declaration list shall
   * have at least one declarator, those declarators shall declare only identifiers from the
   * identifier list, and every identifier in the identifier list shall be declared. An identifier
   * declared as a typedef name shall not be redeclared as a parameter. The declarations in the
   * declaration list shall contain no storage-class specifier other than register and no
   * initializations.
   */

  /* TODO lowest priority  */

  return 0;
}

static int
check_is_void_alone (struct declaration_specifiers *ptr)
{
  assert (ptr != NULL);
  assert (ptr->kind == NODE_DECLARATION_SPECIFIERS);

  struct ds_node *aux = ptr->first;
  assert (aux != NULL);
  if (aux->ds_kind == NODE_TYPE_SPECIFIER && aux->ts->ts_kind == TS_VOID
      && aux->next == NULL)
    return 1;

  return 0;
}
