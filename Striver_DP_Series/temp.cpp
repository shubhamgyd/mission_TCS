#include<bits/stdc++.h>
using namespace std;

int leastInterval(vector<int> &t, int n)
{
    vector<char>tasks(t.size());
    for(int i=0;i<t.size();i++)
    {
        tasks[i]=((t[i]-1)+'A');
    }
    unordered_map<char, int> mp;
    int count = 0;
    for (auto e : tasks)
    {
        mp[e]++;
        count = max(count, mp[e]);
    }

    int ans = (count - 1) * (n + 1);
    for (auto e : mp)
        if (e.second == count)
            ans++;
    return max((int)tasks.size(), ans);
}

int main()
{
    vector<int>res={1,1,1,2,2,2};
    cout<<leastInterval(res,2)<<endl;
    
    string str;
    cin>>str;
    int n=str.length();

    // Solution 1: Brute Force
    bool ok=false;
    for(int i=1;i<n;i++)
    {
        int zero=0;
        int one=0;
        for(int j=0;j<i;j++)
        {
            if(str[j]=='0') zero++;
            else one++;
            if(one==zero)
            {
                cout<<2*zero<<endl;
                ok=true;
                break;
            }
        }
        if(ok) break;
    }
    if(!ok) {
        cout<<-1<<endl;
    }
    

    // Solution 2: Using Hashing
    unordered_map<int,int>mp;
    int sum=0;
    int start=0;
    mp[0]=-1;
    int range=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='1') sum+=1;
        else sum-=1;
        if(mp.find(sum)==mp.end())
        {
            mp[sum]=i;
        }
        range=i-mp[sum];
    }
    if(range==0)
    {
        cout<<-1<<endl;
    }
    else cout<<range<<endl;
}