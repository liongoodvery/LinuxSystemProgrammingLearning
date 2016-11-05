/*************************************************************************
	> File Name: stack_attr.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Sat 05 Nov 2016 03:39:08 PM CST
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

long fibonacci(int fibo) {
    if (fibo == 0 || fibo == 1)
        return 1;
    else
        return fibonacci(fibo - 1) + fibonacci(fibo - 2);
}

void *thr_fn(void *args) {
    int a = 0;
    int b = 1;
    long arr[1<<16] ;
    printf("ret = %d\n", fibonacci(20));
    return (void *) 0;
}

int main() {
    pthread_attr_t attr;
    int err;
    void *addr;
    size_t size;
    pthread_t p;
    if (err = pthread_attr_init(&attr)) {
        return err;
    }

    pthread_attr_getstacksize(&attr, &size);
    printf("size=0x%x\n", size);


    pthread_attr_setstacksize(&attr, 1024*64);

    pthread_attr_getstacksize(&attr, &size);
    printf("size=0x%x\n", size);

    if (err = pthread_create(&p, &attr, thr_fn, NULL)) {
        return err;
    }

    sleep(3);

    pthread_attr_getstacksize(&attr, &size);
    printf("size=0x%x\n", size);

    pthread_attr_getstack(&attr,&addr,&size);
    printf("size=0x%x\n", size);

    pthread_join(p, NULL);
    return 0;
}

