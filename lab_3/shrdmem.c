#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int MAX_COUNT = 1e7;
static int count = 0;
pthread_mutex_t lock;

void *f_count(void *sid) {
    pthread_mutex_init(&lock, NULL);
    int i;
    for (i = 0; i < MAX_COUNT; i++) {
        // proctection code
        pthread_mutex_lock(&lock);
        count = count + 1;
        pthread_mutex_unlock(&lock);
    }

    printf("Thread %s: holding %d \n", (char *) sid, count);
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, &f_count, "1");
    pthread_create(&thread2, NULL, &f_count, "2");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
