/*************************************************************************
	> File Name: signame.c 
	> Author: 
	> Mail: 
	> Created Time: Fri 14 Oct 2016 05:40:09 PM CST
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

extern const char* const sys_siglist[];
int main(){
    for(int i = 0;i<40;++i){
        printf("%d : %s\n",i,sys_siglist[i] );
    }
    return 0;
}
