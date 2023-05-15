#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>

#include "compound_stmt.h"
#include "sem_t.h"
#include "ast.h"
#include "statement.h"
#include "declaration.h"

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

  compound_stmt_t *cs = calloc (1, sizeof (compound_stmt_t));
  assert (cs != NULL);

  if (ast->func_ptr == compound_statement_1)
    {
      assert (ast->n_children == 0 && ast->children == NULL);
      cs->n_block_items = 0;
      cs->block_items = NULL;
      cs->node = ast;
    }
  else if (ast->func_ptr == compound_statement_2)
    sem_block_item_list (cs, ast);
  /* else abort */

  return cs;
}

static void
sem_block_item_list (compound_stmt_t * cs, ast_node_t * ast)
{
  assert (cs != NULL);
  assert (ast != NULL);
  assert (IS_COMPOUND_STATEMENT (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  cs->n_block_items = 1;
  ast_node_t *ptr;

  for (ptr = ast->children[0]; ptr->n_children > 1; ptr = ptr->children[0])
    cs->n_block_items++;

  cs->block_items = calloc (cs->n_block_items, sizeof (block_item_t *));
  assert (cs->block_items != NULL);

  for (ptr = ast; IS_BLOCK_ITEM_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0]);
  cs->block_items[0] = sem_block_item (ptr->children[0]);
  ptr = ptr->parent;
  for (int i = 1; IS_BLOCK_ITEM (ptr->func_ptr); ptr = ptr->parent, i++)
    cs->block_items[i] = sem_block_item (ptr->children[1]);

  for (int i = 0; i < cs->n_block_items; i++)
    {
      cs->block_items[i]->parent = cs;
      cs->block_items[i]->parent_kind = PARENT_COMPOUND_STMT;
    }
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
      bi->node = ast;
      bi->kind = BLOCK_DECLARATION;
      bi->decl = sem_declaration (ast->children[0]);
      bi->decl->parent_kind = PARENT_BLOCK_ITEM;
      bi->decl->parent = bi;
    }
  else if (IS_STATEMENT (ast->children[0]->func_ptr))
    {
      bi->node = ast;
      bi->kind = BLOCK_STATEMENT;
      bi->stmt = sem_statement (ast->children[0]);
      bi->stmt->parent_kind = PARENT_BLOCK_ITEM;
      bi->stmt->parent = bi;
    }
  /* else abort */

  return bi;
}
