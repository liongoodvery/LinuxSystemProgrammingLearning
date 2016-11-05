/*************************************************************************
	> File Name: detached.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Sat 05 Nov 2016 03:07:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include <pthread.h>

void *thr_fn(void *args) {

}

int main() {
    int err;
    pthread_t p;
    pthread_attr_t attr;

    err = pthread_attr_init(&attr);
    if (err != 0)
        return err;
    err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (0 == err)
        pthread_create(&p, &attr, thr_fn, NULL);
    pthread_attr_destroy(&attr);
    return 0;
}