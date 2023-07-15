#ifndef STORAGE_CLASS_SPECIFIER_H
#define STORAGE_CLASS_SPECIFIER_H

/**
 * storage-class-specifier:
 *      TYPEDEF         (1)
 *      EXTERN          (2)
 *      STATIC          (3)
 *      THREAD_LOCAL    (4)
 *      AUTO            (5)
 *      REGISTER        (6)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "symtable.h"

typedef enum
{
  STG_TYPEDEF,
  STG_EXTERN,
  STG_STATIC,
  STG_THREAD_LOCAL,
  STG_AUTO,
  STG_REGISTER
} stg_kind_t;

struct storage_class_specifier
{
  node_kind_t kind;
  stg_kind_t value;
  struct symtable *sym_table;
  void (*create_symtable) (struct storage_class_specifier * buff);
  node_kind_t parent_kind;
  void *parent;
};

#endif
