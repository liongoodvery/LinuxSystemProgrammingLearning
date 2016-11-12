/*************************************************************************
	> File Name: file_lock.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Wed 09 Nov 2016 04:07:44 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc > 1) {
        int fd = open(argv[1], O_WRONLY);
        if (fd == -1) {
            printf("Unable to open the file\n");
            exit(1);
        }
        static struct flock lock;

        lock.l_type = F_WRLCK;
        lock.l_start = 0;
        lock.l_whence = SEEK_SET;
        lock.l_len = 0;
        lock.l_pid = getpid();

        int ret = fcntl(fd, F_SETLKW, &lock);
        printf("Return value of fcntl:%d\n", ret);
        if (ret == 0) {
            while (1) {
                scanf("%c", NULL);
            }
        }
    }
    return 0;
}

