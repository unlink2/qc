#include "libqc/filter.h"
#include <string.h>

struct qc_filter qc_filter_init(enum qc_filters type, const char *name) {
  struct qc_filter self;
  memset(&self, 0, sizeof(self));

  self.type = type;
  self.name = strdup(name);

  self.sinks = qc_sink_lst_init();

  return self;
}

struct qc_filter qc_filter_path_pattern(const char *name, const char *expr) {
  struct qc_filter self = qc_filter_init(QC_FILTER_PATH_PATTERN, name);

  if (regcomp(&self.reg, expr, 0) != 0) {
    qc_errno();
  }

  return self;
}

bool qc_filter_is_included(struct qc_filter *self, const char *path,
                           const char *content, size_t content_len) {
  switch (self->type) {
  case QC_FILTER_PATH_PATTERN:
    return regexec(&self->reg, path, 0, NULL, 0) != REG_NOMATCH;
  default:
    qc_error("filter not implemented!\n");
    abort();
  }
  return true;
}

int qc_filter_sinks_exec(struct qc_filter *self, const char *path,
                         const char *content, size_t content_len) {
  int written = 0;
  for (size_t i = 0; i < self->sinks.len; i++) {
    written += qc_sink_exec(&self->sinks.vals[i], path, content, content_len);
    if (qc_err()) {
      return -1;
    }
  }

  return written;
}

void qc_filter_free(struct qc_filter *self) {
  free((void *)self->name);
  qc_sink_lst_free(&self->sinks);

  switch (self->type) {
  case QC_FILTER_EXT:
    regfree(&self->reg);
    break;
  default:
    break;
  }
}

qc_vec_impl(filter_lst, struct qc_filter)
