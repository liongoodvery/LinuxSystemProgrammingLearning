//
// Created by lion on 10/24/16.
//
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
void sig_quit(int signo){
    printf("\nCaught SIGQUIT\n");
    if (signal(SIGQUIT,SIG_DFL)==SIG_ERR){
        printf("can not reset SIGQUIT");
    }
}
int main(){

    sigset_t old_set , new_set , pending_set;
    if (signal(SIGQUIT,sig_quit)==SIG_ERR){
        printf("can not catch SIGQUIT\n");
    }

    sigemptyset(&new_set);
    sigaddset(&new_set,SIGQUIT);
    if (sigprocmask(SIG_BLOCK,&new_set,&old_set)<0){
        printf("Block SIGQUIT Error\n");
    }

    printf("first sleep\n");
    sleep(5);

    if (sigpending(&pending_set)<0){
        printf("SIG pending Error\n");
    }

    if (sigprocmask(SIG_SETMASK,&old_set,NULL)<0){
        printf("reset error\n");
    }
    printf("second sleep\n");
    sleep(5);

    return 0;
}