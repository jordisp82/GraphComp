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
  int stg_mask;
  int ts_mask;
  /* TODO functions to get the struct, union, enum, and typedef */
  /* NOTE end of experimental code */
  node_kind_t parent_kind;
  void *parent;
};

int is_there_typedef (struct declaration_specifiers *buff);

/* NOTE start of experimental code */
#define MASK_TYPEDEF    0x01
#define MASK_EXTERN     0x02
#define MASK_STATIC     0x04
#define MASK_THREAD_LOCAL 0x08
#define MASK_AUTO       0x10
#define MASK_REGISTER   0x20

#define MASK_VOID       0x0001
#define MASK_CHAR       0x0002
#define MASK_SHORT      0x0004
#define MASK_INT        0x0008
#define MASK_LONG       0x0010
#define MASK_LLONG      0x0020
#define MASK_FLOAT      0x0040
#define MASK_DOUBLE     0x0080
#define MASK_SIGNED     0x0100
#define MASK_UNSIGNED   0x0200
#define MASK_BOOL       0x0400
#define MASK_COMPLEX    0x0800
#define MASK_STRUCT     0x1000
#define MASK_UNION      0x2000
#define MASK_ENUM       0x4000
#define MASK_NAME       0x8000  /* typedef */
/* NOTE end of experimental code */

#endif
