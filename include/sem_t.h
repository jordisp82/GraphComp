#ifndef SEM_T_H
#define SEM_T_H

#include "ast_t.h"

typedef struct func_spec
{
  int n_inline;
  int n_noreturn;
  /* NOTE no ast_node_t * node */
} func_spec_t;

typedef struct stg_class_spec
{
  int n_typedef;
  int n_extern;
  int n_static;
  int n_thread_local;
  int n_auto;
  int n_register;
  /* NOTE no ast_node_t * node */
} stg_class_spec_t;

typedef struct type_qual
{
  int n_const;
  int n_restrict;
  int n_volatile;
  int n_atomic;
  /* NOTE no ast_node_t * node */
} type_qual_t;

typedef enum
{
    PARENT_UNKNOWN = 0,
    PARENT_FUNC_DEF,
    PARENT_COMPOUND_STMT,
    PARENT_BLOCK_ITEM,
    PARENT_LABEL_STMT,
    PARENT_IF_STMT,
    PARENT_SWITCH_STMT,
    PARENT_ITER_STMT,
    PARENT_JUMP_STMT,
    PARENT_STATEMENT,
} parent_kind_t;

struct abstract_dclor;
struct add_expr;
struct ass_expr;
struct bin_and_expr;
struct bin_or_expr;
struct block_item;
struct cast_expr;
struct compound_stmt;
struct cond_expr;
struct const_expr;
struct const_expr;
struct declaration;
struct declarator;
struct decl_specs;
struct decltion;
struct decltion_list;
struct designation;
struct designator;
struct direct_abs_dlcor;
struct direct_dclor;
struct enumerator;
struct enum_spec;
struct equal_expr;
struct expression;
struct extern_decl;
struct func_def;
struct init_decl_list;
struct init_declr;
struct initzer;
struct initzer_block;
struct iteration_stmt;
struct jump_stmt;
struct label_stmt;
struct log_and_expr;
struct log_or_expr;
struct mult_expr;
struct param_decl;
struct param_type_list;
struct pointer;
struct pointer;
struct postfix_expr;
struct prim_expr;
struct rel_expr;
struct select_stmt;
struct shift_expr;
struct statement;
struct static_assert_decl;
struct struct_decl;
struct struct_declr;
struct struct_union_spec;
struct transl_unit;
struct type_name;
struct type_name;
struct type_spec;
struct unary_expr;
struct unary_expr;
struct xor_expr;

typedef struct abstract_dclor
{
  /* at least one shall not be NULL */
  struct pointer *pointer;
  struct direct_abs_dlcor *direct_abs_dlcor;
  ast_node_t *node;
} abstract_dclor_t;

typedef struct add_expr
{
  struct mult_expr *right;
  struct add_expr *left;
  int op;
  ast_node_t *node;
} add_expr_t;

typedef struct ass_expr
{
  union
  {
    struct cond_expr *cond_expr;
    struct
    {
      struct unary_expr *unary_expr;
      int ass_op;
      struct ass_expr *ass_expr;
    };
  };
  ast_node_t *node;
} ass_expr_t;

typedef struct bin_and_expr
{
  struct equal_expr *right;
  struct bin_and_expr *left;
  int op;
  ast_node_t *node;
} bin_and_expr_t;

typedef struct bin_or_expr
{
  struct xor_expr *right;
  struct bin_or_expr *left;
  int op;
  ast_node_t *node;
} bin_or_expr_t;

typedef enum
{
  BLOCK_DECLARATION,
  BLOCK_STATEMENT
} block_kind_t;

typedef struct block_item
{
  block_kind_t kind;
  union
  {
    struct declaration *decl;
    struct statement *stmt;
  };
  ast_node_t *node;
  parent_kind_t parent_kind;
  void *parent;
} block_item_t;

typedef enum
{
  CSEXPR_UNARY,                 /* cast_expression_1 */
  CSEXPR_CAST                   /* cast_expression_2 */
} cast_expr_kind_t;

typedef struct cast_expr
{
  cast_expr_kind_t kind;
  union
  {
    struct unary_expr *unary_expr;      /* CSEXPR_UNARY */
    struct
    {
      struct type_name *type_name;      /* CSEXPR_CAST */
      struct cast_expr *cast_expr;
    };                          /* CSEXPR_CAST */
  };
  ast_node_t *node;
} cast_expr_t;

typedef struct compound_stmt
{
  int n_block_items;
  struct block_item **block_items;
  ast_node_t *node;
  parent_kind_t parent_kind;
  void *parent;
} compound_stmt_t;

typedef struct cond_expr
{
  struct log_or_expr *first;
  struct expression *second;
  struct cond_expr *third;
  ast_node_t *node;
} cond_expr_t;

typedef struct decl_specs
{
  stg_class_spec_t stg_class_specs;
  struct type_spec *type_spec;
  type_qual_t type_quals;
  func_spec_t func_specs;
  /* NOTE fuck off alignment specifier [0..N] */
  ast_node_t *node;             /* parent must be directly a function definition */
} decl_specs_t;

/*
 * If s_ass_d is not NULL,
 * the other fields shall be NULL.
 * If s_ass_d is NULL,
 * the other fields shall not be NULL.
 * At least one of the fiels
 * shall not be NULL.
 */

typedef struct declaration
{
  union
  {
    struct static_assert_decl *s_ass_d;
    struct
    {
      struct decl_specs *decl_specs;    /* mandatory */
      int n_init_declrs;        /* may be zero */
      struct init_declr **init_declrs;  /* may be NULL */
      /* NOTE fuck off static_assert_decl */
    };
  };
  ast_node_t *node;
} declaration_t;

typedef struct declarator
{
  struct pointer *pointer;      /* optional */
  struct direct_dclor *__direct_dclor;  /* mandatory */
  ast_node_t *node;
} declarator_t;

typedef struct decltion_list
{
  int n_declarations;
  struct declaration **declarations;
  ast_node_t *node;
} decltion_list_t;

typedef struct designation
{
  int n_designators;
  struct designator **designators;
  ast_node_t *node;
} designation_t;

typedef enum
{
  DESIGNR_ARRAY,
  DESIGNR_FIELD
} designr_kind_t;

typedef struct designator
{
  designr_kind_t kind;
  union
  {
    struct const_expr *const_expr;      /* DESIGNR_ARRAY [ expr ] */
    const char *str;            /* DESIGNR_FIELD . IDENTIFIER */
  };
  ast_node_t *node;
} designator_t;

typedef enum
{
  DIRECT_ABS_DCLOR_DECLARATOR,
  DIRECT_ABS_DCLOR_ARRAY,
  DIRECT_ABS_DCLOR_FUNCTION
} direct_abs_dclor_kind_t;

typedef struct direct_abs_dlcor
{
  direct_abs_dclor_kind_t kind;
  union
  {
    struct abstract_dclor *abs_dclor;   /* DIRECT_ABS_DCLOR_DECLARATOR */
    struct
    {
      int is_asterisk;
      int is_static;
      type_qual_t type_quals;
      struct ass_expr *ass_expr;        /* may be NULL */
    } array;                    /* DIRECT_ABS_DCLOR_ARRAY */
    struct
    {
      struct param_type_list *param_list;       /* may be NULL */
    } function;                 /* DIRECT_ABS_DCLOR_FUNCTION */
  };
  struct direct_abs_dlcor *dir_abs_dclr;        /* may be NULL */
  ast_node_t *node;
} direct_abs_dlcor_t;

typedef enum
{
  DIRECT_DCLOR_IDENT,
  DIRECT_DCLOR_DECLARATOR,
  DIRECT_DCLOR_ARRAY,
  DIRECT_DCLOR_FUNCTION
} direct_dclor_kind_t;

typedef struct direct_dclor
{
  direct_dclor_kind_t kind;
  union
  {
    const char *str;            /* DIRECT_DCLOR_IDENT */
    struct declarator *declarator;      /* DIRECT_DCLOR_DECLARATOR */
    struct
    {
      int is_asterisk;
      int is_static;
      type_qual_t type_quals;
      struct ass_expr *ass_expr;        /* may be NULL */
    } array;                    /* DIRECT_DCLOR_ARRAY */
    struct
    {
      struct param_type_list *param_list;       /* may be NULL */
      int n_ident_list;         /* may be zero */
      const char **strs;        /* may be NULL */
    } function;                 /* DIRECT_DCLOR_FUNCTION */
    struct direct_dclor *dir_dclor;     /* only NULL for DIRECT_DCLOR_IDENT and DIRECT_DCLOR_DECLARATOR */
  };
  ast_node_t *node;
} direct_dclor_t;

typedef struct enum_spec
{
  const char *tag;              /* if there is a tag */
  int n_enumerators;            /* may be zero */
  struct enumerator *enumerators;       /* may be NULL */
  ast_node_t *node;
} enum_spec_t;

typedef struct enumerator
{
  const char *enum_const;       /* mandatory */
  struct const_expr *const_expr;        /* optional */
  ast_node_t *node;
} enumerator_t;

typedef struct equal_expr
{
  struct rel_expr *right;
  struct equal_expr *left;
  int op;
  ast_node_t *node;
} equal_expr_t;

typedef struct expression
{
  struct ass_expr *right;
  struct expression *left;
  ast_node_t *node;
} expression_t;

typedef enum
{
  EXTDEF_FUNC_DEF,
  EXTDEF_DECL
} ext_def_kind_t;

typedef struct extern_decl
{
  ext_def_kind_t kind;
  union
  {
    struct func_def *func_def;
    struct decltion *decltion;
  };
  struct transl_unit *parent;
  ast_node_t *node;
} extern_decl_t;

typedef struct func_def
{
  decl_specs_t *decl_specs;     /* mandatory */
  struct declarator *declr;     /* mandatory */
  struct decltion_list *decln_list;     /* only for K&R defintions */
  struct compound_stmt *comp_stmt;      /* mandatory */
  struct extern_decl *parent;
  ast_node_t *node;
} func_def_t;

struct init_declr
{
  struct declarator *declr;     /* mandatory */
  struct initzer *initzer;      /* optional */
  ast_node_t *node;
} init_declr_t;

typedef enum
{
  INITZER_EXPR,
  INITZER_LIST
} initzer_kind_t;

typedef struct initzer
{
  initzer_kind_t kind;
  union
  {
    struct ass_expr *ass_expr;  /* INITZER_EXPR */
    struct
    {
      int n_initzer_block;
      struct initzer_block *initzer_blocks;
    } list;                     /* INITZER_LIST */
  };
  ast_node_t *node;
} initzer_t;

typedef struct initzer_block
{
  struct designation *designation;      /* optional */
  struct initzer *initzer;      /* mandatory */
  ast_node_t *node;
} initzer_block_t;

typedef enum
{
  ITER_WHILE,
  ITER_DO,
  ITER_FOR_1,
  ITER_FOR_2,
  ITER_FOR_3,
  ITER_FOR_4
} iter_kind_t;

typedef struct iteration_stmt
{
  iter_kind_t kind;
  struct expression *expr;      /* ITER_WHILE, ITER_DO, ITER_FOR_2, ITER_FOR_4 */
  struct statement *stmt;       /* all */
  struct statement *es1;        /* all ITER_FOR, it must be expression statement */
  struct statement *es2;        /* ITER_FOR_1, ITER_FOR_2, it must be expression statement */
  struct declaration *decl;     /* ITER_FOR_3, ITER_FOR_4 */
  ast_node_t *node;
  struct statement *parent;
} iter_stmt_t;

typedef enum
{
  JUMP_GOTO,
  JUMP_CONTINUE,
  JUMP_BREAK,
  JUMP_RETURN
} jump_kind_t;

typedef struct jump_stmt
{
  jump_kind_t kind;
  const char *label;            /* JUMP_GOTO */
  struct expression *expr;      /* optional for JUMP_RETURN */
  ast_node_t *node;
  struct statement *parent;
} jump_stmt_t;

typedef enum
{
  LABEL_LABEL,
  LABEL_CASE,
  LABEL_DEFAULT
} label_kind_t;

typedef struct label_stmt
{
  label_kind_t kind;
  const char *str;              /* LABEL_LABEL */
  struct const_expr *expr;      /* LABEL_CASE */
  struct statement *stmt;       /* LABEL_LABEL, LABEL_CASE, LABEL_DEFAULT */
  ast_node_t *node;
  struct statement *parent;
} label_stmt_t;

typedef struct log_and_expr
{
  struct bin_or_expr *right;
  struct log_and_expr *left;
  int op;
  ast_node_t *node;
} log_and_expr_t;

typedef struct log_or_expr
{
  struct log_and_expr *right;
  struct log_or_expr *left;
  int op;
  ast_node_t *node;
} log_or_expr_t;

typedef struct mult_expr
{
  struct cast_expr *right;
  struct mult_expr *left;
  int op;
  ast_node_t *node;
} mult_expr_t;

typedef struct param_decl
{
  struct decl_specs *decl_specs;        /* mantatory */
  struct declarator *declarator;        /* may be NULL */
  struct abstract_dclor *abs_dclor;     /* may be NULL */
  /* declarator and abs_dclor shall not be non-NULL both at the same time */
  ast_node_t *node;
} param_decl_t;

typedef struct param_type_list
{
  int n_param_decls;
  struct param_decl *param_decls;
  int variadic;
  ast_node_t *node;
} param_type_list_t;

typedef struct pointer
{
  type_qual_t type_quals;
  struct pointer *pointer;      /* may be NULL */
  ast_node_t *node;
} pointer_t;

typedef enum
{
  POSTFIX_PRI,                  /* postfix_expression_1 */
  POSTFIX_ARRAY,                /* postfix_expression_2 */
  POSTFIX_FUNC,                 /* postfix_expression_3, postfix_expression_4 */
  POSTFIX_MEMB1,                /* postfix_expression_5 */
  POSTFIX_MEMB2,                /* postfix_expression_6 */
  POSTFIX_INCR,                 /* postfix_expression_7 */
  POSTFIX_DECR,                 /* postfix_expression_8 */
  POSTFIX_CLIT,                 /* postfix_expression_9, postfix_expression_10 */
} postfix_expr_kind_t;

typedef struct postfix_expr
{
  postfix_expr_kind_t kind;
  struct postfix_expr *left;
  union
  {
    struct prim_expr *prim;     /* POSTFIX_PRI */
    struct expression *array;   /* POSTFIX_ARRAY */
    struct
    {
      int n_args_exprs;
      struct ass_expr *args_exprs;
    } function;                 /* POSTFIX_FUNC */
    const char *str;            /* POSTFIX_MEMB1, POSTFIX_MEMB2 */
    /* NOTE none needed for POSTFIX_INCR, POSTFIX_DECR */
    struct
    {
      struct type_name *type_name;
      int n_initzers;
      struct initzer *initzers;
    } comp_lit;                 /* POSTFIX_CLIT */
  };
  ast_node_t *node;
} postfix_expr_t;

typedef enum
{
  PREXPR_ID,                    /* primary_expression_1 */
  PREXPR_CONST_I,               /* primary_expression_2, constant_1 */
  PREXPR_CONST_F,               /* primary_expression_2, constant_2 */
  PREXPR_CONST_E,               /* primary_expression_2, constant_3 */
  PREXPR_STRING,                /* primary_expression_3, string_1 */
  PREXPR_FUNCNAM,               /* primary_expression_3, string_2 */
  PREXPR_EXPR,                  /* primary_expression_4 */
  PREXPR_GENERIC                /* primary_expression_5 */
} prim_expr_kind_t;

typedef struct prim_expr
{
  prim_expr_kind_t kind;
  ast_node_t *node;
  union
  {
    const char *str;            /* PREXPR_ID, PREXPR_CONST_E PREXPR_STRING, PREXPR_EXPR */
    long long int iv;           /* PREXPR_CONST_I */
    double dv;                  /* PREXPR_CONST_F */
    struct expression *expr;    /* PREXPR_EXPR */
    /* NOTE fuck off generic selection */
  };
} prim_expr_t;

typedef struct rel_expr
{
  struct shift_expr *right;
  struct rel_expr *left;
  int op;
  ast_node_t *node;
} rel_expr_t;

typedef enum
{
  SELECT_IF,
  SELECT_IF_ELSE,
  SELECT_SWITCH
} select_kind_t;

typedef struct select_stmt
{
  select_kind_t kind;
  struct expression *expr;      /* if or switch controlling expression */
  struct statement *st1;        /* switch or if branch is taken */
  struct statement *st2;        /* else branch is taken */
  ast_node_t *node;
} select_stmt_t;

typedef struct shift_expr
{
  struct add_expr *right;
  struct shift_expr *left;
  int op;
  ast_node_t *node;
} shift_expr_t;

typedef enum
{
  STMT_LABELED,
  STMT_COMPOUND,
  STMT_EXPRESSION,
  STMT_SELECTION,
  STMT_ITERATION,
  STMT_JUMP
} stmt_kind_t;

typedef struct statement
{
  stmt_kind_t kind;
  union
  {
    struct label_stmt *label;   /* STMT_LABELED */
    struct compound_stmt *comp; /* STMT_COMPOUND */
    struct expression *expr;    /* STMT_EXPRESSION, may be NULL */
    struct select_stmt *select; /* STMT_SELECTION */
    struct iteration_stmt *iter;        /* STMT_ITERATION */
    struct jump_stmt *jump;     /* STMT_JUMP */
  };
  ast_node_t *node;
  parent_kind_t parent_kind;
  void *parent;
} statement_t;

typedef struct struct_decl
{
  struct type_spec *type_specs;
  type_qual_t type_quals;
  int n_struct_declrs;
  struct struct_declr **struct_declrs;
  /* NOTE fuck off static assert declaration */
  ast_node_t *ast;
} struct_decl_t;

typedef struct struct_declr
{
  /* both can't be NULL at the same time */
  struct const_expr *const_expr;        /* may be NULL */
  struct declarator *declarator;        /* may be NULL */
  ast_node_t *node;
} struct_declr_t;

typedef enum
{
  SUS_STRUCT,
  SUS_UNION
} sus_kind_t;

typedef struct struct_union_spec
{
  sus_kind_t kind;
  const char *tag;              /* NULL if no tag */
  int n_struct_decl;            /* may be zero only if tag is non-NULL */
  struct struct_decl **struct_decls;    /* may be NULL only if tag is non-NULL */
  ast_node_t *node;
} struct_union_spec_t;

typedef struct transl_unit
{
  int n_children;
  struct extern_decl **children;
  ast_node_t *node;
} transl_unit_t;

typedef struct type_name
{
  /* specifier-qualifier-list *//* mandatory *//* type-specifier */
  type_qual_t type_quals;
  struct abstract_dclor *abs_dclor;     /* optional */
  ast_node_t *node;
} type_name_t;

typedef struct type_spec
{
  int n_void;
  int n_char;
  int n_short;
  int n_int;
  int n_long;
  int n_float;
  int n_double;
  int n_signed;
  int n_unsigned;
  int n_bool;
  int n_complex;
  int n_imaginary;              /* extension */
  /* NOTE fuck off atomic */
  struct struct_union_spec *struct_or_union;
  struct enum_spec *enum_spec;
  ast_node_t *node;
} type_spec_t;

typedef enum
{
  UNEXPR_POSTFIX,               /* unary_expression_1 */
  UNEXPR_INCR,                  /* unary_expression_2 */
  UNEXPR_DECR,                  /* unary_expression_3 */
  UNEXPR_UNOP,                  /* unary_expression_4 */
  UNEXPR_SIZEOF1,               /* unary_expression_5 */
  UNEXPR_SIZEOF2,               /* unary_expression_6 */
  UNEXPR_ALIGNOF,               /* unary_expression_7 */
} unary_expr_kind_t;

typedef struct unary_expr
{
  unary_expr_kind_t kind;
  struct unary_expr *right;
  union
  {
    struct postfix_expr *postfix;       /* UNEXPR_POSTFIX */
    /* NOTE none needed for UNEXPR_INCR, UNEXPR_DECR */
    struct
    {
      int un_op;
      struct cast_expr *cast_expr;
    };                          /* UNEXPR_UNOP */
    struct unary_expr *unary_expr;      /* UNEXPR_SIZEOF1 */
    struct type_name *type_name;        /* UNEXPR_SIZEOF2, UNEXPR_ALIGNOF */
  };
  ast_node_t *node;
} unary_expr_t;

typedef struct xor_expr
{
  struct bin_and_expr *right;
  struct xor_expr *left;
  int op;
  ast_node_t *node;
} xor_expr_t;

#endif
