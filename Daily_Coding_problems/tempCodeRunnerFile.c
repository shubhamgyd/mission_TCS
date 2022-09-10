#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
int main()
{
    if(fork()==1 || fork()==0)
    {
        printf("Hello");
        fork();
        printf("Hello1");
    }
    return 0;
}