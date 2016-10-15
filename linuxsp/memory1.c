/*************************************************************************
	> File Name: memory1.c
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Oct 2016 11:00:42 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
void* xmalloc(size_t);
int main(){
    void* p;
    p=malloc(2048);
    if(!p){
        perror("malloc failed");
    }
    void* p2 = xmalloc(2048);
}

void* xmalloc(size_t size){
    void* p;
    p=malloc(size);
    if(!p){
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    return p;
}
