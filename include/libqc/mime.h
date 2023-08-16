#ifndef MIME_H_
#define MIME_H_

#include "libqc/handle.h"

typedef int (*qc_mime_print)(struct qc_handle *handle, const char *path,
                             const char *content);

typedef int (*qc_mime_determine_custom)(struct qc_handle *handle,
                                        const char *path, const char *content);

enum qc_mime_conds {
  QC_MIME_COND_FILE_EXT,
  QC_MIME_COND_BIN_HEADER,
  QC_MIME_COND_BIN_CONTAINS,
  QC_MIME_COND_STARTS_WITH_TEXT,
  QC_MIME_COND_CONTAINS_TEXT,
  // in case there are mime types that require more complex
  // logic it can be done using a custom callback
  QC_MIME_COND_CUSTOM,
};

// Mime type conditions are really simple
// a struct is *either* of a certain type or it is not
// There is no complex logic in determining a type otherwise
struct qc_mime_cond {
  // lower == higher priority
  int prio;
  enum qc_mime_conds type;
  union {
    const char *ext;
    qc_mime_determine_custom *custom;
  };
};

struct qc_mime {
  const char *type;
  qc_mime_print print;
  // lower == higher priority
  // if determine finds a better mime type
  // with higher priority it will
  // consequently replace the current mime type
  int prio;
};

struct qc_mime qc_mime_determine(struct qc_handle *handle, const char *path,
                                 const char *content, int prev_prio);

void qc_mime_free(const struct qc_mime *self);

#endif
