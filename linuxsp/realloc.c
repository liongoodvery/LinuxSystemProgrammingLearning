/*************************************************************************
	> File Name: realloc.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Sat 15 Oct 2016 12:13:37 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "malloc.h"
int main(){
    int *p;
    p=xcalloc(2,sizeof(int));
    printf("size of p %d\n",sizeof(p));
    p=realloc(p,sizeof(int));
    printf("size of p %d\n",sizeof(p));
    for(int i = 10;i<1<<10;++i){
        p[i] = 1;
    }
}
