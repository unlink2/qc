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
                          const char *content, size_t content_len, void *udata);

int qc_sink_null(struct qc_sink *sink, const char *path, const char *content,
                 size_t content_len);

int qc_sink_puts_path(struct qc_sink *sink, const char *path,
                      const char *content, size_t content_len);

int qc_sink_write_content(struct qc_sink *sink, const char *path,
                          const char *content, size_t content_len);

enum qc_sinks {
  QC_SINK_NULL,
  QC_SINK_PUTS_PATH,
  QC_SINK_WRITE_CONTENT,
  QC_SINK_CUSTOM
};

struct qc_sink {
  const char *name;
  enum qc_sinks type;
  union {
    FILE *fout;
    qc_sink_cb cb;
  };
  void *udata;
};

struct qc_sink qc_sink_init(enum qc_sinks type, const char *name);
struct qc_sink qc_sink_file(FILE *f, enum qc_sinks type, const char *name);

int qc_sink_exec(struct qc_sink *self, const char *path, const char *content,
                 size_t content_len);

void qc_sink_free(struct qc_sink *self);

qc_vec_def(sink_lst, struct qc_sink)

#endif
