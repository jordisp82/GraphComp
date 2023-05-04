#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "compound_stmt.h"
#include "declaration.h"
#include "statement.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_block_item_list (compound_stmt_t * cs, ast_node_t * ast);
static block_item_t *sem_block_item (ast_node_t * ast);

compound_stmt_t *
sem_compound_stmt (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_COMPOUND_STATEMENT (ast->func_ptr));
  assert (ast->n_children == 0 || ast->children != NULL);

  compound_stmt_t *cs = calloc (1, sizeof (compound_stmt_t));
  assert (cs != NULL);

  if (ast->n_children == 0)
    cs->n_blocks = 0;
  else
    sem_block_item_list (cs, ast);

  return cs;
}

static void
sem_block_item_list (compound_stmt_t * cs, ast_node_t * ast)
{
  assert (ast != NULL);
  assert (cs != NULL);
  assert (IS_COMPOUND_STATEMENT (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  cs->n_blocks = 1;
  ast_node_t *ptr;

  for (ptr = ast->children[0]; ptr->n_children > 1; ptr = ptr->children[0])
    cs->n_blocks++;

  cs->blocks = calloc (cs->n_blocks, sizeof (block_item_t *));
  assert (cs->blocks != NULL);

  for (ptr = ast; IS_BLOCK_ITEM_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0]);
  cs->blocks[0] = sem_block_item (ptr->children[0]);
  ptr = ptr->parent;
  for (int i = 1; IS_BLOCK_ITEM (ptr->func_ptr); ptr = ptr->parent, i++)
    cs->blocks[i] = sem_block_item (ptr->children[1]);
}

static block_item_t *
sem_block_item (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_BLOCK_ITEM (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  block_item_t *bi = calloc (1, sizeof (block_item_t));
  assert (bi != NULL);

  if (IS_DECLARATION (ast->children[0]->func_ptr))
    {
      bi->kind = BLOCK_DECLARATION;
      bi->element.decl = sem_declaration (ast->children[0]);
    }
  else if (IS_STATEMENT (ast->children[0]->func_ptr))
    {
      bi->kind = BLOCK_STATEMENT;
      bi->element.stmt = sem_statement (ast->children[0]);
    }

  return bi;
}
