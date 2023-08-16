#include "libqc/vec.h"
#include "libqc/error.h"
#include "libqc/test/test.h"
#include <cmocka.h>
#include <stdlib.h>
#include <string.h>

void test_vec(void **state) {
  struct qc_strlst lst = qc_strlst_init();
  lst.max_len = 4;

  qc_strlst_push(&lst, "Test 1");
  qc_strlst_push(&lst, "Test 2");
  qc_strlst_push(&lst, "Test 3");
  qc_strlst_push(&lst, "Test 4");
  assert_int_equal(lst.max_len, 4);

  qc_strlst_push(&lst, "Test 5");

  assert_int_equal(lst.max_len, 8);
  assert_int_equal(lst.len, 5);
  assert_string_equal("Test 1", lst.vals[0]);
  assert_string_equal("Test 2", lst.vals[1]);
  assert_string_equal("Test 3", lst.vals[2]);
  assert_string_equal("Test 4", lst.vals[3]);
  assert_string_equal("Test 5", lst.vals[4]);

  qc_strlst_free(&lst);
}
