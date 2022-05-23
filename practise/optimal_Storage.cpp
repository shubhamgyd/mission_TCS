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

    // Solution:1
    double mrt=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<=i;j++)
        {
            sum+=res[j];
        }
        mrt+=sum;
    }
    mrt/=n;
    cout<<mrt<<endl;


    // solution:2
    int prefix[n];
    memset(prefix,0,sizeof(prefix));
    prefix[0]=res[0];
    double temp=prefix[0];
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]+res[i];
        temp+=prefix[i];
    }
    temp/=n;
    cout<<temp<<endl;
    return 0;
}
// Time Complexity:O(n*n)
// Space Complexity:O(1)

// Time Complexity:O(n)
// Space Complexity:O(n)



