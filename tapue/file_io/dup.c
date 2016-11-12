/*************************************************************************
	> File Name: dup.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Sat 12 Nov 2016 05:42:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>

int main() {
    int filedes = dup(STDOUT_FILENO);
    printf("%d\n",filedes);
    printf("%d\n",dup(STDOUT_FILENO));
    return 0;
}

