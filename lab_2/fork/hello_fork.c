#include <stdio.h>

int main(int argc, char *argv[]) {
    fork();
    printf("Hello World\n");
    getc(stdin);
    return 0;
}