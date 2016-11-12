/*************************************************************************
	> File Name: deadlock.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Wed 09 Nov 2016 02:54:41 PM CST
 ************************************************************************/

#include<stdio.h>
#include <apue.h>
#include <fcntl.h>

static void
lockabyte(const char *name, int fd, off_t offset) {
    if (writew_lock(fd, offset, SEEK_SET, 1) < 0)
        err_sys("%s: writew_lock error", name);
    printf("%s: got the lock, byte %ld\n", name, offset);
}

int main() {
    int fd;

    if ((fd = creat("file.tmp", FILE_MODE)) < 0) {
        err_sys("create file error");
    }
    if (write(fd, "ab", 2) != 2) {
        err_sys("write error");
    }

    TELL_WAIT();

    pid_t pid;
    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) {
        lockabyte("child", fd, 0);
        TELL_PARENT(getppid());
        WAIT_PARENT();
        lockabyte("child", fd, 1);
    } else {
        lockabyte("parent", fd, 1);
        TELL_CHILD(pid);
        WAIT_CHILD();
        lockabyte("parent", fd, 0);
    }

    return 0;
}

