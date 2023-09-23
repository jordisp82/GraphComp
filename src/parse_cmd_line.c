#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>

#include "parse_cmd_line.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

int
parse_cmd_line (int argc, char *argv[], project_t * project)
{
  assert (argv != NULL);
  assert (project != NULL);

  struct option options[] = {
    {"name", 1, NULL, 'n'},
    {"source", 1, NULL, 's'},
    {"path", 1, NULL, 'p'},
    {"macro", 1, NULL, 'm'}
  };

  project->files = calloc (1, sizeof (cfile_t));
  assert (project->files != NULL);
  project->ipaths = calloc (1, sizeof (ipath_t));
  assert (project->ipaths != NULL);
  project->macros = calloc (1, sizeof (macro_t));
  assert (project->macros != NULL);

  ipath_t *last_path = project->ipaths;
  cfile_t *last_file = project->files;
  macro_t *last_macro = project->macros;

  int opt;
  while ((opt =
          getopt_long_only (argc, argv, "n:s:p:m:", options, NULL)) != -1)
    switch (opt)
      {
      case 'n':
        if (project->name != NULL)
          free ((void *) project->name);
        project->name = strdup (optarg);
        assert (project->name != NULL);
        break;

      case 's':
        last_file->next = calloc (1, sizeof (cfile_t));
        assert (last_file->next != NULL);
        last_file->next->fname = strdup (optarg);
        assert (last_file->next->fname != NULL);
        last_file = last_file->next;
        break;

      case 'p':
        last_path->next = calloc (1, sizeof (ipath_t));
        assert (last_path->next != NULL);
        last_path->next->path = strdup (optarg);
        assert (last_path->next->path != NULL);
        last_path = last_path->next;
        break;

      case 'm':
        last_macro->next = calloc (1, sizeof (macro_t));
        assert (last_macro->next != NULL);
        last_macro->next->m_name = strdup (optarg);
        assert (last_macro->next->m_name != NULL);
        last_macro = last_macro->next;
        break;

      default:
        return -1;
      }

  return 0;
}
