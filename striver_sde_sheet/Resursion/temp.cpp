#include<bits/stdc++.h>
using namespace std;

void recur(char x)
{
    if(x=='A')
    {
        printf("%c",x);
        return;
    }
    if(x%2==0)
    {
        printf("%c",x);
        recur(x-1);
    }
    else
    {
        recur(x-1);
        printf("%c",x);
    }
}

int main()
{
    recur(70);
    return 0;
}