#ifndef DECLARATION_SPECIFIERS_H
#define DECLARATION_SPECIFIERS_H

/**
 * declaration-specifiers:
 *      storage-class-specifier declaration-specifiers          (1)
 *      storage-class-specifier             (2)
 *      type-specifier declaration-specifiers                   (3)
 *      type-specifier                      (4)
 *      type-qualifier declaration-specifiers                   (5)
 *      type-qualifier                      (6)
 *      function-specifier declaration-specifiers               (7)
 *      function-specifier                  (8)
 *      alignment-specifier declaration-specifiers              (9)
 *      alignment-specifier                 (10)
 * 
 * parents:
 *      declaration (1), (2)
 *      parameter-declaration (1), (2), (3)
 *      function-definition (1), (2)
 * 
 * We'll do as it it were a list, but with several kinds of elements.
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symbol.h"

struct declaration_specifiers
{
  node_kind_t kind;
  struct ds_node
  {
    node_kind_t ds_kind;
    union
    {
      struct storage_class_specifier *stg;
      struct type_specifier *ts;
      struct type_qualifier *tq;
      struct function_specifier *fs;
      struct alignment_specifier *as;
    };
    struct ds_node *next;
  } *first, *last;
  node_kind_t scope_kind;
  void *scope;
  node_kind_t parent_kind;
  void *parent;
};

symbol_t *create_symbol_from_declaration_specifiers (struct
                                                     declaration_specifiers
                                                     *buff);
int is_there_typedef (struct declaration_specifiers *buff);
void set_declaration_specifiers_scope (struct declaration_specifiers *buff);

#endif
