#ifndef NONTERMS_H
#define NONTERMS_H

struct __tu;
struct __extdef;
struct __funcdef;
struct __decl;
struct __declspecs;
struct __declr;
struct __decllist;
struct __stgclasspec;
struct __typespec;
struct __typequal;
struct __funcspec;
struct __alignspec;
struct __struct;
struct __union;
struct __enum;
struct __sudecl;
struct __enumtor;

struct __pointer;
struct __ddeclr;
struct __ptlist;
struct __paramdecl;
struct __initdeclr;
#if 0
struct __initzr;
struct __assexpr;
#endif
struct __expr;
struct __prexpr;
struct __pfexpr;
struct __unexpr;
struct __csexpr;
struct __mlexpr;
struct __addexpr;
struct __bitexpr;               /* FIXME shift */
struct __relexpr;
struct __eqexpr;
struct __bandexpr;
struct __bxorexpr;
struct __borexpr;
struct __landexpr;
struct __lorexpr;
struct __condexpr;
struct __assexpr;
struct __cstmt;
struct __stmt;
struct __jstmt;
struct __sstmt;
struct __lstmt;
struct __istmt;
struct __absdeclr;
struct __dadeclr;

typedef enum
{
  EXTDEF_FUNC_DEF,
  EXTDEF_DECL
} ext_def_kind_t;

typedef struct __tu
{
  int n_children;
  struct __extdef **children;
} tu_t;

typedef struct __extdef
{
  ext_def_kind_t kind;
  union
  {
    struct __funcdef *funcdef;
    struct __decl *decl;
  } child;
} ext_def_t;

typedef struct __funcdef
{
  struct __declspecs *decl_specs;
  struct __declr *declarator;
  struct __decllist *decl_list; /* only for K&R-style */
  struct __cstmt *compound_stmt;
} func_def_t;

typedef struct __decllist
{
  int n_children;
  struct __decl **children;
} decl_list_t;

typedef struct __stgclasspec
{
  int n_typedef;
  int n_extern;
  int n_static;
  int n_thread_local;
  int n_auto;
  int n_register;
} stg_class_spec_t;

typedef struct __typespec
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
  int n_atomic;
  int n_struct;
  int n_union;
  int n_enum;
  int n_typedef;
  struct __struct *ts_struct;
  struct __union *ts_union;
  struct __enum *ts_enum;
} type_spec_t;

typedef struct __typequal
{
  int n_const;
  int n_restrict;
  int n_volatile;
  int n_atomic;
} type_qual_t;

typedef struct __funcspec
{
  int n_inline;
  int n_noreturn;
} func_spec_t;

typedef struct __declspecs
{
  stg_class_spec_t stg_class;
  type_spec_t type_spec;
  type_qual_t type_qual;
  func_spec_t func_spec;
  //struct __alignspec **align_spec;
} decl_specs_t;

typedef struct __struct
{
  const char *tag;              /* may be NULL */
  int n_fields;                 /* may be zero */
  struct __sudecl **fields;
} struct_t;

typedef struct __union
{
  const char *tag;              /* may be NULL */
  int n_fields;                 /* may be zero */
  struct __sudecl **fields;
} union_t;

typedef struct __enum
{
  const char *tag;              /* may be NULL */
  int n_consts;                 /* may be zero */
  struct __enumtor **consts;
} enum_t;

typedef struct __sudecl
{
  /* TODO */
} struct_union_field_t;

typedef struct __enumtor
{
  const char *constant;         /* name of the constant */
  struct __condexpr *expr;      /* may be NULL; value of the constant */
} enum_const_t;



typedef struct __declr
{
  int n_pointers;
  struct __pointer **pointers;
  struct __ddeclr *dir_declr;
} declarator_t;

typedef struct __pointer
{
  type_qual_t type_qual;
} pointer_t;

typedef enum
{
  DIR_DECLR_IDENT,
  DIR_DECLR_DECLR,
  DIR_DECLR_ARRAY,
  DIR_DECLR_FUNCTION
} dir_declr_kind_t;

typedef struct
{
  const char *id;
} dir_declr_ident_t;

typedef struct
{
  declarator_t *declr;
} dir_declr_declr_t;

typedef struct
{
  struct __ddeclr *ddeclr;
  /* TODO */
} dir_declr_array_t;

typedef struct
{
  struct __ddeclr *ddeclr;
  struct __ptlist *ptlist;
} dir_declr_function_t;

typedef struct __ddeclr
{
  dir_declr_kind_t kind;
  union
  {
    dir_declr_ident_t ident;
    declarator_t *declr;
    dir_declr_array_t array;
    dir_declr_function_t function;
  } ddeclr;
} direct_declr_t;

typedef struct __ptlist
{
  int is_variadic;
  int n_params;
  struct __paramdecl **params;
} param_type_list_t;

typedef struct __paramdecl
{
  decl_specs_t *decl_specs;     /* shall not be NULL */
  declarator_t *declr;          /* may be NULL */
  struct __absdeclr *adeclr;    /* may be NULL */
} param_decl_t;

typedef struct __decl
{
  decl_specs_t *decl_specs;
  int n_ideclrs;
  struct __initdeclr **ideclrs;
} declaration_t;

typedef struct __initdeclr
{
  declarator_t *declr;          /* mandatory */
  struct __initzr *initzr;      /* optional */
} init_declr_t;

typedef enum
{
  INITZR_LIST,
  INITZR_EXPR
} initzr_t;

typedef struct __initzr
{
  initzr_t kind;
  union
  {
    struct __assexpr *expr;
  } child;
} initializer_t;

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

typedef struct __prexpr
{
  prim_expr_kind_t kind;
  union
  {
    const char *str;            /* PREXPR_ID, PREXPR_CONST_E PREXPR_STRING, PREXPR_EXPR */
    long long int iv;           /* PREXPR_CONST_I */
    double dv;                  /* PREXPR_CONST_F */
    struct __expr *expr;        /* PREXPR_EXPR */
    /* TODO generic selection */
  } child;
} prim_expr_t;

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

typedef struct __pfexpr
{
  postfix_expr_kind_t kind;
  struct __pfexpr *operand;     /* left-hand-side */
  union
  {
    prim_expr_t *pri_expr;      /* POSTFIX_PRI */
    struct __expr *expr;        /* POSTFIX_ARRAY */
    /* TODO *//* POSTFIX_FUNC */
    const char *id;             /* POSTFIX_MEMB1, POSTFIX_MEMB2 */
    /* TODO *//* POSTFIX_CLIT */
  } child;
} postfix_expr_t;

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

typedef struct __unexpr
{
  unary_expr_kind_t kind;
  struct __unexpr *operand;     /* right-hand-side */
  union
  {
    postfix_expr_t *pfe_expr;   /* UNEXPR_POSTFIX */
    struct
    {
      int op;                   /* UNEXPR_UNOP */
      struct __csexpr *cast;    /* UNEXPR_UNOP */
    } unop;
    /* TODO UNEXPR_SIZEOF2 */
    /* TODO UNEXPR_ALIGNOF */
  } child;
} unary_expr_t;

typedef enum
{
  CSEXPR_UNARY,                 /* cast_expression_1 */
  CSEXPR_CAST                   /* cast_expression_2 */
} cast_expr_kind_t;

typedef struct __csexpr
{
  cast_expr_kind_t kind;
  unary_expr_t *unary;          /* CSEXPR_UNARY */
  struct __csexpr *cast;        /* CSEXPR_CAST */
  /* TODO type name *//* CSEXPR_CAST */
} cast_expr_t;

typedef struct __mlexpr
{
  cast_expr_t *cast;
  struct __mlexpr *operand;     /* NULL if no operation */
  int op;                       /* zero if no operation */
} mult_expr_t;

typedef struct __addexpr
{
  mult_expr_t *mult;
  struct __addexpr *operand;
  int op;
} add_expr_t;

typedef struct __bitexpr
{
  add_expr_t *add;
  struct __bitexpr *operand;
  int op;
} bitw_expr_t;

typedef struct __relexpr
{
  bitw_expr_t *shift;
  struct __relexpr *operand;
  int op;
} rel_expr_t;

typedef struct __eqexpr
{
  rel_expr_t *rel;
  struct __eqexpr *operand;
  int op;
} equal_expr_t;

typedef struct __bandexpr
{
  equal_expr_t *eq;
  struct __bandexpr *operand;
  int op;
} bit_and_expr_t;

typedef struct __bxorexpr
{
  bit_and_expr_t *band;
  struct __bxorexpr *operand;
  int op;
} bit_xor_expr_t;

typedef struct __borexpr
{
  bit_xor_expr_t *xor;
  struct __borexpr *operand;
  int op;
} bit_or_expr_t;

typedef struct __landexpr
{
  bit_or_expr_t *bor;
  struct __landexpr *operand;
  int op;
} logic_and_expr_t;

typedef struct __lorexpr
{
  logic_and_expr_t *land;
  struct __lorexpr *operand;
  int op;
} logic_or_expr_t;

typedef struct __condexpr
{
  logic_or_expr_t *op1;         /* shall not be NULL */
  struct __expr *op2;           /* may be NULL */
  struct __condexpr *op3;       /* may be NULL */
} cond_expr_t;

typedef struct __assexpr
{
  cond_expr_t *cond;            /* non-NULL if no assignment */
  unary_expr_t *unary;          /* non-NULL if assignment */
  int op;                       /* non-zero if assignment */
  struct __assexpr *ass;        /* non-NULL if assignment */
} ass_expr_t;

typedef struct __expr
{
  ass_expr_t *ass;
  struct __expr *expr;
} expression_t;

typedef enum
{
  BLOCK_DECLARATION,
  BLOCK_STATEMENT
} block_kind_t;

typedef struct
{
  block_kind_t kind;
  union
  {
    declaration_t *decl;
    struct __stmt *stmt;
  } element;
} block_item_t;

typedef struct __cstmt
{
  int n_blocks;
  block_item_t **blocks;
} compound_stmt_t;

typedef enum
{
  STMT_LABELED,
  STMT_COMPOUND,
  STMT_EXPRESSION,
  STMT_SELECTION,
  STMT_ITERATION,
  STMT_JUMP
} stmt_kind_t;

typedef struct __stmt
{
  stmt_kind_t kind;
  union
  {
    struct __lstmt *label;      /* STMT_LABELED */
    compound_stmt_t *comp;      /* STMT_COMPOUND */
    expression_t *expr;         /* STMT_EXPRESSION, may be NULL */
    struct __sstmt *select;     /* STMT_SELECTION */
    struct __istmt *iter;       /* STMT_ITERATION */
    struct __jstmt *jump;       /* STMT_JUMP */
  } child;
} statement_t;

typedef enum
{
  JUMP_GOTO,
  JUMP_CONTINUE,
  JUMP_BREAK,
  JUMP_RETURN
} jump_kind_t;

typedef struct __jstmt
{
  jump_kind_t kind;
  const char *label;            /* JUMP_GOTO */
  expression_t *expr;           /* optional for JUMP_RETURN */
} jump_stmt_t;

typedef enum
{
  SELECT_IF,
  SELECT_IF_ELSE,
  SELECT_SWITCH
} select_kind_t;

typedef struct __sstmt
{
  select_kind_t kind;
  expression_t *expr;           /* inside if or switch */
  statement_t *st;              /* if or switch */
  statement_t *st_e;            /* only if else */
} select_stmt_t;

typedef enum
{
  LABEL_LABEL,
  LABEL_CASE,
  LABEL_DEFAULT
} label_kind_t;

typedef struct __lstmt
{
  label_kind_t kind;
  const char *id;               /* LABEL_LABEL */
  statement_t *stmt;            /* all */
  cond_expr_t *const_expr;      /* LABEL_CASE constant expressions are conditional expressions with some additional constraints */
} label_stmt_t;

typedef enum
{
  ITER_WHILE,
  ITER_DO,
  ITER_FOR_1,
  ITER_FOR_2,
  ITER_FOR_3,
  ITER_FOR_4
} iter_kind_t;

typedef struct __istmt
{
  iter_kind_t kind;
  expression_t *expr;           /* ITER_WHILE, ITER_DO, ITER_FOR_2, ITER_FOR_4 */
  statement_t *stmt;            /* all */
  statement_t *es1;             /* all ITER_FOR, it must be expression statement */
  statement_t *es2;             /* ITER_FOR_1, ITER_FOR_2, it must be expression statement */
  declaration_t *decl;          /* ITER_FOR_3, ITER_FOR_4 */
} iter_stmt_t;

typedef struct __absdeclr
{
  int n_pointers;
  struct __pointer **pointers;
  struct __dadeclr *dir_abs_declr;
} abs_declr_t;

typedef struct __dadeclr
{
  int kind;
  abs_declr_t *abs_declr;       /* 1 */
  type_qual_t *type_qual_list;  /* 4, 6, 7, 8, 12, 14, 15, 16 */
  ass_expr_t *ass_expr;         /* 4, 5, 6, 7, 9, 12, 13, 14, 15, 17 */
  struct __dadeclr *dad;        /* 10, 11, 12, 13, 14, 15, 16, 17, 20, 21 */
  param_type_list_t *par_type_list;     /* 19, 21 */
} dir_abs_declr_t;

#endif
