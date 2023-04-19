#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>

#include "expressions.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void expr_primary (ast_node_t * node, sym_node_t * symtable);
static void expr_primary_id (ast_node_t * node, sym_node_t * symtable);
static void get_symbol (const char *str, ast_node_t ** first,
                        ast_node_t ** hidden, ast_node_t ** multiple);

void
scan_expressions (ast_node_t * tu, sym_node_t * symtable)
{
  assert (tu != NULL);

  /* temporary code */
  for (int i = 0; i < tu->n_children; i++)
    if (IS_PRIMARY_EXPRESSION (tu->children[i]->func_ptr))
      expr_primary (tu->children[i], symtable);
    else
      scan_expressions (tu->children[i], symtable);
}

static void
expr_primary (ast_node_t * node, sym_node_t * symtable)
{
  assert (node != NULL);
  assert (symtable != NULL);

  if (node->func_ptr == primary_expression_1)   /* identifier */
    expr_primary_id (node, symtable);
  else if (node->func_ptr == primary_expression_2)      /* constant (numeric or string literal */
    ;
  else if (node->func_ptr == primary_expression_3)      /* string literal, __func__ */
    ;
  else if (node->func_ptr == primary_expression_4)      /* ( expression ) */
    ;
  /* fuck off with generic selections */
}

static void
expr_primary_id (ast_node_t * node, sym_node_t * symtable)
{
  assert (node != NULL);
  assert (symtable != NULL);
}

static void
get_symbol (const char *str, ast_node_t ** first, ast_node_t ** hidden,
            ast_node_t ** multiple)
{
  assert (str != NULL);
  assert (first != NULL);
  assert (hidden != NULL);
  assert (multiple != NULL);


}
