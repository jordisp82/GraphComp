#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>

#include "structs.h"
#include "node_kind_t.h"
#include "misra_5_3.h"
#include "declaration.h"
#include "function_definition.h"
#include "parameter_declaration.h"
#include "init_declarator_list.h"
#include "init_declarator.h"
#include "declarator.h"
#include "direct_declarator.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static struct misra_5_3_v *check_misra_5_3_direct_declarator
  (struct direct_declarator *node);
static struct misra_5_3_v *check_misra_5_3_function_definition
  (struct function_definition *node);
static struct misra_5_3_v *check_misra_5_3_parameter_declaration
  (struct parameter_declaration *node);
static struct misra_5_3_v *check_misra_5_3_declarator
  (struct declarator *node, void *scope, node_kind_t kind_scope);

struct misra_5_3_v *
check_misra_5_3 (void *node, node_kind_t kind)
{
  assert (node != NULL);

  switch (kind)
    {
    case NODE_DIRECT_DECLARATOR:
      return check_misra_5_3_direct_declarator (node);

#if 0
    case NODE_FUNCTION_DEFINITION:
      return check_misra_5_3_function_definition (node);

    case NODE_PARAMETER_DECLARATION:
      return check_misra_5_3_parameter_declaration (node);
#endif

    default:
      return NULL;
    }
}

static struct misra_5_3_v *
check_misra_5_3_direct_declarator (struct direct_declarator *node)
{
  assert (node != NULL);
  assert (node->kind == NODE_DIRECT_DECLARATOR);

  /*
   * FIXME we need to make sure that this identifier
   * is worth being checked against this rule,
   * since maybe not all identifiers are covered
   * by the rule.
   */

  if (node->n_prod != 1)
    return NULL;

  switch (node->scope_kind)
    {
    }
}

#if 0
static struct misra_5_3_v *
check_misra_5_3_declaration (struct declaration *node)
{
  assert (node != NULL);
  assert (node->kind == NODE_DECLARATION);
  /*
   * The only way this declaration can declare
   * an identifier of an outer scope is by having
   * an outer scope. If it doesn't, there is no
   * identifier that can be hidden.
   * If the declaration's parent is an external
   * declaration, then it has no outer scope.
   */
  if (node->scope_kind == NODE_EXTERNAL_DECLARATION)
    return NULL;
  /*
   * At this point, we must check, for each identifier
   * in this declaration, that it does not hide an
   * outer identifier.
   * The init-declarator-list has the declaration's
   * identifiers.
   */
  if (node->idl == NULL)
    return NULL;
  for (struct idl_node * ptr = node->idl->first; ptr != NULL; ptr = ptr->next)
    {
    }
}
#endif

static struct misra_5_3_v *
check_misra_5_3_function_definition (struct function_definition *node)
{
  assert (node != NULL);
  assert (node->kind == NODE_FUNCTION_DEFINITION);
  /* TODO */
  return NULL;
}

static struct misra_5_3_v *
check_misra_5_3_parameter_declaration (struct parameter_declaration *node)
{
  assert (node != NULL);
  assert (node->kind == NODE_PARAMETER_DECLARATION);
  /* TODO */
  return NULL;
}

static struct misra_5_3_v *
check_misra_5_3_declarator (struct
                            declarator
                            *node, void *scope, node_kind_t kind_scope)
{
  assert (node != NULL);
  assert (scope != NULL);
  assert (node->kind == NODE_DECLARATOR);
  /* TODO */
  return NULL;
}
