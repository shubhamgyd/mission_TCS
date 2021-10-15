
#include<bits/stdc++.h>
using namespace std;


int BFS(int src,vector<int>graph[],int n)
{
    vector<bool>visited(n,false);
    int dist[n]={0};
    dist[src]=0;

    queue<int>q;
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(auto it:graph[curr])
        {
            if(visited[it])
            {
                continue;
            }
            else
            {
                visited[it]=true;
                dist[it]=dist[curr]+1;
                q.push(it);
            }
        }
    }
    int mx=0;
    for(int i=0;i<n;i++)
    {
        mx=max(mx,dist[i]);
    }
    return mx;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
   int n;
   cin>>n;
   vector<int>res;
   for(int i=0;i<n;i++)
   {
        int a;
        cin>>a;
        res.push_back(a);
   }

   vector<int>graph[n];
   for(int i=0;i<n;i++)
   {
        if(res[i]==-1)
        {
            continue;
        }
        else
        {
            graph[res[i]].push_back(i);
        }
   }
    int temp=BFS(0,graph,n);
    cout<<temp<<endl;
    return 0;
}
// Time Complexity :O(n+m)
// Space Complexity :O(n)







// Alternative


#include <bits/stdc++.h>
using namespace std;
int levels(int arr[],int n)
{
    int l=0,k1=-1,k2=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=k1){
            k2++;
        }
        else{
            k1+=k2;
            k2=1;
            l++;
        }
    }
    return l;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)    cin>>arr[i];
        cout<<levels(arr,n)<<endl;
    }
}
// Time Complexity :O(n)
// Space Complexity :O(1)