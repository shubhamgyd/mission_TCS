#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>res(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>res[i][j];
        }
    }

    queue<pair<pair<int,int>,int>>q;
    q.push({{0,0},0});
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(res[i][j]==0)
            {
                visited[i][j]=true;
            }
        }
    }


    while(!q.empty())
    {
        auto ele=q.front();
        q.pop();
        if(res[ele.first.first][ele.first.second]==9)
        {
            cout<<ele.second<<endl;
            return 0;
        }
        int x=ele.first.first;
        int y=ele.first.second;
        if(x-1>=0 && !visited[x-1][y])
        {
            q.push({{x-1,y},ele.second+1});
            visited[x-1][y]=true;
        }
        if(x+1<n && !visited[x+1][y])
        {
            q.push({{x+1,y},ele.second+1});
            visited[x+1][y]=true;
        }
        if(y-1>=0 && !visited[x][y-1])
        {
            q.push({{x,y-1},ele.second+1});
            visited[x][y-1]=true;
        }
        if(y+1<m && !visited[x][y+1])
        {
            q.push({{x,y+1},ele.second+1});
            visited[x][y+1]=true;
        }
    }
    cout<<-1<<endl;
    return 0;
}