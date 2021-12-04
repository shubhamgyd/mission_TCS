#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long


int32_t main()
{
    vector<int>res={3,2,4,5,1,2,5,3,4,6};
    int x=res[0];
    for(int i=1;i<res.size();i++)
    {
        x^=res[i];
    }
    x&=-x;

    int y=0,z=0;
    for(int i=0;i<res.size();i++)
    {
        if((res[i]&x)==0)
        {
            y^=res[i];
        }
        else
        {
            z^=res[i];
        }
    }
    cout<<y<<" "<<z<<endl;
    return 0;
}