#ifndef VEC_H_
#define VEC_H_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "libqc/log.h"
#include "libqc/error.h"

#define qc_vec_def(name, type)                                                 \
  struct qc_##name {                                                           \
    type *vals;                                                                \
    size_t len;                                                                \
    size_t max_len;                                                            \
  };                                                                           \
  struct qc_##name qc_##name##_init(void);                                     \
  void qc_##name##_push(struct qc_##name *self, type new_val);                 \
  void qc_##name##_free(struct qc_##name *self);

#define qc_vec_impl(name, type)                                                \
  struct qc_##name qc_##name##_init(void) {                                    \
    struct qc_##name self;                                                     \
    memset(&self, 0, sizeof(self));                                            \
    self.max_len = 4;                                                          \
    self.vals = malloc(self.max_len * sizeof(type));                           \
    return self;                                                               \
  }                                                                            \
                                                                               \
  void qc_##name##_push(struct qc_##name *self, type new_val) {                \
    if (self->len >= self->max_len) {                                          \
      size_t new_len = self->max_len * 2;                                      \
      type *new_vals = realloc(self->vals, new_len * sizeof(type));            \
                                                                               \
      if (!new_vals) {                                                         \
        qc_errno();                                                            \
        return;                                                                \
      }                                                                        \
                                                                               \
      self->max_len = new_len;                                                 \
      self->vals = new_vals;                                                   \
    }                                                                          \
    self->vals[self->len++] = new_val;                                         \
  }                                                                            \
                                                                               \
  void qc_##name##_free(struct qc_##name *self) {                              \
    if (self->vals) {                                                          \
      free(self->vals);                                                        \
    }                                                                          \
  }

qc_vec_def(strlst, const char *)

#endif
