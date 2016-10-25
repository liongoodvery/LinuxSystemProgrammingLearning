/*************************************************************************
	> File Name: alarm.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Mon 17 Oct 2016 01:09:04 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int main(){
    alarm(2);
    pause();
    fprintf(stderr,"exits \n");
    return 0;
}
