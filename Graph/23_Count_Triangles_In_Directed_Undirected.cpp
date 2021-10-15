#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;




int32_t main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int n;
    cin>>n;
    vector<vector<int>>graph(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            graph[i][j]=a;
        }
    }
    bool is_undirected=false;     // is graph is undirected graph
    //bool is_directed=true;      // if graph is directed;
    int triangles=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(graph[i][j]&&graph[j][k] && graph[k][i])
                {
                    triangles++;
                }
            }
        }
    }
    is_undirected?triangles/=3:triangles/=6;       //if directed then divide by 3 , else then 6
    cout<<"Total number of triangles formed is : "<<triangles<<endl;
    return 0;
}