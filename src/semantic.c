#include <assert.h>

#include "semantic.h"
#include "node_kind_t.h"
#include "translation_unit.h"
#include "sem_external_declaration.h"

#if 0
#include "node_kind_t.h"
#include "strings.h"
#include "function_definition.h"
#include "declaration_specifiers.h"
#include "declarator.h"
#include "declaration_list.h"
#include "compound_statement.h"
#include "direct_declarator.h"
#include "declaration_specifiers.h"
#include "storage_class_specifier.h"
#include "parameter_type_list.h"
#include "parameter_list.h"
#include "parameter_declaration.h"
#include "type_specifier.h"
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

void
semantic_analysis (struct translation_unit *buff)
{
  assert (buff != NULL);
  assert (buff->kind == NODE_TRANSLATION_UNIT);

    /**
     * A translation unit is a set of external
     * declarations. So we need to perform semantic
     * analysis for each external declaration.
     */

  for (struct tu_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    sem_external_declaration (ptr->ed);
}
