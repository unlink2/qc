#ifndef OPS_H_
#define OPS_H_

#include <stddef.h>

enum bq_ops {
  BQ_OP_INT,
  BQ_OP_FLOAT,
  BQ_OP_PTR,
  BQ_OP_STR,
};

enum bq_endianess {
  BQ_LITTLE,
  BQ_BIG,
};

enum bq_fmt {
  BQ_DEFAULT,
  BQ_DECIMAL,
  BQ_HEX,
  BQ_BIN,
};

struct bq_op {
  // offset of data
  size_t at;
  // lenght in bytes
  size_t len;
  // how often to apply this operation
  size_t amount;

  enum bq_ops type;
  enum bq_endianess endianess;
  enum bq_fmt fmt;
};

void bq_ops_sort(struct bq_op *ops, size_t len) {}

#endif
