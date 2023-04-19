#ifndef DECL_AUX_H
#define DECL_AUX_H

#include "declaration_t.h"

void add_stg_class_spec (decl_specs_t * dst, const stg_class_spec_t * src);
void add_type_spec (decl_specs_t * dst, const type_spec_t * src);
void add_type_qual (decl_specs_t * dst, const type_qual_t * src);
void add_func_spec (decl_specs_t * dst, const func_spec_t * src);
void add_decl_specs (decl_specs_t * dst, const decl_specs_t * src);
#if 0
void add_stg_class_spec (stg_class_spec_t * dst,
                         const stg_class_spec_t * src);
void add_type_spec (type_spec_t * dst, const type_spec_t * src);
void add_type_qual (type_qual_t * dst, const type_qual_t * src);
void add_func_spec (func_spec_t * dst, const func_spec_t * src);
#endif
void debug_decl_specs (const decl_specs_t * ptr);

#endif
