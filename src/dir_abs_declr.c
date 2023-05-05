#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "dir_abs_declr.h"
#include "abs_declr.h"
#include "ass_expr.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

dir_abs_declr_t *
sem_direct_abstract_declarator (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_DIRECT_ABSTRACT_DECLARATOR (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  dir_abs_declr_t *dad = calloc (1, sizeof (dir_abs_declr_t));
  assert (dad != NULL);

  if (ast->func_ptr == direct_abstract_declarator_1)
    {
      dad->kind = 1;
      dad->abs_declr = sem_abstract_declarator (ast->children[0]);
    }
  else if (ast->func_ptr == direct_abstract_declarator_2)
    dad->kind = 2;
  else if (ast->func_ptr == direct_abstract_declarator_3)
    dad->kind = 3;
  else if (ast->func_ptr == direct_abstract_declarator_5)
    {
      dad->kind = 5;
      dad->ass_expr = sem_ass_expr (ast->children[0]);
    }
  else if (ast->func_ptr == direct_abstract_declarator_8)
    {
      dad->kind = 8;
      dad->type_qual_list = 0;  /* TODO mirar com ho faig als punters */
    }
  else if (ast->func_ptr == direct_abstract_declarator_9)
    {
      dad->kind = 9;
      dad->ass_expr = sem_ass_expr (ast->children[0]);
    }
  else if (ast->func_ptr == direct_abstract_declarator_10)
    {
      dad->kind = 10;
      dad->dad = sem_direct_abstract_declarator (ast->children[0]);
    }
  else if (ast->func_ptr == direct_abstract_declarator_11)
    {
      dad->kind = 11;
      dad->dad = sem_direct_abstract_declarator (ast->children[0]);
    }
  else if (ast->func_ptr == direct_abstract_declarator_13)
    {
      dad->kind = 13;
      dad->dad = sem_direct_abstract_declarator (ast->children[0]);
      dad->ass_expr = sem_ass_expr (ast->children[1]);
    }
  else if (ast->func_ptr == direct_abstract_declarator_17)
    {
      dad->kind = 17;
      dad->dad = sem_direct_abstract_declarator (ast->children[0]);
      dad->ass_expr = sem_ass_expr (ast->children[1]);
    }
  else if (ast->func_ptr == direct_abstract_declarator_18)
    dad->kind = 18;
  else if (ast->func_ptr == direct_abstract_declarator_19)
    {
      dad->kind = 19;
      dad->par_type_list = 0;   /* TODO no recordo si ho tinc fet en algun lloc */
    }
  else if (ast->func_ptr == direct_abstract_declarator_20)
    {
      dad->kind = 20;
      dad->dad = sem_direct_abstract_declarator (ast->children[0]);
    }
  else if (ast->func_ptr == direct_abstract_declarator_21)
    {
      dad->kind = 21;
      dad->dad = sem_direct_abstract_declarator (ast->children[0]);
      dad->par_type_list = 0;   /* TODO no recordo si ho tinc fet en algun lloc */
    }

  return dad;
}
