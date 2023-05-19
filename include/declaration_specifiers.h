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
 * We'll do as it it were a list, but with several kinds of elements.
 */

typedef enum
{
  NODE_DECLARATION_SPECIFIERS,
  NODE_STORAGE_CLASS_SPECIFIER,
  NODE_TYPE_SPECIFIER,
  NODE_TYPE_QUALIFIER,
  NODE_FUNCTION_SPECIFIER,
  NODE_ALIGNMENT_SPECIFIER
} node_kind_t;

struct storage_class_specifier;
struct type_specifier;
struct type_qualifier;
struct function_specifier;
struct alignment_specifier;

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
  node_kind_t parent_kind;
  void *parent;
};

#endif
