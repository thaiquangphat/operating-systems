#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isnum(char *arg) {
    long num;
    num = strtol(arg, &arg, 10);
    if (*arg == '\0')
        return 1;
    return 0;
}

void solve() {
    int a, b;
    char input[100];
    char c;

    // get input from user
    fgets(input, sizeof(input), stdin);

    int space = strchr(input, ' ') - input;
    // get first operator
    char A[space + 1];
    strncpy(A, input, space);
    A[space] = '\0';
    a = atoi(A);

    // get operation
    strncpy(input, input + space + 1, sizeof(input) - space - 1);
    c = input[0];
    strncpy(input, input + 2, sizeof(input) - 2);

    // get second operator
    space = strchr(input, '\n') - input;
    char B[space + 1];
    strncpy(B, input, space);
    B[space] = '\0';
    b = atoi(B);

    // printf("%d, %d\n", a, b);
    // printf("%s, %s\n", A, B);

    // check valid for a and b
    if (!isnum(A) || !isnum(B)) {
        printf("SYNTAX ERROR\n");
        return;
    }

    // evaluate
    switch (c) {
        case '+':
            printf("%d\n", a + b);
            break;
        case '-':
            printf("%d\n", a - b);
            break;
        case '*':
            printf("%d\n", a * b);
            break;
        case '/':
            switch (b) {
            case 0:
                printf("MATH ERROR\n");
                return;
                break;
            default:
                printf("%d\n", a / b);
                break;
            }
        default:
            printf("SYNTAX ERROR\n");
            break;
    }
}