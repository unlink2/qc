#ifndef MIME_H_
#define MIME_H_

#include "libqc/handle.h"
#include <stdint.h>

typedef int (*qc_mime_print)(struct qc_handle *handle, const char *path,
                             const char *content, size_t content_len);

typedef int (*qc_mime_determine_custom)(struct qc_handle *handle,
                                        const char *path, const char *content);

enum qc_mime_conds {
  QC_MIME_COND_FILE_EXT,
  QC_MIME_COND_BIN_HEADER,
  QC_MIME_COND_BIN_CONTAINS,
  QC_MIME_COND_STARTS_WITH_TEXT,
  QC_MIME_COND_CONTAINS_TEXT,
  QC_MIME_COND_IS_TEXT,
  // in case there are mime types that require more complex
  // logic it can be done using a custom callback
  QC_MIME_COND_CUSTOM,
};

// Mime type conditions are really simple
// a struct is *either* of a certain type or it is not
// There is no complex logic in determining a type otherwise
struct qc_mime_cond {
  enum qc_mime_conds type;
  const char *meta;
  union {
    const char *sval;
    struct {
      const uint8_t *bval;
      size_t bval_len;
    };
    qc_mime_determine_custom *custom;
  };
};

struct qc_mime {
  const char *meta;
  qc_mime_print print;
};

struct qc_mime qc_mime_init(void);

// determine the best mime type
// based on conditions in handle
// Mime types are only ever determined
// by one buffer full of data (e.g. the first 1024 bytes)
// best effort search. attempt to find first match!
struct qc_mime qc_mime_determine(struct qc_handle *handle, const char *path,
                                 const char *content, size_t content_len);

void qc_mime_free(const struct qc_mime *self);

#endif
