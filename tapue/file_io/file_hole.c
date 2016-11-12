/*************************************************************************
	> File Name: file_hole.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Sat 12 Nov 2016 01:17:33 PM CST
 ************************************************************************/

#include<stdio.h>
#include <apue.h>
#include <fcntl.h>

int main() {
    char buf1[] = "abc";
    char buf2[] = "dfe";
    int fd;
    if ((fd = creat("hole.tmp", FILE_MODE)) < 0)
        err_sys("create file error\n");
    if ((write(fd, buf1, strlen(buf1))) < 0)
        err_sys("write error\n");
    if ((lseek(fd, 100000, SEEK_CUR)) == -1)
        err_sys("seek error\n");
    if ((write(fd, buf2, strlen(buf2))) < 0)
        err_sys("write error\n");
    return 0;
}
