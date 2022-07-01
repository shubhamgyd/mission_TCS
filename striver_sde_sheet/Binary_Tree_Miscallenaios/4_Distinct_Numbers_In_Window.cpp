#include<bits/stdc++.h>
using namespace std;



vector<int> dNums(vector<int> &A, int B) {
    int n=A.size();
    vector<int>ans;
    if(B>n) return ans;
    unordered_map<int,int>mp;
    int i=0,j=0;
    while(j<n)
    {
        mp[A[j]]++;
        if(B==j-i+1)
        {
            ans.push_back(mp.size());
        }
        else if(j-i+1>B)
        {
            mp[A[i]]--;
            if(mp[A[i]]==0)
            {
                mp.erase(A[i]);
            }
            ans.push_back(mp.size());
            i++;
        }
        j++;
    }
    return ans;
}
