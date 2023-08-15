#ifndef HANDLE_H_
#define HANDLE_H_

struct qc_handle {};

struct qc_handle qc_handle_init();

void qc_handle_free(struct qc_handle *self);

#endif
