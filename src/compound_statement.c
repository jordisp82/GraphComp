#include <assert.h>
#include <stdlib.h>

#include "compound_statement.h"
#include "block_item_list.h"
#include "block_item.h"
#include "declaration.h"
#include "statement.h"
#include "function_definition.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

struct compound_statement *
compound_statement_1 (void)
{
  struct compound_statement *buff =
    calloc (1, sizeof (struct compound_statement));
  assert (buff != NULL);
  buff->kind = NODE_COMPOUND_STATEMENT;
  buff->cs_kind = CS_EMPTY;

  return buff;
}

struct compound_statement *
compound_statement_2 (void *ptr)
{
  assert (ptr != NULL);

  struct compound_statement *buff =
    calloc (1, sizeof (struct compound_statement));
  assert (buff != NULL);
  buff->kind = NODE_COMPOUND_STATEMENT;
  buff->cs_kind = CS_BLOCK_ITEM_LIST;
  buff->bil = ptr;
  buff->bil->parent_kind = NODE_COMPOUND_STATEMENT;
  buff->bil->parent = buff;

  return buff;
}

void
create_symbol_table_cs (struct compound_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_COMPOUND_STATEMENT);

  if (buff->cs_kind == CS_EMPTY)        // buff->bil == NULL
    return;

  for (struct bil_node * ptr = buff->bil->first; ptr != NULL; ptr = ptr->next)
    if (ptr->block_item->child_kind == NODE_DECLARATION)
      {
        symbol_t **syms = NULL;
        int n = create_symbols_from_declaration (ptr->block_item->d, &syms);
        for (int i = 0; i < n; i++)
          switch (syms[i]->sym_ns)
            {
            case SYM_NS_ORDINARY:
            case SYM_NS_TYPEDEF:
              if (buff->ordinary == NULL)
                buff->ordinary = avl_create (syms[i]);
              else
                avl_add (buff->ordinary, syms[i]);
              break;

            case SYM_NS_TAG:
              if (buff->tags == NULL)
                buff->tags = avl_create (syms[i]);
              else
                avl_add (buff->tags, syms[i]);
              break;

            default:
              ;                 /* BUG! */
            }
      }
    else if (ptr->block_item->child_kind == NODE_STATEMENT)
      {
        if (ptr->block_item->s->child_kind == NODE_COMPOUND_STATEMENT)
          create_symbol_table_cs (ptr->block_item->s->cs);
        /* TODO iteration statement: for */
      }
}

void
set_compound_stmt_scope (struct compound_statement *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_COMPOUND_STATEMENT);

  switch (buff->parent_kind)
    {
    case NODE_STATEMENT:
      set_statement_scope (buff->parent);
      buff->scope = ((struct statement *) (buff->parent))->scope;
      buff->scope_kind = ((struct statement *) (buff->parent))->scope_kind;
      break;

    case NODE_FUNCTION_DEFINITION:
      buff->scope = ((struct function_definition *) (buff->parent))->parent;
      buff->scope_kind = NODE_TRANSLATION_UNIT;
      break;

    default:
      ;                         /* BUG! */
    }
}
