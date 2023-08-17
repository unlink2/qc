#include "libqc/test/filter.h"
#include "libqc/error.h"
#include "libqc/sink.h"
#include "libqc/test/test.h"
#include <cmocka.h>
#include <stdlib.h>
#include <string.h>
#include "libqc/filter.h"

void test_filter(void **state) {
  {
    // path pattern
    struct qc_filter f = qc_filter_path_pattern("filter", "p.th");
    assert_true(qc_filter_includes(&f, "path", "", 0));
    assert_true(qc_filter_includes(&f, "pith", "", 0));
    assert_false(qc_filter_includes(&f, "bath", "", 0));
    qc_filter_free(&f);
  }
}
