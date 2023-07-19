#ifndef MISRA_5_3_H
#define MISRA_5_3_H

/*
 * An identifier declared in an inner scope
 * shall not hide an identifier declared in
 * an outer scope.
 */

#include "symtable.h"

void check_misra_5_3 (struct symtable *sym_table);

#endif
