/*************************************************************************
	> File Name: simple.c
	> Author: 
	> Mail: 
	> Created Time: Wed 12 Oct 2016 10:42:33 AM CST
 ************************************************************************/

#include<stdio.h>
#include<apue.h>
#include<signal.h>
void sig_usr(int);
int main(){
    if(signal(SIGUSR1,sig_usr)==SIG_ERR)
        err_sys("SIGUSR1 Failed\n");
    if(signal(SIGUSR2,sig_usr)==SIG_ERR)
        err_sys("SIGUSR2 Failed\n");
    return 0;
}


void sig_usr(int signo){
    if(signo == SIGUSR1){
        printf("catch SIGUSR1\n");
    } 
    if(signo == SIGUSR2){
        printf("catch SIGUSR2\n");
    } 
}
