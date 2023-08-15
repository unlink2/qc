#include "libqc/handle.h"
#include "libqc/error.h"
#include "libqc/log.h"
#include <stdlib.h>
#include <string.h>

struct qc_strlst qc_strlst_init(void) {
  struct qc_strlst self;
  memset(&self, 0, sizeof(self));
  return self;
}

void qc_strlst_push(struct qc_strlst *self, const char *link) {
  size_t new_len = self->len + 1;
  char **new_links = realloc(self->vals, new_len);

  if (!new_links) {
    qc_errno();
    return;
  }

  self->len = new_len;
  self->vals = new_links;
  self->vals[self->len - 1] = strdup(link);
}

void qc_strlst_free(struct qc_strlst *self) {
  if (self->vals) {
    for (size_t i = 0; i < self->len; i++) {
      free(self->vals[i]);
    }
    free(self->vals);
  }
}

struct qc_handle qc_handle_init(void) {
  struct qc_handle handle;
  memset(&handle, 0, sizeof(handle));

  handle.words = qc_strlst_init();
  handle.links = qc_strlst_init();

  handle.max_link_depth = QC_MAX_LINK_DEPTH_INF;

  return handle;
}

void qc_handle_add_link(struct qc_handle *self, const char *link) {
  qc_strlst_push(&self->links, link);
}

void qc_handle_crawl(struct qc_handle *self, int depth) {
  for (size_t i = 0; i < self->links.len; i++) {
    self->read_entry(self, self->links.vals[i]);
  }
}

void qc_handle_free(struct qc_handle *self) {
  qc_strlst_free(&self->links);
  qc_strlst_free(&self->words);
}
