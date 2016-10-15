/*************************************************************************
	> File Name: free.c
	> Author: Lion
	> Mail: lion.good.very.first@gmail.com
	> Created Time: Sat 15 Oct 2016 01:14:47 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void print_chars(int n,char c){
    int i;
    for(i=0;i<n;++i){
        char *s;
        s=(char*)calloc(i+2,1);
        int j;
        for(j=0;j<i+1;++j){
            s[j]=c;
        }
        printf("%s\n",s);
        free(s);
    }
}

int main(){
    print_chars(10,'x');
    return 0;
}
