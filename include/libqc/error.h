#ifndef ERROR_H_
#define ERROR_H_

#include "libqc/macros.h"
#include <stddef.h>
#include <errno.h>
#include <stdio.h>

/**
 * Error is a error type struct that provides
 * an errno-style interface.
 */

// Possible error types.
// Some may or may not require special error info
enum qc_error { QC_OK = 0, QC_ERR_IO, QC_ERRNO };

#define qc_errno()                                                             \
  {                                                                            \
    qc_error("%s\n", strerror(errno));                                         \
    qc_err_set(QC_ERRNO);                                                      \
  }

#define qc_err_fset(err, ...)                                                  \
  {                                                                            \
    qc_err_set((err));                                                         \
    qc_error(__VA_ARGS__);                                                     \
  }

// sets err to a value
// to indicate a failure in a call
void qc_err_set(enum qc_error err);

void qc_err_print(FILE *f);

// return error code
enum qc_error qc_err(void);

#endif
