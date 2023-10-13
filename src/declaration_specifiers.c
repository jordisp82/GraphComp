#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "declaration_specifiers.h"
#include "storage_class_specifier.h"
#include "type_qualifier.h"
#include "function_specifier.h"
#include "alignment_specifier.h"
#include "type_specifier.h"
#include "declaration.h"
#include "parameter_declaration.h"
#include "function_definition.h"
#include "struct_or_union_specifier.h"
#include "struct_or_union.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void local_dot_create (void *Node, void *F);
/* NOTE start of experimental code */
static int local_sem_analysis (void *Node);
static int stg_class_sem_analysis (struct declaration_specifiers *node);
static int type_spec_sem_analysis (struct declaration_specifiers *node);
static int type_qual_sem_analysis (struct declaration_specifiers *node);
static int func_spec_sem_analysis (struct declaration_specifiers *node);
static const char *get_typedef_name (struct declaration_specifiers *node);
/* NOTE end of experimental code */

struct declaration_specifiers *
declaration_specifiers_1 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct storage_class_specifier *stg = ptr1;
  struct declaration_specifiers *buff = ptr2;

  buff->last->next = calloc (1, sizeof (struct ds_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ds_kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->last->stg = stg;
  stg->parent_kind = NODE_DECLARATION_SPECIFIERS;
  stg->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_2 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration_specifiers *buff =
    calloc (1, sizeof (struct declaration_specifiers));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION_SPECIFIERS;
  buff->first = calloc (1, sizeof (struct ds_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ds_kind = NODE_STORAGE_CLASS_SPECIFIER;
  buff->first->stg = ptr;
  buff->first->stg->parent_kind = NODE_DECLARATION_SPECIFIERS;
  buff->first->stg->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_3 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct type_specifier *ts = ptr1;
  struct declaration_specifiers *buff = ptr2;

  buff->last->next = calloc (1, sizeof (struct ds_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ds_kind = NODE_TYPE_SPECIFIER;
  buff->last->ts = ts;
  ts->parent_kind = NODE_DECLARATION_SPECIFIERS;
  ts->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_4 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration_specifiers *buff =
    calloc (1, sizeof (struct declaration_specifiers));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION_SPECIFIERS;
  buff->first = calloc (1, sizeof (struct ds_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ds_kind = NODE_TYPE_SPECIFIER;
  buff->first->ts = ptr;
  buff->first->ts->parent_kind = NODE_DECLARATION_SPECIFIERS;
  buff->first->ts->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_5 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct type_qualifier *tq = ptr1;
  struct declaration_specifiers *buff = ptr2;

  buff->last->next = calloc (1, sizeof (struct ds_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ds_kind = NODE_TYPE_QUALIFIER;
  buff->last->tq = tq;
  tq->parent_kind = NODE_DECLARATION_SPECIFIERS;
  tq->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_6 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration_specifiers *buff =
    calloc (1, sizeof (struct declaration_specifiers));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION_SPECIFIERS;
  buff->first = calloc (1, sizeof (struct ds_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ds_kind = NODE_TYPE_QUALIFIER;
  buff->first->tq = ptr;
  buff->first->tq->parent_kind = NODE_DECLARATION_SPECIFIERS;
  buff->first->tq->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_7 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct function_specifier *fs = ptr1;
  struct declaration_specifiers *buff = ptr2;

  buff->last->next = calloc (1, sizeof (struct ds_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ds_kind = NODE_FUNCTION_SPECIFIER;
  buff->last->fs = fs;
  fs->parent_kind = NODE_DECLARATION_SPECIFIERS;
  fs->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_8 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration_specifiers *buff =
    calloc (1, sizeof (struct declaration_specifiers));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION_SPECIFIERS;
  buff->first = calloc (1, sizeof (struct ds_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ds_kind = NODE_FUNCTION_SPECIFIER;
  buff->first->fs = ptr;
  buff->first->fs->parent_kind = NODE_DECLARATION_SPECIFIERS;
  buff->first->fs->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_9 (void *ptr1, void *ptr2)
{
  assert (ptr1 != NULL);
  assert (ptr2 != NULL);

  struct alignment_specifier *as = ptr1;
  struct declaration_specifiers *buff = ptr2;

  buff->last->next = calloc (1, sizeof (struct ds_node));
  assert (buff->last->next != NULL);
  buff->last = buff->last->next;
  buff->last->ds_kind = NODE_ALIGNMENT_SPECIFIER;
  buff->last->as = as;
  as->parent_kind = NODE_DECLARATION_SPECIFIERS;
  as->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

struct declaration_specifiers *
declaration_specifiers_10 (void *ptr)
{
  assert (ptr != NULL);

  struct declaration_specifiers *buff =
    calloc (1, sizeof (struct declaration_specifiers));
  assert (buff != NULL);
  buff->kind = NODE_DECLARATION_SPECIFIERS;
  buff->first = calloc (1, sizeof (struct ds_node));
  assert (buff->first != NULL);
  buff->last = buff->first;
  buff->first->ds_kind = NODE_ALIGNMENT_SPECIFIER;
  buff->first->as = ptr;
  buff->first->as->parent_kind = NODE_DECLARATION_SPECIFIERS;
  buff->first->as->parent = buff;

  buff->dot_create = local_dot_create;
  /* NOTE start of experimental code */
  buff->sem_analysis = local_sem_analysis;
  /* NOTE end of experimental code */

  return buff;
}

int
is_there_typedef (struct declaration_specifiers *buff)
{
  assert (buff != NULL);

  for (struct ds_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    if (ptr->ds_kind == NODE_STORAGE_CLASS_SPECIFIER)
      if (ptr->stg->value == STG_TYPEDEF)
        return 1;

  return 0;
}

static void
local_dot_create (void *Node, void *F)
{
  assert (Node != NULL);
  assert (F != NULL);

  struct declaration_specifiers *node = Node;
  assert (node->kind == NODE_DECLARATION_SPECIFIERS);
  FILE *f = F;

  for (struct ds_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    switch (ptr->ds_kind)
      {
      case NODE_STORAGE_CLASS_SPECIFIER:
        fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
                 (unsigned long) ptr->stg);
        fprintf (f, "\t%lu [label=\"storage class specifier\"]\n",
                 (unsigned long) ptr->stg);
        ptr->stg->dot_create (ptr->stg, f);
        break;

      case NODE_TYPE_SPECIFIER:
        fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
                 (unsigned long) ptr->ts);
        fprintf (f, "\t%lu [label=\"type specifier\"]\n",
                 (unsigned long) ptr->ts);
        ptr->ts->dot_create (ptr->ts, f);
        break;

      case NODE_TYPE_QUALIFIER:
        fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
                 (unsigned long) ptr->tq);
        fprintf (f, "\t%lu [label=\"type qualifier\"]\n",
                 (unsigned long) ptr->tq);
        ptr->tq->dot_create (ptr->tq, f);
        break;

      case NODE_FUNCTION_SPECIFIER:
        fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
                 (unsigned long) ptr->fs);
        fprintf (f, "\t%lu [label=\"function specifier\"]\n",
                 (unsigned long) ptr->fs);
        ptr->fs->dot_create (ptr->fs, f);
        break;

      case NODE_ALIGNMENT_SPECIFIER:
        fprintf (f, "\t%lu -> %lu;\n", (unsigned long) node,
                 (unsigned long) ptr->as);
        fprintf (f, "\t%lu [label=\"alignment specifier\"]\n",
                 (unsigned long) ptr->as);
        ptr->as->dot_create (ptr->as, f);
        break;

      default:;                /* BUG! */
      }
}

static const int valid_stgs[] = {
  0, MASK_TYPEDEF, MASK_EXTERN,
  MASK_STATIC, MASK_THREAD_LOCAL,
  MASK_AUTO, MASK_REGISTER,
  MASK_THREAD_LOCAL | MASK_STATIC,
  MASK_THREAD_LOCAL | MASK_EXTERN
};

static const struct
{
  int mask;
  nd_type_t nd;
} valid_types[] = {
  {MASK_VOID, NT_VOID},
  {MASK_CHAR, NT_CHAR},
  {MASK_SIGNED | MASK_CHAR, NT_SIGNED_CHAR},
  {MASK_UNSIGNED | MASK_CHAR, NT_UNSIGNED_CHAR},
  {MASK_SHORT, NT_SIGNED_SHORT},
  {MASK_SHORT | MASK_INT, NT_SIGNED_SHORT},
  {MASK_SHORT | MASK_SIGNED, NT_SIGNED_SHORT},
  {MASK_SHORT | MASK_SIGNED | MASK_INT, NT_SIGNED_SHORT},
  {MASK_SHORT | MASK_UNSIGNED, NT_UNSIGNED_SHORT},
  {MASK_SHORT | MASK_UNSIGNED | MASK_INT, NT_UNSIGNED_SHORT},
  {MASK_INT, NT_SIGNED_INT},
  {MASK_SIGNED | MASK_INT, NT_SIGNED_INT},
  {MASK_UNSIGNED | MASK_INT, NT_UNSIGNED_INT},
  {MASK_SIGNED, NT_SIGNED_INT},
  {MASK_UNSIGNED, NT_UNSIGNED_INT},
  {MASK_LONG, NT_SIGNED_LONG},
  {MASK_LONG | MASK_INT, NT_SIGNED_LONG},
  {MASK_LONG | MASK_SIGNED, NT_SIGNED_LONG},
  {MASK_LONG | MASK_SIGNED | MASK_INT, NT_SIGNED_LONG},
  {MASK_LONG | MASK_UNSIGNED, NT_UNSIGNED_LONG},
  {MASK_LONG | MASK_UNSIGNED | MASK_INT, NT_UNSIGNED_LONG},
  {MASK_LLONG, NT_SIGNED_LONG_LONG},
  {MASK_LLONG | MASK_INT, NT_SIGNED_LONG_LONG},
  {MASK_LLONG | MASK_SIGNED, NT_SIGNED_LONG_LONG},
  {MASK_LLONG | MASK_SIGNED | MASK_INT, NT_SIGNED_LONG_LONG},
  {MASK_LLONG | MASK_UNSIGNED, NT_UNSIGNED_LONG_LONG},
  {MASK_LLONG | MASK_UNSIGNED | MASK_INT, NT_UNSIGNED_LONG_LONG},
  {MASK_FLOAT, NT_FLOAT},
  {MASK_DOUBLE, NT_DOUBLE},
  {MASK_LONG | MASK_DOUBLE, NT_LONG_DOUBLE},
  {MASK_LONG | MASK_FLOAT, NT_DOUBLE},
  {MASK_BOOL, NT_BOOL},
  {MASK_STRUCT, NT_UNKNOWN},
  {MASK_UNION, NT_UNKNOWN},
  {MASK_ENUM, NT_UNKNOWN},
  {MASK_NAME, NT_UNKNOWN}
};

static int
local_sem_analysis (void *Node)
{
  assert (Node != NULL);
  struct declaration_specifiers *node = Node;
  assert (node->kind == NODE_DECLARATION_SPECIFIERS);

  if (stg_class_sem_analysis (node) < 0)
    return -1;
  if (type_spec_sem_analysis (node) < 0)
    return -1;
  if (type_qual_sem_analysis (node) < 0)
    return -1;
  if (func_spec_sem_analysis (node) < 0)
    return -1;

  /*
   * storage class specifiers and
   * function specifiers do not take part
   * in the type.
   */

  if (node->ts_mask & MASK_STRUCT)
    {
      node->type.type_kind = TYPE_STRUCT;
      /* TODO */
    }
  else if (node->ts_mask & MASK_UNION)
    {
      node->type.type_kind = TYPE_UNION;
      /* TODO */
    }
  else if (node->ts_mask & MASK_ENUM)
    {
      node->type.type_kind = TYPE_ENUM;
      /* TODO */
    }
  else if (node->ts_mask & MASK_NAME)
    {
      node->type.type_kind = TYPE_TYPEDEF;
      node->type.typedef_type.name = get_typedef_name (node);
      // TODO node->type.typedef_type.can_type;
    }
  else
    {
      /*
       * arrays, functions and pointers
       * are found in declarators.
       */
      node->type.type_kind = TYPE_NO_DERIVED;
      for (int i = 0; i < sizeof (valid_types) / sizeof (valid_types[0]); i++)
        if (node->ts_mask == valid_types[i].mask)
          {
            node->type.nd_type = valid_types[i].nd;
            break;
          }
    }

  node->type.type_quals = 0;
  if (node->tq_mask & MASK_CONST)
    node->type.type_quals |= QUAL_CONST;
  if (node->tq_mask & MASK_RESTRICT)
    node->type.type_quals |= QUAL_RESTRICT;
  if (node->tq_mask & MASK_VOLATILE)
    node->type.type_quals |= QUAL_VOLATILE;
  if (node->tq_mask & MASK_ATOMIC)
    node->type.type_quals |= QUAL_ATOMIC;

  return 0;
}

static int
stg_class_sem_analysis (struct declaration_specifiers *node)
{
  assert (node != NULL);
  assert (node->kind == NODE_DECLARATION_SPECIFIERS);

  for (struct ds_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    switch (ptr->ds_kind)
      {
      case NODE_STORAGE_CLASS_SPECIFIER:
        switch (ptr->stg->value)
          {
          case STG_TYPEDEF:
            if (node->stg_mask & MASK_TYPEDEF)
              printf
                ("[%s:%d]<%s> typedef already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            node->stg_mask |= MASK_TYPEDEF;
            break;

          case STG_EXTERN:
            if (node->stg_mask & MASK_EXTERN)
              printf
                ("[%s:%d]<%s> extern already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            node->stg_mask |= MASK_EXTERN;

          case STG_STATIC:
            if (node->stg_mask & MASK_STATIC)
              printf
                ("[%s:%d]<%s> static already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            node->stg_mask |= MASK_STATIC;
            break;

          case STG_THREAD_LOCAL:
            if (node->stg_mask & MASK_THREAD_LOCAL)
              printf
                ("[%s:%d]<%s> _Thread_local already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            node->stg_mask |= MASK_THREAD_LOCAL;
            break;

          case STG_AUTO:
            if (node->stg_mask & MASK_AUTO)
              printf ("[%s:%d]<%s> auto already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            node->stg_mask |= MASK_AUTO;
            break;

          case STG_REGISTER:
            if (node->stg_mask & MASK_REGISTER)
              printf
                ("[%s:%d]<%s> register already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            node->stg_mask |= MASK_REGISTER;
            break;

          default:;            /* BUG! */
          }
        break;

      default:;
      }

  for (int i = 0; i < sizeof (valid_stgs) / sizeof (valid_stgs[0]); i++)
    if (node->stg_mask == valid_stgs[i])
      return 0;

  printf
    ("[%s:%d]<%s> Invalid combination of storage class specifiers (6.7.1, 2):\n",
     __FILE__, __LINE__, __func__);
  return -1;
}

static int
type_spec_sem_analysis (struct declaration_specifiers *node)
{
  assert (node != NULL);
  assert (node->kind == NODE_DECLARATION_SPECIFIERS);

  for (struct ds_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    switch (ptr->ds_kind)
      {
      case NODE_TYPE_SPECIFIER:
        switch (ptr->ts->ts_kind)
          {
          case TS_VOID:
            if (node->ts_mask & MASK_VOID)
              printf ("[%s:%d]<%s> void already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            node->ts_mask |= MASK_VOID;
            break;

          case TS_CHAR:
            if (node->ts_mask & MASK_CHAR)
              printf ("[%s:%d]<%s> char already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            node->ts_mask |= MASK_CHAR;
            break;

          case TS_SHORT:
            if (node->ts_mask & MASK_SHORT)
              printf ("[%s:%d]<%s> short already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            node->ts_mask |= MASK_SHORT;
            break;

          case TS_INT:
            if (node->ts_mask & MASK_INT)
              printf ("[%s:%d]<%s> int already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            node->ts_mask |= MASK_INT;
            break;

          case TS_LONG:
            /* beware!
             * long is valid, long long is too
             * (but with a different meaning),
             * but long long long is not!
             */
            if ((node->ts_mask & MASK_LONG) == 0
                && (node->ts_mask & MASK_LLONG) == 0)
              node->ts_mask |= TS_LONG;
            else if ((node->ts_mask & MASK_LONG) == 1
                     && (node->ts_mask & MASK_LLONG) == 0)
              {
                node->ts_mask &= ~MASK_LONG;
                node->ts_mask |= MASK_LLONG;
              }
            else if (node->ts_mask & MASK_LLONG)
              printf
                ("[%s:%d]<%s> long already found twice in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            break;

          case TS_FLOAT:
            if (node->ts_mask & MASK_FLOAT)
              printf ("[%s:%d]<%s> float already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            node->ts_mask |= MASK_FLOAT;
            break;

          case TS_DOUBLE:
            if (node->ts_mask & MASK_DOUBLE)
              printf
                ("[%s:%d]<%s> double already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            node->ts_mask |= MASK_DOUBLE;
            break;

          case TS_SIGNED:
            if (node->ts_mask & MASK_SIGNED)
              printf
                ("[%s:%d]<%s> signed already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            node->ts_mask |= MASK_SIGNED;
            break;

          case TS_UNSIGNED:
            if (node->ts_mask & MASK_UNSIGNED)
              printf
                ("[%s:%d]<%s> unsigned already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            node->ts_mask |= MASK_UNSIGNED;
            break;

          case TS_BOOL:
            if (node->ts_mask & MASK_BOOL)
              printf ("[%s:%d]<%s> _Bool already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            node->ts_mask |= MASK_BOOL;
            break;

            /* NOTE so far fuck off complex and imaginary and atomic */

          case TS_STRUCT_UNION:
            switch (ptr->ts->sus->su->value)
              {
              case SU_STRUCT:
                if (node->ts_mask & MASK_STRUCT)
                  printf
                    ("[%s:%d]<%s> struct already found in the declaration.\n",
                     __FILE__, __LINE__, __func__);
                node->ts_mask |= MASK_STRUCT;
                break;

              case SU_UNION:
                if (node->ts_mask & MASK_UNION)
                  printf
                    ("[%s:%d]<%s> union already found in the declaration.\n",
                     __FILE__, __LINE__, __func__);
                node->ts_mask |= MASK_UNION;
                break;

              default:;        /* BUG! */
              }
            break;

          case TS_ENUM:
            if (node->ts_mask & MASK_ENUM)
              printf ("[%s:%d]<%s> enum already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            node->ts_mask |= MASK_ENUM;
            break;

          case TS_TYPEDEF:
            if (node->ts_mask & MASK_NAME)
              printf
                ("[%s:%d]<%s> typedef name already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            node->ts_mask |= MASK_NAME;
            break;

          default:;            /* BUG! */
          }
        break;

      default:;
      }

  for (int i = 0; i < sizeof (valid_types) / sizeof (valid_types[0]); i++)
    if (node->ts_mask == valid_types[i].mask)
      return 0;

  printf
    ("[%s:%d]<%s> Invalid combination of type specifiers (6.7.2, 2):\n",
     __FILE__, __LINE__, __func__);
  return -1;
}

static int
type_qual_sem_analysis (struct declaration_specifiers *node)
{
  assert (node != NULL);
  assert (node->kind == NODE_DECLARATION_SPECIFIERS);

  for (struct ds_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    switch (ptr->ds_kind)
      {
      case NODE_TYPE_QUALIFIER:
        switch (ptr->tq->tq_kind)
          {
          case TQ_CONST:
            if (node->tq_mask & MASK_CONST)
              printf
                ("[%s:%d]<%s> const already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            node->tq_mask |= MASK_CONST;
            break;

          case TQ_RESTRICT:
            if (node->tq_mask & MASK_RESTRICT)
              printf
                ("[%s:%d]<%s> restrict already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            node->tq_mask |= MASK_RESTRICT;
            break;

          case TQ_VOLATILE:
            if (node->tq_mask & MASK_VOLATILE)
              printf
                ("[%s:%d]<%s> volatile already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            node->tq_mask |= MASK_VOLATILE;
            break;

          case TQ_ATOMIC:
            if (node->tq_mask & MASK_ATOMIC)
              printf
                ("[%s:%d]<%s> _Atomic already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            node->tq_mask |= MASK_ATOMIC;
            break;

          default:;            /* BUG! */
          }
        break;

      default:;
      }

  return 0;
}

static int
func_spec_sem_analysis (struct declaration_specifiers *node)
{
  assert (node != NULL);
  assert (node->kind == NODE_DECLARATION_SPECIFIERS);

  /* TODO */

  return 0;
}

static const char *
get_typedef_name (struct declaration_specifiers *node)
{
  assert (node != NULL);
  assert (node->kind == NODE_DECLARATION_SPECIFIERS);

  for (struct ds_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    switch (ptr->ds_kind)
      {
      case NODE_TYPE_SPECIFIER:
        switch (ptr->ts->ts_kind)
          {
          case TS_TYPEDEF:
            return ptr->ts->typedef_name;
            break;

          default:;
          }

      default:;
      }

  return NULL;
}
