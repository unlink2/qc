#ifndef FMT_H_
#define FMT_H_

#include "libqc/macros.h"
#include <stddef.h>
#include <stdint.h>
#include "libqc/vec.h"

struct qc_handle;
struct qc_filter;
struct qc_sink;

typedef int (*qc_sink_cb)(struct qc_sink *sink, const char *path,
                          const char *content, size_t content_len);

struct qc_sink {
  qc_sink_cb printf;
};

int qc_sink_exec(struct qc_sink *self, const char *path, const char *content);

qc_vec_def(sink_lst, struct qc_sink)

#endif
