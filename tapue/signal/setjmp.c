#include <stdio.h>
#include <setjmp.h>

jmp_buf jump_buffer;

void func(void) {
    printf("Before calling longjmp\n");
    longjmp(jump_buffer, 1);
    printf("After calling longjmp\n");
}

void func1(void) {
    printf("Before calling func\n");
    func();
    printf("After calling func\n");
}

int main() {
    if (setjmp(jump_buffer) == 0) {
        printf("first calling set_jmp\n");
        func1();
    } else {
        printf("second calling set_jmp\n");
    }
    return 0;
}
