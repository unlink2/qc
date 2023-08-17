#include "libqc/handle.h"
#include "libqc/error.h"
#include "libqc/log.h"
#include <stdlib.h>
#include <string.h>

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

// read - if mime type->meta is NULL it will deptermine a mime type, if the mime
// type should be filtered it will filter and abort reading by returning -1
int qc_handle_read(struct qc_handle *self, const char *link, char *buffer,
                   size_t buffer_len, int depth) {
  int read = self->read_entry(self, link, buffer, buffer_len);

  if (depth == QC_MAX_LINK_DEPTH_INF || depth < self->max_link_depth) {
    self->find_links(self, link, buffer, buffer_len);
  }

  return read;
}

void qc_handle_crawl(struct qc_handle *self, size_t link_idx, int depth) {
  const size_t buffer_len = 1024;
  char buffer[buffer_len];
  const char *link = self->links.vals[link_idx];

  int read = 0;

  while ((read = qc_handle_read(self, link, buffer, buffer_len, depth)) != -1) {
  }
}

void qc_handle_free(struct qc_handle *self) {
  qc_strlst_free(&self->links);
  qc_strlst_free(&self->words);
}
