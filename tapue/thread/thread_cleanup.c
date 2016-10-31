//
// Created by lion on 10/31/16.
//
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void cleanup(void *arg) {
    printf("cleanup: %s\n", (char *) arg);
}

void *thr_fn1(void *arg) {
    printf("thread 1 start\n");
    pthread_cleanup_push(cleanup, "thread 1 first handler") ;
    pthread_cleanup_push(cleanup, "thread 1 second handler") ;
    printf("thread 1 push complete\n");
    if (arg)
        return ((void *) 1); //return from routine
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    return ((void *) 1);
}

void *thr_fn2(void *arg) {
    printf("thread 2 start\n");
    pthread_cleanup_push(cleanup, "thread 2 first handler") ;
    pthread_cleanup_push(cleanup, "thread 2 second handler") ;
    printf("thread 2 push complete\n");
    if (arg)
        pthread_exit((void *) 2); // return with pthread_exit
    pthread_cleanup_pop(0);
    pthread_cleanup_pop(0);
    pthread_exit((void *) 2);
}

int main() {
    pthread_t p1, p2;
    void *ret;
    pthread_create(&p1, NULL, thr_fn1, (void *) 1);
    pthread_create(&p2, NULL, thr_fn2, (void *) 2);
    sleep(1);
    pthread_join(p1, &ret);
    printf("return from thread1 is : %d\n", (int) (ret));

    pthread_join(p2, &ret);
    printf("return from thread2 is : %d\n", (int) (ret));
    exit(0);
}
