#include <assert.h>
#include <stdlib.h>

#include "sem_external_declaration.h"
#include "node_kind_t.h"
#include "structs.h"
#include "external_declaration.h"
#include "translation_unit.h"
#include "function_definition.h"
#include "declaration.h"
#if 0
#include "declaration_specifiers.h"
#include "storage_class_specifier.h"
#include "declarator.h"
#include "direct_declarator.h"
#include "init_declarator_list.h"
#include "init_declarator.h"
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

void
sem_external_declaration (struct external_declaration *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_EXTERNAL_DECLARATION);

    /**
     * An external declaration can be either:
     * (a) a declaration
     * (b) a function definition
     */

  struct translation_unit *tu = buff->parent;

  switch (buff->child_kind)
    {
    case NODE_FUNCTION_DEFINITION:
#if 0
      sec_6_9_1_clause_2_f (buff);
#endif
      break;

    case NODE_DECLARATION:
#if 0
      sec_6_9_1_clause_2_d (buff);
#endif
      break;

    default:
      ;                         /* BUG! */
    }
}
