#ifndef MISRA_H
#define MISRA_H

#include "structs.h"
#include "symbol.h"

void check_misra (struct translation_unit *tu);
int is_typedef (symbol_t * sym);        /* defined if misra_5_6.c */

#endif
