#ifndef EXTERNAL_DECLARATION_H
#define EXTERNAL_DECLARATION_H

/**
 * external-declaration:
 *      function-definition     (1)
 *      declaration             (2)
 * 
 * parents:
 *      translation-unit (1), (2)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

struct external_declaration
{
  node_kind_t kind;
  node_kind_t child_kind;
  union
  {
    struct function_definition *fd;
    struct declaration *d;
  };
  struct symtable *sym_table;
  void (*create_symtable) (struct external_declaration * buff);
  node_kind_t parent_kind;
  void *parent;
};

#if 0
void set_symbol_for_external_declaration (struct external_declaration *buff);
#endif

#endif
