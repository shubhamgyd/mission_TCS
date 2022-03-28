/*
Given a number represented by a list of digits, find the next greater permutation of a number, 
in terms of lexicographic ordering. If there is not greater permutation possible, 
return the permutation with the lowest value/ordering.

For example, the list [1,2,3] should return [1,3,2]. The list [1,3,2] should return [2,1,3]. 
The list [3,2,1] should return [1,2,3].


*/

#include<bits/stdc++.h>
using namespace std;

#define deb(arr) for(auto it: arr) cout<<it<<" ";



int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    if(n==1)
    {
        deb(res);
    }

    int i=n-2;
    while(i>=0 && res[i+1]<=res[i])
    {
        i--;
    }
    if(i>=0)
    {
        int j=n-1;
        while(res[j]<=res[i])
        {
            j--;
        }
        swap(res[i],res[j]);
    }
    reverse(res.begin()+i+1,res.end());
    deb(res);
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(1)