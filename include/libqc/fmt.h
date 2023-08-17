#ifndef FMT_H_
#define FMT_H_

#include "libqc/macros.h"
#include <stddef.h>
#include <stdint.h>
#include "libqc/vec.h"

struct qc_handle;
struct qc_filter;
struct qc_fmt;

typedef int (*qc_fmt_printf_cb)(struct qc_handle *handle, struct qc_fmt *fmt,
                                const char *path, const char *content,
                                size_t content_len);

struct qc_fmt {
  qc_fmt_printf_cb printf;
};

int qc_fmt_printf(struct qc_handle *handle, struct qc_filter *self,
                  const char *path, const char *content);

qc_vec_def(fmt_lst, struct qc_fmt)

#endif
