#include "unity.h"
#include "main.h"
#include <string.h> //strcpy
#include <stdio.h> //freopen

void test_main(void) {
    FILE *write, *read;
    char ch;
    int unsigned index = 0;
    char *argv[2] = {
        "pay_calculator/main.c",
        "39"
    };

    write = freopen("test_run.txt", "w", stdout);
    _main(3, argv);
    fclose(write);
    freopen ("/dev/tty", "a", stdout); // restore stdout
    read = fopen("test_run.txt", "r");
    char* expected_stdout = "Gross pay is 468.00\nTax deductions is 79.50\nNet pay is 388.50\n";
    while(ch = getc(read)) { 
        if (ch == EOF) break;
        TEST_ASSERT_EQUAL_UINT8(expected_stdout[index++], ch);
    }
    fclose(read);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_main);
    return UNITY_END();
}