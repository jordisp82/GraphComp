#ifndef AST_T_H
#define AST_T_H

typedef struct __astnode
{
  int token;                    /* enum yytokentype */
  void *data;
  int n_children;
  void *func_ptr;
  struct __astnode *parent;
  struct __astnode **children;
} ast_node_t;

#endif
