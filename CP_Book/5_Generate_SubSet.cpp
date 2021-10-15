// Programm to generate the subsets
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=5;
    vector<int> subset;
    for (int b = 0; b < (1<<n); b++) 
    {
        for (int i = 0; i < n; i++)
        {
            if (b&(1<<i)) 
                subset.push_back(i);
                cout<<i<<" ";
        }
        cout<<endl;
    }
    // for(auto ele:subset)
    // {
    //     cout<<ele<<" ";
    // }
    return 0;
}