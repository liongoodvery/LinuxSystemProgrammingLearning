/*************************************************************************
	> File Name: signal1.c
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Oct 2016 05:40:09 PM CST
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
static void sigint_handler(int signo){
    printf("Caught SIGINT\n");
    exit(EXIT_SUCCESS);

}

int main(){
    if(signal(SIGINT,sigint_handler)==SIG_ERR){
        fprintf(stderr,"cannot handle SIGINT");
        exit(EXIT_FAILURE);
    }
    for(;;){
        pause();
    }
    return 0;
}
