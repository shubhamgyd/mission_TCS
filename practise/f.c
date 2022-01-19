#include<stdio.h>
#include<unistd.h>
#include<unwind.h>
#include  <sys/types.h>

int extern x;
int main()
{
    printf("%d", x);
    x=2;
    getch();
    return 0;
}
int x=23;