#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define BUF_SIZE 2
#define THREADS 1
#define LOOPS 3 * BUF_SIZE

int buffer[BUF_SIZE];
int fill = 0;
int use = 0;

void put(int value);
int get();

void *producer(void *arg) {
    int i;
    int tid = (int) arg;
    for (i = 0; i < LOOPS; i++) {
        put(i);
        printf("Producer %d put data %d\n", tid, i);
        sleep(1);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int i, tmp = 0;
    int tid = (int) arg;
    while (tmp != -1) {
        tmp = get();
        printf("Consumer %d get data %d\n", tid, tmp);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    int i;
    int tid[THREADS];
    pthread_t producers[THREADS];
    pthread_t consumers[THREADS];

    for (i = 0; i < THREADS; i++) {
        tid[i] = i;
        pthread_create(&producers[i], NULL, producer, (void*) tid[i]);
        pthread_create(&consumers[i], NULL, consumer, (void*) tid[i]);
    }

    return 0;
}

void put(int value) {
    buffer[fill] = value;
    fill = (fill + 1) % BUF_SIZE;
}

int get() {
    int tmp = buffer[use];
    buffer[use] = -1;
    use = (use + 1) % BUF_SIZE;

    return tmp;
}