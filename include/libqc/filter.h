#ifndef FILTER_H_
#define FILTER_H_

#include "libqc/macros.h"
#include <stddef.h>
#include <stdint.h>
#include "libqc/vec.h"

enum qc_filters {
  QC_FILTER_EXT,
  QC_FILTER_IS_TXT,
  QC_FILTER_IS_BIN,
  QC_FILTER_CONTAINS_TEXT,
  QC_FILTER_CONTAINS_BIN,
  QC_FILTER_STARTS_WITH_TEXT,
  QC_FILTER_STARTS_WITH_BIN,
  QC_FILTER_PATH_PATTERN,
};

struct qc_filter {
  enum qc_filters type;
  const char *name;
  union {
    const char *sval;
    struct {
      const uint8_t *bval;
      size_t blen;
    };
  };
  // TODO: list of output functions here
  // each filter with a name can have many output functions
};

struct qc_filter qc_filter_init(enum qc_filters type, const char *name);

bool qc_filter_is_included(struct qc_filter *self, const char *path,
                           const char *content);

void qc_filter_free(struct qc_filter *self);

qc_vec_def(qc_filterlst, struct qc_filter)

#endif
