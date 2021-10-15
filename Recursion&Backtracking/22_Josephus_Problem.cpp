// Game of death in circle

#include<bits/stdc++.h>
using namespace std;



void solve(int n,int k,vector<int>&arr,int &ans,int index)
{
    if(arr.size()==1)
    {
        ans=arr[0];
        return;
    }
    index=(index+k)%arr.size();

    // killing the k the element starting from the current position
    arr.erase(arr.begin()+index);
    solve(n,k,arr,ans,index);
    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        arr.push_back(i+1);
    }
    // Person to kill by previous man
    //  starting with zero index
    int k;
    cin>>k;
    k--;
    int ans=-1;
    int index=0;
    solve(n,k,arr,ans,index);
    cout<<ans<<endl;
    return 0;
}

/*
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
*/