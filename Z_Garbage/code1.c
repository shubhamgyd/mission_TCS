#include<stdio.h>
#include<string.h>


int main()
{
    long int limit=10000001;
    char str[limit];
    gets(str);
    int n=strlen(str);
    //sort(str,n);
    char temp;
    int i,j;
    for (i = 0; i < n-1; i++) {
      for (j = i+1; j < n; j++) {
         if (str[i] > str[j]) {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
         }
      }
   }
    if(strlen(str)==1)
    {
        printf("%s\n",str);
    }
    else if(str[0]=='0')
    {
        char ch=str[1];
        str[0]=ch;
        str[1]='0';
        printf("%s\n",str);
    }
    else{
        printf("%s\n",str);
    }
}