#ifndef MIME_H_
#define MIME_H_

#include "libqc/handle.h"

typedef int (*qc_mime_print)(struct qc_handle *handle, const char *path,
                             const char *content);

enum qc_mime_conds {
  QC_MIME_COND_FILE_EXT,
  QC_MIME_COND_BIN_HEADER,
  QC_MIME_COND_BIN_CONTAINS,
  QC_MIME_COND_STARTS_WITH_TEXT,
  QC_MIME_COND_CONTAINS_TEXT,
};

// Mime type conditions are really simple
// a struct is *either* of a certain type or it is not
// There is no complex logic in determining a type otherwise
struct qc_mime_cond {
  int prio; // lower == higher priority
  enum qc_mime_conds type;
  union {
    const char *ext;
  };
};

struct qc_mime {
  int prio;
  const char *type;
  qc_mime_print print;
};

struct qc_mime qc_mime_determine(struct qc_handle *handle, const char *path,
                                 const char *content);

// TODO: how do we register mime types?
void qc_mime_register(struct qc_handle *handle);

void qc_mime_free(const struct qc_mime *self);

#endif
