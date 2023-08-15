#ifndef LOG_H_
#define LOG_H_

#include "assert.h"
#include <stdio.h>
#include <stdlib.h>

enum qc_loglevel {
  QC_LOG_LEVEL_OFF,
  QC_LOG_LEVEL_ERROR,
  QC_LOG_LEVEL_WARN,
  QC_LOG_LEVEL_INFO,
  QC_LOG_LEVEL_DBG,
};

void qc_log_init(enum qc_loglevel level);

extern enum qc_loglevel QC_LOG_LEVEL;
extern FILE *QC_LOG_TARGET;

#define qc_dbg_assert(a) assert((a))
#define qc_log_fprintf(f, level, ...)                                          \
  if ((level) <= QC_LOG_LEVEL) {                                               \
    /* fprintf((f), "[%d] ", level); */                                        \
    fprintf((f), __VA_ARGS__);                                                 \
  }

#define qc_dbg(...) qc_log_fprintf(stderr, QC_LOG_LEVEL_DBG, __VA_ARGS__)
#define qc_warn(...) qc_log_fprintf(stderr, QC_LOG_LEVEL_WARN, __VA_ARGS__)
#define qc_info(...) qc_log_fprintf(stderr, QC_LOG_LEVEL_INFO, __VA_ARGS__)
#define qc_error(...) qc_log_fprintf(stderr, QC_LOG_LEVEL_ERROR, __VA_ARGS__)

#define qc_panic(...)                                                          \
  {                                                                            \
    fprintf(stderr, __VA_ARGS__);                                              \
    exit(-1);                                                                  \
  }
#define qc_todo(...)                                                           \
  { qc_panic(__VA_ARGS__); }

#endif
