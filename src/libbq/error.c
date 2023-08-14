#include <libbq/macros.h>
#include <libbq/error.h>
#include <stdlib.h>
#include <string.h>

_Thread_local enum bq_error BQ_ERR;

void bq_err_set(enum bq_error err) { BQ_ERR = err; }

enum bq_error bq_err(void) {
  enum bq_error latest = BQ_ERR;
  return latest;
}
