#include "libqc/config.h"
#include <string.h>

struct qc_config qc_config_init(void) {
  struct qc_config c;
  memset(&c, 0, sizeof(c));

  return c;
}
