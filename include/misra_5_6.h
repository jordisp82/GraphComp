#ifndef MISRA_5_6_H
#define MISRA_5_6_H

/*
 * A typedef name shall be a unique identifier.
 * 
 * A typedef name shall be unique across
 * all namespaces and translation units.
 * Multiple declarations of the same typedef name
 * are only permitted by this rule if the
 * type definition is made in a header file and
 * that header file is included in multiple
 * source code files.
 * 
 * And also across all scopes, according to
 * the examples available in the MISRA document.
 */

#include "symtable.h"

void check_misra_5_6 (struct symtable *sym_table);

#endif
