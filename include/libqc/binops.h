#ifndef BINOPS_H_
#define BINOPS_H_

#include <stddef.h>

enum qc_ops {
  QC_OP_INT,
  QC_OP_FLOAT,
  QC_OP_PTR,
  QC_OP_STR,
};

enum qc_endianess {
  QC_LITTLE,
  QC_BIG,
};

enum qc_fmt {
  QC_DEFAULT,
  QC_DECIMAL,
  QC_HEX,
  QC_BIN,
};

struct qc_op {
  // offset of data
  size_t at;
  // lenght in bytes
  size_t len;
  // how often to apply this operation
  size_t amount;

  enum qc_ops type;
  enum qc_endianess endianess;
  enum qc_fmt fmt;
};

void bq_ops_sort(struct qc_op *ops, size_t len) {}

#endif
