/*************************************************************************
	> File Name: exch.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Fri 04 Nov 2016 05:06:22 PM CST
 ************************************************************************/

void swap(int *a, int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int main(){
    int a , b;
    a = 16;
    b = 32;
    swap(&a,&b);
    return (a-b);
}
