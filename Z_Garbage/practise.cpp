#include<bits/stdc++.h>
using namespace std;


int maxSubArraySum(vector<int>&a, int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
       start =0, end = 0, s=0;

    for (int i=0; i< size; i++ )
    {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    int sum=max_so_far;
    int mn=INT_MAX;
    int len=0;
    cout<<start<<" "<<end<<endl;
    for(int i=start;i<end;i++)
    {
        mn=min(a[i],mn);
        len++;
    }
    int ans=sum+mn*len;
    return ans;
    
}

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int ans=maxSubArraySum(res,n);
    cout<<ans<<endl;
    return 0;

}