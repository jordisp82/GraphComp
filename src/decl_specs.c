#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "decl_specs.h"
#include "decl_aux.h"
#include "ast.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_stg_class_spec (ast_node_t * ast);
static void sem_type_spec (ast_node_t * ast);
static void sem_type_qual (ast_node_t * ast);
static void sem_func_spec (ast_node_t * ast);
static void sem_align_spec (ast_node_t * ast);
static void sem_struct_union (ast_node_t * ast);
static void sem_enum (ast_node_t * ast);
static void sem_enum1 (ast_node_t * ast);
static void sem_enum2 (ast_node_t * ast);
static void sem_enum3 (ast_node_t * ast);
static void sem_enum_list (ast_node_t * ast);
static void sem_enumerator (ast_node_t * ast);

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

static void
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
          switch (ast->children[0]->token)
            {
            case STRUCT:
              ptr->n_struct++;
              break;

            case UNION:
              ptr->n_union++;
              break;
            }
          sem_struct_union (ast->children[0]);
        }
      else if (ast->func_ptr == type_spec_15)
        {
          ptr->n_enum++;
          sem_enum (ast->children[0]);
        }
      break;
    }
}

static void
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

static void
sem_struct_union (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_STRUCT_OR_UNION (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  /* TODO */
}

static void
sem_enum (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ENUM_SPEC (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  enum_t *ptr = calloc (1, sizeof (enum_t));
  assert (ptr != NULL);
  if (ast->data != NULL)
    ptr->tag = ast->data;
  ast->data = ptr;
  ptr->enum_consts = calloc (1, sizeof (enum_const_t));
  assert (ptr->enum_consts != NULL);

  /*
   * (a) and (b): enum without tag with constants
   * (c) and (d): enum with tag and constants
   * (e): enum with tag without constants
   */

  if (ast->func_ptr == enum_spec_1 || ast->func_ptr == enum_spec_2)
    sem_enum1 (ast);
  else if (ast->func_ptr == enum_spec_3 || ast->func_ptr == enum_spec_4)
    sem_enum2 (ast);
  else if (ast->func_ptr == enum_spec_5)
    sem_enum3 (ast);

  assert (ast->data != NULL);   /* FIXME only for debugging purposes */
}

static void
sem_enum1 (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ENUM_SPEC (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL);
  assert (IS_ENUMERATOR_LIST (ast->children[0]->func_ptr));

  sem_enum_list (ast->children[0]);
}

static void
sem_enum2 (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ENUM_SPEC (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL);
  assert (IS_ENUMERATOR_LIST (ast->children[0]->func_ptr));

  sem_enum_list (ast->children[0]);
}

static void
sem_enum3 (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ENUM_SPEC (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL || ast->n_children == 0);

  /* NOTE do nothing? */
}

static void
sem_enum_list (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ENUMERATOR_LIST (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL);

  ast->data = ast->parent->data;

  for (int i = 0; i < ast->n_children; i++)
    if (IS_ENUMERATOR (ast->children[i]->func_ptr))
      sem_enumerator (ast->children[i]);
    else if (IS_ENUMERATOR_LIST (ast->children[i]->func_ptr))
      sem_enum_list (ast->children[i]);
}

static void
sem_enumerator (ast_node_t * ast)
{
  assert (ast != NULL);
  assert (IS_ENUMERATOR (ast->func_ptr));
  assert (ast->parent != NULL);
  assert (ast->children != NULL);

  enum_const_t *ptr1 = calloc (1, sizeof (enum_const_t));
  assert (ptr1 != NULL);
  ast->data = ptr1;
  ptr1->name = strdup (ast->children[0]->data);
  assert (ptr1->name != NULL);
  if (ast->n_children > 1)
    ptr1->value = ast->children[1];
  enum_t *ptr2 = ast->parent->data;
  assert (ptr2 != NULL);
  ptr1->next = ptr2->enum_consts->next;
  ptr2->enum_consts->next = ptr1;
}
