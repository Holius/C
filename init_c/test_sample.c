#include <stdlib.h>

void test(void) {
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test);
    return UNITY_END();
}
