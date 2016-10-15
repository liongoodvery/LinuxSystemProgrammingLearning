/*************************************************************************
	> File Name: calloc.c
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Oct 2016 11:16:17 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"malloc.h"
int main(){
    int *p,*q;
    p=(int*)xmalloc(50*sizeof(int));
    q=(int*)xcalloc(50,sizeof(int));
    printf("%d\n",q[0]);
    return 0;
}
