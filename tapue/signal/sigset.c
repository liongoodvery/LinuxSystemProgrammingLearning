//
// Created by lion on 10/24/16.
//
#include <signal.h>
#include <unistd.h>

int main() {
    sigset_t *set;
    sigfillset(set);
    sigprocmask(SIG_BLOCK, set, NULL);
    pause();
    return 0;
}