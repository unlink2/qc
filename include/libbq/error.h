#ifndef ERROR_H_
#define ERROR_H_

#include "libbq/macros.h"
#include <stddef.h>
#include <errno.h>
#include <stdio.h>

/**
 * Error is a error type struct that provides
 * an errno-style interface.
 */

// Possible error types.
// Some may or may not require special error info
enum bq_error {
  BQ_OK = 0,
  // errno is stored in err_detail
  BQ_ERRNO
};

#define bq_errno()                                                           \
  { bq_err_set(BQ_ERRNO); }

#define bq_err_fset(err, ...)                                                \
  {                                                                            \
    bq_err_set((err));                                                       \
    bq_error(__VA_ARGS__);                                                   \
  }

// sets err to a value
// to indicate a failure in a call
void bq_err_set(enum bq_error err);

void bq_err_print(FILE *f);

// return error code
enum bq_error bq_err(void);

#endif
