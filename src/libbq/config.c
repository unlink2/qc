#include "libbq/config.h"
#include <string.h>

struct bq_config bq_config_init(void) {
  struct bq_config c;
  memset(&c, 0, sizeof(c));

  return c;
}
