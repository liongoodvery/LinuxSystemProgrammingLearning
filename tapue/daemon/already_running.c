/*************************************************************************
	> File Name: already_running.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Tue 08 Nov 2016 04:51:58 PM CST
 ************************************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>

#define LOCKFILE "/var/run/already_running.pid"
#define LOCKFILEMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

extern int lockfile(int);

int already_running(void) {
    int fd;
    fd = open(LOCKFILE, O_RDWR | O_CREAT, LOCKFILEMODE);
    if (fd < 0) {
        syslog(LOG_ERR, "can't open %s: %s", LOCKFILE, strerror(errno));
        exit(1);
    }

    if (lockfile(fd) < 0) {
        if (errno == EACCES || errno == EAGAIN) {
            close(fd);
            return 1;
        }
        syslog(LOG_ERR, "can't lock %s: %s", LOCKFILE, strerror(errno));
        exit(1);
    }

    sleep(3);
    ftruncate(fd, 0);

    char buf[16];
    sprintf(buf, "%ld", (long) getpid());
    write(fd, buf, strlen(buf) + 1);
    return 0;
}

int main() {
    if (!already_running()) {
        printf("run success\n");
    }
    return 0;
}