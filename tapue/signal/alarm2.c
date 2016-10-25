/*************************************************************************
	> File Name: alarm.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Mon 17 Oct 2016 01:09:04 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void alarm_handle(int signo){
    if(signo==SIGALRM){
        fprintf(stderr,"caught alarm\n");
    }

}
int main(){
    if(signal(SIGALRM,alarm_handle)==SIG_ERR){
        fprintf(stderr,"register error\n");
    }
    alarm(2);
    int ret = alarm(3);
    fprintf(stderr,"ret=%d \n",ret);
    pause();
    fprintf(stderr,"exits \n");
    return 0;
}
