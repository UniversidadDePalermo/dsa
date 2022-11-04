#include "imc.h"

void test_imc_result(void) {
  TEST_ASSERT_TRUE(imc(160, 80) == 31.2);
  TEST_ASSERT_TRUE(imc(180, 95) == 29.3);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_imc_result);

  return UNITY_END();
}
