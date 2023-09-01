#include <stdio.h>
#include <string.h>
char globalBuf[100];
void vulnerable(int i)
{

   int whatEver = 987654321;
   double notNeeded = 1.23456789;
   char buf[26];
   printf("\n Entering our vulnerable function.\n");
   printf(" Please enter a string: ");
   scanf("%s", buf);
   printf("\n whatEver is: %d", whatEver);
   strncpy(globalBuf, buf, 99);
   printf("\n Leaving our vulnerable function.\n");
   return;
}

int main()
{
   int n = 1;
   printf("Calling our vulnerable function.\n");
   vulnerable(n);
   printf("n = %d\n", n);
   if (n)
   {
      printf("\nHere is what is in the buffer\n");
      printf(globalBuf);
      printf("\nThat's it.\n");
   }
   else
      printf("We really shouldn't be able to ever see this output.\n");
   return 0;
}