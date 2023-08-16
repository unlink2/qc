#ifndef HANDLE_H_
#define HANDLE_H_

#include <stddef.h>
#include "libqc/vec.h"

#define QC_MAX_LINK_DEPTH_INF -1

// Generic function that reads an entry
// the entry should return a buffer that does not need to be freed
// or NULL if no more reads are required
typedef char *(*qc_read_entry)(const void *handle, const char *path,
                               char *buffer, size_t buffer_len);

// Attempts to find links in the read file
// adds them to links list in handle
// Note: data may be a partial file and this may be called more than once per
// path
// This call should also be able to handle cases where a link may be incomplete
// because of partial calls
typedef void (*qc_find_links)(const void *handle, const char *path,
                              const char *data, size_t data_len);

struct qc_handle {
  struct qc_strlst words;
  struct qc_strlst links;
  int max_link_depth;

  qc_read_entry read_entry;
  qc_find_links find_links;
};

struct qc_handle qc_handle_init(void);
void qc_handle_add_link(struct qc_handle *self, const char *link);
void qc_handle_crawl(struct qc_handle *self, size_t link_idx, int depth);
void qc_handle_crawl_all(struct qc_handle *self);
void qc_handle_free(struct qc_handle *self);

#endif
