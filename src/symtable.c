#include <assert.h>
#include <stdlib.h>

#include "symtable.h"
#include "ast.h"

void look_for_declaration (ast_node_t * ast, sym_node_t * sym);
void proc_declaration (ast_node_t * ast, sym_node_t * sym);

sym_node_t *
create_symtable (ast_node_t * tu)
{
  assert (tu != NULL);
  assert (IS_TRANSLATION_UNIT (tu->func_ptr));

  sym_node_t *sym_table = calloc (1, sizeof (sym_node_t));
  assert (sym_table != NULL);
  sym_table->list = calloc (1, sizeof (symbol_t));
  assert (sym_table->list != NULL);

  for (int i = 0; i < tu->n_children; i++)
    look_for_declaration (tu->children[i], sym_table);

  return sym_table;
}

void
look_for_declaration (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

  sym_node_t *current = sym;

  if (IS_FUNCTION_DEFINITION (ast->func_ptr))
    {
      /* TODO parameters */
    }
  else if (ast->func_ptr == declaration_1 || ast->func_ptr == declaration_2)
    {
      /* declaration_3 is static_assert */
      proc_declaration (ast, current);
      /* TODO return? */
    }
  else if (IS_COMPOUND_STATEMENT (ast->func_ptr))
    {
      current = calloc (1, sizeof (sym_node_t));
      assert (current != NULL);
      current->parent = sym;
      current->scope = ast;
      current->list = calloc (1, sizeof (symbol_t));
      assert (current->list != NULL);
      sym->n_children++;
      sym->children =
        realloc (sym->children, sym->n_children * sizeof (sym_node_t *));
      assert (sym->children != NULL);
      sym->children[sym->n_children - 1] = current;
    }
  for (int i = 0; i < ast->n_children; i++)
    look_for_declaration (ast->children[i], current);
}

void
proc_declaration (ast_node_t * ast, sym_node_t * sym)
{
  assert (ast != NULL);
  assert (sym != NULL);

}
