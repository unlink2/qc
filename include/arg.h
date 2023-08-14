#ifndef ARG_H_
#define ARG_H_

#include "argtable2.h"
#include <stdlib.h>

#include "libqc/config.h"
#include "libqc/log.h"
#include "libqc/macros.h"

struct qc_config qc_args_to_config(int argc, char **argv);

#endif
