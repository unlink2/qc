#include <stdio.h>
#include <stdlib.h>
#include "libqc/config.h"
#include "libqc/log.h"
#include "arg.h"

int main(int argc, char **argv) {
  struct qc_config cfg = qc_args_to_config(argc, argv);
  return 0;
}
