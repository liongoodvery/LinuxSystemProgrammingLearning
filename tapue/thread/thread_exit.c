//
// Created by lion on 10/31/16.
//
#include <pthread.h>
#include <stdio.h>
void* thr_fn1(void* arg){
    printf("I am thread 1 return 1\n");
    pthread_exit((void*)1);
}


void* thr_fn2(void* arg){
    printf("I am thread 2 return 2\n");
    pthread_exit((void*)2);
}

//ignore error handling
int main() {
    pthread_t p1,p2;
    void* pret;
    pthread_create(&p1,NULL,thr_fn1,NULL);
    pthread_join(p1,&pret);
    printf("return from p1 %d\n",(int)pret);

    pthread_create(&p2,NULL,thr_fn2,NULL);
    pthread_join(p2,&pret);
    printf("return from p2 %d\n",(int)pret);

    return 0;
}