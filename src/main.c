#include <stdio.h>
#include <stdlib.h>
#include "libbq/config.h"
#include "libbq/log.h"
#include "arg.h"

int main(int argc, char **argv) {
  struct bq_config cfg = bq_args_to_config(argc, argv);
  return 0;
}
