#include <unistd.h> //dup
#include <stdio.h> //fopen

int main(void) {
    FILE *write;
    printf("\n");
    int original_stdout = dup(1);
    write = fopen("test_run.txt", "w");
    dup2(fileno(write), 1);
    printf("Why does it want a new line\nfor redirecting STDOUT?\n");
    dup2(original_stdout, 1);
    close(original_stdout);
}