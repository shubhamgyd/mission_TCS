#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    sort(res.begin(),res.end());
    for(auto it:res)
    {
        cout<<it<<" ";
    }
    return 0;
}
/*
Time Complexity:O(nlogn)
Auxilary Space : O(1)



Input and Output:
Input:
5
4 2 8 3 1


Output:
1 2 3 4 8 


*/