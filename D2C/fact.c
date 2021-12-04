#include<stdio.h>
#include <inttypes.h>
int main(){
unsigned long long  t;
scanf("%"SCNu64, &t);
for(int i=0;i<t;i++)
{
    unsigned long long  n;
    scanf("%"SCNu64, &n);
    unsigned long long  a=1;
    for(unsigned long long  i=2;i<=n;i++)
    {
        a*=i;
    }
    printf("%"PRIu64"\n",a);
}
return 0;
}