#include <signal.h>
#include <unistd.h>
void sig_alrm(int signo){

}
int main(int argc, char const *argv[]) {
  if (signal(SIGALRM,sig_alrm)==SIG_ERR) {
    /* code */
  }
  return 0;
}
