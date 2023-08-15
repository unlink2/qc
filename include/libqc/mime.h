#ifndef MIME_H_
#define MIME_H_

#include "libqc/handle.h"

typedef int (*qc_mime_print)(struct qc_handle *handle, const char *path,
                             const char *content);

struct qc_mime {
  const char *type;
  qc_mime_print print;
};

struct qc_mime qc_mime_determine(struct qc_handle *handle, const char *path,
                                 const char *content);

void qc_mime_register(struct qc_handle *handle);

void qc_mime_free(const struct qc_mime *self);

#endif
