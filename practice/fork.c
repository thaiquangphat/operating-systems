#include <stdio.h>
#include <unistd.h>
int main() {
    printf("hi\n");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        fork();
    }
    printf("hello\n");
    return 0;
}