//
// Created by lion on 10/26/16.
//
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

pthread_t ntid;


void printids(const char *s) {
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int) pid,
           (unsigned int) tid, (unsigned int) tid);
}

void *start_rtn(void *arg) {
    printids("new thread");
    return (void *) 0;
}

int main() {
    int err = pthread_create(&ntid, NULL, start_rtn, NULL);
    if (err != 0) {
        printf("can not create thread : %s\n", strerror(err));
    }
    printids("main thread");
    sleep(1);
    return 0;
}
