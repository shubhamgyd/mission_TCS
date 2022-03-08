#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nums[1]={1};
    long long k=1000000000;
    long long t1,t2;
            if(nums[0]%2==0)
            {
                t1=k/2;
                t2=k+1;
            }
            else
            {
                t1=k;
                t2=(k+1)/2;
            }
            long long temp=t1*t2;
            temp-=nums[0];
            temp+=(k+1);
            cout<<temp<<endl;
}