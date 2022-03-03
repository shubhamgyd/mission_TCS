/*
This problem was asked by Microsoft.

A number is considered perfect if its digits sum up to exactly 10.

Given a positive integer n, return the n-th perfect number.

For example, given 1, you should return 19. Given 2, you should return 28.
*/

#include<bits/stdc++.h>
using namespace std;



void solve()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<19<<endl;
        return;
    }
    int kth=0;
    for(int i=19;;i+=9)
    {
        int num=i;
        int sum=0;
        while(num)
        {
            sum+=num%10;
            num/=10;
        }
        if(sum==10)
        {
            kth++;
            if(kth==n)
            {
                cout<<i<<endl;
                return;
            }
        }
    }
}


vector<int>res;

void preCount()
{
    for(int i=19;i<=100000;i++)
    {
        int num=i;
        int sum1=0;
        while(num)
        {
            sum1+=num%10;
            num/=10;
        }
        if(sum1==10)
        {
            res.push_back(i);
        }
    }
}



int main()
{
    preCount();
    int n;
    cin>>n;
    cout<<res[n-1]<<endl;
    return 0;
}
// Time Complexity:O(n)
// Auxilary Complexity:O(1)