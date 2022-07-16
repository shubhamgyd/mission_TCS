#include <bits/stdc++.h>
using namespace std;

const int num = 100005;
int degree[num];
int findPar(int x)
{
    if (degree[x] < 0)
    {
        return x;
    }
    return degree[x] = findPar(degree[x]);
}
void unionn(int x, int y)
{
    x = findPar(x);
    y = findPar(y);
    if (x == y)
        return;
    if (x < y)
    {
        degree[x] += degree[y];
        degree[y] = x;
    }
    else
    {
        degree[y] += degree[x];
        degree[x] = y;
    }
}

vector<int> getStorage(int connections_nodes, vector<int>connections_from, vector<int>connections_to, vector<int>storage, int threshold)
{
    int sz=connections_from.size();
    int n = sz;
    int cnt = 0;
    for (int i = 0; i < connections_nodes; i++)
    {
        degree[i] = -storage[i];
        if (storage[i] <= threshold)
        {
            cnt++;
        }
    }
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int parentX = findPar(connections_from[i]);
        int val1 = abs(degree[parentX]);
        int parentY = findPar(connections_to[i]);
        int val2 = abs(degree[parentY]);
        if (parentX == parentY)
        {
            ans.push_back(cnt);
            continue;
        }
        unionn(connections_from[i], connections_to[i]);

        int newV = findPar(connections_from[i]);
        newV = abs(degree[newV]);
        if (newV > threshold)
        {
            if (val1 <= threshold)
            {
                cnt--;
            }
            if (val2 <= threshold)
            {
                cnt--;
            }
        }
        else
        {
            cnt--;
        }

        ans.push_back(cnt);
    }
    return ans;
}

int main()
{

    vector<int>dfs={20,-1,5,18,-90,60,53,62,0,61,43,52};
    int x=INT_MIN;
    int a=INT_MIN;
    for(int i=0;i<dfs.size();i++)
    {
        if(x==INT_MIN)
        {
            x=dfs[i];
            continue;
        }

        if(a==INT_MIN)
        {
            if(x<dfs[i])
            {
                a=x;
                x=dfs[i];
                continue;
            }
            else
            {
                if(x==dfs[i])
                {
                    continue;
                }
                a=dfs[i];
                continue;
            }
        }
        if(x==dfs[i])
        {
            continue;
        }

        if(x<dfs[i])
        {
            a=x;
            x=dfs[i];
        }
        else if(x!=dfs[i] and x>=a)
        {
            if(a>dfs[i])
            {
                continue;
            }
            a=dfs[i];
        }
    }
    cout<<x<<" "<<a<<endl;
}