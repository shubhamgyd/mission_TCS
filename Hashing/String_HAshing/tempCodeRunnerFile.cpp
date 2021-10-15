#include<bits/stdc++.h>
using  namespace std;

int main()
{
    vector<int>res={8,6,7,1,0};
    sort(res.rbegin(),res.rend());
    do
    {
        for(auto it:res)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }while(prev_permutation(res.begin(),res.end()));
}