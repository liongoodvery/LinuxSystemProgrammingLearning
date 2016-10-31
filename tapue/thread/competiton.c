//
// Created by lion on 10/31/16.
//
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int a = 0;

void* thr_run(void* arg){
    sleep(1);
    ++a;
    return (void*)0;
}

int main() {
    int count = 10000;
    pthread_t ts[count];
    for (int i = 0; i < count; ++i) {
        pthread_create(&ts[i],NULL,thr_run,NULL);
    }

    for (int i = 0; i < count; ++i) {
        pthread_join(ts[i],NULL);
    }
    printf("a=%d\n",a);
    return 0;
}