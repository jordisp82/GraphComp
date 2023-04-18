%{
void yyerror(void **, const char *);
extern int yylex (void);
#include "ast.h"
%}
//%define api.value.type union
%parse-param {void ** ast}
%union
{
    void *ptr;
    int i_num;
    double d_num;
    const char *str;
}
%token	IDENTIFIER I_CONSTANT F_CONSTANT STRING_LITERAL FUNC_NAME SIZEOF
%token	PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token	AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token	SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token	XOR_ASSIGN OR_ASSIGN
%token	TYPEDEF_NAME ENUMERATION_CONSTANT

%token	TYPEDEF EXTERN STATIC AUTO REGISTER INLINE
%token	CONST RESTRICT VOLATILE
%token	BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token	COMPLEX IMAGINARY 
%token	STRUCT UNION ENUM ELLIPSIS

%token	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token	ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL

%start  start_symbol        // translation_unit

%type<ptr> direct_declarator type_qualifier function_specifier struct_or_union storage_class_specifier type_specifier declarator pointer assignment_operator
%type<ptr> unary_operator translation_unit declaration_specifiers external_declaration function_definition alignment_specifier compound_statement
%type<ptr> block_item_list block_item statement declaration labeled_statement expression_statement selection_statement iteration_statement jump_statement
%type<ptr> expression constant_expression declaration_list designator designator_list designation initializer_list initializer direct_abstract_declarator
%type<ptr> abstract_declarator type_qualifier_list parameter_type_list assignment_expression type_name specifier_qualifier_list identifier_list
%type<ptr> parameter_list parameter_declaration enumerator enumerator_list enumeration_constant constant string primary_expression generic_selection
%type<ptr> postfix_expression argument_expression_list unary_expression cast_expression multiplicative_expression additive_expression shift_expression
%type<ptr> relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression
%type<ptr> conditional_expression init_declarator_list static_assert_declaration init_declarator struct_declaration_list struct_or_union_specifier
%type<ptr> struct_declaration struct_declarator struct_declarator_list enum_specifier atomic_type_specifier generic_association generic_assoc_list
%type<str> IDENTIFIER ENUMERATION_CONSTANT STRING_LITERAL FUNC_NAME TYPEDEF_NAME
%type<i_num> I_CONSTANT
%type<d_num> F_CONSTANT
%%

primary_expression
	: IDENTIFIER               { $$ = primary_expression_1 ($1); }
	| constant                 { $$ = primary_expression_2 ($1); }
	| string                   { $$ = primary_expression_3 ($1); }
	| '(' expression ')'       { $$ = primary_expression_4 ($2); }
	| generic_selection        { $$ = primary_expression_5 ($1); }
	;

constant
	: I_CONSTANT               { $$ = constant_1 ($1); }		/* includes character_constant */
	| F_CONSTANT               { $$ = constant_2 ($1); }
	| ENUMERATION_CONSTANT     { $$ = constant_3 ($1); }	/* after it has been defined as such */
	;

enumeration_constant		/* before it has been defined as such */
	: IDENTIFIER           { $$ = enumeration_constant ($1); }
	;

string
	: STRING_LITERAL           { $$ = string_1 ($1); }
	| FUNC_NAME                { $$ = string_2 ($1); }
	;

generic_selection
	: GENERIC '(' assignment_expression ',' generic_assoc_list ')'     { $$ = generic_selection ($3, $5); }
	;

generic_assoc_list
	: generic_association      { $$ = generic_assoc_list_1 ($1); }
	| generic_assoc_list ',' generic_association       { $$ = generic_assoc_list_2 ($1, $3); }
	;

generic_association
	: type_name ':' assignment_expression      { $$ = generic_assoc_1 ($1, $3); }
	| DEFAULT ':' assignment_expression        { $$ = generic_assoc_2 ($3); }
	;

postfix_expression
	: primary_expression           { $$ = postfix_expression_1 ($1); }
	| postfix_expression '[' expression ']'        { $$ = postfix_expression_2 ($1, $3); }
	| postfix_expression '(' ')'   { $$ = postfix_expression_3 ($1); }
	| postfix_expression '(' argument_expression_list ')'  { $$ = postfix_expression_4 ($1, $3); }
	| postfix_expression '.' IDENTIFIER            { $$ = postfix_expression_5 ($1, $3); }
	| postfix_expression PTR_OP IDENTIFIER         { $$ = postfix_expression_6 ($1, $3); }
	| postfix_expression INC_OP    { $$ = postfix_expression_7 ($1); }
	| postfix_expression DEC_OP    { $$ = postfix_expression_8 ($1); }
	| '(' type_name ')' '{' initializer_list '}'           { $$ = postfix_expression_9 ($2, $5); }
	| '(' type_name ')' '{' initializer_list ',' '}'       { $$ = postfix_expression_10 ($2, $5); }
	;

argument_expression_list
	: assignment_expression        { $$ = argument_expression_list_1 ($1); }
	| argument_expression_list ',' assignment_expression   { $$ = argument_expression_list_2 ($1, $3); }
	;

unary_expression
	: postfix_expression               { $$ = unary_expression_1 ($1); }
	| INC_OP unary_expression          { $$ = unary_expression_2 ($2); }
	| DEC_OP unary_expression          { $$ = unary_expression_3 ($2); }
	| unary_operator cast_expression   { $$ = unary_expression_4 ($1, $2); }
	| SIZEOF unary_expression          { $$ = unary_expression_5 ($2); }
	| SIZEOF '(' type_name ')'         { $$ = unary_expression_6 ($3); }
	| ALIGNOF '(' type_name ')'        { $$ = unary_expression_7 ($3); }
	;

unary_operator
	: '&'      { $$ = unary_op_1 (); }
	| '*'      { $$ = unary_op_2 (); }
	| '+'      { $$ = unary_op_3 (); }
	| '-'      { $$ = unary_op_4 (); }
	| '~'      { $$ = unary_op_5 (); }
	| '!'      { $$ = unary_op_6 (); }
	;

cast_expression
	: unary_expression                     { $$ = cast_expression_1 ($1); }
	| '(' type_name ')' cast_expression    { $$ = cast_expression_2 ($2, $4); }
	;

multiplicative_expression
	: cast_expression          { $$ = mult_expression_1 ($1); }
	| multiplicative_expression '*' cast_expression        { $$ = mult_expression_2 ($1, $3); }
	| multiplicative_expression '/' cast_expression        { $$ = mult_expression_3 ($1, $3); }
	| multiplicative_expression '%' cast_expression        { $$ = mult_expression_4 ($1, $3); }
	;

additive_expression
	: multiplicative_expression    { $$ = add_expression_1 ($1); }
	| additive_expression '+' multiplicative_expression    { $$ = add_expression_2 ($1, $3); }
	| additive_expression '-' multiplicative_expression    { $$ = add_expression_3 ($1, $3); }
	;

shift_expression
	: additive_expression          { $$ = shift_expression_1 ($1); }
	| shift_expression LEFT_OP additive_expression         { $$ = shift_expression_2 ($1, $3); }
	| shift_expression RIGHT_OP additive_expression        { $$ = shift_expression_3 ($1, $3); }
	;

relational_expression
	: shift_expression             { $$ = relational_expression_1 ($1); }
	| relational_expression '<' shift_expression           { $$ = relational_expression_2 ($1, $3); }
	| relational_expression '>' shift_expression           { $$ = relational_expression_3 ($1, $3); }
	| relational_expression LE_OP shift_expression         { $$ = relational_expression_4 ($1, $3); }
	| relational_expression GE_OP shift_expression         { $$ = relational_expression_5 ($1, $3); }
	;

equality_expression
	: relational_expression        { $$ = equality_expression_1 ($1); }
	| equality_expression EQ_OP relational_expression      { $$ = equality_expression_2 ($1, $3); }
	| equality_expression NE_OP relational_expression      { $$ = equality_expression_3 ($1, $3); }
	;

and_expression
	: equality_expression          { $$ = and_expression_1 ($1); }
	| and_expression '&' equality_expression               { $$ = and_expression_2 ($1, $3); }
	;

exclusive_or_expression
	: and_expression               { $$ = xor_expression_1 ($1); }
	| exclusive_or_expression '^' and_expression           { $$ = xor_expression_2 ($1, $3); }
	;

inclusive_or_expression
	: exclusive_or_expression      { $$ = or_expression_1 ($1); }
	| inclusive_or_expression '|' exclusive_or_expression  { $$ = or_expression_2 ($1, $3); }
	;

logical_and_expression
	: inclusive_or_expression      { $$ = logic_and_expression_1 ($1); }
	| logical_and_expression AND_OP inclusive_or_expression    { $$ = logic_and_expression_2 ($1, $3); }
	;

logical_or_expression
	: logical_and_expression       { $$ = logic_or_expression_1 ($1); }
	| logical_or_expression OR_OP logical_and_expression       { $$ = logic_or_expression_2 ($1, $3); }
	;

conditional_expression
	: logical_or_expression        { $$ = conditional_expression_1 ($1); }
	| logical_or_expression '?' expression ':' conditional_expression  { $$ = conditional_expression_2 ($1, $3, $5); }
	;

assignment_expression
	: conditional_expression       { $$ = assignment_expression_1 ($1); }
	| unary_expression assignment_operator assignment_expression       { $$ = assignment_expression_2 ($1, $2, $3); }
	;

assignment_operator
	: '='              { $$ = assign_op_1 (); }
	| MUL_ASSIGN       { $$ = assign_op_2 (); }
	| DIV_ASSIGN       { $$ = assign_op_3 (); }
	| MOD_ASSIGN       { $$ = assign_op_4 (); }
	| ADD_ASSIGN       { $$ = assign_op_5 (); }
	| SUB_ASSIGN       { $$ = assign_op_6 (); }
	| LEFT_ASSIGN      { $$ = assign_op_7 (); }
	| RIGHT_ASSIGN     { $$ = assign_op_8 (); }
	| AND_ASSIGN       { $$ = assign_op_9 (); }
	| XOR_ASSIGN       { $$ = assign_op_10 (); }
	| OR_ASSIGN        { $$ = assign_op_11 (); }
	;

expression
	: assignment_expression                    { $$ = expression_1 ($1); }
	| expression ',' assignment_expression     { $$ = expression_2 ($1, $3); }
	;

constant_expression
	: conditional_expression       { $$ = constant_expression ($1); }      /* with constraints */
	;

declaration
	: declaration_specifiers ';'       { $$ = declaration_1 ($1); }
	| declaration_specifiers init_declarator_list ';'  { $$ = declaration_2 ($1, $2); }
	| static_assert_declaration        { $$ = declaration_3 ($1); }
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers   { $$ = declaration_specifiers_1 ($1, $2); }
	| storage_class_specifier                          { $$ = declaration_specifiers_2 ($1); }
	| type_specifier declaration_specifiers            { $$ = declaration_specifiers_3 ($1, $2); }
	| type_specifier                                   { $$ = declaration_specifiers_4 ($1); }
	| type_qualifier declaration_specifiers            { $$ = declaration_specifiers_5 ($1, $2); }
	| type_qualifier                                   { $$ = declaration_specifiers_6 ($1); }
	| function_specifier declaration_specifiers        { $$ = declaration_specifiers_7 ($1, $2); }
	| function_specifier                               { $$ = declaration_specifiers_8 ($1); }
	| alignment_specifier declaration_specifiers       { $$ = declaration_specifiers_9 ($1, $2); }
	| alignment_specifier                              { $$ = declaration_specifiers_10 ($1); }
	;

init_declarator_list
	: init_declarator          { $$ = init_declarator_list_1 ($1); }
	| init_declarator_list ',' init_declarator         { $$ = init_declarator_list_2 ($1, $3); }
	;

init_declarator
	: declarator '=' initializer       { $$ = init_declarator_1 ($1, $3); }
	| declarator                       { $$ = init_declarator_2 ($1); }
	;

storage_class_specifier
	: TYPEDEF                  { $$ = storage_class_spec_1 (); }	/* identifiers must be flagged as TYPEDEF_NAME */
	| EXTERN                   { $$ = storage_class_spec_2 (); }
	| STATIC                   { $$ = storage_class_spec_3 (); }
	| THREAD_LOCAL             { $$ = storage_class_spec_4 (); }
	| AUTO                     { $$ = storage_class_spec_5 (); }
	| REGISTER                 { $$ = storage_class_spec_6 (); }
	;

type_specifier
	: VOID                     { $$ = type_spec_1 (); }
	| CHAR                     { $$ = type_spec_2 (); }
	| SHORT                    { $$ = type_spec_3 (); }
	| INT                      { $$ = type_spec_4 (); }
	| LONG                     { $$ = type_spec_5 (); }
	| FLOAT                    { $$ = type_spec_6 (); }
	| DOUBLE                   { $$ = type_spec_7 (); }
	| SIGNED                   { $$ = type_spec_8 (); }
	| UNSIGNED                 { $$ = type_spec_9 (); }
	| BOOL                     { $$ = type_spec_10 (); }
	| COMPLEX                  { $$ = type_spec_11 (); }
	| IMAGINARY	  	           { $$ = type_spec_12 (); } /* non-mandated extension */
	| atomic_type_specifier    { $$ = type_spec_13 ($1); }
	| struct_or_union_specifier    { $$ = type_spec_14 ($1); }
	| enum_specifier           { $$ = type_spec_15 ($1); }
	| TYPEDEF_NAME             { $$ = type_spec_16 ($1); }		/* after it has been defined as such */
	;

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'              { $$ = struct_union_spec_1 ($1, $3); }
	| struct_or_union IDENTIFIER '{' struct_declaration_list '}'   { $$ = struct_union_spec_2 ($1, $2, $4); }
	| struct_or_union IDENTIFIER           { $$ = struct_union_spec_3 ($1, $2); }
	;

struct_or_union
	: STRUCT                   { $$ = struct_or_union_1 (); }
	| UNION                    { $$ = struct_or_union_2 (); }
	;

struct_declaration_list
	: struct_declaration       { $$ = struct_declaration_list_1 ($1); }
	| struct_declaration_list struct_declaration       { $$ = struct_declaration_list_2 ($1, $2); }
	;

struct_declaration
	: specifier_qualifier_list ';'                         { $$ = struct_declaration_1 ($1); } /* for anonymous struct/union */
	| specifier_qualifier_list struct_declarator_list ';'  { $$ = struct_declaration_2 ($1, $2); }
	| static_assert_declaration                            { $$ = struct_declaration_3 ($1); }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list      { $$ = spec_qual_list_1 ($1, $2); }
	| type_specifier                               { $$ = spec_qual_list_2 ($1); }
	| type_qualifier specifier_qualifier_list      { $$ = spec_qual_list_3 ($1, $2); }
	| type_qualifier                               { $$ = spec_qual_list_4 ($1); }
	;

struct_declarator_list
	: struct_declarator            { $$ = struct_declarator_list_1 ($1); }
	| struct_declarator_list ',' struct_declarator         { $$ = struct_declarator_list_2 ($1, $3); }
	;

struct_declarator
	: ':' constant_expression              { $$ = struct_declarator_1 ($2); }
	| declarator ':' constant_expression   { $$ = struct_declarator_2 ($1, $3); }
	| declarator                           { $$ = struct_declarator_3 ($1); }
	;

enum_specifier
	: ENUM '{' enumerator_list '}'         { $$ = enum_spec_1 ($3); }
	| ENUM '{' enumerator_list ',' '}'     { $$ = enum_spec_2 ($3); }
	| ENUM IDENTIFIER '{' enumerator_list '}'          { $$ = enum_spec_3 ($2, $4); }
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'      { $$ = enum_spec_4 ($2, $4); }
	| ENUM IDENTIFIER                      { $$ = enum_spec_5 ($2); }
	;

enumerator_list
	: enumerator                           { $$ = enumerator_list_1 ($1); }
	| enumerator_list ',' enumerator       { $$ = enumerator_list_2 ($1, $3); }
	;

enumerator	/* identifiers must be flagged as ENUMERATION_CONSTANT */
	: enumeration_constant '=' constant_expression     { $$ = enumerator_1 ($1, $3); }
	| enumeration_constant                             { $$ = enumerator_2 ($1); }
	;

atomic_type_specifier
	: ATOMIC '(' type_name ')'     { $$ = atomic_type_spec ($3); }
	;

type_qualifier
	: CONST            { $$ = type_qualifier_1 (); }
	| RESTRICT         { $$ = type_qualifier_2 (); }
	| VOLATILE         { $$ = type_qualifier_3 (); }
	| ATOMIC           { $$ = type_qualifier_4 (); }
	;

function_specifier
	: INLINE           { $$ = function_spec_1 (); }
	| NORETURN         { $$ = function_spec_2 (); }
;

alignment_specifier
	: ALIGNAS '(' type_name ')'                { $$ = alignment_spec_1 ($3); }
	| ALIGNAS '(' constant_expression ')'      { $$ = alignment_spec_2 ($3); }
	;

declarator
	: pointer direct_declarator        { $$ = declarator_1 ($1, $2); }
	| direct_declarator                { $$ = declarator_2 ($1); }
	;

direct_declarator
	: IDENTIFIER               { $$ = direct_declarator_1 ($1); }
	| '(' declarator ')'       { $$ = direct_declarator_2 ($2); }
	| direct_declarator '[' ']'        { $$ = direct_declarator_3 ($1); }
	| direct_declarator '[' '*' ']'    { $$ = direct_declarator_4 ($1); }
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'   { $$ = direct_declarator_5 ($1, $4, $5); }
	| direct_declarator '[' STATIC assignment_expression ']'       { $$ = direct_declarator_6 ($1, $4); }
	| direct_declarator '[' type_qualifier_list '*' ']'            { $$ = direct_declarator_7 ($1, $3); }
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'   { $$ = direct_declarator_8 ($1, $3, $5); }
	| direct_declarator '[' type_qualifier_list assignment_expression ']'          { $$ = direct_declarator_9 ($1, $3, $4); }
	| direct_declarator '[' type_qualifier_list ']'                { $$ = direct_declarator_10 ($1, $3); }
	| direct_declarator '[' assignment_expression ']'              { $$ = direct_declarator_11 ($1, $3); }
	| direct_declarator '(' parameter_type_list ')'                { $$ = direct_declarator_12 ($1, $3); }
	| direct_declarator '(' ')'    { $$ = direct_declarator_13 ($1); }
	| direct_declarator '(' identifier_list ')'                    { $$ = direct_declarator_14 ($1, $3); }
	;

pointer
	: '*' type_qualifier_list pointer  { $$ = pointer_1 ($2, $3); }
	| '*' type_qualifier_list          { $$ = pointer_2 ($2); }
	| '*' pointer                      { $$ = pointer_3 ($2); }
	| '*'                              { $$ = pointer_4 (); }
	;

type_qualifier_list
	: type_qualifier                       { $$ = type_qualifier_list_1 ($1); }
	| type_qualifier_list type_qualifier   { $$ = type_qualifier_list_2 ($1, $2); }
	;


parameter_type_list
	: parameter_list ',' ELLIPSIS      { $$ = parameter_type_list_1 ($1); }
	| parameter_list                   { $$ = parameter_type_list_1 ($1); }
	;

parameter_list
	: parameter_declaration                        { $$ = parameter_list_1 ($1); }
	| parameter_list ',' parameter_declaration     { $$ = parameter_list_2 ($1, $3); }
	;

parameter_declaration
	: declaration_specifiers declarator            { $$ = parameter_declaration_1 ($1, $2); }
	| declaration_specifiers abstract_declarator   { $$ = parameter_declaration_2 ($1, $2); }
	| declaration_specifiers                       { $$ = parameter_declaration_3 ($1); }
	;

identifier_list
	: IDENTIFIER                           { $$ = identifier_list_1 ($1); }
	| identifier_list ',' IDENTIFIER       { $$ = identifier_list_2 ($1, $3); }
	;

type_name
	: specifier_qualifier_list abstract_declarator     { $$ = type_name_1 ($1, $2); }
	| specifier_qualifier_list                         { $$ = type_name_2 ($1); }
	;

abstract_declarator
	: pointer direct_abstract_declarator   { $$ = abstract_declarator_1 ($1, $2); }
	| pointer                              { $$ = abstract_declarator_2 ($1); }
	| direct_abstract_declarator           { $$ = abstract_declarator_3 ($1); }
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'          { $$ = direct_abstract_declarator_1 ($2); }
	| '[' ']'          { $$ = direct_abstract_declarator_2 (); }
	| '[' '*' ']'      { $$ = direct_abstract_declarator_3 (); }
	| '[' STATIC type_qualifier_list assignment_expression ']' { $$ = direct_abstract_declarator_4 ($3, $4); }
	| '[' STATIC assignment_expression ']' { $$ = direct_abstract_declarator_5 ($3); }
	| '[' type_qualifier_list STATIC assignment_expression ']' { $$ = direct_abstract_declarator_6 ($2, $4); }
	| '[' type_qualifier_list assignment_expression ']'        { $$ = direct_abstract_declarator_7 ($2, $3); }
	| '[' type_qualifier_list ']'          { $$ = direct_abstract_declarator_8 ($2); }
	| '[' assignment_expression ']'        { $$ = direct_abstract_declarator_9 ($2); }
	| direct_abstract_declarator '[' ']'   { $$ = direct_abstract_declarator_10 ($1); }
	| direct_abstract_declarator '[' '*' ']'   { $$ = direct_abstract_declarator_11 ($1); }
	| direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']'  { $$ = direct_abstract_declarator_12 ($1, $4, $5); }
	| direct_abstract_declarator '[' STATIC assignment_expression ']'  { $$ = direct_abstract_declarator_13 ($1, $4); }
	| direct_abstract_declarator '[' type_qualifier_list assignment_expression ']'     { $$ = direct_abstract_declarator_14 ($1, $3, $4); }
	| direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']'  { $$ = direct_abstract_declarator_15 ($1, $3, $5); }
	| direct_abstract_declarator '[' type_qualifier_list ']'       { $$ = direct_abstract_declarator_16 ($1, $3); }
	| direct_abstract_declarator '[' assignment_expression ']'     { $$ = direct_abstract_declarator_17 ($1, $3); }
	| '(' ')'          { $$ = direct_abstract_declarator_18 (); }
	| '(' parameter_type_list ')'      { $$ = direct_abstract_declarator_19 ($2); }
	| direct_abstract_declarator '(' ')'   { $$ = direct_abstract_declarator_20 ($1); }
	| direct_abstract_declarator '(' parameter_type_list ')'   { $$ = direct_abstract_declarator_21 ($1, $3); }
	;

initializer
	: '{' initializer_list '}'         { $$ = initializer_1 ($2); }
	| '{' initializer_list ',' '}'     { $$ = initializer_2 ($2); }
	| assignment_expression            { $$ = initializer_3 ($1); }
	;

initializer_list
	: designation initializer                          { $$ = initializer_list_1 ($1, $2); }
	| initializer                                      { $$ = initializer_list_2 ($1); }
	| initializer_list ',' designation initializer     { $$ = initializer_list_3 ($1, $3, $4); }
	| initializer_list ',' initializer                 { $$ = initializer_list_4 ($1, $3); }
	;

designation
	: designator_list '='          { $$ = designation ($1); }
	;

designator_list
	: designator                   { $$ = designator_list_1 ($1); }
	| designator_list designator   { $$ = designator_list_2 ($1, $2); }
	;

designator
	: '[' constant_expression ']'  { $$ = designator_1 ($2); }
	| '.' IDENTIFIER               { $$ = designator_2 ($2); }
	;

static_assert_declaration
	: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';' { $$ = static_assert_declaration ($3, $5); }
	;

statement
	: labeled_statement        { $$ = statement_1 ($1); }
	| compound_statement       { $$ = statement_2 ($1); }
	| expression_statement     { $$ = statement_3 ($1); }
	| selection_statement      { $$ = statement_4 ($1); }
	| iteration_statement      { $$ = statement_5 ($1); }
	| jump_statement           { $$ = statement_6 ($1); }
	;

labeled_statement
	: IDENTIFIER ':' statement                 { $$ = labeled_statement_1 ($1, $3); }
	| CASE constant_expression ':' statement   { $$ = labeled_statement_2 ($2, $4); }
	| DEFAULT ':' statement                    { $$ = labeled_statement_3 ($3); }
	;

compound_statement
	: '{' '}'                      { $$ = compound_statement_1 (); }
	| '{' { push_scope (); } block_item_list { pull_scope (); } '}'     { $$ = compound_statement_2 ($3); }    // it was $2
	;

block_item_list
	: block_item                   { $$ = block_item_list_1 ($1); }
	| block_item_list block_item   { $$ = block_item_list_2 ($1, $2); }
	;

block_item
	: declaration                  { $$ = block_item_1 ($1); }
	| statement                    { $$ = block_item_2 ($1); }
	;

expression_statement
	: ';'                          { $$ = expression_statement_1 (); }
	| expression ';'               { $$ = expression_statement_2 ($1); }
	;

selection_statement
	: IF '(' expression ')' statement ELSE statement   { $$ = selection_statement_1 ($3, $5, $7); }
	| IF '(' expression ')' statement                  { $$ = selection_statement_2 ($3, $5); }
	| SWITCH '(' expression ')' statement              { $$ = selection_statement_3 ($3, $5); }
	;

iteration_statement
	: WHILE '(' expression ')' statement               { $$ = iteration_statement_1 ($3, $5); }
	| DO statement WHILE '(' expression ')' ';'        { $$ = iteration_statement_2 ($2, $5); }
	| FOR '(' expression_statement expression_statement ')' statement  { $$ = iteration_statement_3 ($3, $4, $6); }
	| FOR '(' expression_statement expression_statement expression ')' statement   { $$ = iteration_statement_4 ($3, $4, $5, $7); }
	| FOR '(' declaration expression_statement ')' statement           { $$ = iteration_statement_5 ($3, $4, $6); }
	| FOR '(' declaration expression_statement expression ')' statement    { $$ = iteration_statement_6 ($3, $4, $5, $7); }
	;

jump_statement
	: GOTO IDENTIFIER ';'          { $$ = jump_statement_1 ($2); }
	| CONTINUE ';'                 { $$ = jump_statement_2 (); }
	| BREAK ';'                    { $$ = jump_statement_3 (); }
	| RETURN ';'                   { $$ = jump_statement_4 (); }
	| RETURN expression ';'        { $$ = jump_statement_5 ($2); }
	;

translation_unit
	: external_declaration                     { $$ = translation_unit_1 ($1); }
	| translation_unit external_declaration    { $$ = translation_unit_2 ($1, $2); }
	;

external_declaration
	: function_definition                      { $$ = external_declaration_1 ($1); }
	| declaration                              { $$ = external_declaration_2 ($1); }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement    { $$ = function_definition_1 ($1, $2, $3, $4); }
	| declaration_specifiers declarator compound_statement                     { $$ = function_definition_2 ($1, $2, $3); }
	;

declaration_list
	: declaration                      { $$ = declaration_list_1 ($1); }
	| declaration_list declaration     { $$ = declaration_list_2 ($1, $2); }
	;

start_symbol
    : translation_unit      { *ast = $1; }

%%
#include <stdio.h>

void yyerror(void ** shit __attribute__ ((unused)), const char *s)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", s);
}
