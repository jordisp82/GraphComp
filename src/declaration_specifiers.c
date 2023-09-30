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
static type_t local_create_type (void *Node);
static void show_stg (int stg_mask);
static void show_ts (int ts_mask);
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
  buff->create_type = local_create_type;
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
  buff->create_type = local_create_type;
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
  buff->create_type = local_create_type;
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
  buff->create_type = local_create_type;
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
  buff->create_type = local_create_type;
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
  buff->create_type = local_create_type;
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
  buff->create_type = local_create_type;
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
  buff->create_type = local_create_type;
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
  buff->create_type = local_create_type;
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
  buff->create_type = local_create_type;
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

#define MASK_TYPEDEF    0x01
#define MASK_EXTERN     0x02
#define MASK_STATIC     0x04
#define MASK_THREAD_LOCAL 0x08
#define MASK_AUTO       0x10
#define MASK_REGISTER   0x20

#define MASK_VOID       0x0001
#define MASK_CHAR       0x0002
#define MASK_SHORT      0x0004
#define MASK_INT        0x0008
#define MASK_LONG       0x0010
#define MASK_LLONG      0x0020
#define MASK_FLOAT      0x0040
#define MASK_DOUBLE     0x0080
#define MASK_SIGNED     0x0100
#define MASK_UNSIGNED   0x0200
#define MASK_BOOL       0x0400
#define MASK_COMPLEX    0x0800
#define MASK_STRUCT     0x1000
#define MASK_UNION      0x2000
#define MASK_ENUM       0x4000
#define MASK_NAME       0x8000  /* typedef */

static const int valid_types[] = {
  MASK_VOID,
  MASK_CHAR,
  MASK_SIGNED | MASK_CHAR,
  MASK_UNSIGNED | MASK_CHAR,
  MASK_SHORT,
  MASK_SHORT | MASK_INT,
  MASK_SHORT | MASK_SIGNED,
  MASK_SHORT | MASK_SIGNED | MASK_INT,
  MASK_SHORT | MASK_UNSIGNED,
  MASK_SHORT | MASK_UNSIGNED | MASK_INT,
  MASK_INT,
  MASK_SIGNED | MASK_INT,
  MASK_UNSIGNED | MASK_INT,
  MASK_SIGNED,                  /* means signed int */
  MASK_UNSIGNED,                /* means unsigned int */
  MASK_LONG,
  MASK_LONG | MASK_INT,
  MASK_LONG | MASK_SIGNED,
  MASK_LONG | MASK_SIGNED | MASK_INT,
  MASK_LONG | MASK_UNSIGNED,
  MASK_LONG | MASK_UNSIGNED | MASK_INT,
  MASK_LLONG,
  MASK_LLONG | MASK_INT,
  MASK_LLONG | MASK_SIGNED,
  MASK_LLONG | MASK_SIGNED | MASK_INT,
  MASK_LLONG | MASK_UNSIGNED,
  MASK_LLONG | MASK_UNSIGNED | MASK_INT,
  MASK_FLOAT,
  MASK_DOUBLE,
  MASK_LONG | MASK_DOUBLE,
  MASK_LONG | MASK_FLOAT,       /* old syn. for double */
  MASK_BOOL,
  MASK_STRUCT,
  MASK_UNION,
  MASK_ENUM,
  MASK_NAME
};

/* NOTE start of experimental code */
static int
local_sem_analysis (void *Node)
{
  assert (Node != NULL);
  struct declaration_specifiers *node = Node;
  assert (node->kind == NODE_DECLARATION_SPECIFIERS);

  int stg_mask = 0;
  int ts_mask = 0;

  for (struct ds_node * ptr = node->first; ptr != NULL; ptr = ptr->next)
    switch (ptr->ds_kind)
      {
      case NODE_STORAGE_CLASS_SPECIFIER:
        switch (ptr->stg->value)
          {
          case STG_TYPEDEF:
            if (stg_mask & MASK_TYPEDEF)
              printf
                ("[%s:%d]<%s> typedef already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            stg_mask |= MASK_TYPEDEF;
            break;

          case STG_EXTERN:
            if (stg_mask & MASK_EXTERN)
              printf
                ("[%s:%d]<%s> extern already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            stg_mask |= MASK_EXTERN;
            break;

          case STG_STATIC:
            if (stg_mask & MASK_STATIC)
              printf
                ("[%s:%d]<%s> static already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            stg_mask |= MASK_STATIC;
            break;

          case STG_THREAD_LOCAL:
            if (stg_mask & MASK_THREAD_LOCAL)
              printf
                ("[%s:%d]<%s> _Thread_local already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            stg_mask |= MASK_THREAD_LOCAL;
            break;

          case STG_AUTO:
            if (stg_mask & MASK_AUTO)
              printf ("[%s:%d]<%s> auto already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            stg_mask |= MASK_AUTO;
            break;

          case STG_REGISTER:
            if (stg_mask & MASK_REGISTER)
              printf
                ("[%s:%d]<%s> register already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            stg_mask |= MASK_REGISTER;
            break;

          default:;            /* BUG! */
          }
        break;

      case NODE_TYPE_SPECIFIER:
        switch (ptr->ts->ts_kind)
          {
          case TS_VOID:
            if (ts_mask & MASK_VOID)
              printf ("[%s:%d]<%s> void already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            ts_mask |= MASK_VOID;
            break;

          case TS_CHAR:
            if (ts_mask & MASK_CHAR)
              printf ("[%s:%d]<%s> char already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            ts_mask |= MASK_CHAR;
            break;

          case TS_SHORT:
            if (ts_mask & MASK_SHORT)
              printf ("[%s:%d]<%s> short already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            ts_mask |= MASK_SHORT;
            break;

          case TS_INT:
            if (ts_mask & MASK_INT)
              printf ("[%s:%d]<%s> int already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            ts_mask |= MASK_INT;
            break;

          case TS_LONG:
            /* beware!
             * long is valid, long long is too
             * (but with a different meaning),
             * but long long long is not!
             */
            if ((ts_mask & MASK_LONG) == 0 && (ts_mask & MASK_LLONG) == 0)
              ts_mask |= TS_LONG;
            else if ((ts_mask & MASK_LONG) == 1
                     && (ts_mask & MASK_LLONG) == 0)
              {
                ts_mask &= ~MASK_LONG;
                ts_mask |= MASK_LLONG;
              }
            else if (ts_mask & MASK_LLONG)
              printf
                ("[%s:%d]<%s> long already found twice in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            break;

          case TS_FLOAT:
            if (ts_mask & MASK_FLOAT)
              printf ("[%s:%d]<%s> float already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            ts_mask |= MASK_FLOAT;
            break;

          case TS_DOUBLE:
            if (ts_mask & MASK_DOUBLE)
              printf
                ("[%s:%d]<%s> double already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            ts_mask |= MASK_DOUBLE;
            break;

          case TS_SIGNED:
            if (ts_mask & MASK_SIGNED)
              printf
                ("[%s:%d]<%s> signed already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            ts_mask |= MASK_SIGNED;
            break;

          case TS_UNSIGNED:
            if (ts_mask & MASK_UNSIGNED)
              printf
                ("[%s:%d]<%s> unsigned already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            ts_mask |= MASK_UNSIGNED;
            break;

          case TS_BOOL:
            if (ts_mask & MASK_BOOL)
              printf ("[%s:%d]<%s> _Bool already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            ts_mask |= MASK_BOOL;
            break;

            /* NOTE so far fuck off complex and imaginary and atomic */

          case TS_STRUCT_UNION:
            switch (ptr->ts->sus->su->value)
              {
              case SU_STRUCT:
                if (ts_mask & MASK_STRUCT)
                  printf
                    ("[%s:%d]<%s> struct already found in the declaration.\n",
                     __FILE__, __LINE__, __func__);
                ts_mask |= MASK_STRUCT;
                break;

              case SU_UNION:
                if (ts_mask & MASK_UNION)
                  printf
                    ("[%s:%d]<%s> union already found in the declaration.\n",
                     __FILE__, __LINE__, __func__);
                ts_mask |= MASK_UNION;
                break;

              default:;        /* BUG! */
              }
            break;

          case TS_ENUM:
            if (ts_mask & MASK_ENUM)
              printf ("[%s:%d]<%s> enum already found in the declaration.\n",
                      __FILE__, __LINE__, __func__);
            ts_mask |= MASK_ENUM;
            break;

          case TS_TYPEDEF:
            if (ts_mask & MASK_NAME)
              printf
                ("[%s:%d]<%s> typedef name already found in the declaration.\n",
                 __FILE__, __LINE__, __func__);
            ts_mask |= MASK_NAME;
            break;

          default:;            /* BUG! */
          }
        break;

      case NODE_TYPE_QUALIFIER:
        /* no problem with those and fuck _Atomic */
        break;

      case NODE_FUNCTION_SPECIFIER:
        /* no probkem with those, at least at this level */
        break;

      case NODE_ALIGNMENT_SPECIFIER:
        /* fuck off with them */
        break;

      default:;                /* BUG! */
      }

  int ret = 0;

  /*
   * 6.7.1, paragraph 2:
   * "At most, one storage-class specifier
   * may be given in the declaration specifiers
   * in a declaration, except that _Thread_local
   * may appear with static or extern".
   */

  /* TODO
   * 6.7.1 paragraph 3:
   * "In the declaration of an object with block scope,
   * if the declaration specifiers include _Thread_local,
   * they shall also include either static or extern."
   * "If _Thread_local appears in any declaration of
   * an object, it shall be present in every declaration
   * of that object".
   */

  switch (stg_mask)
    {
    case 0:
    case MASK_TYPEDEF:
    case MASK_EXTERN:
    case MASK_STATIC:
    case MASK_THREAD_LOCAL:
    case MASK_AUTO:
    case MASK_REGISTER:
    case MASK_THREAD_LOCAL | MASK_STATIC:
    case MASK_THREAD_LOCAL | MASK_EXTERN:
      break;

    default:
      printf
        ("[%s:%d]<%s> Invalid combination of storage class specifiers (6.7.1, 2):\n",
         __FILE__, __LINE__, __func__);
      show_stg (stg_mask);
      ret = -1;
    }

  /* 6.7.2 paragraph 2 */
  size_t i, s = sizeof (valid_types) / sizeof (valid_types[0]);
  for (i = 0; i < s; i++)
    if (ts_mask == valid_types[i])
      break;
  if (i == s)
    {
      printf
        ("[%s:%d]<%s> Invalid combination of type specifiers (6.7.2, 2):\n",
         __FILE__, __LINE__, __func__);
      show_ts (ts_mask);
      ret = -1;
    }

  return ret;
}

static type_t
local_create_type (void *Node)
{
  assert (Node != NULL);
  struct declaration_specifiers *node = Node;
  assert (node->kind == NODE_DECLARATION_SPECIFIERS);
  type_t type = {.type_kind = TYPE_UNKNOWN };
  /* TODO */
  return type;
}

static void
show_stg (int stg_mask)
{
  if (stg_mask & MASK_TYPEDEF)
    printf ("\ttypedef\n");
  if (stg_mask & MASK_EXTERN)
    printf ("\textern\n");
  if (stg_mask & MASK_STATIC)
    printf ("\tstatic\n");
  if (stg_mask & MASK_THREAD_LOCAL)
    printf ("\t_Thread_local\n");
  if (stg_mask & MASK_AUTO)
    printf ("\tauto\n");
  if (stg_mask & MASK_REGISTER)
    printf ("\tregister\n");
}

static void
show_ts (int ts_mask)
{
  if (ts_mask & MASK_VOID)
    printf ("\tvoid\n");
  if (ts_mask & MASK_CHAR)
    printf ("\tchar\n");
  if (ts_mask & MASK_SHORT)
    printf ("\\tshort\n");
  if (ts_mask & MASK_INT)
    printf ("\tint\n");
  if (ts_mask & MASK_LONG)
    printf ("\tlong\n");
  if (ts_mask & MASK_LLONG)
    printf ("\tlong long\n");
  if (ts_mask & MASK_DOUBLE)
    printf ("\tdouble\n");
  if (ts_mask & MASK_SIGNED)
    printf ("\tsigned\n");
  if (ts_mask & MASK_UNSIGNED)
    printf ("\tunsigned\n");
  if (ts_mask & MASK_BOOL)
    printf ("\t_Bool\n");
  if (ts_mask & MASK_COMPLEX)
    printf ("\t_Complex\n");
  if (ts_mask & MASK_STRUCT)
    printf ("\tstruct\n");
  if (ts_mask & MASK_UNION)
    printf ("\tunion\n");
  if (ts_mask & MASK_ENUM)
    printf ("\tenum\n");
  if (ts_mask & MASK_NAME)
    printf ("\ttypedef name\n");
}

/* NOTE end of experimental code */
