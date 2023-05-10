#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "struct_union_spec.h"
#include "cond_expr.h"
#include "declarator.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static struct_t *sem_struct_spec (ast_node_t * ast);
static union_t *sem_union_spec (ast_node_t * ast);
static void sem_struct_decl_list (struct_t * s, ast_node_t * ast);
static struct_union_field_t *sem_struct_union_field (ast_node_t * ast);
static void sem_sql_list (struct_union_field_t * suf, ast_node_t * ast);
static void sem_sdl_list (struct_union_field_t * suf, ast_node_t * ast);
static void sem_union_decl_list (union_t * u, ast_node_t * ast);
static struct_declr_t *sem_sdl (ast_node_t * ast);
static void sem_sql_type_spec (type_spec_t * ts, ast_node_t * ast);
static void sem_sql_type_qual (type_qual_t * tq, ast_node_t * ast);
static void sem_struct_union_spec1 (type_spec_t * ts, ast_node_t * ast);

void
sem_struct_union_spec (decl_specs_t * ds, ast_node_t * ast)
{
  assert (ds != NULL);
  assert (ast != NULL);
  assert (IS_STRUCT_UNION_SPEC (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);
  assert (IS_STRUCT_OR_UNION (ast->children[0]->func_ptr));

  if (ast->children[0]->func_ptr == struct_or_union_1)
    {
      ds->type_spec.ts_struct = sem_struct_spec (ast);
      ds->type_spec.n_struct++;
    }
  else if (ast->children[0]->func_ptr == struct_or_union_2)
    {
      ds->type_spec.ts_union = sem_union_spec (ast);
      ds->type_spec.n_union++;
    }
}

static struct_t *
sem_struct_spec (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  struct_t *s = calloc (1, sizeof (struct_t));
  assert (s != NULL);

  if (ast->func_ptr == struct_union_spec_2
      || ast->func_ptr == struct_union_spec_3)
    s->tag = strdup (ast->data);
  if (ast->func_ptr == struct_union_spec_1
      || ast->func_ptr == struct_union_spec_2)
    sem_struct_decl_list (s, ast->children[1]);

  return s;
}

static union_t *
sem_union_spec (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  union_t *u = calloc (1, sizeof (union_t));
  assert (u != NULL);

  if (ast->func_ptr == struct_union_spec_2
      || ast->func_ptr == struct_union_spec_3)
    u->tag = strdup (ast->data);
  if (ast->func_ptr == struct_union_spec_1
      || ast->func_ptr == struct_union_spec_2)
    sem_union_decl_list (u, ast->children[1]);

  return u;
}

static void
sem_struct_decl_list (struct_t * s, ast_node_t * ast)
{
  assert (s != NULL);
  assert (ast != NULL);
  assert (IS_STRUCT_DECLARATION_LIST (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  s->n_fields = 1;
  ast_node_t *ptr;

  for (ptr = ast; IS_STRUCT_DECLARATION_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0])
    s->n_fields++;

  s->fields = calloc (s->n_fields, sizeof (struct __sudecl *));
  assert (s->fields != NULL);

  for (ptr = ast; IS_STRUCT_DECLARATION_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0]);
  s->fields[0] = sem_struct_union_field (ptr->children[0]);
  for (int i = 1; ptr != NULL; ptr = ptr->parent, i++)
    s->fields[i] = sem_struct_union_field (ptr->children[1]);
}

static void
sem_union_decl_list (union_t * u, ast_node_t * ast)
{
  assert (u != NULL);
  assert (ast != NULL);
  assert (IS_STRUCT_DECLARATION_LIST (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  u->n_fields = 1;
  ast_node_t *ptr;

  for (ptr = ast; IS_STRUCT_DECLARATION_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0])
    u->n_fields++;

  u->fields = calloc (u->n_fields, sizeof (struct __sudecl *));
  assert (u->fields != NULL);

  for (ptr = ast; IS_STRUCT_DECLARATION_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0]);
  u->fields[0] = sem_struct_union_field (ptr->children[0]);
  for (int i = 1; ptr != NULL; ptr = ptr->parent, i++)
    u->fields[i] = sem_struct_union_field (ptr->children[1]);
}

static struct_union_field_t *
sem_struct_union_field (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_STRUCT_DECLARATION (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  struct_union_field_t *suf = calloc (1, sizeof (struct_union_field_t));
  assert (suf != NULL);

  if (ast->func_ptr == struct_declaration_3)
    return suf;                 /* fuck off with static assert declarations */

  sem_sql_list (suf, ast->children[0]);
  if (ast->func_ptr == struct_declaration_2)
    sem_sdl_list (suf, ast->children[1]);

  return suf;
}

static void
sem_sql_list (struct_union_field_t * suf, ast_node_t * ast)
{
  assert (suf != NULL);
  assert (ast != NULL);
  assert (IS_SPEC_QUAL_LIST (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  ast_node_t *ptr = ast->children[0];

  while (1)
    {
      if (IS_TYPE_SPEC (ptr->func_ptr))
        sem_sql_type_spec (&suf->ts, ptr);
      else if (IS_TYPE_QUAL (ptr->func_ptr))
        sem_sql_type_qual (&suf->tq, ptr);

      if (ptr->n_children > 1)
        ptr = ptr->children[1];
      else
        break;
    }
}

static void
sem_sdl_list (struct_union_field_t * suf, ast_node_t * ast)
{
  assert (suf != NULL);
  assert (ast != NULL);
  assert (IS_STRUCT_DECLARATOR_LIST (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);

  suf->n_struct_declr = 1;
  ast_node_t *ptr;

  for (ptr = ast; IS_STRUCT_DECLARATOR_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0])
    suf->n_struct_declr++;

  suf->struct_declr = calloc (suf->n_struct_declr, sizeof (struct_declr_t *));
  assert (suf->struct_declr != NULL);

  for (ptr = ast; IS_STRUCT_DECLARATOR_LIST (ptr->children[0]->func_ptr);
       ptr = ptr->children[0]);
  suf->struct_declr[0] = sem_sdl (ptr->children[0]);
  ptr = ptr->parent;
  for (int i = 1; ptr != NULL; ptr = ptr->parent, i++)
    suf->struct_declr[0] = sem_sdl (ptr->children[1]);
}

static struct_declr_t *
sem_sdl (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (ast->n_children > 0);
  assert (ast->children != NULL);
  assert (IS_STRUCT_DECLARATOR (ast->func_ptr));

  struct_declr_t *sd = calloc (1, sizeof (struct_declr_t));
  assert (sd != NULL);

  if (ast->func_ptr == struct_declarator_1)
    sd->const_expr = sem_cond_expr (ast->children[0]);
  else if (ast->func_ptr == struct_declarator_2)
    {
      sd->declr = sem_declarator (ast->children[0]);
      sd->const_expr = sem_cond_expr (ast->children[1]);
    }
  else if (ast->func_ptr == struct_declarator_3)
    sd->declr = sem_declarator (ast->children[0]);

  return sd;
}

static void
sem_sql_type_spec (type_spec_t * ts, ast_node_t * ast)
{
  assert (ts != NULL);
  assert (ast != NULL);

  assert (IS_TYPE_SPEC (ast->func_ptr));

  switch (ast->token)
    {
    case VOID:
      ts->n_void++;
      break;

    case CHAR:
      ts->n_char++;
      break;

    case SHORT:
      ts->n_short++;
      break;

    case INT:
      ts->n_int++;
      break;

    case LONG:
      ts->n_long++;
      break;

    case FLOAT:
      ts->n_float++;
      break;

    case DOUBLE:
      ts->n_double++;
      break;

    case SIGNED:
      ts->n_signed++;
      break;

    case UNSIGNED:
      ts->n_unsigned++;
      break;

    case BOOL:
      ts->n_bool++;
      break;

    case COMPLEX:
      ts->n_complex++;
      break;

    case IMAGINARY:
      ts->n_imaginary++;
      break;

    case TYPEDEF_NAME:
      ts->n_typedef++;
      break;

    default:
#if 0
      if (ast->func_ptr == type_spec_13)
        sem_atomic_spec (ds, ast);
      else if (ast->func_ptr == type_spec_14)
        sem_struct_union_spec (ds, ast->children[0]);
      else if (ast->func_ptr == type_spec_15)
        sem_enum_spec (ds, ast->children[0]);
#endif
      if (ast->func_ptr == type_spec_14)
        sem_struct_union_spec1 (ts, ast->children[0]);
      break;
    }
}

static void
sem_sql_type_qual (type_qual_t * tq, ast_node_t * ast)
{
  assert (tq != NULL);
  assert (ast != NULL);
  assert (IS_TYPE_QUAL (ast->func_ptr));

  switch (ast->token)
    {
    case CONST:
      tq->n_const++;
      break;

    case RESTRICT:
      tq->n_restrict++;
      break;

    case VOLATILE:
      tq->n_volatile++;
      break;

    case ATOMIC:
      tq->n_atomic++;
      break;
    }
}

static void
sem_struct_union_spec1 (type_spec_t * ts, ast_node_t * ast)
{
  assert (ts != NULL);
  assert (ast != NULL);
  assert (IS_STRUCT_UNION_SPEC (ast->func_ptr));
  assert (ast->n_children > 0);
  assert (ast->children != NULL);
  assert (IS_STRUCT_OR_UNION (ast->children[0]->func_ptr));

  if (ast->children[0]->func_ptr == struct_or_union_1)
    {
      ts->ts_struct = sem_struct_spec (ast);
      ts->n_struct++;
    }
  else if (ast->children[0]->func_ptr == struct_or_union_2)
    {
      ts->ts_union = sem_union_spec (ast);
      ts->n_union++;
    }
}
