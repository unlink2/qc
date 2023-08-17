#include "libqc/filter.h"
#include <string.h>

struct qc_filter qc_filter_init(enum qc_filters type, const char *name) {
  struct qc_filter self;
  memset(&self, 0, sizeof(self));

  self.type = type;
  self.name = strdup(name);

  self.fmts = qc_fmt_lst_init();

  return self;
}

bool qc_filter_is_included(struct qc_filter *self, const char *path,
                           const char *content) {}

int qc_filter_printf(struct qc_handle *handle, struct qc_filter *self,
                     const char *path, const char *content) {}

void qc_filter_free(struct qc_filter *self) {
  free((void *)self->name);
  qc_fmt_lst_free(&self->fmts);
}

qc_vec_impl(filter_lst, struct qc_filter)
