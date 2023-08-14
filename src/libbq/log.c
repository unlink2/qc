#include "libbq/log.h"

#include <stdint.h>

enum bq_loglevel BQ_LOG_LEVEL;
FILE *BQ_LOG_TARGET;

void bq_log_init(enum bq_loglevel level) {
  BQ_LOG_LEVEL = level;
  BQ_LOG_TARGET = stderr;
}
