#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"

static ast_node_t *ast_node_0_token (void *fptr, int token);
static ast_node_t *ast_node_0_str (void *fptr, const char *str);        /* token IDENTIFIER assumed */
static ast_node_t *ast_node_0_token_str (void *fptr, int token,
                                         const char *str);
static ast_node_t *ast_node_0_int (void *fptr, long long int value);
static ast_node_t *ast_node_0_double (void *fptr, double value);
static ast_node_t *ast_node_1 (void *fptr, ast_node_t * n1);
static ast_node_t *ast_node_1_str (void *fptr, ast_node_t * n1,
                                   const char *str);
static ast_node_t *ast_node_2 (void *fptr, ast_node_t * n1, ast_node_t * n2);
static ast_node_t *ast_node_3 (void *fptr, ast_node_t * n1, ast_node_t * n2,
                               ast_node_t * n3);
static ast_node_t *ast_node_4 (void *fptr, ast_node_t * n1, ast_node_t * n2,
                               ast_node_t * n3, ast_node_t * n4);
static void scope_add_enumeration_constant (const char *str);
static void scope_add_typedef (const char *str);
static void register_id_as_typedef (ast_node_t * node);
#if 0
static ast_node_t *look_for_id_in_declarator_list (ast_node_t * node);
#endif

ast_id_t ghost1 = { NULL, NULL };
ast_id_t ghost2 = { NULL, NULL };
ast_scope_t root_scope = { &ghost1, &ghost2, NULL };

ast_scope_t *current_scope = &root_scope;

ast_node_t *
translation_unit_1 (ast_node_t * node)
{
  return ast_node_1 (translation_unit_1, node);
}

ast_node_t *
translation_unit_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (translation_unit_2, n1, n2);
}

ast_node_t *
external_declaration_1 (ast_node_t * node)
{
  return ast_node_1 (external_declaration_1, node);
}

ast_node_t *
external_declaration_2 (ast_node_t * node)
{
  return ast_node_1 (external_declaration_2, node);
}

ast_node_t *
function_definition_1 (ast_node_t * n1, ast_node_t * n2, ast_node_t * n3,
                       ast_node_t * n4)
{
  // printf ("function definition, style K&R C\n");
  return ast_node_4 (function_definition_1, n1, n2, n3, n4);
}

ast_node_t *
function_definition_2 (ast_node_t * n1, ast_node_t * n2, ast_node_t * n3)
{
  // printf ("function definition, style ISO C\n");  /* including () as parameter list */
  return ast_node_3 (function_definition_2, n1, n2, n3);
}

ast_node_t *
declaration_specifiers_1 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (declaration_specifiers_1, n1, n2);
}

ast_node_t *
declaration_specifiers_2 (ast_node_t * node)
{
  return ast_node_1 (declaration_specifiers_2, node);
}

ast_node_t *
declaration_specifiers_3 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (declaration_specifiers_3, n1, n2);
}

ast_node_t *
declaration_specifiers_4 (ast_node_t * node)
{
  return ast_node_1 (declaration_specifiers_4, node);
}

ast_node_t *
declaration_specifiers_5 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (declaration_specifiers_5, n1, n2);
}

ast_node_t *
declaration_specifiers_6 (ast_node_t * node)
{
  return ast_node_1 (declaration_specifiers_6, node);
}

ast_node_t *
declaration_specifiers_7 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (declaration_specifiers_7, n1, n2);
}

ast_node_t *
declaration_specifiers_8 (ast_node_t * node)
{
  return ast_node_1 (declaration_specifiers_8, node);
}

ast_node_t *
declaration_specifiers_9 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (declaration_specifiers_9, n1, n2);
}

ast_node_t *
declaration_specifiers_10 (ast_node_t * node)
{
  return ast_node_1 (declaration_specifiers_10, node);
}

ast_node_t *
storage_class_spec_1 (void)
{
  return ast_node_0_token (storage_class_spec_1, TYPEDEF);
}

ast_node_t *
storage_class_spec_2 (void)
{
  return ast_node_0_token (storage_class_spec_2, EXTERN);
}

ast_node_t *
storage_class_spec_3 (void)
{
  return ast_node_0_token (storage_class_spec_3, STATIC);
}

ast_node_t *
storage_class_spec_4 (void)
{
  return ast_node_0_token (storage_class_spec_4, THREAD_LOCAL);
}

ast_node_t *
storage_class_spec_5 (void)
{
  return ast_node_0_token (storage_class_spec_5, AUTO);
}

ast_node_t *
storage_class_spec_6 (void)
{
  return ast_node_0_token (storage_class_spec_6, REGISTER);
}

ast_node_t *
type_spec_1 (void)
{
  return ast_node_0_token (type_spec_1, VOID);
}

ast_node_t *
type_spec_2 (void)
{
  return ast_node_0_token (type_spec_2, CHAR);
}

ast_node_t *
type_spec_3 (void)
{
  return ast_node_0_token (type_spec_3, SHORT);
}

ast_node_t *
type_spec_4 (void)
{
  return ast_node_0_token (type_spec_4, INT);
}

ast_node_t *
type_spec_5 (void)
{
  return ast_node_0_token (type_spec_5, LONG);
}

ast_node_t *
type_spec_6 (void)
{
  return ast_node_0_token (type_spec_6, FLOAT);
}

ast_node_t *
type_spec_7 (void)
{
  return ast_node_0_token (type_spec_7, DOUBLE);
}

ast_node_t *
type_spec_8 (void)
{
  return ast_node_0_token (type_spec_8, SIGNED);
}

ast_node_t *
type_spec_9 (void)
{
  return ast_node_0_token (type_spec_9, UNSIGNED);
}

ast_node_t *
type_spec_10 (void)
{
  return ast_node_0_token (type_spec_10, BOOL);
}

ast_node_t *
type_spec_11 (void)
{
  return ast_node_0_token (type_spec_11, COMPLEX);
}

ast_node_t *
type_spec_12 (void)
{
  return ast_node_0_token (type_spec_12, IMAGINARY);
}

ast_node_t *
type_spec_13 (ast_node_t * node)
{
  return ast_node_1 (type_spec_13, node);
}

ast_node_t *
type_spec_14 (ast_node_t * node)
{
  return ast_node_1 (type_spec_14, node);
}

ast_node_t *
type_spec_15 (ast_node_t * node)
{
  return ast_node_1 (type_spec_15, node);
}

ast_node_t *
type_spec_16 (const char *str)
{
  return ast_node_0_token_str (type_spec_12, TYPEDEF_NAME, str);
}

ast_node_t *
struct_or_union_1 (void)
{
  return ast_node_0_token (struct_or_union_1, STRUCT);
}

ast_node_t *
struct_or_union_2 (void)
{
  return ast_node_0_token (struct_or_union_2, UNION);
}

ast_node_t *
type_qualifier_1 (void)
{
  return ast_node_0_token (type_qualifier_1, CONST);
}

ast_node_t *
type_qualifier_2 (void)
{
  return ast_node_0_token (type_qualifier_2, RESTRICT);
}

ast_node_t *
type_qualifier_3 (void)
{
  return ast_node_0_token (type_qualifier_3, VOLATILE);
}

ast_node_t *
type_qualifier_4 (void)
{
  return ast_node_0_token (type_qualifier_4, ATOMIC);
}

ast_node_t *
function_spec_1 (void)
{
  return ast_node_0_token (function_spec_1, INLINE);
}

ast_node_t *
function_spec_2 (void)
{
  return ast_node_0_token (function_spec_2, NORETURN);
}

ast_node_t *
assign_op_1 (void)
{
  return ast_node_0_token (assign_op_1, '=');
}

ast_node_t *
assign_op_2 (void)
{
  return ast_node_0_token (assign_op_2, MUL_ASSIGN);
}

ast_node_t *
assign_op_3 (void)
{
  return ast_node_0_token (assign_op_3, DIV_ASSIGN);
}

ast_node_t *
assign_op_4 (void)
{
  return ast_node_0_token (assign_op_4, MOD_ASSIGN);
}

ast_node_t *
assign_op_5 (void)
{
  return ast_node_0_token (assign_op_5, ADD_ASSIGN);
}

ast_node_t *
assign_op_6 (void)
{
  return ast_node_0_token (assign_op_6, SUB_ASSIGN);
}

ast_node_t *
assign_op_7 (void)
{
  return ast_node_0_token (assign_op_7, LEFT_ASSIGN);
}

ast_node_t *
assign_op_8 (void)
{
  return ast_node_0_token (assign_op_8, RIGHT_ASSIGN);
}

ast_node_t *
assign_op_9 (void)
{
  return ast_node_0_token (assign_op_9, AND_ASSIGN);
}

ast_node_t *
assign_op_10 (void)
{
  return ast_node_0_token (assign_op_10, XOR_ASSIGN);
}

ast_node_t *
assign_op_11 (void)
{
  return ast_node_0_token (assign_op_11, OR_ASSIGN);
}

ast_node_t *
unary_op_1 (void)
{
  return ast_node_0_token (unary_op_1, '&');
}

ast_node_t *
unary_op_2 (void)
{
  return ast_node_0_token (unary_op_2, '*');
}

ast_node_t *
unary_op_3 (void)
{
  return ast_node_0_token (unary_op_3, '+');
}

ast_node_t *
unary_op_4 (void)
{
  return ast_node_0_token (unary_op_4, '-');
}

ast_node_t *
unary_op_5 (void)
{
  return ast_node_0_token (unary_op_5, '~');
}

ast_node_t *
unary_op_6 (void)
{
  return ast_node_0_token (unary_op_6, '!');
}

ast_node_t *
declarator_1 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (declarator_1, n1, n2);
}

ast_node_t *
declarator_2 (ast_node_t * node)
{
  return ast_node_1 (declarator_2, node);
}

ast_node_t *
compound_statement_1 (void)
{
  return ast_node_0_token (compound_statement_1, 0);
}

ast_node_t *
compound_statement_2 (ast_node_t * node)
{
  return ast_node_1 (compound_statement_2, node);
}

ast_node_t *
block_item_list_1 (ast_node_t * node)
{
  return ast_node_1 (block_item_list_1, node);
}

ast_node_t *
block_item_list_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (block_item_list_2, n1, n2);
}

ast_node_t *
block_item_1 (ast_node_t * node)
{
  return ast_node_1 (block_item_1, node);
}

ast_node_t *
block_item_2 (ast_node_t * node)
{
  return ast_node_1 (block_item_2, node);
}

ast_node_t *
statement_1 (ast_node_t * node)
{
  return ast_node_1 (statement_1, node);
}

ast_node_t *
statement_2 (ast_node_t * node)
{
  return ast_node_1 (statement_2, node);
}

ast_node_t *
statement_3 (ast_node_t * node)
{
  return ast_node_1 (statement_3, node);
}

ast_node_t *
statement_4 (ast_node_t * node)
{
  return ast_node_1 (statement_4, node);
}

ast_node_t *
statement_5 (ast_node_t * node)
{
  return ast_node_1 (statement_5, node);
}

ast_node_t *
statement_6 (ast_node_t * node)
{
  return ast_node_1 (statement_6, node);
}

ast_node_t *
labeled_statement_1 (const char *str, ast_node_t * node)
{
  return ast_node_1_str (labeled_statement_1, node, str);
}

ast_node_t *
labeled_statement_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (labeled_statement_2, n1, n2);
}

ast_node_t *
labeled_statement_3 (ast_node_t * node)
{
  return ast_node_1 (labeled_statement_3, node);
}

ast_node_t *
expression_statement_1 (void)
{
  return ast_node_0_token (expression_statement_1, ';');
}

ast_node_t *
expression_statement_2 (ast_node_t * node)
{
  return ast_node_1 (expression_statement_2, node);
}

ast_node_t *
selection_statement_1 (ast_node_t * n1, ast_node_t * n2, ast_node_t * n3)
{
  return ast_node_3 (selection_statement_1, n1, n2, n3);
}

ast_node_t *
selection_statement_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (selection_statement_2, n1, n2);
}

ast_node_t *
selection_statement_3 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (selection_statement_3, n1, n2);
}

ast_node_t *
iteration_statement_1 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (iteration_statement_1, n1, n2);
}

ast_node_t *
iteration_statement_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (iteration_statement_2, n1, n2);
}

ast_node_t *
iteration_statement_3 (ast_node_t * n1, ast_node_t * n2, ast_node_t * n3)
{
  return ast_node_3 (iteration_statement_3, n1, n2, n3);
}

ast_node_t *
iteration_statement_4 (ast_node_t * n1, ast_node_t * n2, ast_node_t * n3,
                       ast_node_t * n4)
{
  return ast_node_4 (iteration_statement_4, n1, n2, n3, n4);
}

ast_node_t *
iteration_statement_5 (ast_node_t * n1, ast_node_t * n2, ast_node_t * n3)
{
  return ast_node_3 (iteration_statement_5, n1, n2, n3);
}

ast_node_t *
iteration_statement_6 (ast_node_t * n1, ast_node_t * n2, ast_node_t * n3,
                       ast_node_t * n4)
{
  return ast_node_4 (iteration_statement_6, n1, n2, n3, n4);
}

ast_node_t *
jump_statement_1 (const char *str)
{
  return ast_node_0_token_str (jump_statement_1, GOTO, str);
}

ast_node_t *
jump_statement_2 (void)
{
  return ast_node_0_token (jump_statement_2, CONTINUE);
}

ast_node_t *
jump_statement_3 (void)
{
  return ast_node_0_token (jump_statement_3, BREAK);
}

ast_node_t *
jump_statement_4 (void)
{
  return ast_node_0_token (jump_statement_4, RETURN);
}

ast_node_t *
jump_statement_5 (ast_node_t * node)
{
  return ast_node_1 (jump_statement_5, node);
}

ast_node_t *
declaration_list_1 (ast_node_t * node)
{
  return ast_node_1 (declaration_list_1, node);
}

ast_node_t *
declaration_list_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (declaration_list_2, n1, n2);
}

ast_node_t *
designator_1 (ast_node_t * node)
{
  return ast_node_1 (designator_1, node);
}

ast_node_t *
designator_2 (const char *str)
{
  return ast_node_0_str (designator_2, str);
}

ast_node_t *
designator_list_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (designator_list_2, n1, n2);
}

ast_node_t *
designator_list_1 (ast_node_t * node)
{
  return ast_node_1 (designator_list_1, node);
}

ast_node_t *
designation (ast_node_t * node)
{
  return ast_node_1 (designation, node);
}

ast_node_t *
initializer_list_1 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (initializer_list_1, n1, n2);
}

ast_node_t *
initializer_list_2 (ast_node_t * node)
{
  return ast_node_1 (initializer_list_2, node);
}

ast_node_t *
initializer_list_3 (ast_node_t * n1, ast_node_t * n2, ast_node_t * n3)
{
  return ast_node_3 (initializer_list_3, n1, n2, n3);
}

ast_node_t *
initializer_list_4 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (initializer_list_4, n1, n2);
}

ast_node_t *
initializer_1 (ast_node_t * node)
{
  return ast_node_1 (initializer_1, node);
}

ast_node_t *
initializer_2 (ast_node_t * node)
{
  return ast_node_1 (initializer_2, node);
}

ast_node_t *
initializer_3 (ast_node_t * node)
{
  return ast_node_1 (initializer_3, node);
}

ast_node_t *
direct_abstract_declarator_1 (ast_node_t * node)
{
  return ast_node_1 (direct_abstract_declarator_1, node);
}

ast_node_t *
direct_abstract_declarator_2 (void)
{
  return ast_node_0_token (direct_abstract_declarator_2, 0);
}

ast_node_t *
direct_abstract_declarator_3 (void)
{
  return ast_node_0_token (direct_abstract_declarator_3, 0);
}

ast_node_t *
direct_abstract_declarator_4 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (direct_abstract_declarator_4, n1, n2);
}

ast_node_t *
direct_abstract_declarator_5 (ast_node_t * node)
{
  return ast_node_1 (direct_abstract_declarator_5, node);
}

ast_node_t *
direct_abstract_declarator_6 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (direct_abstract_declarator_6, n1, n2);
}

ast_node_t *
direct_abstract_declarator_7 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (direct_abstract_declarator_7, n1, n2);
}

ast_node_t *
direct_abstract_declarator_8 (ast_node_t * node)
{
  return ast_node_1 (direct_abstract_declarator_8, node);
}

ast_node_t *
direct_abstract_declarator_9 (ast_node_t * node)
{
  return ast_node_1 (direct_abstract_declarator_9, node);
}

ast_node_t *
direct_abstract_declarator_10 (ast_node_t * node)
{
  return ast_node_1 (direct_abstract_declarator_10, node);
}

ast_node_t *
direct_abstract_declarator_11 (ast_node_t * node)
{
  return ast_node_1 (direct_abstract_declarator_11, node);
}

ast_node_t *
direct_abstract_declarator_12 (ast_node_t * n1, ast_node_t * n2,
                               ast_node_t * n3)
{
  return ast_node_3 (direct_abstract_declarator_12, n1, n2, n3);
}

ast_node_t *
direct_abstract_declarator_13 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (direct_abstract_declarator_13, n1, n2);
}

ast_node_t *
direct_abstract_declarator_14 (ast_node_t * n1, ast_node_t * n2,
                               ast_node_t * n3)
{
  return ast_node_3 (direct_abstract_declarator_14, n1, n2, n3);
}

ast_node_t *
direct_abstract_declarator_15 (ast_node_t * n1, ast_node_t * n2,
                               ast_node_t * n3)
{
  return ast_node_3 (direct_abstract_declarator_15, n1, n2, n3);
}

ast_node_t *
direct_abstract_declarator_16 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (direct_abstract_declarator_16, n1, n2);
}

ast_node_t *
direct_abstract_declarator_17 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (direct_abstract_declarator_17, n1, n2);
}

ast_node_t *
direct_abstract_declarator_18 (void)
{
  return ast_node_0_token (direct_abstract_declarator_18, 0);
}

ast_node_t *
direct_abstract_declarator_19 (ast_node_t * node)
{
  return ast_node_1 (direct_abstract_declarator_19, node);
}

ast_node_t *
direct_abstract_declarator_20 (ast_node_t * node)
{
  return ast_node_1 (direct_abstract_declarator_20, node);
}

ast_node_t *
direct_abstract_declarator_21 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (direct_abstract_declarator_21, n1, n2);
}

ast_node_t *
abstract_declarator_1 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (abstract_declarator_1, n1, n2);
}

ast_node_t *
abstract_declarator_2 (ast_node_t * node)
{
  return ast_node_1 (abstract_declarator_2, node);
}

ast_node_t *
abstract_declarator_3 (ast_node_t * node)
{
  return ast_node_1 (abstract_declarator_3, node);
}

ast_node_t *
type_name_1 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (type_name_1, n1, n2);
}

ast_node_t *
type_name_2 (ast_node_t * node)
{
  return ast_node_1 (type_name_2, node);
}

ast_node_t *
identifier_list_1 (const char *str)
{
  return ast_node_0_str (identifier_list_1, str);
}

ast_node_t *
identifier_list_2 (ast_node_t * node, const char *str)
{
  return ast_node_1_str (identifier_list_2, node, str);
}

ast_node_t *
parameter_type_list_1 (ast_node_t * node)
{
  // with va_args
  return ast_node_1 (parameter_type_list_1, node);
}

ast_node_t *
parameter_type_list_2 (ast_node_t * node)
{
  return ast_node_1 (parameter_type_list_2, node);
}

ast_node_t *
parameter_list_1 (ast_node_t * node)
{
  return ast_node_1 (parameter_list_1, node);
}

ast_node_t *
parameter_list_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (parameter_list_2, n1, n2);
}

ast_node_t *
parameter_declaration_1 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (parameter_declaration_1, n1, n2);
}

ast_node_t *
parameter_declaration_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (parameter_declaration_2, n1, n2);
}

ast_node_t *
parameter_declaration_3 (ast_node_t * node)
{
  return ast_node_1 (parameter_declaration_3, node);
}

ast_node_t *
type_qualifier_list_1 (ast_node_t * node)
{
  return ast_node_1 (type_qualifier_list_1, node);
}

ast_node_t *
type_qualifier_list_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (type_qualifier_list_2, n1, n2);
}

ast_node_t *
pointer_1 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (pointer_1, n1, n2);
}

ast_node_t *
pointer_2 (ast_node_t * node)
{
  return ast_node_1 (pointer_2, node);
}

ast_node_t *
pointer_3 (ast_node_t * node)
{
  return ast_node_1 (pointer_3, node);
}

ast_node_t *
pointer_4 (void)
{
  return ast_node_0_token (pointer_4, '*');
}

ast_node_t *
direct_declarator_1 (const char *str)
{
  return ast_node_0_str (direct_declarator_1, str);
}

ast_node_t *
direct_declarator_2 (ast_node_t * node)
{
  return ast_node_1 (direct_declarator_2, node);
}

ast_node_t *
direct_declarator_3 (ast_node_t * node)
{
  return ast_node_1 (direct_declarator_3, node);
}

ast_node_t *
direct_declarator_4 (ast_node_t * node)
{
  return ast_node_1 (direct_declarator_4, node);
}

ast_node_t *
direct_declarator_5 (ast_node_t * n1, ast_node_t * n2, ast_node_t * n3)
{
  return ast_node_3 (direct_declarator_5, n1, n2, n3);
}

ast_node_t *
direct_declarator_6 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (direct_declarator_6, n1, n2);
}

ast_node_t *
direct_declarator_7 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (direct_declarator_7, n1, n2);
}

ast_node_t *
direct_declarator_8 (ast_node_t * n1, ast_node_t * n2, ast_node_t * n3)
{
  return ast_node_3 (direct_declarator_8, n1, n2, n3);
}

ast_node_t *
direct_declarator_9 (ast_node_t * n1, ast_node_t * n2, ast_node_t * n3)
{
  return ast_node_3 (direct_declarator_9, n1, n2, n3);
}

ast_node_t *
direct_declarator_10 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (direct_declarator_10, n1, n2);
}

ast_node_t *
direct_declarator_11 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (direct_declarator_11, n1, n2);
}

ast_node_t *
direct_declarator_12 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (direct_declarator_12, n1, n2);
}

ast_node_t *
direct_declarator_13 (ast_node_t * node)
{
  return ast_node_1 (direct_declarator_13, node);
}

ast_node_t *
direct_declarator_14 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (direct_declarator_14, n1, n2);
}

ast_node_t *
enumerator_1 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (enumerator_1, n1, n2);
}

ast_node_t *
enumerator_2 (ast_node_t * node)
{
  return ast_node_1 (enumerator_2, node);
}

ast_node_t *
enumerator_list_1 (ast_node_t * node)
{
  return ast_node_1 (enumerator_list_1, node);
}

ast_node_t *
enumerator_list_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (enumerator_list_2, n1, n2);
}

ast_node_t *
enumeration_constant (const char *str)
{
  scope_add_enumeration_constant (str);
  return ast_node_0_str (enumeration_constant, str);
}

ast_node_t *
constant_1 (long long int value)
{
  return ast_node_0_int (constant_1, value);
}

ast_node_t *
constant_2 (double value)
{
  return ast_node_0_double (constant_2, value);
}

ast_node_t *
constant_3 (const char *str)
{
  return ast_node_0_token_str (constant_3, ENUMERATION_CONSTANT, str);
}

ast_node_t *
string_1 (const char *str)
{
  return ast_node_0_token_str (string_1, STRING_LITERAL, str);
}

ast_node_t *
string_2 (const char *str)
{
  return ast_node_0_token_str (string_2, FUNC_NAME, str);
}

ast_node_t *
primary_expression_1 (const char *str)
{
  return ast_node_0_str (primary_expression_1, str);
}

ast_node_t *
primary_expression_2 (ast_node_t * node)
{
  return ast_node_1 (primary_expression_2, node);
}

ast_node_t *
primary_expression_3 (ast_node_t * node)
{
  return ast_node_1 (primary_expression_3, node);
}

ast_node_t *
primary_expression_4 (ast_node_t * node)
{
  return ast_node_1 (primary_expression_4, node);
}

ast_node_t *
primary_expression_5 (ast_node_t * node)
{
  return ast_node_1 (primary_expression_5, node);
}

ast_node_t *
postfix_expression_1 (ast_node_t * node)
{
  return ast_node_1 (postfix_expression_1, node);
}

ast_node_t *
postfix_expression_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (postfix_expression_2, n1, n2);
}

ast_node_t *
postfix_expression_3 (ast_node_t * node)
{
  return ast_node_1 (postfix_expression_3, node);
}

ast_node_t *
postfix_expression_4 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (postfix_expression_4, n1, n2);
}

ast_node_t *
postfix_expression_5 (ast_node_t * node, const char *str)
{
  // a.b
  return ast_node_1_str (postfix_expression_5, node, str);
}

ast_node_t *
postfix_expression_6 (ast_node_t * node, const char *str)
{
  // a->b
  return ast_node_1_str (postfix_expression_6, node, str);
}

ast_node_t *
postfix_expression_7 (ast_node_t * node)
{
  // ++
  return ast_node_1 (postfix_expression_7, node);
}

ast_node_t *
postfix_expression_8 (ast_node_t * node)
{
  // --
  return ast_node_1 (postfix_expression_8, node);
}

ast_node_t *
postfix_expression_9 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (postfix_expression_9, n1, n2);
}

ast_node_t *
postfix_expression_10 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (postfix_expression_10, n1, n2);
}

ast_node_t *
unary_expression_1 (ast_node_t * node)
{
  return ast_node_1 (unary_expression_1, node);
}

ast_node_t *
unary_expression_2 (ast_node_t * node)
{
  // ++
  return ast_node_1 (unary_expression_2, node);
}

ast_node_t *
unary_expression_3 (ast_node_t * node)
{
  // --
  return ast_node_1 (unary_expression_3, node);
}

ast_node_t *
unary_expression_4 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (unary_expression_4, n1, n2);
}

ast_node_t *
unary_expression_5 (ast_node_t * node)
{
  // sizeof
  return ast_node_1 (unary_expression_5, node);
}

ast_node_t *
unary_expression_6 (ast_node_t * node)
{
  // sizeof
  return ast_node_1 (unary_expression_6, node);
}

ast_node_t *
unary_expression_7 (ast_node_t * node)
{
  // alignof
  return ast_node_1 (unary_expression_7, node);
}

ast_node_t *
cast_expression_1 (ast_node_t * node)
{
  return ast_node_1 (cast_expression_1, node);
}

ast_node_t *
cast_expression_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (cast_expression_2, n1, n2);
}

ast_node_t *
mult_expression_1 (ast_node_t * node)
{
  return ast_node_1 (mult_expression_1, node);
}

ast_node_t *
mult_expression_2 (ast_node_t * n1, ast_node_t * n2)
{
  // *
  return ast_node_2 (mult_expression_2, n1, n2);
}

ast_node_t *
mult_expression_3 (ast_node_t * n1, ast_node_t * n2)
{
  // /
  return ast_node_2 (mult_expression_3, n1, n2);
}

ast_node_t *
mult_expression_4 (ast_node_t * n1, ast_node_t * n2)
{
  // %
  return ast_node_2 (mult_expression_4, n1, n2);
}

ast_node_t *
add_expression_1 (ast_node_t * node)
{
  return ast_node_1 (add_expression_1, node);
}

ast_node_t *
add_expression_2 (ast_node_t * n1, ast_node_t * n2)
{
  // +
  return ast_node_2 (add_expression_2, n1, n2);
}

ast_node_t *
add_expression_3 (ast_node_t * n1, ast_node_t * n2)
{
  // -
  return ast_node_2 (add_expression_3, n1, n2);
}

ast_node_t *
shift_expression_1 (ast_node_t * node)
{
  return ast_node_1 (shift_expression_1, node);
}

ast_node_t *
shift_expression_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (shift_expression_2, n1, n2);
}

ast_node_t *
shift_expression_3 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (shift_expression_3, n1, n2);
}

ast_node_t *
relational_expression_1 (ast_node_t * node)
{
  return ast_node_1 (relational_expression_1, node);
}

ast_node_t *
relational_expression_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (relational_expression_2, n1, n2);
}

ast_node_t *
relational_expression_3 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (relational_expression_3, n1, n2);
}

ast_node_t *
relational_expression_4 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (relational_expression_4, n1, n2);
}

ast_node_t *
relational_expression_5 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (relational_expression_5, n1, n2);
}

ast_node_t *
equality_expression_1 (ast_node_t * node)
{
  return ast_node_1 (equality_expression_1, node);
}

ast_node_t *
equality_expression_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (equality_expression_2, n1, n2);
}

ast_node_t *
equality_expression_3 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (equality_expression_3, n1, n2);
}

ast_node_t *
and_expression_1 (ast_node_t * node)
{
  return ast_node_1 (and_expression_1, node);
}

ast_node_t *
and_expression_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (and_expression_2, n1, n2);
}

ast_node_t *
xor_expression_1 (ast_node_t * node)
{
  return ast_node_1 (xor_expression_1, node);
}

ast_node_t *
xor_expression_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (xor_expression_2, n1, n2);
}

ast_node_t *
or_expression_1 (ast_node_t * node)
{
  return ast_node_1 (or_expression_1, node);
}

ast_node_t *
or_expression_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (or_expression_2, n1, n2);
}

ast_node_t *
logic_and_expression_1 (ast_node_t * node)
{
  return ast_node_1 (logic_and_expression_1, node);
}

ast_node_t *
logic_and_expression_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (logic_and_expression_2, n1, n2);
}

ast_node_t *
logic_or_expression_1 (ast_node_t * node)
{
  return ast_node_1 (logic_or_expression_1, node);
}

ast_node_t *
logic_or_expression_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (logic_or_expression_2, n1, n2);
}

ast_node_t *
conditional_expression_1 (ast_node_t * node)
{
  return ast_node_1 (conditional_expression_1, node);
}

ast_node_t *
conditional_expression_2 (ast_node_t * n1, ast_node_t * n2, ast_node_t * n3)
{
  return ast_node_3 (conditional_expression_2, n1, n2, n3);
}

ast_node_t *
assignment_expression_1 (ast_node_t * node)
{
  return ast_node_1 (assignment_expression_1, node);
}

ast_node_t *
assignment_expression_2 (ast_node_t * n1, ast_node_t * n2, ast_node_t * n3)
{
  return ast_node_3 (assignment_expression_2, n1, n2, n3);
}

ast_node_t *
expression_1 (ast_node_t * node)
{
  return ast_node_1 (expression_1, node);
}

ast_node_t *
expression_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (expression_2, n1, n2);
}

ast_node_t *
constant_expression (ast_node_t * node)
{
  return ast_node_1 (constant_expression, node);
}

ast_node_t *
declaration_1 (ast_node_t * node)
{
  return ast_node_1 (declaration_1, node);
}

ast_node_t *
declaration_2 (ast_node_t * n1, ast_node_t * n2)
{
  if (look_for_typedef (n1) == 1)
    register_id_as_typedef (n2);

  /* DO NOT do the same for n2 */
  return ast_node_2 (declaration_2, n1, n2);
}

ast_node_t *
declaration_3 (ast_node_t * node)
{
  return ast_node_1 (declaration_3, node);
}

ast_node_t *
init_declarator_list_1 (ast_node_t * node)
{
  return ast_node_1 (init_declarator_list_1, node);
}

ast_node_t *
init_declarator_list_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (init_declarator_list_2, n1, n2);
}

ast_node_t *
init_declarator_1 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (init_declarator_1, n1, n2);
}

ast_node_t *
init_declarator_2 (ast_node_t * node)
{
  return ast_node_1 (init_declarator_2, node);
}

ast_node_t *
struct_union_spec_1 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (struct_union_spec_1, n1, n2);
}

ast_node_t *
struct_union_spec_2 (ast_node_t * n1, const char *str, ast_node_t * n2)
{
  assert (n1 != NULL);
  assert (str != NULL);
  assert (n2 != NULL);

  ast_node_t *ptr = calloc (1, sizeof (ast_node_t));
  assert (ptr != NULL);
  ptr->data = (char *) str;
  ptr->n_children = 1;
  ptr->children = calloc (1, sizeof (ast_node_t *));
  assert (ptr->children != NULL);
  ptr->children[0] = n1;
  ptr->children[1] = n2;
  n1->parent = ptr;
  n2->parent = ptr;
  ptr->func_ptr = struct_union_spec_2;
  return ptr;
}

ast_node_t *
struct_union_spec_3 (ast_node_t * node, const char *str)
{
  return ast_node_1_str (struct_union_spec_3, node, str);
}

ast_node_t *
struct_declaration_list_1 (ast_node_t * node)
{
  return ast_node_1 (struct_declaration_list_1, node);
}

ast_node_t *
struct_declaration_list_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (struct_declaration_list_2, n1, n2);
}

ast_node_t *
struct_declaration_1 (ast_node_t * node)
{
  return ast_node_1 (struct_declaration_1, node);
}

ast_node_t *
struct_declaration_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (struct_declaration_2, n1, n2);
}

ast_node_t *
struct_declaration_3 (ast_node_t * node)
{
  return ast_node_1 (struct_declaration_3, node);
}

ast_node_t *
spec_qual_list_1 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (spec_qual_list_1, n1, n2);
}

ast_node_t *
spec_qual_list_2 (ast_node_t * node)
{
  return ast_node_1 (spec_qual_list_2, node);
}

ast_node_t *
spec_qual_list_3 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (spec_qual_list_3, n1, n2);
}

ast_node_t *
spec_qual_list_4 (ast_node_t * node)
{
  return ast_node_1 (spec_qual_list_4, node);
}

ast_node_t *
struct_declarator_list_1 (ast_node_t * node)
{
  return ast_node_1 (struct_declarator_list_1, node);
}

ast_node_t *
struct_declarator_list_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (struct_declarator_list_2, n1, n2);
}

ast_node_t *
struct_declarator_1 (ast_node_t * node)
{
  return ast_node_1 (struct_declarator_1, node);
}

ast_node_t *
struct_declarator_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (struct_declarator_2, n1, n2);
}

ast_node_t *
struct_declarator_3 (ast_node_t * node)
{
  return ast_node_1 (struct_declarator_3, node);
}

ast_node_t *
enum_spec_1 (ast_node_t * node)
{
  return ast_node_1 (enum_spec_1, node);
}

ast_node_t *
enum_spec_2 (ast_node_t * node)
{
  return ast_node_1 (enum_spec_2, node);
}

ast_node_t *
enum_spec_3 (const char *str, ast_node_t * node)
{
  return ast_node_1_str (enum_spec_3, node, str);
}

ast_node_t *
enum_spec_4 (const char *str, ast_node_t * node)
{
  return ast_node_1_str (enum_spec_4, node, str);
}

ast_node_t *
enum_spec_5 (const char *str)
{
  return ast_node_0_str (enum_spec_5, str);
}

ast_node_t *
atomic_type_spec (ast_node_t * node)
{
  return ast_node_1 (atomic_type_spec, node);
}

ast_node_t *
generic_selection (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (generic_selection, n1, n2);
}

ast_node_t *
generic_assoc_list_1 (ast_node_t * node)
{
  return ast_node_1 (generic_assoc_list_1, node);
}

ast_node_t *
generic_assoc_list_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (generic_assoc_list_2, n1, n2);
}

ast_node_t *
generic_assoc_1 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (generic_assoc_1, n1, n2);
}

ast_node_t *
generic_assoc_2 (ast_node_t * node)
{
  return ast_node_1 (generic_assoc_2, node);
}

ast_node_t *
argument_expression_list_1 (ast_node_t * node)
{
  return ast_node_1 (generic_assoc_2, node);
}

ast_node_t *
argument_expression_list_2 (ast_node_t * n1, ast_node_t * n2)
{
  return ast_node_2 (generic_assoc_1, n1, n2);
}

ast_node_t *
alignment_spec_1 (ast_node_t * node)
{
  return ast_node_1 (generic_assoc_2, node);
}

ast_node_t *
alignment_spec_2 (ast_node_t * node)
{
  return ast_node_1 (generic_assoc_2, node);
}

ast_node_t *
static_assert_declaration (ast_node_t * node, const char *str)
{
  return ast_node_1_str (static_assert_declaration, node, str);
}


static ast_node_t *
ast_node_0_token (void *fptr, int token)
{
  assert (fptr != NULL);

  ast_node_t *ptr = calloc (1, sizeof (ast_node_t));
  assert (ptr != NULL);
  ptr->data = NULL;
  ptr->n_children = 0;
  ptr->children = NULL;
  ptr->token = token;
  ptr->func_ptr = fptr;
  return ptr;
}

static ast_node_t *
ast_node_0_str (void *fptr, const char *str)
{
  assert (fptr != NULL);
  assert (str != NULL);

  ast_node_t *ptr = calloc (1, sizeof (ast_node_t));
  assert (ptr != NULL);
  ptr->data = (char *) str;
  ptr->n_children = 0;
  ptr->children = NULL;
  ptr->token = IDENTIFIER;
  ptr->func_ptr = fptr;
  return ptr;
}

static ast_node_t *
ast_node_0_token_str (void *fptr, int token, const char *str)
{
  assert (fptr != NULL);
  assert (str != NULL);

  ast_node_t *ptr = calloc (1, sizeof (ast_node_t));
  assert (ptr != NULL);
  ptr->data = (char *) str;
  ptr->n_children = 0;
  ptr->children = NULL;
  ptr->token = token;
  ptr->func_ptr = fptr;
  return ptr;
}

static ast_node_t *
ast_node_0_int (void *fptr, long long int value)
{
  assert (fptr != NULL);

  ast_node_t *ptr = calloc (1, sizeof (ast_node_t));
  assert (ptr != NULL);
  ptr->data = calloc (1, sizeof (long long int));
  assert (ptr->data != NULL);
  *(long long int *) (ptr->data) = value;
  ptr->n_children = 0;
  ptr->children = NULL;
  ptr->token = I_CONSTANT;
  ptr->func_ptr = fptr;
  return ptr;
}

static ast_node_t *
ast_node_0_double (void *fptr, double value)
{
  assert (fptr != NULL);

  ast_node_t *ptr = calloc (1, sizeof (ast_node_t));
  assert (ptr != NULL);
  ptr->data = calloc (1, sizeof (double));
  assert (ptr->data != NULL);
  *(double *) (ptr->data) = value;
  ptr->n_children = 0;
  ptr->children = NULL;
  ptr->token = F_CONSTANT;
  ptr->func_ptr = fptr;
  return ptr;
}

static ast_node_t *
ast_node_1 (void *fptr, ast_node_t * n1)
{
  assert (fptr != NULL);
  assert (n1 != NULL);

  ast_node_t *ptr = calloc (1, sizeof (ast_node_t));
  assert (ptr != NULL);
  ptr->data = NULL;
  ptr->n_children = 1;
  ptr->children = calloc (1, sizeof (ast_node_t *));
  assert (ptr->children != NULL);
  ptr->children[0] = n1;
  n1->parent = ptr;
  ptr->func_ptr = fptr;
  return ptr;
}

static ast_node_t *
ast_node_1_str (void *fptr, ast_node_t * n1, const char *str)
{
  assert (n1 != NULL);
  assert (str != NULL);

  ast_node_t *ptr = calloc (1, sizeof (ast_node_t));
  assert (ptr != NULL);
  ptr->data = (char *) str;
  ptr->n_children = 1;
  ptr->children = calloc (1, sizeof (ast_node_t *));
  assert (ptr->children != NULL);
  ptr->children[0] = n1;
  n1->parent = ptr;
  ptr->func_ptr = fptr;
  return ptr;
}

static ast_node_t *
ast_node_2 (void *fptr, ast_node_t * n1, ast_node_t * n2)
{
  assert (n1 != NULL);
  assert (n2 != NULL);

  ast_node_t *ptr = calloc (1, sizeof (ast_node_t));
  assert (ptr != NULL);
  ptr->data = NULL;
  ptr->n_children = 2;
  ptr->children = calloc (1, sizeof (ast_node_t *));
  assert (ptr->children != NULL);
  ptr->children[0] = n1;
  ptr->children[1] = n2;
  n1->parent = ptr;
  n2->parent = ptr;
  ptr->func_ptr = fptr;
  return ptr;
}

static ast_node_t *
ast_node_3 (void *fptr, ast_node_t * n1, ast_node_t * n2, ast_node_t * n3)
{
  assert (n1 != NULL);
  assert (n2 != NULL);
  assert (n3 != NULL);

  ast_node_t *ptr = calloc (1, sizeof (ast_node_t));
  assert (ptr != NULL);
  ptr->data = NULL;
  ptr->n_children = 3;
  ptr->children = calloc (3, sizeof (ast_node_t *));
  assert (ptr->children != NULL);
  ptr->children[0] = n1;
  ptr->children[1] = n2;
  ptr->children[2] = n3;
  n3->parent = ptr;
  n2->parent = ptr;
  n1->parent = ptr;
  ptr->func_ptr = fptr;
  return ptr;
}

static ast_node_t *
ast_node_4 (void *fptr, ast_node_t * n1, ast_node_t * n2, ast_node_t * n3,
            ast_node_t * n4)
{
  assert (n1 != NULL);
  assert (n2 != NULL);
  assert (n3 != NULL);
  assert (n4 != NULL);

  ast_node_t *ptr = calloc (1, sizeof (ast_node_t));
  assert (ptr != NULL);
  ptr->data = NULL;
  ptr->n_children = 4;
  ptr->children = calloc (4, sizeof (ast_node_t *));
  assert (ptr->children != NULL);
  ptr->children[0] = n1;
  ptr->children[1] = n2;
  ptr->children[2] = n3;
  ptr->children[3] = n4;
  n1->parent = ptr;
  n2->parent = ptr;
  n2->parent = ptr;
  n3->parent = ptr;
  ptr->func_ptr = fptr;
  return ptr;
}

int
sym_type (const char *str)
{
  assert (str != NULL);

  ast_id_t *ptr = NULL;

  /* let's start by the current scope */
  for (ptr = current_scope->typedefs->next; ptr != NULL; ptr = ptr->next)
    if (strcmp (str, ptr->str) == 0)
      return TYPEDEF_NAME;
  for (ptr = current_scope->enumconsts->next; ptr != NULL; ptr = ptr->next)
    if (strcmp (str, ptr->str) == 0)
      return ENUMERATION_CONSTANT;

  /* let's look at the higher scopes */
  ast_scope_t *scope = current_scope->parent;
  while (scope != NULL)
    {
      for (ptr = scope->typedefs->next; ptr != NULL; ptr = ptr->next)
        if (strcmp (str, ptr->str) == 0)
          return TYPEDEF_NAME;
      for (ptr = scope->enumconsts->next; ptr != NULL; ptr = ptr->next)
        if (strcmp (str, ptr->str) == 0)
          return ENUMERATION_CONSTANT;
      scope = scope->parent;
    }

  return IDENTIFIER;
}

void
push_scope (void)
{
  ast_scope_t *ptr = calloc (1, sizeof (ast_scope_t));
  assert (ptr != NULL);
  ptr->enumconsts = calloc (1, sizeof (ast_id_t));
  assert (ptr->enumconsts != NULL);
  ptr->typedefs = calloc (1, sizeof (ast_id_t));
  assert (ptr->typedefs != NULL);
  ptr->parent = current_scope;
  current_scope = ptr;
}

void
pull_scope (void)
{
  ast_scope_t *ptr = current_scope;
  current_scope = ptr->parent;
  ast_id_t *tmp;
  do
    {
      tmp = ptr->enumconsts;
      ptr->enumconsts = tmp->next;
      free ((void *) tmp->str);
      free (tmp);
    }
  while (ptr->enumconsts != NULL);
  do
    {
      tmp = ptr->typedefs;
      ptr->typedefs = tmp->next;
      free ((void *) tmp->str);
      free (tmp);
    }
  while (ptr->typedefs != NULL);
  free (ptr);
}

static void
scope_add_enumeration_constant (const char *str)
{
  assert (str != NULL);

  ast_id_t *id = calloc (1, sizeof (ast_id_t));
  assert (id != NULL);
  id->str = strdup (str);
  assert (id->str != NULL);
  id->next = current_scope->enumconsts->next;
  current_scope->enumconsts->next = id;
#if 0
  printf ("[%s] added '%s'\n", __func__, str);
#endif
}

static void
scope_add_typedef (const char *str)
{
  assert (str != NULL);

  ast_id_t *id = calloc (1, sizeof (ast_id_t));
  assert (id != NULL);
  id->str = strdup (str);
  assert (id->str != NULL);
  id->next = current_scope->typedefs->next;
  current_scope->typedefs->next = id;
#if 0
  printf ("[%s] added '%s'\n", __func__, str);
#endif
}

int
look_for_typedef (ast_node_t * node)
{
  assert (node != NULL);

  if (IS_STORAGE_CLASS_SPEC (node->func_ptr) && node->token == TYPEDEF)
    return 1;

  if (node->n_children == 0)
    return 0;

  for (int i = 0; i < node->n_children; i++)
    if (look_for_typedef (node->children[i]) == 1)
      return 1;

  return 0;
}

static void
register_id_as_typedef (ast_node_t * node)
{
  assert (node != NULL);

  if (node->func_ptr == direct_declarator_1 && node->token == IDENTIFIER)
    scope_add_typedef (node->data);
  else
    for (int i = 0; i < node->n_children; i++)
      register_id_as_typedef (node->children[i]);
}
