#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int fact(int n)
{
    int prod=1;
    for(int i=1;i<=n;i++)
    {
        prod*=i;
    }
    return prod%mod;
}

int main()
{
    int n;
    cin>>n;
    vector<int>adj[n+1];
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<bool>visited(n+1,false);
    queue<int>q;
    q.push(1);
    int sum=1;
    int last=0;
    int level=1;
    // visited[1]=true;
    while(!q.empty())
    {
        int sz=q.size();
        // cout<<sz<<endl;
        last=sz;
        sum=((sum%mod)*(fact(sz)%mod))%mod;
        while(sz--)
        {
            int u=q.front();
            q.pop();
            if(!visited[u])
            {
                // cout<<"level: "<<level<<"->";
                visited[u]=true;
                for(auto it:adj[u])
                {
                    if(!visited[it])
                    {
                        // cout<<it<<" ";
                        q.push(it);
                    }
                }
                // cout<<endl;
            }
        }
        level++;
    }
    // sum=(sum/fact(last));
    cout<<sum%mod;
    return 0;
}