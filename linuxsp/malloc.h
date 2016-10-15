#include<stdio.h>
#include<stdlib.h>
void* xmalloc(size_t size){
    void* p;
    p=malloc(size);
    if(!p){
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    return p;
}
void* xcalloc(size_t nr,size_t size){
    void* p;
    p=calloc(nr,size);
    if(!p){
        perror("calloc failed");
        exit(EXIT_FAILURE);
    }
    return p;
}
