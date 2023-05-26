#include <assert.h>
#include <stdlib.h>

#include "declaration_specifiers.h"
#include "storage_class_specifier.h"
#include "type_qualifier.h"
#include "function_specifier.h"
#include "alignment_specifier.h"
#include "type_specifier.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static void sem_stg (struct storage_class_specifier *ptr, int *mask);
static void sem_qual (struct type_qualifier *ptr, int *mask);

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

  return buff;
}

symbol_t *
create_symbol_from_declaration_specifiers (struct declaration_specifiers
                                           *buff)
{
  assert (buff != NULL);

  /*
   * NOTE this function is called *only* when the
   * declaration doesn't have declarators.
   * For the declaration to be "useful", there must be
   * a struct or union specifier or an enum specifier.
   * Other things require a name, therefore a declarator,
   * and we said that this function is called when the
   * declaration has no declarators.
   */

  for (struct ds_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    if (ptr->ds_kind == NODE_TYPE_SPECIFIER)
      return create_symbol_from_type_specifier (ptr->ts);

  return NULL;
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

/*
 * NOTE from here, to be removed.
 */

#define MASK_TYPEDEF  0x01
#define MASK_EXTERN   0x02
#define MASK_STATIC   0x04
#define MASK_THREAD   0x08
#define MASK_AUTO     0x10
#define MASK_REGISTER 0x20

#define MASK_CONST      0x01
#define MASK_VOLATILE   0x02
#define MASK_RESTRICT   0x04
#define MASK_ATOMIC     0x08

void
sem_declaration_specifiers (struct declaration_specifiers *buff)
{
  assert (buff != NULL);

  int mask_stg = 0;
  int mask_qual = 0;

  for (struct ds_node * ptr = buff->first; ptr != NULL; ptr = ptr->next)
    switch (ptr->ds_kind)
      {
      case NODE_STORAGE_CLASS_SPECIFIER:
        sem_stg (ptr->stg, &mask_stg);
        break;

      case NODE_TYPE_SPECIFIER:
        sem_type_specifier (ptr->ts);
        break;

      case NODE_TYPE_QUALIFIER:
        sem_qual (ptr->tq, &mask_qual);
        break;

      case NODE_FUNCTION_SPECIFIER:
        ;

      case NODE_ALIGNMENT_SPECIFIER:
        ;

      default:
        ;                       /* BUG! */
      }

  /*
   * TODO but we're not done yet!
   * we need to check all the specifiers
   * as a whole.
   */

  /*
   * TODO section 6.7.1, clauses 2, 3, 4 and 7.
   * section 6.7.2, clause 2.
   * section 6.7.3, clauses 2 and 3.
   * section 6.7.4, clauses 2 and 3 (forget clause 4).
   */
}

static void
sem_stg (struct storage_class_specifier *ptr, int *mask)
{
  assert (ptr != NULL);
  assert (mask != NULL);
  assert (ptr->kind == NODE_STORAGE_CLASS_SPECIFIER);

  switch (ptr->value)
    {
    case STG_TYPEDEF:
      if (*mask & MASK_TYPEDEF)
        {
          /* multiple typedef */
        }
      else if (*mask != 0)
        {
          /* only one stg class spec */
        }
      *mask |= MASK_TYPEDEF;
      break;

    case STG_EXTERN:
      if (*mask & MASK_EXTERN)
        {
          /* multiple extern */
        }
      else if (*mask != 0 && (*mask & MASK_THREAD) == 0)
        {
          /* only one stg class spec */
        }
      *mask |= MASK_EXTERN;
      break;

    case STG_STATIC:
      if (*mask & MASK_STATIC)
        {
          /* multiple static */
        }
      else if (*mask != 0 && (*mask & MASK_THREAD) == 0)
        {
          /* only one stg class spec */
        }
      *mask |= MASK_STATIC;
      break;

    case STG_THREAD_LOCAL:
      if (*mask & MASK_THREAD)
        {
          /* multiple thread local */
        }
      else if (*mask != 0 && (*mask & MASK_STATIC) == 0
               && (*mask & MASK_EXTERN) == 0)
        {
          /* only one stg class spec */
        }
      *mask |= MASK_THREAD;
      break;

    case STG_AUTO:
      if (*mask & MASK_AUTO)
        {
          /* multiple auto */
        }
      else if (*mask != 0)
        {
          /* only one stg class spec */
        }
      *mask |= MASK_AUTO;
      break;

    case STG_REGISTER:
      if (*mask & MASK_REGISTER)
        {
          /* multiple register */
        }
      else if (*mask != 0)
        {
          /* only one stg class spec */
        }
      *mask |= MASK_REGISTER;
      break;

    default:
      ;                         /* BUG! */
    }
}

static void
sem_qual (struct type_qualifier *ptr, int *mask)
{
  assert (ptr != NULL);
  assert (mask != NULL);
  assert (ptr->kind == NODE_TYPE_QUALIFIER);

  switch (ptr->tq_kind)
    {
    case TQ_CONST:
      if (*mask & MASK_CONST)
        {
          /* repeated const */
        }
      *mask |= MASK_CONST;
      break;

    case TQ_RESTRICT:
      if (*mask & MASK_RESTRICT)
        {
          /* repeated restrict */
        }
      *mask |= MASK_RESTRICT;
      break;

    case TQ_VOLATILE:
      if (*mask & MASK_VOLATILE)
        {
          /* repeated volatile */
        }
      *mask |= MASK_VOLATILE;
      break;

    case TQ_ATOMIC:
      if (*mask & MASK_ATOMIC)
        {
          /* repeated atomic */
        }
      *mask |= MASK_VOLATILE;
      break;

    default:
      ;                         /* BUG! */
    }
}
