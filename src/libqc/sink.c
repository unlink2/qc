#include "libqc/sink.h"

qc_vec_impl(sink_lst, struct qc_sink)

    int qc_sink_exec(struct qc_handle *handle, struct qc_sink *self,
                     const char *path, const char *content) {}
