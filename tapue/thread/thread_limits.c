/*************************************************************************
	> File Name: thread_limits.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Sat 05 Nov 2016 02:29:02 PM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
#ifdef _SC_THREAD_DESTRUCTOR_ITERATIONS
    printf("PTHREAD_DESTRUCTOR_ITERATIONS=%d\n", sysconf(_SC_THREAD_DESTRUCTOR_ITERATIONS));
#endif

#ifdef _SC_THREAD_KEYS_MAX
    printf("PTHREAD_KEYS_MAX=0x%X\n", sysconf(_SC_THREAD_KEYS_MAX));
#endif

#ifdef _SC_THREAD_STACK_MIN
    printf("PTHREAD_STACK_MIN=0x%X\n", sysconf(_SC_THREAD_STACK_MIN));
#endif

#ifdef _SC_THREAD_THREADS_MAX
    printf("PTHREAD_THREADS_MAX=0x%X\n", sysconf(_SC_THREAD_THREADS_MAX));
#endif
    return 0;
}