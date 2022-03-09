#include<bits/stdc++.h>
using namespace std;

int maxGCD(int N,vector<int>A,int Q,vector<int>Queires)
{
    int xor_arr=0;
    for(int k=0;k<Q;k++)
    {
        int i;
        i=Queires[k];
        swap(A[i],A[(i+1)%N]);
        int gcd=0;
        for(int j=0;j<N-1;j++)
        {
            int temp=__gcd(A[j],A[j+1]);
            gcd=max(gcd,temp);
        }
        xor_arr^=gcd;
    }
    return xor_arr;
}

void minMax(int n)
{
    string str=to_string(n);
    string str1=str;
    char ch='0';
    char src='~';
    char dest='~';
    int sz=str.length();
    long long int mn=0;
    long long int mx=0;
    for(int i=0;i<sz;i++)
    {
        if(i==0 && str[i]!='1')
        {
            src=str[i];
            dest='1';
            break;
        }
        else if(i==0 && str[i]=='1')
        {
            continue;
        }
        else
        {
            if(str[i]=='0')
            {
                continue;
            }
            else
            {
                src=str[i];
                dest='0';
                break;
            }
        }
    }
    char ch1='9';
    for(int i=0;i<sz;i++)
    {
        if(str[i]=='9')
        {
            continue;
        }
        else
        {
            ch1=str[i];
            break;
        }
    }
    if(src!='~' && dest!='~')
    {
        for(int i=0;i<sz;i++)
        {
            if(str[i]==src)
            {
                str[i]=dest;
            }
        }
        while(!str.empty() && str[0]=='0')
        {
            str.erase(str.begin()+0);
        }
        sz=str.length();
        for(int i=0;i<sz;i++)
        {
            mn=mn*10+str[i]-'0';
        }
    }
    else
    {
        mn=n;
    }
    if(ch1!='9')
    {
        for(int i=0;i<sz;i++)
        {
            if(str1[i]==ch1)
            {
                str1[i]='9';
                mx=mx*10+str1[i]-'0';
            }
            else
            {
                mx=mx*10+str1[i]-'0';
            }
        }
    }
    else{
        mx=n;
    }

    cout<<mn<<" "<<mx<<endl;
}

int main()
{
    int n;
    cin>>n;
    minMax(n);
    return 0;
}