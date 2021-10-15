// In this problem we are going to find the k'th floor of building(critical  floor) , where egg brreak
// means before k'th floor egg can't break , after k'th floor egg break

#include<bits/stdc++.h>
using namespace std;

int static dp[11][51];

int EggDropping(int egg,int floor)
{
    // Base Case , if egg==0 or floor==1 , means in worst case scenario , we don't need to check anymore
    if(floor==0 || floor==1)
    {
        return floor;
    }
    if(egg==1) // This is worst case , means we haev to check floors from 1st to last i.e at every floor
    {
        return floor;
    }
    if(dp[egg][floor]!=-1)
    {
        return dp[egg][floor];
    }

    // we don't know where k'th floor belong ,so we check it from 1st floor till last
    int mn=INT_MAX; //gives the minimum number of attempts
    for(int k=1;k<=floor;k++)
    {
        int temp=1+max(EggDropping(egg-1,k-1),EggDropping(egg,floor-k)); // Here floor-k means for checking the floor above this value
        // This max for worst case , means maximum number of attempts to check the k'th floor
        // There are different attepmts.
        mn=min(mn,temp);
        // this mn for to find out the minimum form the worse case attepmts .
    }
    return dp[egg][floor]=mn;
}


int main()
{
    // int arr[8]={1,2,3,4,5,6,7,8};
    // int egg=3;
    // int n=8;
    memset(dp,-1,sizeof(dp));
    int egg,n;
    cout<<"Enter number of eggs and number of total floor: ";
    cin>>egg>>n;
    cout<<"Minimum number of attempts to check k'th floor: "<<EggDropping(egg,n)<<endl;
    return 0;
}



/*
It is very important to understand why we are sending (f-k) in case of egg didn't break and again
using a for loop where k is initiated from 1 again.

the reason is we are checking for a range where we are min number of possibly attempt where egg didn't break.

Let's say in simple terms there are 10 floor.
Egg didn't break from 7th floor. So now only 10-7 = 3 floor needs to be checked.
But to check the next 3 floor we need to use a k loop again.
Here k=1 will represent 8th floor.
Here k=2  will represent 9th floor.
Here k=3  will represent 10th floor.

So to answer the initial question , You need to check the min number of attempts in next 3 floors and that is why you are sending (f-k) and k range is (1,f-k)
PS. I was not able to understand for 2 days why we are looping from K=1 again. Putting this explanation out incase someone gets stuck in the same point again.

*/