#include <stdio.h>
#include <pthread.h>

#define MAX_COUNT 1e8
int count;

void *f_count(void *sid) {
    int i;
    for (i =0 ; i < MAX_COUNT; i++) {
        count = count + 1;
    }

    printf("Thread %s: holding %d \n", (char *) sid, count);
    getc(stdin);
}

int main(int argc, char *atgv[]) {
    printf("Hello World\n");
    pthread_t thread1, thread2;

    count = 0;

    pthread_create(&thread1, NULL, &f_count, "1");
    pthread_create(&thread2, NULL, &f_count, "2");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    getc(stdin);

    return 0;
}