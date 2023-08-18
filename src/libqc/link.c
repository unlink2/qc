#include "libqc/link.h"
#include <string.h>

struct qc_link qc_link_init(const char *link, int depth) {
  struct qc_link self;
  memset(&self, 0, sizeof(self));

  self.link = strdup(link);
  self.depth = depth;

  return self;
}

void qc_link_free(struct qc_link *self) { free((void *)self->link); }

qc_vec_impl(link_lst, struct qc_link)
