#ifndef AST_H
#define AST_H

#include "grammar.tab.h"
#include "ast_t.h"

typedef struct __astid
{
  const char *str;
  struct __astid *next;
} ast_id_t;

typedef struct __astscope
{
  ast_id_t *typedefs;
  ast_id_t *enumconsts;
  struct __astscope *parent;
} ast_scope_t;

ast_node_t *translation_unit_1 (ast_node_t * node);
ast_node_t *translation_unit_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_TRANSLATION_UNIT(x)      ((x) == translation_unit_1 || \
                                     (x) == translation_unit_2)
ast_node_t *external_declaration_1 (ast_node_t * node);
ast_node_t *external_declaration_2 (ast_node_t * node);
#define IS_EXTERNAL_DECLARATION(x)  ((x) == external_declaration_1 || \
                                     (x) == external_declaration_2)
ast_node_t *function_definition_1 (ast_node_t * n1, ast_node_t * n2,
                                   ast_node_t * n3, ast_node_t * n4);
ast_node_t *function_definition_2 (ast_node_t * n1, ast_node_t * n2,
                                   ast_node_t * n3);
#define IS_FUNCTION_DEFINITION(x)   ((x) == function_definition_1 || \
                                     (x) == function_definition_2)
ast_node_t *declaration_specifiers_1 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *declaration_specifiers_2 (ast_node_t * node);
ast_node_t *declaration_specifiers_3 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *declaration_specifiers_4 (ast_node_t * node);
ast_node_t *declaration_specifiers_5 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *declaration_specifiers_6 (ast_node_t * node);
ast_node_t *declaration_specifiers_7 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *declaration_specifiers_8 (ast_node_t * node);
ast_node_t *declaration_specifiers_9 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *declaration_specifiers_10 (ast_node_t * node);
#define IS_DECLARATION_SPECS(x)     ((x) == declaration_specifiers_1 || \
                                     (x) == declaration_specifiers_2 || \
                                     (x) == declaration_specifiers_3 || \
                                     (x) == declaration_specifiers_4 || \
                                     (x) == declaration_specifiers_5 || \
                                     (x) == declaration_specifiers_6 || \
                                     (x) == declaration_specifiers_7 || \
                                     (x) == declaration_specifiers_8 || \
                                     (x) == declaration_specifiers_9 || \
                                     (x) == declaration_specifiers_10)
ast_node_t *storage_class_spec_1 (void);
ast_node_t *storage_class_spec_2 (void);
ast_node_t *storage_class_spec_3 (void);
ast_node_t *storage_class_spec_4 (void);
ast_node_t *storage_class_spec_5 (void);
ast_node_t *storage_class_spec_6 (void);
#define IS_STORAGE_CLASS_SPEC(x)   ((x) == storage_class_spec_1 || \
                                    (x) == storage_class_spec_2 || \
                                    (x) == storage_class_spec_3 || \
                                    (x) == storage_class_spec_4 || \
                                    (x) == storage_class_spec_5 || \
                                    (x) == storage_class_spec_6)
ast_node_t *type_spec_1 (void);
ast_node_t *type_spec_2 (void);
ast_node_t *type_spec_3 (void);
ast_node_t *type_spec_4 (void);
ast_node_t *type_spec_5 (void);
ast_node_t *type_spec_6 (void);
ast_node_t *type_spec_7 (void);
ast_node_t *type_spec_8 (void);
ast_node_t *type_spec_9 (void);
ast_node_t *type_spec_10 (void);
ast_node_t *type_spec_11 (void);
ast_node_t *type_spec_12 (void);
ast_node_t *type_spec_13 (ast_node_t * node);
ast_node_t *type_spec_14 (ast_node_t * node);
ast_node_t *type_spec_15 (ast_node_t * node);
ast_node_t *type_spec_16 (const char *str);
#define IS_TYPE_SPEC(x)     ((x) == type_spec_1 || \
                             (x) == type_spec_2 || \
                             (x) == type_spec_3 || \
                             (x) == type_spec_4 || \
                             (x) == type_spec_5 || \
                             (x) == type_spec_6 || \
                             (x) == type_spec_7 || \
                             (x) == type_spec_8 || \
                             (x) == type_spec_9 || \
                             (x) == type_spec_10 || \
                             (x) == type_spec_11)
ast_node_t *struct_or_union_1 (void);
ast_node_t *struct_or_union_2 (void);
#define IS_STRUCT_OR_UNION(x)       ((x) == struct_or_union_1 || \
                                     (x) == struct_or_union_2)
ast_node_t *type_qualifier_1 (void);
ast_node_t *type_qualifier_2 (void);
ast_node_t *type_qualifier_3 (void);
ast_node_t *type_qualifier_4 (void);
#define IS_TYPE_QUAL(x)     ((x) == type_qualifier_1 || \
                             (x) == type_qualifier_2 || \
                             (x) == type_qualifier_3 || \
                             (x) == type_qualifier_4)
ast_node_t *function_spec_1 (void);
ast_node_t *function_spec_2 (void);
#define IS_FUNCTION_SPEC(x) ((x) == function_spec_1 || \
                             (x) == function_spec_2)
ast_node_t *assign_op_1 (void);
ast_node_t *assign_op_2 (void);
ast_node_t *assign_op_3 (void);
ast_node_t *assign_op_4 (void);
ast_node_t *assign_op_5 (void);
ast_node_t *assign_op_6 (void);
ast_node_t *assign_op_7 (void);
ast_node_t *assign_op_8 (void);
ast_node_t *assign_op_9 (void);
ast_node_t *assign_op_10 (void);
ast_node_t *assign_op_11 (void);
#define IS_ASSIGN_OP(x)     ((x) == assign_op_1 || \
                             (x) == assign_op_2 || \
                             (x) == assign_op_3 || \
                             (x) == assign_op_4 || \
                             (x) == assign_op_5 || \
                             (x) == assign_op_6 || \
                             (x) == assign_op_7 || \
                             (x) == assign_op_8 || \
                             (x) == assign_op_9 || \
                             (x) == assign_op_10 || \
                             (x) == assign_op_11)
ast_node_t *unary_op_1 (void);
ast_node_t *unary_op_2 (void);
ast_node_t *unary_op_3 (void);
ast_node_t *unary_op_4 (void);
ast_node_t *unary_op_5 (void);
ast_node_t *unary_op_6 (void);
#define IS_UNARY_OP(x)      ((x) == unary_op_1 || \
                             (x) == unary_op_2 || \
                             (x) == unary_op_3 || \
                             (x) == unary_op_4 || \
                             (x) == unary_op_5 || \
                             (x) == unary_op_6)
ast_node_t *declarator_1 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *declarator_2 (ast_node_t * node);
#define IS_DECLARATOR(x)    ((x) == declarator_1 || \
                             (x) == declarator_2)
ast_node_t *compound_statement_1 (void);
ast_node_t *compound_statement_2 (ast_node_t * node);
#define IS_COMPOUND_STATEMENT(x)    ((x) == compound_statement_1 || \
                                     (x) == compound_statement_2)
ast_node_t *block_item_list_1 (ast_node_t * node);
ast_node_t *block_item_list_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_BLOCK_ITEM_LIST(x)       ((x) == block_item_list_1 || \
                                     (x) == block_item_list_2)
ast_node_t *block_item_1 (ast_node_t * node);
ast_node_t *block_item_2 (ast_node_t * node);
#define IS_BLOCK_ITEM(x)        ((x) == block_item_1 || \
                                 (x) == block_item_2)
ast_node_t *statement_1 (ast_node_t * node);
ast_node_t *statement_2 (ast_node_t * node);
ast_node_t *statement_3 (ast_node_t * node);
ast_node_t *statement_4 (ast_node_t * node);
ast_node_t *statement_5 (ast_node_t * node);
ast_node_t *statement_6 (ast_node_t * node);
#define IS_STATEMENT(x)         ((x) == statement_1 || \
                                 (x) == statement_2 || \
                                 (x) == statement_3 || \
                                 (x) == statement_4 || \
                                 (x) == statement_5 || \
                                 (x) == statement_6)
ast_node_t *labeled_statement_1 (const char *str, ast_node_t * node);
ast_node_t *labeled_statement_2 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *labeled_statement_3 (ast_node_t * node);
#define IS_LABELED_STATEMENT(x)  ((x) == labeled_statement_1 || \
                                 (x) == labeled_statement_2 || \
                                 (x) == labeled_statement_3)
ast_node_t *expression_statement_1 (void);
ast_node_t *expression_statement_2 (ast_node_t * node);
#define IS_EXPRESSION_STATEMENT(x)  ((x) == expression_statement_1 || \
                                     (x) == expression_statement_2)
ast_node_t *selection_statement_1 (ast_node_t * n1, ast_node_t * n2,
                                   ast_node_t * n3);
ast_node_t *selection_statement_2 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *selection_statement_3 (ast_node_t * n1, ast_node_t * n2);
#define IS_SELECTION_STATEMENT(x)   ((x) == selection_statement_1 || \
                                     (x) == selection_statement_2 || \
                                     (x) == selection_statement_3)
ast_node_t *iteration_statement_1 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *iteration_statement_2 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *iteration_statement_3 (ast_node_t * n1, ast_node_t * n2,
                                   ast_node_t * n3);
ast_node_t *iteration_statement_4 (ast_node_t * n1, ast_node_t * n2,
                                   ast_node_t * n3, ast_node_t * n4);
ast_node_t *iteration_statement_5 (ast_node_t * n1, ast_node_t * n2,
                                   ast_node_t * n3);
ast_node_t *iteration_statement_6 (ast_node_t * n1, ast_node_t * n2,
                                   ast_node_t * n3, ast_node_t * n4);
#define IS_ITERATION_STATEMENT(x)   ((x) == iteration_statement_1 || \
                                     (x) == iteration_statement_2 || \
                                     (x) == iteration_statement_3 || \
                                     (x) == iteration_statement_4 || \
                                     (x) == iteration_statement_5 || \
                                     (x) == iteration_statement_6)
ast_node_t *jump_statement_1 (const char *str);
ast_node_t *jump_statement_2 (void);
ast_node_t *jump_statement_3 (void);
ast_node_t *jump_statement_4 (void);
ast_node_t *jump_statement_5 (ast_node_t * node);
#define IS_JUMP_STATEMENT(x)        ((x) == jump_statement_1 || \
                                     (x) == jump_statement_2 || \
                                     (x) == jump_statement_3 || \
                                     (x) == jump_statement_4 || \
                                     (x) == jump_statement_5)
ast_node_t *declaration_list_1 (ast_node_t * node);
ast_node_t *declaration_list_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_DECLARATION_LIST(x)      ((x) == declaration_list_1 || \
                                     (x) == declaration_list_2)
ast_node_t *designator_1 (ast_node_t * node);
ast_node_t *designator_2 (const char *str);
#define IS_DESIGNATOR(x)            ((x) == designator_1 || \
                                     (x) == designator_2)
ast_node_t *designator_list_1 (ast_node_t * node);
ast_node_t *designator_list_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_DESIGNATOR_LIST(x)        ((x) == designator_list_1 || \
                                      (x) == designator_list_2)
ast_node_t *designation (ast_node_t * node);
ast_node_t *initializer_list_1 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *initializer_list_2 (ast_node_t * node);
ast_node_t *initializer_list_3 (ast_node_t * n1, ast_node_t * n2,
                                ast_node_t * n3);
ast_node_t *initializer_list_4 (ast_node_t * n1, ast_node_t * n2);
#define IS_INITIALIZER_LIST(x)      ((x) == initializer_list_1 || \
                                     (x) == initializer_list_2 || \
                                     (x) == initializer_list_3 || \
                                     (x) == initializer_list_4)
ast_node_t *initializer_1 (ast_node_t * node);
ast_node_t *initializer_2 (ast_node_t * node);
ast_node_t *initializer_3 (ast_node_t * node);
#define IS_INITIALIZER(x)           ((x) == initializer_1 || \
                                     (x) == initializer_2 || \
                                     (x) == initializer_3)
ast_node_t *direct_abstract_declarator_1 (ast_node_t * node);
ast_node_t *direct_abstract_declarator_2 (void);
ast_node_t *direct_abstract_declarator_3 (void);
ast_node_t *direct_abstract_declarator_4 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *direct_abstract_declarator_5 (ast_node_t * node);
ast_node_t *direct_abstract_declarator_6 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *direct_abstract_declarator_7 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *direct_abstract_declarator_8 (ast_node_t * node);
ast_node_t *direct_abstract_declarator_9 (ast_node_t * node);
ast_node_t *direct_abstract_declarator_10 (ast_node_t * node);
ast_node_t *direct_abstract_declarator_11 (ast_node_t * node);
ast_node_t *direct_abstract_declarator_12 (ast_node_t * n1, ast_node_t * n2,
                                           ast_node_t * n3);
ast_node_t *direct_abstract_declarator_13 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *direct_abstract_declarator_14 (ast_node_t * n1, ast_node_t * n2,
                                           ast_node_t * n3);
ast_node_t *direct_abstract_declarator_15 (ast_node_t * n1, ast_node_t * n2,
                                           ast_node_t * n3);
ast_node_t *direct_abstract_declarator_16 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *direct_abstract_declarator_17 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *direct_abstract_declarator_18 (void);
ast_node_t *direct_abstract_declarator_19 (ast_node_t * node);
ast_node_t *direct_abstract_declarator_20 (ast_node_t * node);
ast_node_t *direct_abstract_declarator_21 (ast_node_t * n1, ast_node_t * n2);
#define IS_DIRECT_ABSTRACT_DECLARATOR(x)    ((x) == direct_abstract_declarator_1 || \
                                             (x) == direct_abstract_declarator_2 || \
                                             (x) == direct_abstract_declarator_3 || \
                                             (x) == direct_abstract_declarator_4 || \
                                             (x) == direct_abstract_declarator_5 || \
                                             (x) == direct_abstract_declarator_6 || \
                                             (x) == direct_abstract_declarator_7 || \
                                             (x) == direct_abstract_declarator_8 || \
                                             (x) == direct_abstract_declarator_9 || \
                                             (x) == direct_abstract_declarator_10 || \
                                             (x) == direct_abstract_declarator_11 || \
                                             (x) == direct_abstract_declarator_12 || \
                                             (x) == direct_abstract_declarator_13 || \
                                             (x) == direct_abstract_declarator_14 || \
                                             (x) == direct_abstract_declarator_15 || \
                                             (x) == direct_abstract_declarator_16 || \
                                             (x) == direct_abstract_declarator_17 || \
                                             (x) == direct_abstract_declarator_18 || \
                                             (x) == direct_abstract_declarator_19 || \
                                             (x) == direct_abstract_declarator_20 || \
                                             (x) == direct_abstract_declarator_21 ||
ast_node_t *abstract_declarator_1 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *abstract_declarator_2 (ast_node_t * node);
ast_node_t *abstract_declarator_3 (ast_node_t * node);
#define IS_ABSTRACT_DECLARATOR(x)       ((x) == abstract_declarator_1 || \
                                         (x) == abstract_declarator_2 || \
                                         (x) == abstract_declarator_3)
ast_node_t *type_name_1 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *type_name_2 (ast_node_t * node);
#define IS_TYPE_NAME(x)                 ((x) == type_name_1 || \
                                         (x) == type_name_2)
ast_node_t *identifier_list_1 (const char *str);
ast_node_t *identifier_list_2 (ast_node_t * node, const char *str);
#define IS_IDENTIFIER_LIST(x)           ((x) == identifier_list_1 || \
                                         (x) == identifier_list_2)
ast_node_t *parameter_type_list_1 (ast_node_t * node);
ast_node_t *parameter_type_list_2 (ast_node_t * node);
#define IS_PARAMETER_TYPE_LIST(x)       ((x) == parameter_type_list_1 || \
                                         (x) == parameter_type_list_2)
ast_node_t *parameter_list_1 (ast_node_t * node);
ast_node_t *parameter_list_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_PARAMETER_LIST(x)            ((x) == parameter_list_1 || \
                                         (x) == parameter_list_2)
ast_node_t *parameter_declaration_1 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *parameter_declaration_2 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *parameter_declaration_3 (ast_node_t * node);
#define IS_PARAMETER_DECLARATION(x)     ((x) == parameter_declaration_1 || \
                                         (x) == parameter_declaration_2 || \
                                         (x) == parameter_declaration_3)
ast_node_t *type_qualifier_list_1 (ast_node_t * node);
ast_node_t *type_qualifier_list_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_TYPE_QUALIFIER_LIST(x)       ((x) == type_qualifier_list_1 || \
                                         (x) == type_qualifier_list_2)
ast_node_t *pointer_1 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *pointer_2 (ast_node_t * node);
ast_node_t *pointer_3 (ast_node_t * node);
ast_node_t *pointer_4 (void);
#define IS_POINTER(x)                   ((x) == pointer_1 || \
                                         (x) == pointer_2 || \
                                         (x) == pointer_3 || \
                                         (x) == pointer_4)
ast_node_t *direct_declarator_1 (const char *str);
ast_node_t *direct_declarator_2 (ast_node_t * node);
ast_node_t *direct_declarator_3 (ast_node_t * node);
ast_node_t *direct_declarator_4 (ast_node_t * node);
ast_node_t *direct_declarator_5 (ast_node_t * n1, ast_node_t * n2,
                                 ast_node_t * n3);
ast_node_t *direct_declarator_6 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *direct_declarator_7 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *direct_declarator_8 (ast_node_t * n1, ast_node_t * n2,
                                 ast_node_t * n3);
ast_node_t *direct_declarator_9 (ast_node_t * n1, ast_node_t * n2,
                                 ast_node_t * n3);
ast_node_t *direct_declarator_10 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *direct_declarator_11 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *direct_declarator_12 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *direct_declarator_13 (ast_node_t * node);
ast_node_t *direct_declarator_14 (ast_node_t * n1, ast_node_t * n2);
#define IS_DIRECT_DECLARATOR(x)         ((x) == direct_declarator_1 || \
                                         (x) == direct_declarator_2 || \
                                         (x) == direct_declarator_3 || \
                                         (x) == direct_declarator_4 || \
                                         (x) == direct_declarator_5 || \
                                         (x) == direct_declarator_6 || \
                                         (x) == direct_declarator_7 || \
                                         (x) == direct_declarator_8 || \
                                         (x) == direct_declarator_9 || \
                                         (x) == direct_declarator_10 || \
                                         (x) == direct_declarator_11 || \
                                         (x) == direct_declarator_12 || \
                                         (x) == direct_declarator_13 || \
                                         (x) == direct_declarator_14)
ast_node_t *enumerator_1 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *enumerator_2 (ast_node_t * node);
#define IS_ENUMERATOR(x)                ((x) == enumerator_1 || \
                                         (x) == enumerator_2)
ast_node_t *enumerator_list_1 (ast_node_t * node);
ast_node_t *enumerator_list_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_ENUMERATOR_LIST(x)           ((x) == enumerator_list_1 || \
                                         (x) == enumerator_list_2)
ast_node_t *enumeration_constant (const char *str);
ast_node_t *constant_1 (long long int value);
ast_node_t *constant_2 (double value);
ast_node_t *constant_3 (const char *str);
#define IS_CONSTANT(x)                  ((x) == constant_1 || \
                                         (x) == constant_2 || \
                                         (x) == constant_3)
ast_node_t *string_1 (const char *str);
ast_node_t *string_2 (const char *str);
#define IS_STRING(x)                    ((x) == string_1 || \
                                         (x) == string_2)
ast_node_t *primary_expression_1 (const char *str);
ast_node_t *primary_expression_2 (ast_node_t * node);
ast_node_t *primary_expression_3 (ast_node_t * node);
ast_node_t *primary_expression_4 (ast_node_t * node);
ast_node_t *primary_expression_5 (ast_node_t * node);
#define IS_PRIMARY_EXPRESSION(x)        ((x) == primary_expression_1 || \
                                         (x) == primary_expression_2 || \
                                         (x) == primary_expression_3 || \
                                         (x) == primary_expression_4 || \
                                         (x) == primary_expression_5)
ast_node_t *postfix_expression_1 (ast_node_t * node);
ast_node_t *postfix_expression_2 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *postfix_expression_3 (ast_node_t * node);
ast_node_t *postfix_expression_4 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *postfix_expression_5 (ast_node_t * node, const char *str);
ast_node_t *postfix_expression_6 (ast_node_t * node, const char *str);
ast_node_t *postfix_expression_7 (ast_node_t * node);
ast_node_t *postfix_expression_8 (ast_node_t * node);
ast_node_t *postfix_expression_9 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *postfix_expression_10 (ast_node_t * n1, ast_node_t * n2);
#define IS_POSTFIX_EXPRESSION(x)        ((x) == postfix_expression_1 || \
                                         (x) == postfix_expression_2 || \
                                         (x) == postfix_expression_3 || \
                                         (x) == postfix_expression_4 || \
                                         (x) == postfix_expression_5 || \
                                         (x) == postfix_expression_6 || \
                                         (x) == postfix_expression_7 || \
                                         (x) == postfix_expression_8 || \
                                         (x) == postfix_expression_9 || \
                                         (x) == postfix_expression_10)
ast_node_t *unary_expression_1 (ast_node_t * node);
ast_node_t *unary_expression_2 (ast_node_t * node);
ast_node_t *unary_expression_3 (ast_node_t * node);
ast_node_t *unary_expression_4 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *unary_expression_5 (ast_node_t * node);
ast_node_t *unary_expression_6 (ast_node_t * node);
ast_node_t *unary_expression_7 (ast_node_t * node);
#define IS_UNARY_EXPRESSION(x)          ((x) == unary_expression_1 || \
                                         (x) == unary_expression_2 || \
                                         (x) == unary_expression_3 || \
                                         (x) == unary_expression_4 || \
                                         (x) == unary_expression_5 || \
                                         (x) == unary_expression_6 || \
                                         (x) == unary_expression_7)
ast_node_t *cast_expression_1 (ast_node_t * node);
ast_node_t *cast_expression_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_CAST_EXPRESSION(x)           ((x) == cast_expression_1 || \
                                         (x) == cast_expression_2)
ast_node_t *mult_expression_1 (ast_node_t * node);
ast_node_t *mult_expression_2 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *mult_expression_3 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *mult_expression_4 (ast_node_t * n1, ast_node_t * n2);
#define IS_MULT_EXPRESSION(x)           ((x) == mult_expression_1 || \
                                         (x) == mult_expression_2 || \
                                         (x) == mult_expression_3 || \
                                         (x) == mult_expression_4)
ast_node_t *add_expression_1 (ast_node_t * node);
ast_node_t *add_expression_2 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *add_expression_3 (ast_node_t * n1, ast_node_t * n2);
#define IS_ADD_EXPRESSION(x)            ((x) == add_expression_1 || \
                                         (x) == add_expression_2 || \
                                         (x) == add_expression_3)
ast_node_t *shift_expression_1 (ast_node_t * node);
ast_node_t *shift_expression_2 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *shift_expression_3 (ast_node_t * n1, ast_node_t * n2);
#define IS_SHIFT_EXPRESSION(x)          ((x) == shift_expression_1 || \
                                         (x) == shift_expression_2 || \
                                         (x) == shift_expression_3)
ast_node_t *relational_expression_1 (ast_node_t * node);
ast_node_t *relational_expression_2 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *relational_expression_3 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *relational_expression_4 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *relational_expression_5 (ast_node_t * n1, ast_node_t * n2);
#define IS_RELATIONAL_EXPRESSION(x)     ((x) == relational_expression_1 || \
                                         (x) == relational_expression_2 || \
                                         (x) == relational_expression_3 || \
                                         (x) == relational_expression_4 || \
                                         (x) == relational_expression_5)
ast_node_t *equality_expression_1 (ast_node_t * node);
ast_node_t *equality_expression_2 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *equality_expression_3 (ast_node_t * n1, ast_node_t * n2);
#define IS_EQUALITY_EXPRESSION(x)       ((x) == equality_expression_1 || \
                                         (x) == equality_expression_2 || \
                                         (x) == equality_expression_3)
ast_node_t *and_expression_1 (ast_node_t * node);
ast_node_t *and_expression_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_AND_EXPRESSION(x)            ((x) == and_expression_1 || \
                                         (x) == and_expression_2)
ast_node_t *xor_expression_1 (ast_node_t * node);
ast_node_t *xor_expression_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_XOR_EXPRESSION(x)            ((x) == xor_expression_1 || \
                                         (x) == xor_expression_2)
ast_node_t *or_expression_1 (ast_node_t * node);
ast_node_t *or_expression_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_OR_EXPRESSION(x)             ((x) == or_expression_1 || \
                                         (x) == or_expression_2)
ast_node_t *logic_and_expression_1 (ast_node_t * node);
ast_node_t *logic_and_expression_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_LOGIC_AND_EXPRESSION(x)      ((x) == logic_and_expression_1 || \
                                         (x) == logic_and_expression_2)
ast_node_t *logic_or_expression_1 (ast_node_t * node);
ast_node_t *logic_or_expression_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_LOGIC_OR_EXPRESSION(x)       ((x) == logic_or_expression_1 || \
                                         (x) == logic_or_expression_2)
ast_node_t *conditional_expression_1 (ast_node_t * node);
ast_node_t *conditional_expression_2 (ast_node_t * n1, ast_node_t * n2,
                                      ast_node_t * n3);
#define IS_CONDITIONAL_EXPRESSION(x)    ((x) == conditional_expression_1 || \
                                         (x) == conditional_expression_2)
ast_node_t *assignment_expression_1 (ast_node_t * node);
ast_node_t *assignment_expression_2 (ast_node_t * n1, ast_node_t * n2,
                                     ast_node_t * n3);
#define IS_ASSIGNMENT_EXPRESSION(x)     ((x) == assignment_expression_1 || \
                                         (x) == assignment_expression_2)
ast_node_t *expression_1 (ast_node_t * node);
ast_node_t *expression_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_EXPRESSION(x)                ((x) == expression_1 || \
                                         (x) == expression_2)
ast_node_t *constant_expression (ast_node_t * node);
ast_node_t *declaration_1 (ast_node_t * node);
ast_node_t *declaration_2 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *declaration_3 (ast_node_t * node);
#define IS_DECLARATION(x)               ((x) == declaration_1 || \
                                         (x) == declaration_2 || \
                                         (x) == declaration_3)
ast_node_t *init_declarator_list_1 (ast_node_t * node);
ast_node_t *init_declarator_list_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_INIT_DECLARATOR_LIST(x)      ((x) == init_declarator_list_1 || \
                                         (x) == init_declarator_list_2)
ast_node_t *init_declarator_1 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *init_declarator_2 (ast_node_t * node);
#define IS_INIT_DECLARATOR(x)           ((x) == init_declarator_1 || \
                                         (x) == init_declarator_2)
ast_node_t *struct_union_spec_1 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *struct_union_spec_2 (ast_node_t * n1, const char *str,
                                 ast_node_t * n2);
ast_node_t *struct_union_spec_3 (ast_node_t * node, const char *str);
#define IS_STRUCT_UNION_SPEC(x)         ((x) == struct_union_spec_1 || \
                                         (x) == struct_union_spec_2 || \
                                         (x) == struct_union_spec_3)
ast_node_t *struct_declaration_list_1 (ast_node_t * node);
ast_node_t *struct_declaration_list_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_STRUCT_DECLARATION_LIST(x)   ((x) == struct_declaration_list_1 || \
                                         (x) == struct_declaration_list_2)
ast_node_t *struct_declaration_1 (ast_node_t * node);
ast_node_t *struct_declaration_2 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *struct_declaration_3 (ast_node_t * node);
#define IS_STRUCT_DECLARATION(x)        ((x) == struct_declaration_1 || \
                                         (x) == struct_declaration_2 || \
                                         (x) == struct_declaration_3)
ast_node_t *spec_qual_list_1 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *spec_qual_list_2 (ast_node_t * node);
ast_node_t *spec_qual_list_3 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *spec_qual_list_4 (ast_node_t * node);
#define IS_SPEC_QUAL_LIST(x)            ((x) == spec_qual_list_1 || \
                                         (x) == spec_qual_list_2 || \
                                         (x) == spec_qual_list_3 || \
                                         (x) == spec_qual_list_4)
ast_node_t *struct_declarator_list_1 (ast_node_t * node);
ast_node_t *struct_declarator_list_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_STRUCT_DECLARATOR_LIST(x)    ((x) == struct_declarator_list_1 || \
                                         (x) == struct_declarator_list_2)
ast_node_t *struct_declarator_1 (ast_node_t * node);
ast_node_t *struct_declarator_2 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *struct_declarator_3 (ast_node_t * node);
#define IS_STRUCT_DECLARATOR(x)         ((x) == struct_declarator_1 || \
                                         (x) == struct_declarator_2 || \
                                         (x) == struct_declarator_3)
ast_node_t *enum_spec_1 (ast_node_t * node);
ast_node_t *enum_spec_2 (ast_node_t * node);
ast_node_t *enum_spec_3 (const char *str, ast_node_t * node);
ast_node_t *enum_spec_4 (const char *str, ast_node_t * node);
ast_node_t *enum_spec_5 (const char *str);
#define IS_ENUM_SPEC(x)                 ((x) == enum_spec_1 || \
                                         (x) == enum_spec_2 || \
                                         (x) == enum_spec_3 || \
                                         (x) == enum_spec_4 || \
                                         (x) == enum_spec_5)
ast_node_t *atomic_type_spec (ast_node_t * node);
ast_node_t *generic_selection (ast_node_t * n1, ast_node_t * n2);
ast_node_t *generic_assoc_list_1 (ast_node_t * node);
ast_node_t *generic_assoc_list_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_GENERIC_ASSOC_LIST(x)        ((x) == generic_assoc_list_1 || \
                                         (x) == generic_assoc_list_2)
ast_node_t *generic_assoc_1 (ast_node_t * n1, ast_node_t * n2);
ast_node_t *generic_assoc_2 (ast_node_t * node);
#define IS_GENERIC_ASSOC(x)             ((x) == generic_assoc_1 || \
                                         (x) == generic_assoc_2)
ast_node_t *argument_expression_list_1 (ast_node_t * node);
ast_node_t *argument_expression_list_2 (ast_node_t * n1, ast_node_t * n2);
#define IS_ARGUMENT_EXPRESSION_LIST(x)  ((x) == argument_expression_list_1 || \
                                         (x) == argument_expression_list_2)
ast_node_t *alignment_spec_1 (ast_node_t * node);
ast_node_t *alignment_spec_2 (ast_node_t * node);
#define IS_ALIGNMENT_SPEC(x)            ((x) == alignment_spec_1 || \
                                         (x) == alignment_spec_2)
ast_node_t *static_assert_declaration (ast_node_t * node, const char *str);

int sym_type (const char *str);
void push_scope (void);
void pull_scope (void);

#endif
