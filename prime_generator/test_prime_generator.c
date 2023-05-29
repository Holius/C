#include "unity.h"
#include "prime_generator.h"

void test_main(void) {
    int expected_primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int acutal_primes[25];
    prime_generator(acutal_primes, 25);
    TEST_ASSERT_EQUAL_INT_ARRAY(expected_primes, acutal_primes, 25);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_main);
    return UNITY_END();
}