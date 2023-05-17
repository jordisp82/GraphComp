#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "decl_specs.h"
#include "sem_t.h"
#include "ast.h"

#if 0
#include "cond_expr.h"
#include "struct_union_spec.h"
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_stg_class_spec (stg_class_spec_t * ds, ast_node_t * ast);
static void sem_type_spec (type_spec_t * ptr, ast_node_t * ast);
static void sem_type_qual (type_qual_t * ptr, ast_node_t * ast);
static void sem_func_spec (func_spec_t * ptr, ast_node_t * ast);
#if 0
static void sem_atomic_spec (decl_specs_t * ds, ast_node_t * ast);
static void sem_enum_spec (decl_specs_t * ds, ast_node_t * ast);
static void sem_enum_list (enum_t * et, ast_node_t * ast);
static enum_const_t *sem_enum_const (ast_node_t * ast);
#endif

decl_specs_t *
sem_decl_specs (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_DECLARATION_SPECS (ast->func_ptr));
  assert (ast->children != NULL);

  decl_specs_t *ds = calloc (1, sizeof (decl_specs_t));
  assert (ds != NULL);
  ds->node = ast;
  ds->type_spec = calloc (1, sizeof (type_spec_t));
  assert (ds->type_spec != NULL);

  /* NOTE we're going to ignore alignment specifiers */

  ast_node_t *ptr = ast->children[0];
  while (1)
    {
      if (IS_STORAGE_CLASS_SPEC (ptr->func_ptr))
        sem_stg_class_spec (&ds->stg_class_specs, ptr);
      else if (IS_TYPE_SPEC (ptr->func_ptr))
        sem_type_spec (ds->type_spec, ptr);
      else if (IS_TYPE_QUAL (ptr->func_ptr))
        sem_type_qual (&ds->type_quals, ptr);
      else if (IS_FUNCTION_SPEC (ptr->func_ptr))
        sem_func_spec (&ds->func_specs, ptr);
      if (ptr->parent->n_children == 2)
        ptr = ptr->parent->children[1]->children[0];
      else
        break;
    };

  return ds;
}

static void
sem_stg_class_spec (stg_class_spec_t * ptr, ast_node_t * ast)
{
  assert (ptr != NULL);
  assert (ast != NULL);
  assert (IS_STORAGE_CLASS_SPEC (ast->func_ptr));

  switch (ast->token)
    {
    case TYPEDEF:
      ptr->n_typedef++;
      break;

    case EXTERN:
      ptr->n_extern++;
      break;

    case STATIC:
      ptr->n_static++;
      break;

    case THREAD_LOCAL:
      ptr->n_thread_local++;
      break;

    case AUTO:
      ptr->n_auto++;
      break;

    case REGISTER:
      ptr->n_register++;
      break;
    }
}

static void
sem_type_spec (type_spec_t * ptr, ast_node_t * ast)
{
  assert (ptr != NULL);
  assert (ast != NULL);
  assert (IS_TYPE_SPEC (ast->func_ptr));

  switch (ast->token)
    {
    case VOID:
      ptr->n_void++;
      break;

    case CHAR:
      ptr->n_char++;
      break;

    case SHORT:
      ptr->n_short++;
      break;

    case INT:
      ptr->n_int++;
      break;

    case LONG:
      ptr->n_long++;
      break;

    case FLOAT:
      ptr->n_float++;
      break;

    case DOUBLE:
      ptr->n_double++;
      break;

    case SIGNED:
      ptr->n_signed++;
      break;

    case UNSIGNED:
      ptr->n_unsigned++;
      break;

    case BOOL:
      ptr->n_bool++;
      break;

    case COMPLEX:
      ptr->n_complex++;
      break;

    case IMAGINARY:
      ptr->n_imaginary++;
      break;

    case TYPEDEF_NAME:
      ptr->typedef_name = strdup (ast->data);
      assert (ptr->typedef_name != NULL);
      break;

    default:
      /* TODO */
#if 0
      if (ast->func_ptr == type_spec_13)
        sem_atomic_spec (ds, ast);
      else if (ast->func_ptr == type_spec_14)
        sem_struct_union_spec (ds, ast->children[0]);
      else if (ast->func_ptr == type_spec_15)
        sem_enum_spec (ds, ast->children[0]);
#if 0
      assert (ast->n_children > 0 && ast->children != NULL
              && ast->children[0] != NULL);
      if (ast->func_ptr == type_spec_13)
        ptr->n_atomic++;        /* for now, fuck off with that */
      else if (ast->func_ptr == type_spec_14)
        {
          sem_struct_union_spec (ast->children[0]);
          decl_specs_t *parent = ast->parent->data;
          parent->struct_union_specs = ast->children[0]->data;
        }
#endif
#endif
      break;
    }
}

static void
sem_type_qual (type_qual_t * ptr, ast_node_t * ast)
{
  assert (ptr != NULL);
  assert (ast != NULL);
  assert (IS_TYPE_QUAL (ast->func_ptr));

  switch (ast->token)
    {
    case CONST:
      ptr->n_const++;
      break;

    case RESTRICT:
      ptr->n_restrict++;
      break;

    case VOLATILE:
      ptr->n_volatile++;
      break;

    case ATOMIC:
      ptr->n_atomic++;
      break;
    }
}

static void
sem_func_spec (func_spec_t * ptr, ast_node_t * ast)
{
  assert (ptr != NULL);
  assert (ast != NULL);
  assert (IS_FUNCTION_SPEC (ast->func_ptr));

  switch (ast->token)
    {
    case INLINE:
      ptr->n_inline++;
      break;

    case NORETURN:
      ptr->n_noreturn++;
      break;
    }
}

#if 0
static void
sem_atomic_spec (decl_specs_t * ds, ast_node_t * ast)
{
  assert (ds != NULL);
  assert (ast != NULL);
  assert (IS_TYPE_SPEC (ast->func_ptr));

  /*
   * TODO needs type-name,
   * which in turn needs the
   * abstract declarator
   */
}

static void
sem_enum_spec (decl_specs_t * ds, ast_node_t * ast)
{
  assert (ds != NULL);
  assert (ast != NULL);
  assert (IS_TYPE_SPEC (ast->func_ptr));

  ds->type_spec.n_enum++;
  ds->type_spec.ts_enum = calloc (1, sizeof (enum_t));
  assert (ds->type_spec.ts_enum != NULL);
  enum_t *e = ds->type_spec.ts_enum;

  if (ast->func_ptr == enum_spec_3 || ast->func_ptr == enum_spec_4
      || ast->func_ptr == enum_spec_5)
    e->tag = strdup (ast->data);
  if (ast->func_ptr != enum_spec_5)
    sem_enum_list (e, ast->children[0]);
}

static void
sem_enum_list (enum_t * et, ast_node_t * ast)
{
  assert (ast != NULL);
  assert (et != NULL);

  et->n_consts = 1;
  ast_node_t *ptr;

  for (ptr = ast; IS_ENUMERATOR_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0])
    et->n_consts++;

  et->consts = calloc (et->n_consts, sizeof (enum_const_t *));
  assert (et->consts != NULL);

  for (ptr = ast; IS_ENUMERATOR_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0]);
  et->consts[0] = sem_enum_const (ptr->children[0]);
  ptr = ptr->parent;
  for (int i = 1; ptr != NULL; ptr = ptr->parent, i++)
    et->consts[i] = sem_enum_const (ptr->children[1]);
}

static enum_const_t *
sem_enum_const (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ENUMERATOR (ast->func_ptr));

  enum_const_t *ec = calloc (1, sizeof (enum_const_t));
  assert (ec != NULL);

  ec->constant = strdup (ast->children[0]->data);
  assert (ec->constant != NULL);
  if (ast->func_ptr == enumerator_1)
    ec->expr = sem_cond_expr (ast->children[1]);

  return ec;
}
#endif
