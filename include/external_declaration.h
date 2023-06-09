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

struct external_declaration
{
  node_kind_t kind;
  node_kind_t child_kind;
  union
  {
    struct function_definition *fd;
    struct declaration *d;
  };
  node_kind_t parent_kind;
  void *parent;
};

void set_symbol_for_external_declaration (struct external_declaration *buff);

#endif
