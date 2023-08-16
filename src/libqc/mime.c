#include "libqc/mime.h"
#include <string.h>

struct qc_mime qc_mime_init(void) {
  struct qc_mime self;
  memset(&self, 0, sizeof(self));
  self.meta = NULL;
  return self;
}

struct qc_mime qc_mime_determine(struct qc_handle *handle, const char *path,
                                 const char *content, size_t content_len) {
  struct qc_mime self = qc_mime_init();
  return self;
}

void qc_mime_free(const struct qc_mime *self) {
  if (self->meta) {
    free((void *)self->meta);
  }
}
