#include <bits/stdc++.h>
using namespace std;

int MaxPath(int s,int t,int n,vector<pair<int,int>>adj[])
{
    int distPath[n];
    for(int i=0;i<n;i++) distPath[i]=0; 
    priority_queue<pair<int,int>>pq; vector<bool>vis(n,false);
    distPath[s]=0; pq.push({0,s});
    while(!pq.empty())
    {
        int u=pq.top().second;pq.pop();
        if(vis[u]) continue;
        else
        {
            vis[u]=true;
            for(auto ele:adj[u])
            {
                int v=ele.first,w=ele.second;
                if(distPath[u]+w>distPath[v])
                {
                    distPath[v]=distPath[u]+w; pq.push({distPath[v],v});
                }
                
            }
        }
    }
    return distPath[t]+1;
}

static bool DFSGraph(int src, vector<int> &vis, vector<int> &degree, vector<int> adj[])
{
    vis[src] = 1;
    degree[src] = 1;
    for (auto it=adj[src].begin();it!=adj[src].end();++it)
    {
        if (!vis[*it])
        {
            bool ok = DFSGraph(*it, vis, degree, adj);
            if (ok == true)
            {
                return true;
            }
            // if(DFSGraph(it,vis,degree,adj)) return true;
        }
        else if (degree[*it])
        {
            return true;
        }
        // {
        //     return true;
        // }
    }
    degree[src] = 0;
    return false;
}

static bool DetectCycle(vector<int> adj[], int n)
{
    vector<int> tracker(n, 0);
    vector<int> degree(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!tracker[i])
        {
            if (DFSGraph(i, tracker, degree, adj))
            {
                return true;
            }
        }
    }
    return false;
}

void Adjacents(int i, vector<int> adj[], vector<bool> &temp, vector<int>&ans)
{
    if (temp[i] == true)
    {
        return;
    }
    temp[i] = true;
    if(adj[i].size()==0)
    {
        ans.push_back(i);
    }
    for (auto it:adj[i])
    {
        Adjacents(it, adj, temp, ans);
    }
}

int main()
{
    string str;
    getline(cin, str);
    map<int, vector<int>> mp;
    int i = 0;
    int n = str.length();
    // cout<<n<<endl;
    while (i < n)
    {
        int node = -1;
        if (isdigit(str[i]))
        {
            node = str[i] - '0';

            node--;
            mp[node] = {};
            i += 2;
            int j = i;
            while (str[j] != '}')
            {
                if (isdigit(str[j]))
                {
                    int child = str[j] - '0';
                    child--;
                    mp[node].push_back(child);
                }
                j++;
            }
            j += 3;
            // cout<<j<<" ";
            i = j;
        }
        i++;
    }
    int nodes = mp.size();
    vector<int> adj[10001];
    vector<pair<int,int>>graph[10001];
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        int node = it->first;
        for (auto ele = it->second.begin(); ele != it->second.end(); ++ele)
        {
            adj[*ele].push_back(node);
            graph[*ele].push_back({node,1});
        }
    }
    

    bool isCycle = DetectCycle(adj, nodes+1);
    if (isCycle)
    {
        cout << "error";
    }
    else
    {
        int ct = 0;
        for (int j = 0; j < nodes; j++)
        {
            // if(!temp[j])
            // {
            vector<int>ans;
            vector<bool> temp(nodes, false);
            
            Adjacents(j, adj, temp,ans);
            int cnt1=0;
            for(auto it:ans)
            {
                cnt1=max(cnt1,MaxPath(j,it,nodes,graph));
            }
            ct=max(ct,cnt1);
            
            // }
        }
        cout << ct;
    }
    return 0;
}