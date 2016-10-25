#include <signal.h>
#include <unistd.h>
#include <setjmp.h>
jmp_buf jbuf;
void sig_alrm(int signo) {
    /* nothing to do, just return to wake up the pause */
}

unsigned int sleep2(unsigned int nsecs) {
    if (signal(SIGALRM, sig_alrm) == SIG_ERR) {
        return nsecs;
    }
    if(setjmp(jbuf) == 0){
        alarm(nsecs);
        pause();
    }
    return (alarm(0));
}

int main(int argc, char const *argv[]) {
    sleep2(3);
    return 0;
}
