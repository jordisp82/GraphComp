#ifndef PROJECT_T_H
#define PROJECT_T_H

typedef struct p_node
{
  const char *path;
  struct p_node *next;
} ipath_t;

typedef struct d_node
{
  const char *m_name;           /* compulsory */
  const char *m_value;          /* optional */
  struct d_node *next;
} macro_t;

typedef struct f_node
{
  const char *fname;            /* compulsory */
  ipath_t *ipaths;              /* optional */
  macro_t *macros;              /* optional */
  struct f_node *next;
} cfile_t;

typedef struct
{
  const char *name;
  cfile_t *files;
  ipath_t *ipaths;              /* optional */
  macro_t *macros;              /* optional */
} project_t;

#endif
