#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>player(n);
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>player[i].first;
        player[i].second=i+1;
        nums[i]=player[i].first;
    }
    vector<int>ans;
    sort(player.begin(),player.end());
    vector<int>prefix(n,0);
    prefix[0]=player[0].first;
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]+player[i].first;
    }
    for(int i=0;i<n;i++)
    {
        int sum=prefix[i];
        int ind=i;
        bool ok=true;
        while(ind<=n)
        {
            
            auto it=upper_bound(prefix.begin(),prefix.end(),sum)-prefix.begin();
            auto it1=upper_bound(prefix.begin(),prefix.end(),sum+1)-prefix.begin();
            if(it==ind)
            {
                if(prefix[it]<nums[it+1])
                {
                    ok=false;
                    break;
                }
                else
                {
                    ind=it;
                    sum=prefix[ind];
                }
            }
            if(it1>ind)
            {
                ind=it1;
                sum=prefix[ind];
            }
            if(!ok)
            {
                break;
            }
        }
        if(ok)
        {
            ans.push_back(player[i].second);
        }
    }
    if(ans.size())
    {
        cout<<ans.size()<<endl;
        sort(ans.begin(),ans.end());
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return 0;
    }
    cout<<0<<endl;
    return 0;

}