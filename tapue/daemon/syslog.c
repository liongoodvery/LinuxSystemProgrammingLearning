/*************************************************************************
	> File Name: syslog.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Tue 08 Nov 2016 04:28:24 PM CST
 ************************************************************************/

#include<stdio.h>
#include <syslog.h>

int main() {
    syslog(LOG_DEBUG, "open error for===========");
    return 0;
}

