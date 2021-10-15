#include<bits/stdc++.h>
using namespace std;

vector<int> findPerm(const string A, int B) {
    vector<int>v;
    int i=1,j=B;
    for(int l=0;l<A.size();l++)
    {
        if(A[l]=='D')
        {
            v.push_back(j);
            j--;
        }
        else 
        {
            v.push_back(i);
            i++;
        }
    }
    for(int k=i;k<=j;k++)
    {
        v.push_back(k);
    }
    return v;
}
