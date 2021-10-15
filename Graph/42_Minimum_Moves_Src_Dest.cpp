#include<bits/stdc++.h>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

bool isValid(int x, int y, int r, int c){
    if(x>=0 && x<r && y>=0 && y<c) return true;
    return false;
}

int BFS(vector<vector<int>>&g, int i, int j){
    int r=g.size(),c=g[0].size();
    /// pair<pair<x-coordinate,y-coordinate>,depth>  depth is the distance of the node from source node
    queue<pair<pair<int,int>,int>> q;
    q.push({{i,j},0});  /// initialising queue with source node
    while(!q.empty()){
        int qsize=q.size();
        /// push all valid neighbours of the front in the queue
        while(qsize--){
            auto p=q.front();q.pop();
            int px=p.first.first,py=p.first.second;
            int depth=p.second;
            if(g[px][py]==2) return depth;  /// destination reached yay !!
            for(int k=0;k<4;k++){ /// checking all neighbours
                int nx=dx[k]+px;
                int ny=dy[k]+py;
                if(isValid(nx,ny,r,c) && g[nx][ny]!=0){
                    q.push({{nx,ny},depth+1}); /// pushing valid nodes in queue
                }
            }
        }
    }
    /// destination node is not found or is unreachable
    return -1;
}
// Time Complexity :O(n*n)
// Space Complexity :O(n)



int minSteps(vector<vector<int>>&g){
    int r=g.size(),c=g[0].size(); /// size of matrix
    int x,y;  /// to store the source coordinates
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(g[i][j]==1){
                x=i;y=j;break;
            }
        }
    }
    /// call BFS with these source coordinates
    return BFS(g,x,y);
}

int main(){
    int t;cin>>t; // test cases
    while(t--){
        int r,c;cin>>r>>c;  /// size of matrix
        vector<vector<int>> g(r,vector<int>(c)); /// declaring matrix

        /// input matrix
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++) cin>>g[i][j];
        }
        /// call minSteps function to compute answer
        cout<<minSteps(g)<<endl;
    }
}


















// Recursive Solution

#include <bits/stdc++.h>
using namespace std;

set<int>st;
void Step(int step,int x1,int y1,int x2,int y2,vector<vector<int>>&res,int n)
{
    if(x1<0 || x1>=n || y1<0 || y1>=n)
    {
        return;
    }
    if(res[x1][y1]==0)
    {
        return;
    }
    if(x1==x2 && y1==y2)
    {
        st.insert(step);
        return;
    }
    res[x1][y1]=0;
    step++;
    Step(step,x1+1,y1,x2,y2,res,n);
    Step(step,x1-1,y1,x2,y2,res,n);
    Step(step,x1,y1+1,x2,y2,res,n);
    Step(step,x1,y1-1,x2,y2,res,n);
    res[x1][y1]=3;
}

void solve(int n)
{
    vector<vector<int>>res(n,vector<int>(n));
    int x1,y1,x2,y2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int a;
            cin>>a;
            res[i][j]=a;
            if(a==1)
            {
                x1=i;
                y1=j;
            }
            else if(a==2)
            {
                x2=i;
                y2=j;
            }
        }
    }

    Step(0,x1,y1,x2,y2,res,n);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    int n;
    cin>>n;
    solve(n);
    auto it=st.begin();
    cout<<*it<<endl;
	return 0;
}