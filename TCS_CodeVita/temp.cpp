#include<bits/stdc++.h>
using namespace std;

#define lli long long int
#define llu unsigned long long int
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())
const lli MOD = 1e9 + 7;
 
lli n, logn = 18;
vector<vector<lli>> adj, dp;
vector<lli> level, ht;
vector<bool> vis;
 
struct anss {
    lli a, b, c;
};
 
// storing 2^j th parent of i with dfs
void dfs(lli a) {
    for (auto val : adj[a]) {
        if (vis[val] == 0) {
            vis[val] = 1;
            dp[val][0] = a;
            for (lli j = 1; j <= logn; j++) {
                dp[val][j] = dp[dp[val][j - 1]][j - 1];
            }
            ht[val] = ht[a] + 1;
            dfs(val);
        }
    }
}
 
lli lca(lli a, lli b) {
    if (ht[a] < ht[b]) {
        swap(a, b);
    }
 
    if (ht[a] != ht[b]) {
        for (lli i = logn; i >= 0; i--) {
            if (dp[a][i] == 0) {
                continue;
            }
            lli val = dp[a][i];
            if (ht[val] >= ht[b]) {
                a = val;
            }
        }
    }
 
    if (a == b) {
        return a;
    }
 
    for (lli i = logn; i >= 0; i--) {
        if (dp[a][i] == 0 || dp[b][i] == 0) {
            continue;
        }
        if (dp[a][i] != dp[b][i]) {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}
 
lli dist(lli a, lli b) {
    lli ancestor = lca(a, b);
    lli dis = level[a] + level[b] - 2 * (level[ancestor]);
    return dis;
}
 
int maximumProfit(vector<vector<lli>>edges) {
    n=edges.size()+1;
    lli a, b;
    adj.resize(n + 2);
    level.resize(n + 2, 0);
    dp.resize(n + 2, vector<lli>(logn + 2, 0));
 
    for (lli i = 0; i < n-1; i++) {
        lli a=edges[i][0];
        lli b=edges[i][1];
        adj[a].pb(b);
        adj[b].pb(a);
    }
 
    queue<lli> qu;
    vis.resize(n + 3, 0);
    vis[1] = 1;
    level[1] = 1;
    qu.push(1);
 
    lli node1 = 1, node2 = 1;
    lli mx = 0;
 
    // first BFS
    while (!qu.empty()) {
        a = qu.front();
        qu.pop();
        for (auto val : adj[a]) {
            if (!vis[val]) {
                vis[val] = 1;
                level[val] = level[a] + 1;
                if (level[a] > mx) {
                    mx = level[a];
                    node1 = val;
                }
                qu.push(val);
            }
        }
    }
 
    // second BFS
    vis.clear();
    vis.resize(n + 2, 0);
    vector<lli> tmp_level(n + 2, 0);
    vis[node1] = 1;
    tmp_level[node1] = 1;
    qu.push(node1);
    mx = 0;
 
    while (!qu.empty()) {
        a = qu.front();
        qu.pop();
        for (auto val : adj[a]) {
            if (!vis[val]) {
                vis[val] = 1;
                tmp_level[val] = tmp_level[a] + 1;
                if (tmp_level[a] > mx) {
                    mx = tmp_level[a];
                    node2 = val;
                }
                qu.push(val);
            }
        }
    }
 
    vis.clear();
    vis.resize(n + 2, 0);
    vis[1] = 1;
    ht.resize(n + 2, 0);
    ht[1] = 0;
    dfs(1);
 
    set<lli> st;
    vector<lli> deg(n + 2, 0);
 
    for (lli i = 1; i <= n; i++) {
        deg[i] = adj[i].size();
        if (i != node1 && i != node2 && deg[i] == 1) {
            st.insert(i);
        }
    }
 
    vis.clear();
    vis.resize(n + 2, 0);
    lli ans = 0;
    vector<struct anss> fin;
 
    while (!st.empty()) {
        auto it = st.begin();
        lli val = *it;
        vis[val] = 1;
        lli dis1 = dist(node1, val);
        lli dis2 = dist(node2, val);
        if (dis1 > dis2) {
            ans += dis1;
            fin.pb({node1, val, val});
        } else {
            ans += dis2;
            fin.pb({node2, val, val});
        }
 
        st.erase(it);
        for (auto vv : adj[val]) {
            if (vv != node1 && vv != node2 && vis[vv] == 0) {
                deg[vv]--;
                if (deg[vv] == 1) {
                    st.insert(vv);
                }
            }
        }
    }
 
    st.insert(node2);
    while (!st.empty()) {
        auto it = st.begin();
        lli val = *it;
        if (val == node1) {
            break;
        }
        vis[val] = 1;
        lli dis1 = dist(node1, val);
        ans += dis1;
        fin.pb({node1, val, val});
        st.erase(it);
        for (auto vv : adj[val]) {
            if (vis[vv] == 0) {
                deg[vv]--;
                if (deg[vv] == 1) {
                    st.insert(vv);
                }
            }
        }
    }
    return ans;
}

int main()
{
    lli num;
    cin>>num;
    vector<vector<lli>>res;
    for(int i=0;i<num-1;i++)
    {
        lli a,b;
        cin>>a>>b;
        vector<lli>temp;
        temp.push_back(a);
        temp.push_back(b);
        res.push_back(temp);
    }
    cout<<maximumProfit(res)<<endl;
}