#include "libqc/test/test.h"
#include "libqc/error.h"
#include "libqc/log.h"
#include "libqc/test/vec.h"

static int test_setup(void **state) {
  qc_err_set(QC_OK);

  return 0;
}

int main(int arc, char **argv) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test_setup(test_vec, test_setup),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

