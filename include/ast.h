#ifndef AST_H
#define AST_H

#include "node_kind_t.h"
#include "structs.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

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

struct abstract_declarator *abstract_declarator_1 (void *ptr1, void *ptr2);
struct abstract_declarator *abstract_declarator_2 (void *ptr);
struct abstract_declarator *abstract_declarator_3 (void *ptr);
struct additive_expression *additive_expression_1 (void *ptr);
struct additive_expression *additive_expression_2 (void *ptr1, void *ptr2);
struct additive_expression *additive_expression_3 (void *ptr1, void *ptr2);
struct alignment_specifier *alignment_specifier_1 (void *ptr);
struct alignment_specifier *alignment_specifier_2 (void *ptr);
struct and_expression *and_expression_1 (void *ptr);
struct and_expression *and_expression_2 (void *ptr1, void *ptr2);
struct argument_expression_list *argument_expression_list_1 (void *ptr);
struct argument_expression_list *argument_expression_list_2 (void *ptr1,
                                                             void *ptr2);
struct assignment_expression *assignment_expression_1 (void *ptr);
struct assignment_expression *assignment_expression_2 (void *ptr1, void *ptr2,
                                                       void *ptr3);
struct assignment_operator *assignment_operator_1 (void);
struct assignment_operator *assignment_operator_2 (void);
struct assignment_operator *assignment_operator_3 (void);
struct assignment_operator *assignment_operator_4 (void);
struct assignment_operator *assignment_operator_5 (void);
struct assignment_operator *assignment_operator_6 (void);
struct assignment_operator *assignment_operator_7 (void);
struct assignment_operator *assignment_operator_8 (void);
struct assignment_operator *assignment_operator_9 (void);
struct assignment_operator *assignment_operator_10 (void);
struct assignment_operator *assignment_operator_11 (void);
struct atomic_type_specifier *atomic_type_specifier_1 (void *ptr);
struct block_item_list *block_item_list_1 (void *ptr);
struct block_item_list *block_item_list_2 (void *ptr1, void *ptr2);
struct block_item *block_item_1 (void *ptr);
struct block_item *block_item_2 (void *ptr);
struct cast_expression *cast_expression_1 (void *ptr);
struct cast_expression *cast_expression_2 (void *ptr1, void *ptr2);
struct compound_statement *compound_statement_1 (void);
struct compound_statement *compound_statement_2 (void *ptr);
struct conditional_expression *conditional_expression_1 (void *ptr);
struct conditional_expression *conditional_expression_2 (void *ptr1,
                                                         void *ptr2,
                                                         void *ptr3);
struct constant_expression *constant_expression_1 (void *ptr);
struct constant *constant_1 (int value);
struct constant *constant_2 (double value);
struct constant *constant_3 (const char *str);
struct declaration_list *declaration_list_1 (void *ptr);
struct declaration_list *declaration_list_2 (void *ptr1, void *ptr2);
struct declaration_specifiers *declaration_specifiers_1 (void *ptr1,
                                                         void *ptr2);
struct declaration_specifiers *declaration_specifiers_2 (void *ptr);
struct declaration_specifiers *declaration_specifiers_3 (void *ptr1,
                                                         void *ptr2);
struct declaration_specifiers *declaration_specifiers_4 (void *ptr);
struct declaration_specifiers *declaration_specifiers_5 (void *ptr1,
                                                         void *ptr2);
struct declaration_specifiers *declaration_specifiers_6 (void *ptr);
struct declaration_specifiers *declaration_specifiers_7 (void *ptr1,
                                                         void *ptr2);
struct declaration_specifiers *declaration_specifiers_8 (void *ptr);
struct declaration_specifiers *declaration_specifiers_9 (void *ptr1,
                                                         void *ptr2);
struct declaration_specifiers *declaration_specifiers_10 (void *ptr);
struct declaration *declaration_1 (void *ptr);
struct declaration *declaration_2 (void *ptr1, void *ptr2);
struct declaration *declaration_3 (void *ptr);
struct declarator *declarator_1 (void *ptr1, void *ptr2);
struct declarator *declarator_2 (void *ptr);
struct designation *designation_1 (void *ptr);
struct designator_list *designator_list_1 (void *ptr);
struct designator_list *designator_list_2 (void *ptr1, void *ptr2);
struct designator *designator_1 (void *ptr);
struct designator *designator_2 (const char *str);
struct direct_abstract_declarator *direct_abstract_declarator_1 (void *ptr);
struct direct_abstract_declarator *direct_abstract_declarator_2 (void);
struct direct_abstract_declarator *direct_abstract_declarator_3 (void);
struct direct_abstract_declarator *direct_abstract_declarator_4 (void *ptr1,
                                                                 void *ptr2);
struct direct_abstract_declarator *direct_abstract_declarator_5 (void *ptr);
struct direct_abstract_declarator *direct_abstract_declarator_6 (void *ptr1,
                                                                 void *ptr2);
struct direct_abstract_declarator *direct_abstract_declarator_7 (void *ptr1,
                                                                 void *ptr2);
struct direct_abstract_declarator *direct_abstract_declarator_8 (void *ptr);
struct direct_abstract_declarator *direct_abstract_declarator_9 (void *ptr);
struct direct_abstract_declarator *direct_abstract_declarator_10 (void *ptr);
struct direct_abstract_declarator *direct_abstract_declarator_11 (void *ptr);
struct direct_abstract_declarator *direct_abstract_declarator_12 (void *ptr1,
                                                                  void *ptr2,
                                                                  void *ptr3);
struct direct_abstract_declarator *direct_abstract_declarator_13 (void *ptr1,
                                                                  void *ptr2);
struct direct_abstract_declarator *direct_abstract_declarator_14 (void *ptr1,
                                                                  void *ptr2,
                                                                  void *ptr3);
struct direct_abstract_declarator *direct_abstract_declarator_15 (void *ptr1,
                                                                  void *ptr2,
                                                                  void *ptr3);
struct direct_abstract_declarator *direct_abstract_declarator_16 (void *ptr1,
                                                                  void *ptr2);
struct direct_abstract_declarator *direct_abstract_declarator_17 (void *ptr1,
                                                                  void *ptr2);
struct direct_abstract_declarator *direct_abstract_declarator_18 (void);
struct direct_abstract_declarator *direct_abstract_declarator_19 (void *ptr);
struct direct_abstract_declarator *direct_abstract_declarator_20 (void *ptr);
struct direct_abstract_declarator *direct_abstract_declarator_21 (void *ptr1,
                                                                  void *ptr2);
struct direct_declarator *direct_declarator_1 (const char *str);
struct direct_declarator *direct_declarator_2 (void *ptr);
struct direct_declarator *direct_declarator_3 (void *ptr);
struct direct_declarator *direct_declarator_4 (void *ptr);
struct direct_declarator *direct_declarator_5 (void *ptr1, void *ptr2,
                                               void *ptr3);
struct direct_declarator *direct_declarator_6 (void *ptr1, void *ptr2);
struct direct_declarator *direct_declarator_7 (void *ptr1, void *ptr2);
struct direct_declarator *direct_declarator_8 (void *ptr1, void *ptr2,
                                               void *ptr3);
struct direct_declarator *direct_declarator_9 (void *ptr1, void *ptr2,
                                               void *ptr3);
struct direct_declarator *direct_declarator_10 (void *ptr1, void *ptr2);
struct direct_declarator *direct_declarator_11 (void *ptr1, void *ptr2);
struct direct_declarator *direct_declarator_12 (void *ptr1, void *ptr2);
struct direct_declarator *direct_declarator_13 (void *ptr);
struct direct_declarator *direct_declarator_14 (void *ptr1, void *ptr2);
struct enum_specifier *enum_specifier_1 (void *ptr);
struct enum_specifier *enum_specifier_2 (void *ptr);
struct enum_specifier *enum_specifier_3 (const char *str, void *ptr2);
struct enum_specifier *enum_specifier_4 (const char *str, void *ptr2);
struct enum_specifier *enum_specifier_5 (const char *str);
struct enumeration_constant *enumeration_constant_1 (const char *str);
struct enumerator_list *enumerator_list_1 (void *ptr);
struct enumerator_list *enumerator_list_2 (void *ptr1, void *ptr2);
struct enumerator *enumerator_1 (void *ptr1, void *ptr2);
struct enumerator *enumerator_2 (void *ptr);
struct equality_expression *equality_expression_1 (void *ptr);
struct equality_expression *equality_expression_2 (void *ptr1, void *ptr2);
struct equality_expression *equality_expression_3 (void *ptr1, void *ptr2);
struct exclusive_or_expression *exclusive_or_expression_1 (void *ptr);
struct exclusive_or_expression *exclusive_or_expression_2 (void *ptr1,
                                                           void *ptr2);
struct expression_statement *expression_statement_1 (void);
struct expression_statement *expression_statement_2 (void *ptr);
struct expression *expression_1 (void *ptr);
struct expression *expression_2 (void *ptr1, void *ptr2);
struct external_declaration *external_declaration_1 (void *ptr);
struct external_declaration *external_declaration_2 (void *ptr);
struct function_definition *function_definition_1 (void *ptr1, void *ptr2,
                                                   void *ptr3, void *ptr4);
struct function_definition *function_definition_2 (void *ptr1, void *ptr2,
                                                   void *ptr3);
struct function_specifier *function_specifier_1 (void);
struct function_specifier *function_specifier_2 (void);
struct identifier_list *identifier_list_1 (const char *str);
struct identifier_list *identifier_list_2 (void *ptr1, const char *str);
struct inclusive_or_expression *inclusive_or_expression_1 (void *ptr);
struct inclusive_or_expression *inclusive_or_expression_2 (void *ptr1,
                                                           void *ptr2);
struct init_declarator_list *init_declarator_list_1 (void *ptr);
struct init_declarator_list *init_declarator_list_2 (void *ptr1, void *ptr2);
struct init_declarator *init_declarator_1 (void *ptr1, void *ptr2);
struct init_declarator *init_declarator_2 (void *ptr);
struct initializer_list *initializer_list_1 (void *ptr1, void *ptr2);
struct initializer_list *initializer_list_2 (void *ptr);
struct initializer_list *initializer_list_3 (void *ptr1, void *ptr2,
                                             void *ptr3);
struct initializer_list *initializer_list_4 (void *ptr1, void *ptr2);
struct initializer *initializer_1 (void *ptr);
struct initializer *initializer_2 (void *ptr);
struct initializer *initializer_3 (void *ptr);
struct iteration_statement *iteration_statement_1 (void *ptr1, void *ptr2);
struct iteration_statement *iteration_statement_2 (void *ptr1, void *ptr2);
struct iteration_statement *iteration_statement_3 (void *ptr1, void *ptr2,
                                                   void *ptr3);
struct iteration_statement *iteration_statement_4 (void *ptr1, void *ptr2,
                                                   void *ptr3, void *ptr4);
struct iteration_statement *iteration_statement_5 (void *ptr1, void *ptr2,
                                                   void *ptr3);
struct iteration_statement *iteration_statement_6 (void *ptr1, void *ptr2,
                                                   void *ptr3, void *ptr4);
struct jump_statement *jump_statement_1 (const char *str);
struct jump_statement *jump_statement_2 (void);
struct jump_statement *jump_statement_3 (void);
struct jump_statement *jump_statement_4 (void);
struct jump_statement *jump_statement_5 (void *ptr);
struct labeled_statement *labeled_statement_1 (const char *str, void *ptr2);
struct labeled_statement *labeled_statement_2 (void *ptr1, void *ptr2);
struct labeled_statement *labeled_statement_3 (void *ptr);
struct logical_and_expression *logical_and_expression_1 (void *ptr);
struct logical_and_expression *logical_and_expression_2 (void *ptr1,
                                                         void *ptr2);
struct logical_or_expression *logical_or_expression_1 (void *ptr);
struct logical_or_expression *logical_or_expression_2 (void *ptr1,
                                                       void *ptr2);
struct multiplicative_expression *multiplicative_expression_1 (void *ptr);
struct multiplicative_expression *multiplicative_expression_2 (void *ptr1,
                                                               void *ptr2);
struct multiplicative_expression *multiplicative_expression_3 (void *ptr1,
                                                               void *ptr2);
struct multiplicative_expression *multiplicative_expression_4 (void *ptr1,
                                                               void *ptr2);
struct parameter_declaration *parameter_declaration_1 (void *ptr1,
                                                       void *ptr2);
struct parameter_declaration *parameter_declaration_2 (void *ptr1,
                                                       void *ptr2);
struct parameter_declaration *parameter_declaration_3 (void *ptr);
struct parameter_list *parameter_list_1 (void *ptr);
struct parameter_list *parameter_list_2 (void *ptr1, void *ptr2);
struct parameter_type_list *parameter_type_list_1 (void *ptr);
struct parameter_type_list *parameter_type_list_2 (void *ptr);
struct pointer *pointer_1 (void *ptr1, void *ptr2);
struct pointer *pointer_2 (void *ptr);
struct pointer *pointer_3 (void *ptr);
struct pointer *pointer_4 (void);
struct postfix_expression *postfix_expression_1 (void *ptr);
struct postfix_expression *postfix_expression_2 (void *ptr1, void *ptr2);
struct postfix_expression *postfix_expression_3 (void *ptr);
struct postfix_expression *postfix_expression_4 (void *ptr1, void *ptr2);
struct postfix_expression *postfix_expression_5 (void *ptr1, const char *str);
struct postfix_expression *postfix_expression_6 (void *ptr1, const char *str);
struct postfix_expression *postfix_expression_7 (void *ptr);
struct postfix_expression *postfix_expression_8 (void *ptr);
struct postfix_expression *postfix_expression_9 (void *ptr1, void *ptr2);
struct postfix_expression *postfix_expression_10 (void *ptr1, void *ptr2);
struct primary_expression *primary_expression_1 (const char *str);
struct primary_expression *primary_expression_2 (void *ptr);
struct primary_expression *primary_expression_3 (void *ptr);
struct primary_expression *primary_expression_4 (void *ptr);
struct primary_expression *primary_expression_5 (void *ptr);
struct relational_expression *relational_expression_1 (void *ptr);
struct relational_expression *relational_expression_2 (void *ptr1,
                                                       void *ptr2);
struct relational_expression *relational_expression_3 (void *ptr1,
                                                       void *ptr2);
struct relational_expression *relational_expression_4 (void *ptr1,
                                                       void *ptr2);
struct relational_expression *relational_expression_5 (void *ptr1,
                                                       void *ptr2);
struct selection_statement *selection_statement_1 (void *ptr1, void *ptr2,
                                                   void *ptr3);
struct selection_statement *selection_statement_2 (void *ptr1, void *ptr2);
struct selection_statement *selection_statement_3 (void *ptr1, void *ptr2);
struct shift_expression *shift_expression_1 (void *ptr);
struct shift_expression *shift_expression_2 (void *ptr1, void *ptr2);
struct shift_expression *shift_expression_3 (void *ptr1, void *ptr2);
struct specifier_qualifier_list *specifier_qualifier_list_1 (void *ptr1,
                                                             void *ptr2);
struct specifier_qualifier_list *specifier_qualifier_list_2 (void *ptr);
struct specifier_qualifier_list *specifier_qualifier_list_3 (void *ptr1,
                                                             void *ptr2);
struct specifier_qualifier_list *specifier_qualifier_list_4 (void *ptr);
struct statement *statement_1 (void *ptr);
struct statement *statement_2 (void *ptr);
struct statement *statement_3 (void *ptr);
struct statement *statement_4 (void *ptr);
struct statement *statement_5 (void *ptr);
struct statement *statement_6 (void *ptr);
struct static_assert_declaration *static_assert_declaration_1 (void *ptr1,
                                                               const char
                                                               *str);
struct storage_class_specifier *storage_class_specifier_1 (void);
struct storage_class_specifier *storage_class_specifier_2 (void);
struct storage_class_specifier *storage_class_specifier_3 (void);
struct storage_class_specifier *storage_class_specifier_4 (void);
struct storage_class_specifier *storage_class_specifier_5 (void);
struct storage_class_specifier *storage_class_specifier_6 (void);
struct string *string_1 (const char *str);
struct string *string_2 (const char *str);
struct struct_declaration_list *struct_declaration_list_1 (void *ptr);
struct struct_declaration_list *struct_declaration_list_2 (void *ptr1,
                                                           void *ptr2);
struct struct_declaration *struct_declaration_1 (void *ptr);
struct struct_declaration *struct_declaration_2 (void *ptr1, void *ptr2);
struct struct_declaration *struct_declaration_3 (void *ptr);
struct struct_declarator_list *struct_declarator_list_1 (void *ptr);
struct struct_declarator_list *struct_declarator_list_2 (void *ptr1,
                                                         void *ptr2);
struct struct_declarator *struct_declarator_1 (void *ptr);
struct struct_declarator *struct_declarator_2 (void *ptr1, void *ptr2);
struct struct_declarator *struct_declarator_3 (void *ptr);
struct struct_or_union_specifier *struct_or_union_specifier_1 (void *ptr1,
                                                               void *ptr2);
struct struct_or_union_specifier *struct_or_union_specifier_2 (void *ptr1,
                                                               const char
                                                               *str,
                                                               void *ptr3);
struct struct_or_union_specifier *struct_or_union_specifier_3 (void *ptr1,
                                                               const char
                                                               *str);
struct struct_or_union *struct_or_union_1 (void);
struct struct_or_union *struct_or_union_2 (void);
struct translation_unit *translation_unit_1 (void *ptr);
struct translation_unit *translation_unit_2 (void *ptr1, void *ptr2);
struct type_name *type_name_1 (void *ptr1, void *ptr2);
struct type_name *type_name_2 (void *ptr);
struct type_qualifier_list *type_qualifier_list_1 (void *ptr);
struct type_qualifier_list *type_qualifier_list_2 (void *ptr1, void *ptr2);
struct type_qualifier *type_qualifier_1 (void);
struct type_qualifier *type_qualifier_2 (void);
struct type_qualifier *type_qualifier_3 (void);
struct type_qualifier *type_qualifier_4 (void);
struct type_specifier *type_specifier_1 (void);
struct type_specifier *type_specifier_2 (void);
struct type_specifier *type_specifier_3 (void);
struct type_specifier *type_specifier_4 (void);
struct type_specifier *type_specifier_5 (void);
struct type_specifier *type_specifier_6 (void);
struct type_specifier *type_specifier_7 (void);
struct type_specifier *type_specifier_8 (void);
struct type_specifier *type_specifier_9 (void);
struct type_specifier *type_specifier_10 (void);
struct type_specifier *type_specifier_11 (void);
struct type_specifier *type_specifier_12 (void);
struct type_specifier *type_specifier_13 (void *ptr);
struct type_specifier *type_specifier_14 (void *ptr);
struct type_specifier *type_specifier_15 (void *ptr);
struct type_specifier *type_specifier_16 (const char *str);
struct unary_expression *unary_expression_1 (void *ptr);
struct unary_expression *unary_expression_2 (void *ptr);
struct unary_expression *unary_expression_3 (void *ptr);
struct unary_expression *unary_expression_4 (void *ptr1, void *ptr2);
struct unary_expression *unary_expression_5 (void *ptr);
struct unary_expression *unary_expression_6 (void *ptr);
struct unary_expression *unary_expression_7 (void *ptr);
struct unary_operator *unary_operator_1 (void);
struct unary_operator *unary_operator_2 (void);
struct unary_operator *unary_operator_3 (void);
struct unary_operator *unary_operator_4 (void);
struct unary_operator *unary_operator_5 (void);
struct unary_operator *unary_operator_6 (void);

int look_for_typedef (struct declaration_specifiers *ds);
void register_ids_as_typedef (struct init_declarator_list *idl);
int sym_type (const char *str);
void push_scope (void);
void pull_scope (void);

#endif
