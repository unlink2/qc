#ifndef HANDLE_H_
#define HANDLE_H_

#include <stddef.h>
#include "libqc/vec.h"

struct qc_mime;

#define QC_MAX_LINK_DEPTH_INF (-1)

// Generic function that reads an entry
// return actual bytes read
// it should prefer using the buffer to store the result,
// but if it is not possible it may also
// store it in a tmpfile which then is mmaped
typedef const char *(*qc_entry_read)(const void *handle, const char *path,
                                     char *buffer, size_t buffer_len,
                                     size_t *total_len);

// optional cleanup call for read functions that allocate resources
typedef void (*qc_entry_free)(const void *handle, const char *buffer);

// Attempts to find links in the read file
// adds them to links list in handle
// Note: data may be a partial file and this may be called more than once per
// path
// This call should also be able to handle cases where a link may be incomplete
// because of partial calls
typedef void (*qc_links_find)(const void *handle, const char *path,
                              const char *data, size_t data_len);

struct qc_handle {
  struct qc_strlst words;
  // TODO: have a way to figure out if a link has already been scanned
  // previosuly
  struct qc_strlst links;
  int max_link_depth;

  struct qc_strlst accepts_mime;

  qc_entry_read read_entry;
  qc_entry_free free_entry;
  qc_links_find find_links;
};

struct qc_handle qc_handle_init(void);
void qc_handle_add_link(struct qc_handle *self, const char *link);
void qc_handle_crawl(struct qc_handle *self, size_t link_idx, int depth);
void qc_handle_crawl_all(struct qc_handle *self);

void qc_handle_free(struct qc_handle *self);

#endif
