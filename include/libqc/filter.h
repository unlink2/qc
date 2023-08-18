#ifndef FILTER_H_
#define FILTER_H_

#include "libqc/macros.h"
#include <stddef.h>
#include <stdint.h>
#include "libqc/vec.h"
#include "libqc/sink.h"
#include <regex.h>

struct qc_handle;
struct qc_filter;

typedef bool (*qc_filter_cb)(struct qc_filter *filter, const char *path,
                             const char *content, void *udata);

enum qc_filters {
  QC_FILTER_EXT,
  QC_FILTER_IS_TXT,
  QC_FILTER_IS_BIN,
  QC_FILTER_CONTAINS_TEXT,
  QC_FILTER_CONTAINS_BIN,
  QC_FILTER_STARTS_WITH_TEXT,
  QC_FILTER_STARTS_WITH_BIN,
  QC_FILTER_PATH_PATTERN,
  QC_FILTER_CUSTOM,
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
    regex_t reg;
    qc_filter_cb custom;
  };
  struct qc_sink_lst sinks;
  void *udata;
};

struct qc_filter qc_filter_init(enum qc_filters type, const char *name);
struct qc_filter qc_filter_path_pattern(const char *name, const char *expr);

bool qc_filter_includes(struct qc_filter *self, const char *path,
                        const char *content, size_t content_len);

int qc_filter_sinks_exec(struct qc_filter *self, const char *path,
                         const char *content, size_t content_len);

void qc_filter_free(struct qc_filter *self);

qc_vec_def(filter_lst, struct qc_filter)

#endif
