//
// Created by lion on 10/31/16.
//
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct foo {
    int a, b, c, d;
};

void print_foo(const char *msg, const struct foo *fp) {
    printf(msg);
    printf("  structure at 0x%x\n", (unsigned) fp);
    printf("  foo.a = %d\n", fp->a);
    printf("  foo.b = %d\n", fp->b);
    printf("  foo.c = %d\n", fp->c);
    printf("  foo.d = %d\n", fp->d);
}

void *thr_fn1(void *arg) {
    struct foo *foo = malloc(sizeof(struct foo));
    foo->a = 1;
    foo->b = 2;
    foo->c = 3;
    foo->d = 4;
    print_foo("thread 1:\n", foo);
    pthread_exit((void *) foo);
}

void *thr_fn2(void *arg) {
    printf("thread 2: ID is %d\n", pthread_self());
    pthread_exit((void *) 0);
}

int main() {
    struct foo *fp;
    pthread_t p1, p2;
    pthread_create(&p1, NULL, thr_fn1, NULL);
    pthread_join(p1, (void *) &fp);
    sleep(1);
    pthread_create(&p2, NULL, thr_fn2, NULL);
    pthread_join(p2, NULL);
    sleep(1);
    print_foo("parent \n", fp);
    return 0;
}