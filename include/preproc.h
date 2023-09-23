#ifndef PREPROC_H
#define PREPROC_H

#include "project_t.h"

int preproc (const char *src, char **dst, const ipath_t * paths,
             const macro_t * macros);

#endif
