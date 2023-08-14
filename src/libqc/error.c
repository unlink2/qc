#include <libqc/macros.h>
#include <libqc/error.h>
#include <stdlib.h>
#include <string.h>

_Thread_local enum qc_error QC_ERR;

void qc_err_set(enum qc_error err) { QC_ERR = err; }

enum qc_error qc_err(void) {
  enum qc_error latest = QC_ERR;
  return latest;
}
