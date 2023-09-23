#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#include "preproc.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

static int call_gcc_E_with_pipe (const char *src, const char *dst,
                                 const ipath_t * paths,
                                 const macro_t * macros);

int
preproc (const char *src, char **dst, const ipath_t * paths,
         const macro_t * macros)
{
  assert (src != NULL);
  assert (*src != 0);           /* empty filenames are not allowed */
  assert (dst != NULL);
  /* let paths be NULL */
  /* let macros be NULL */

  /* does src exist? */
  if (access (src, R_OK) < 0)
    {
      fprintf (stderr, "[%s][%s:%d] unable to read '%s': %s (errno %d)\n",
               __func__, __FILE__, __LINE__, src, strerror (errno), errno);
      return -1;
    }

  /* ok, now let's decide the new filename */
  *dst = strdup (src);
  assert (*dst != NULL);

  /*
   * we're going to assume that the original filename
   * was something ending in .c, so the only change
   * needed is to replace it with an 'i'
   */
  int i = 0;
  for (; (*dst)[i] != 0; i++);
  (*dst)[i - 1] = 'i';

  /*
   * now we have to call gcc -E src -o dst
   * but with all the paths and macros
   */
  return call_gcc_E_with_pipe (src, *dst, paths, macros);
}

static int
call_gcc_E_with_pipe (const char *src, const char *dst, const ipath_t * paths,
                      const macro_t * macros)
{
  assert (src != NULL);
  assert (dst != NULL);
  /* let paths be NULL */
  /* let macros be NULL */

  /*
   * how many arguments are we going to need?
   * gcc -E src : at least 3
   * but one for each path, and one for each macro
   */

  int how_many = 4;             /* 3 plus room for NULL */
  if (paths != NULL)
    for (const ipath_t * aux = paths->next; aux != NULL; aux = aux->next)
      how_many++;
  if (macros != NULL)
    for (const macro_t * aux = macros->next; aux != NULL; aux = aux->next)
      how_many++;

  int pipefd[2] = { 0 };
  if (pipe (pipefd) < 0)
    {
      fprintf (stderr, "[%s][%s:%d] pipe: %s (errno %d)\n", __func__,
               __FILE__, __LINE__, strerror (errno), errno);
      /* NOTE allocated resources go fuck yourself */
      return -1;
    }

  int filefd = creat (dst, 0644);
  if (filefd < 0)
    {
      fprintf (stderr, "[%s][%s:%d] creat '%s': %s (errno %d)\n", __func__,
               __FILE__, __LINE__, dst, strerror (errno), errno);
      /* NOTE allocated resources go fuck yourself */
      return -1;
    }

  char **args = calloc (how_many, sizeof (char *));
  assert (args != NULL);
  args[0] = strdup ("gcc");
  args[1] = strdup ("-E");
  args[2] = strdup (src);

  int i = 3;
  if (paths != NULL)
    for (const ipath_t * aux = paths->next; aux != NULL; aux = aux->next)
      {
        args[i] = NULL;
        asprintf (&args[i], "-I%s", aux->path);
        i++;
      }
  if (macros != NULL)
    for (const macro_t * aux = macros->next; aux != NULL; aux = aux->next)
      {
        args[i] = NULL;
        if (aux->m_value == NULL)
          asprintf (&args[i], "-D%s", aux->m_name);
        else if (aux->m_value[0] == 0)
          asprintf (&args[i], "-D%s=", aux->m_name);
        else
          asprintf (&args[i], "-D%s=%s", aux->m_name, aux->m_value);
        i++;
      }
  args[i] = NULL;

  pid_t pid = fork ();
  switch (pid)
    {
    case -1:
      fprintf (stderr, "[%s][%s:%d] fork: %s (errno %d)\n", __func__,
               __FILE__, __LINE__, strerror (errno), errno);
      /* NOTE allocated memory go fuck yourself */
      return -1;

    case 0:
      close (pipefd[0]);
      close (1);
      dup (pipefd[1]);
      execvp (args[0], args);
      _exit (-1);

    default:
      close (pipefd[1]);
      //waitpid (pid, NULL, 0);
    }

  while (1)
    {
      char c;
      ssize_t sst = read (pipefd[0], &c, 1);
      if (sst == 0)
        break;
      if (c == '#')
        for (read (pipefd[0], &c, 1); c != '\n'; read (pipefd[0], &c, 1));
      else
        write (filefd, &c, 1);
    }

  close (filefd);
  close (pipefd[0]);

  /* NOTE this under cygwin might cause problems... */
  for (int j = 0; j < how_many; j++)
    free (args[j]);
  free (args);

  return 0;
}
