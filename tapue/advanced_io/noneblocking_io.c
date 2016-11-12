/*************************************************************************
	> File Name: noneblocking_io.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Wed 09 Nov 2016 09:45:07 AM CST
 ************************************************************************/
//./noneblocking_io.out < ~/backups/yjyx-teacher-2016-11-03-19-00.737827127.tgz >re.tmp
//./noneblocking_io.out < ~/backups/yjyx-teacher-2016-11-03-19-00.737827127.tgz 2>re2.tmp
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <apue.h>
int main() {
    char buf[500000];
    int ntowrite;
    ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
    fprintf(stderr, "read %d bytes\n", ntowrite);
    set_fl(STDOUT_FILENO, O_NONBLOCK);

    char *ptr;
    int nwrite;

    while (ntowrite > 0) {
        errno = 0;
        nwrite = write(STDOUT_FILENO, buf, ntowrite);
        fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);
        if (nwrite > 0) {
            ptr += nwrite;
            ntowrite -= nwrite;
        }
    }
    clr_fl(STDOUT_FILENO,O_NONBLOCK);
    return 0;
}
