/*************************************************************************
	> File Name: seekwrite.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Sat 12 Nov 2016 03:37:57 PM CST
 ************************************************************************/
#include <fcntl.h>
extern int writeout(const char *filename , int oflag);
int main() {
    writeout("seekwrite.tmp",O_WRONLY);
    return 0;
}
