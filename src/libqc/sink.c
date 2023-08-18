#include "libqc/sink.h"
#include <stdio.h>

int qc_sink_null(struct qc_sink *sink, const char *path, const char *content,
                 size_t content_len) {
  return 0;
}

int qc_sink_puts_path(struct qc_sink *sink, const char *path,
                      const char *content, size_t content_len) {
  int written = fprintf(sink->fout, "[PATH] %s\n\n", path);
  if (errno) {
    qc_errno();
  }
  return written;
}

int qc_sink_write_content(struct qc_sink *sink, const char *path,
                          const char *content, size_t content_len) {
  int written = (int)fwrite(content, 1, content_len, sink->fout);
  if (errno) {
    qc_errno();
  }
  return written;
}
int qc_sink_write_separator(struct qc_sink *sink, const char *path,
                            const char *content, size_t content_len) {
  int written = fputs("\n\n", sink->fout);
  return written;
}

struct qc_sink qc_sink_init(enum qc_sinks type, const char *name) {
  struct qc_sink self;
  memset(&self, 0, sizeof(self));
  self.type = type;
  self.name = strdup(name);
  return self;
}

struct qc_sink qc_sink_file(FILE *f, enum qc_sinks type, const char *name) {
  struct qc_sink self = qc_sink_init(type, name);
  self.fout = f;
  return self;
}

int qc_sink_exec(struct qc_sink *self, const char *path, const char *content,
                 size_t content_len) {
  switch (self->type) {
  case QC_SINK_NULL:
    return qc_sink_null(self, path, content, content_len);
  case QC_SINK_PUTS_PATH:
    return qc_sink_puts_path(self, path, content, content_len);
  case QC_SINK_WRITE_CONTENT:
    return qc_sink_write_content(self, path, content, content_len);
  case QC_SINK_CUSTOM:
    return self->cb(self, path, content, content_len, self->udata);
  }
  return -1;
}

void qc_sink_free(struct qc_sink *self) { free((void *)self->name); }

qc_vec_impl(sink_lst, struct qc_sink)
