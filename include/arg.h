#ifndef ARG_H_
#define ARG_H_

#include "argtable2.h"
#include <stdlib.h>

#include "libbq/config.h"
#include "libbq/log.h"
#include "libbq/macros.h"

struct bq_config bq_args_to_config(int argc, char **argv);

#endif
