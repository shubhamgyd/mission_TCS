#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>A(n),B(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }
    vector<int>p;
    sort(A.begin(),A.end());
    for(int i=0;i<n;i++)
    {
        auto it=upper_bound(A.begin(),A.end(),B[i])-A.begin();
        cout<<it<<endl;
        
    }
}