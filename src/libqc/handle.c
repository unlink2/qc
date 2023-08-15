#include "libqc/handle.h"
#include "libqc/error.h"
#include "libqc/log.h"
#include <stdlib.h>
#include <string.h>

struct qc_handle qc_handle_init(void) {
  struct qc_handle handle;
  memset(&handle, 0, sizeof(handle));

  return handle;
}

void qc_handle_add_link(struct qc_handle *self, const char *link) {
  size_t new_len = self->links_len + 1;
  char **new_links = realloc(self->links, new_len);

  if (!new_links) {
    qc_errno();
    return;
  }

  self->links_len = new_len;
  self->links = new_links;
  self->links[self->links_len - 1] = strdup(link);
}

void qc_handle_free(struct qc_handle *self) {
  if (self->links) {
    for (size_t i = 0; i < self->links_len; i++) {
      free(self->links[i]);
    }
    free(self->links);
  }
}
