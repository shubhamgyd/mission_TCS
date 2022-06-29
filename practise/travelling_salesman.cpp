#include<bits/stdc++.h>
using namespace std;

int fun(int n)
{
    if(n!=0)
    {
        return n-fun(n-5);
    }
    else
    {
        return n;
    }
}

int calc(int x,int *py,int **ppz)
{
    int y,z;
    **ppz+=1;
    z=**ppz;
    *py+=**ppz;
    y=*py;
    x+=*py;
    return x+y+z;
}


int max1(int x,int y)
{
    return (y>x)?y:x;
}

int incr(int i)
{
    static int count=5;
    count=count+i;
    return count;
}


int Decode(string str)
{
    int iRetVal=0;
    for(auto it:str)
    {
        if(it>='0' and it<='9') iRetVal=iRetVal*10+(it-'0');
    }
    return iRetVal;
}

int main()
{
    int a=Decode("7SENSE");
    int b=Decode("6");
   cout<<a+b<<endl;
}