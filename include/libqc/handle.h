#ifndef HANDLE_H_
#define HANDLE_H_

#include <stddef.h>

struct qc_handle;

// Generic function that reads an entry
typedef char (*qc_read_entry)(const struct qc_handle *handle, const char *path);

// Attempts to find links in the read file
// adds them to links list in handle
// Note: data may be a partial file and this may be called more than once per
// path
typedef void (*qc_find_links)(const struct qc_handle *handle, const char *path,
                              const char *data, size_t data_len);

struct qc_handle {
  char **links;
  size_t links_len;

  int max_link_depth;

  qc_read_entry read_entry;
  qc_find_links find_links;
};

struct qc_handle qc_handle_init(void);

void qc_handle_add_link(struct qc_handle *self, const char *link);

void qc_handle_free(struct qc_handle *self);

#endif
