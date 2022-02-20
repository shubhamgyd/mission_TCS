/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"

*/

#include<bits/stdc++.h>
using namespace std;

string solve(int n,int k)
{
    vector<int>ans;
    int fact=1;
    for(int i=1;i<n;i++)
    {
        fact*=i;
        ans.push_back(i);
    }
    ans.push_back(n);
    string res="";
    k-=1;
    while(true)
    {
        res+=to_string(ans[k/fact]);
        ans.erase(ans.begin()+k/fact);
        if(ans.size()==0)
        {
            break;
        }
        k=k%fact;
        fact=fact/ans.size();
    }
    return res;
}
// Time Complexity:O(n*n)
// Space Complexity:O(n)

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<solve(n,k)<<endl;
    return 0;
}