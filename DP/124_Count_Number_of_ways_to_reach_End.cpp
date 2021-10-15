
#include <bits/stdc++.h>
using namespace std;


void solve(vector<int>&res,int n)
{
    // count_jump[i] store number of ways
    // arr[i] can reach to the end
    int can_jump[n];
    memset(can_jump,0,sizeof(can_jump));


    // Last element does not require to jump.
    // Count ways to jump for remaining
    // elements
    for(int i=n-2;i>=0;i--)
    {
        // if the element can directly
        // jump to the end
        if(res[i]>=n-i-1)
        {
            can_jump[i]++;
        }

        // add the count of all the elements
        // that can reach to end and arr[i] can
        // reach to them
        for(int j=i+1;j<n && j<=res[i]+i;j++)
        {
            // if element can reach to end then add
            // its count to count_jump[i]
            if(can_jump[j]!=-1)
            {
                can_jump[i]+=can_jump[j];
            }
        }
        if(can_jump[i]==0)
        {
            can_jump[i]=-1;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<can_jump[i]<<" ";
    }
}
// Time Complexity :O(n*n)
// Space Complexity :O(n)



int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n;
    cin>>n;
    vector<int>res;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        res.push_back(a);
    }
    solve(res,n);
	return 0;
}