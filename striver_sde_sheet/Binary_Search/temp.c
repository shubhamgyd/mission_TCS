#include<stdio.h>

int main()
{
    int a=3;
    int b=4;
    static int c=1;
    c=a*b+a/3+b*2;
    printf("%d",c);
}