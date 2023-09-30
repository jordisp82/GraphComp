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
/* NOTE start of experimental code */
#include "type_t.h"
/* NOTE end of experimental code */

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
  void (*dot_create) (void *node, void *f);
  /* NOTE start of experimental code */
  int (*sem_analysis) (void *node);
    type_t (*create_type) (void *node);
  /* NOTE end of experimental code */
  node_kind_t parent_kind;
  void *parent;
};

int is_there_typedef (struct declaration_specifiers *buff);

#endif
