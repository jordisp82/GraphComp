#ifndef MISRA_5_3_H
#define MISRA_5_3_H

/*
 * An identifier declared in an inner scope
 * shall not hide an identifier declared in
 * an outer scope.
 */

#include "structs.h"

struct misra_5_3_v
{
  void *inner;                  /* pointer to the inner declaration */
  node_kind_t kind_inner;
  void *outer;                  /* pointer to the outer declaration, the one hidden by the inner one */
  node_kind_t kind_outer;
};

struct misra_5_3_v *check_misra_5_3 (void *node, node_kind_t kind);

#endif
