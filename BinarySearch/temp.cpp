#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int  long long 
using namespace std;
#define endl '\n'
#define repFor(i, n) for (int i = 0; i < n; i++)
#define repiFor(i, x, n) for (int i = x; i < n; i++)




void DFS(int src,vector<int>adj[],vector<bool>&visited,int &end)
{
    end=src;
    if(visited[src]) return;
    visited[src]=true;
    for(auto it:adj[src])
    {
        DFS(it,adj,visited,end);
    }
}

void solve()
{
    int n, m, x1, x2, y1, y2;
    cin >> n >> m;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    x1--;x2--;y1--; y2--;
    if (((x1 + y1) % 2) != ((x2 + y2) % 2))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int temp1 = (i + j) % 2;
                if (temp1 == (x1 + y1) % 2) cout << 1 << " ";
                else cout << 2 << " ";
            }
            cout << endl;
        }
        return;
    }
    
    int resArr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int temp1 = (i + j) % 2;
            if (temp1 == (x1 + y1) % 2) resArr[i][j]=1;
            else resArr[i][j]=2;
        }
    }
    resArr[x1][y1]=1;resArr[x2][y2]=2;

    if (x2>0) resArr[x2-1][y2]=3;
    if (x2<n-1) resArr[x2+1][y2]=3;
    if (y2>0) resArr[x2][y2-1]=3;
    if (y2<m-1) resArr[x2][y2+1]=3;
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           cout<<resArr[i][j]<<" ";
       }
       cout<<endl;
   }

}


int best_cumulative_sum(int arr[],int N,int K) 
{ 
    set<int> cumulativeSet; 
    cumulativeSet.insert(0); 
 
    int max_sum=INT_MIN,currentSum=0; 
 
    for(int i=0;i<N;i++) 
    { 
        currentSum+=arr[i]; 
        set<int>::iterator sit=cumulativeSet.upper_bound(currentSum-K); 
        if(sit!=cumulativeSet.end())
        {
            max_sum=max(max_sum,currentSum-*sit); 
        }
        cumulativeSet.insert(currentSum); 
    }
    return max_sum; 
} 

signed main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    fast();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}