/*************************************************************************
	> File Name: writerandom.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Sat 12 Nov 2016 03:38:38 PM CST
 ************************************************************************/

#include <unistd.h>
#include <apue.h>
#include <fcntl.h>

int write_random(int filedes) {
    char buf[] = "0123456789";
    if (write(filedes, buf, 10) != 10)
        err_sys("write error");
    return 0;
}

int writeout(const char *filename, int oflag) {
    //create or truncate the file
    if (open(filename, O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE) < 0) {
        err_sys("open error");
    }

    if ((fork()) < 0) {
        err_sys("fork error\n");
        return -1;
    }
    //two process here
    int filedes;
    if ((filedes = open(filename, oflag)) < 0) {
        err_sys("open file error\n");
        return -1;
    }

    for (int i = 0; i < 10000; ++i) {
        if (!(oflag & O_APPEND)){
            if ((lseek(filedes, 0, SEEK_END)) == -1) {
                err_sys("seek error\n");
                return -1;
            }
        }
        write_random(filedes);
    }
    return 0;
}

