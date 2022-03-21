/*
This question is asked by Facebook. In a gym hallway there are N lockers. 
You walk back and forth down the hallway opening and closing lockers. 
On your first pass you open all the lockers. On your second pass, you close every other locker. 
On your third pass you open every third locker. After walking the hallway N times 
opening/closing lockers in the previously described manner, how many locker are left open?
*/

#include<bits/stdc++.h>
using namespace std;

// brute force
void gymLocker(int n)
{
    vector<int>locker(n+1,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j%i==0)
            {
                locker[j]=1-locker[j];
            }
        }
    }
    int openLocker=0;
    for(int i=1;i<=n;i++)
    {
        if(locker[i])
        {
            openLocker++;
        }
    }
    cout<<openLocker<<endl;
}
// Time Complexity:O(n*n)
// Space Complexity:O(n)



// Optimise 
void gymLocker1(int n)
{
    vector<int>locker(n,1);
    int cnt=2;
    for(int i=2;i<=n;i++)
    {   
        double num=log(i);
        double denom=log(cnt);
        int res=num/denom;
        double temp=(res)%(2);
        if(temp==0)
        {
            locker[i-1]=1;
            cnt++;
        }
        else
        {
            locker[i-1]=0;
        }
    }
    int openLocker=0;
    for(int i=0;i<n;i++)
    {
        if(locker[i]!=0)
        {
            openLocker++;
        }
    }
    cout<<openLocker<<endl;
}
// Time Complexity:O(n)
// Space Complexity:O(n)


void small(int n)
{
    cout<<(int)sqrt(n)<<endl;
}
// Time Complexity:O(1)
// Space :O(1)

int main()
{
    int n;
    cin>>n;
    gymLocker(n);
    gymLocker1(n);
    small(n);
    return 0;
}