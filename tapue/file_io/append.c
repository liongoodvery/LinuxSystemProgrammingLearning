/*************************************************************************
	> File Name: append.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Sat 12 Nov 2016 03:38:14 PM CST
 ************************************************************************/

#include <fcntl.h>

extern int writeout(const char *filename, int oflag);

int main() {
    writeout("append.tmp", O_WRONLY | O_APPEND);
    return 0;
}
