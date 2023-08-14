#ifndef LOG_H_
#define LOG_H_

#include "assert.h"
#include <stdio.h>
#include <stdlib.h>

enum bq_loglevel {
  BQ_LOG_LEVEL_OFF,
  BQ_LOG_LEVEL_ERROR,
  BQ_LOG_LEVEL_WARN,
  BQ_LOG_LEVEL_INFO,
  BQ_LOG_LEVEL_DBG,
};

void bq_log_init(enum bq_loglevel level);

extern enum bq_loglevel BQ_LOG_LEVEL;
extern FILE *BQ_LOG_TARGET;

#define bq_dbg_assert(a) assert((a))
#define bq_log_fprintf(f, level, ...)                                        \
  if ((level) <= LOG_LEVEL) {                                                  \
    /* fprintf((f), "[%d] ", level); */                                        \
    fprintf((f), __VA_ARGS__);                                                 \
  }

#define bq_dbg(...) bq_log_fprintf(stderr, BQ_LOG_LEVEL_DBG, __VA_ARGS__)
#define bq_warn(...)                                                         \
  bq_log_fprintf(stderr, BQ_LOG_LEVEL_WARN, __VA_ARGS__)
#define bq_info(...)                                                         \
  bq_log_fprintf(stderr, BQ_LOG_LEVEL_INFO, __VA_ARGS__)
#define bq_error(...)                                                        \
  bq_log_fprintf(stderr, BQ_LOG_LEVEL_ERROR, __VA_ARGS__)

#define bq_panic(...)                                                        \
  {                                                                            \
    fprintf(stderr, __VA_ARGS__);                                              \
    exit(-1);                                                                  \
  }
#define bq_todo(...)                                                         \
  { bq_panic(__VA_ARGS__); }

#endif
