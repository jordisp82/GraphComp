#ifndef MISRA_5_7_H
#define MISRA_5_7_H

/*
 * A tag name shall be a unique identifier.
 * 
 * The tag name shall be unique across
 * all namespaces and translation units.
 * 
 * All declarations of the tag shall specify
 * the same tag.
 * 
 * Multiple complete declarations of the same tag
 * are only permitted by this rule if the tag
 * is declared in a header file and that header
 * file is included in multiple source code files.
 * 
 * Exception: the tag name may be the same as
 * the typedef name with which it is associated.
 */

#include "symtable.h"

void check_misra_5_7 (struct symtable *sym_table);

#endif
