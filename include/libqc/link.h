#ifndef LINK_H_
#define LINK_H_

#include "libqc/vec.h"

struct qc_link {
  const char *link;
  int depth;
};

struct qc_link qc_link_init(const char *link, int depth);

void qc_link_free(struct qc_link *self);

qc_vec_def(link_lst, struct qc_link)

#endif
