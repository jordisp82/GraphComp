#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "decl_specs.h"
#include "decl_aux.h"
#include "enums.h"
#include "struct_union.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_stg_class_spec (ast_node_t * ast);
static void sem_func_spec (ast_node_t * ast);
static void sem_align_spec (ast_node_t * ast);

void
sem_decl_specs (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_DECLARATION_SPECS (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  /*
   * it's a combination of:
   * - storage-class-specifier
   * - type-specifier
   * - type-qualifier
   * - function-specifier
   * - alignment-specifier
   */

  ast->data = calloc (1, sizeof (decl_specs_t));
  assert (ast->data != NULL);

  for (int i = 0; i < ast->n_children; i++)
    if (IS_STORAGE_CLASS_SPEC (ast->children[i]->func_ptr))
      {
        sem_stg_class_spec (ast->children[i]);
        add_stg_class_spec (ast->data, ast->children[i]->data);
      }
    else if (IS_TYPE_SPEC (ast->children[i]->func_ptr))
      {
        sem_type_spec (ast->children[i]);
        add_type_spec (ast->data, ast->children[i]->data);
      }
    else if (IS_TYPE_QUAL (ast->children[i]->func_ptr))
      {
        sem_type_qual (ast->children[i]);
        add_type_qual (ast->data, ast->children[i]->data);
      }
    else if (IS_FUNCTION_SPEC (ast->children[i]->func_ptr))
      {
        sem_func_spec (ast->children[i]);
        add_func_spec (ast->data, ast->children[i]->data);
      }
    else if (IS_ALIGNMENT_SPEC (ast->children[i]->func_ptr))
      sem_align_spec (ast->children[i]);
    else if (IS_DECLARATION_SPECS (ast->children[i]->func_ptr))
      {
        sem_decl_specs (ast->children[i]);
        add_decl_specs (ast->data, ast->children[i]->data);
      }
}

static void
sem_stg_class_spec (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_STORAGE_CLASS_SPEC (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  /*
   * typedef, extern, static,
   * thread_local, auto, register
   */

  ast->data = calloc (1, sizeof (stg_class_spec_t));
  assert (ast->data != NULL);
  stg_class_spec_t *ptr = ast->data;

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

void
sem_type_spec (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_TYPE_SPEC (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  ast->data = calloc (1, sizeof (type_spec_t));
  assert (ast->data != NULL);
  type_spec_t *ptr = ast->data;

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
      ptr->n_typedef++;
      break;

    default:
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
      else if (ast->func_ptr == type_spec_15)
        {
          ptr->n_enum++;
          sem_enum (ast->children[0]);
          decl_specs_t *parent = ast->parent->data;
          parent->enum_specs = ast->children[0]->data;
        }
      break;
    }
}

void
sem_type_qual (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_TYPE_QUAL (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  /* const, restrict, volatile, atomic */

  ast->data = calloc (1, sizeof (type_qual_t));
  assert (ast->data != NULL);
  type_qual_t *ptr = ast->data;

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
sem_func_spec (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_FUNCTION_SPEC (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  /* inline, noreturn */

  ast->data = calloc (1, sizeof (func_spec_t));
  assert (ast->data != NULL);
  func_spec_t *ptr = ast->data;

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

static void
sem_align_spec (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ALIGNMENT_SPEC (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  /* so far, we do nothing */

  return;
}
