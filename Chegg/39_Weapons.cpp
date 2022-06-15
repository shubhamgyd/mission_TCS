#include<bits/stdc++.h>
using namespace std;

/*
Intuition: 
    For every cost array element we have two choices, 
    1. we can make the weapon from this cost with rating
    2. we can ignore and go to the next


Note: We can use same weapon multiple times

*/



// Utility function which return the maximum power 
int maxPower(int W,int n,int val[],int wt[])
{

    // array which store the maximum power till the i'th index
    int dp[W+1];

    // Initially fill all zeros
    memset(dp,0,sizeof dp);

    // Filling DP Table
    for(int i=0;i<=W;i++)
    {
        for(int j=0;j<n;j++)
        {
            //  if remaining cost is greater then the equal to the cost of making weapons
            // then we can make weapong from this rating
            if(wt[j]<=i)
            {
                dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
            }
        }
    }
    // return the max reating power weapon
    return dp[W];
}

int main()
{
    // (p: no of containers, w: no of weapons in each container, 
    // v : total amount of Vibranium available for creating the weapons)
    cout<<"Input: "<<endl;
    int c,w,v;
    cin>>c>>w>>v;

    // cost of container
    int cost_container;
    cin>>cost_container;


    int cost[c*w];       // representing the cost of weapons
    int rating[c*w];     // representing the rating of weapons

    // Input of cost of weapons
    for(int i=0;i<c*w;i++)
    {
        cin>>cost[i];
    }

    // Input of rating of weapons
    for(int i=0;i<c*w;i++)
    {
        cin>>rating[i];
    }

    // we need to minus the cost of container from the total available vibranium
    int piecesToBeMade=v-cost_container;

    // getting maxPower
    int ans=maxPower(piecesToBeMade,c*w,rating,cost);

    // printing power
    cout<<"\nOutput: "<<endl;
    cout<<ans<<endl;


    return 0;
}

// Time Complexity:O((toal_weapons)*(total_amount_vibranium-cost_container))
// Space Complexity:O(total_amount_vibranium-cost_container)

// 2 4 25
// 2 1
// 5 3 4 4
// 2 1 3 5
// 2 9 3 7 
// 5 2 6 5