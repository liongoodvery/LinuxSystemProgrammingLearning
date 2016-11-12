/*************************************************************************
	> File Name: copy.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Sat 12 Nov 2016 02:06:45 PM CST
 ************************************************************************/

#include<stdio.h>
#include <apue.h>
#include <stdlib.h>

int copy(int bufsize) {
    int n;
    char buf[bufsize];

    while ((n = read(STDIN_FILENO, buf, bufsize)) > 0) {
        if (n != write(STDOUT_FILENO, buf, n)) {
            err_sys("write error\n");
            return -1;
        }
    }

    if (n < 0) {
        err_sys("read error\n");
        return -1;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        err_sys("usage copy.out bufsize\n");
    }

    int bufsize = atoi(argv[1]);
    copy(bufsize);
    return 0;
}