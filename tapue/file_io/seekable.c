/*************************************************************************
	> File Name: seekable.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Sat 12 Nov 2016 09:49:27 AM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>

int main() {
    if (lseek(STDIN_FILENO,1,SEEK_SET)<0){
        printf("can not seek\n");
    } else{
        printf("can seek\n");
    }
    return 0;
}
