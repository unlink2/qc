#include "libqc/log.h"

#include <stdint.h>

enum qc_loglevel QC_LOG_LEVEL;
FILE *QC_LOG_TARGET;

void qc_log_init(enum qc_loglevel level) {
  QC_LOG_LEVEL = level;
  QC_LOG_TARGET = stderr;
}
