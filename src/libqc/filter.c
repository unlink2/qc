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

bool qc_filter_is_included(struct qc_filter *self, const char *path,
                           const char *content) {}

void qc_filter_free(struct qc_filter *self) {
  free((void *)self->name);
  qc_sink_lst_free(&self->sinks);
}

qc_vec_impl(filter_lst, struct qc_filter)
