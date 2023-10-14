#ifndef DECLARATOR_H
#define DECLARATOR_H

/**
 * declarator:
 *      pointer direct-declarator       (1)
 *      direct-declarator               (2)
 * 
 * parents:
 *      init-declarator (1)(2)
 *      struct-declarator (2)(3)
 *      direct-declarator (2)
 *      parameter-declaration (1)
 *      function-definition (1)(2)
 */

#include "node_kind_t.h"
#include "structs.h"
#include "type_t.h"

typedef enum
{
  DCLR_WITH_POINTER,
  DCLR_NO_POINTER
} dclr_kind_t;

struct declarator
{
  node_kind_t kind;
  dclr_kind_t dclr_kind;
  struct pointer *ptr;
  struct direct_declarator *ddclr;
  void (*dot_create) (void *node, void *f);
  /* NOTE start of experimental code */
  int (*sem_analysis) (void *node);
  type_t type;
  /* NOTE end of experimental code */
  node_kind_t parent_kind;
  void *parent;
};

#endif
