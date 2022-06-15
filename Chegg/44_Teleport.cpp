#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isReached()
    {
        // Set of obstacles
        vector<vector<int>> obstacles = {{2, 0}, {1, 1}};

        // set of teleportals
        // i,j,k,l
        // i,j->starting cell
        // k,l->ending cell
        vector<vector<int>> tPort = {{0, 2, 0, 1}, {0, 3, 2, 0}};

        //  size of matrix
        int n = 3;
        int m = 4;

        // initial row and col at 0
        int r = 0;
        int c = 0;

        // temporary matrix to track the journey/teleports
        vector<vector<int>> x_new(n, vector<int>(m, -1));
        vector<vector<int>> y_new(n, vector<int>(m, -1));

        // obstacles tracker
        vector<vector<bool>> ob(n, vector<bool>(m));

        // cell tracker
        vector<vector<bool>> vis(n, vector<bool>(m));

        int size = obstacles.size();
        
        // mark the obstacle as true in obstacle tracker
        for (int i = 0; i < size; i++)
        {
            int u = obstacles[i][0];
            int v = obstacles[i][1];
            ob[u][v] = true;
        }

        size = tPort.size();

        // assign the path in teleports trackers
        for (int i = 0; i < size; i++)
        {
            int a, b, c, d;
            // a,b teleport start
            a = tPort[i][0];
            b = tPort[i][1];

            // c,d teleport end
            c = tPort[i][2];
            d = tPort[i][3];

            // create a tunnel
            x_new[a][b] = c;
            y_new[a][b] = d;
        }


        // iteratr from the start column
        for (c; c < m; c++)
        {
            vis[r][c] = true;
            // if we reached to the end of the matrix
            // return true;
            if (r == n - 1 and c == m - 1)
            {
                return true;
            }

            // if there is any obstacle or given cell is already visited
            // intuition behind visited cell is , it tell that this path is not rechable
            if (vis[r][c] or ob[r][c])
            {
                return false;
            }

            // if ther is a path/tunnel, then go through it
            if (x_new[r][c] >= 0 and y_new[r][c] >= 0)
            {
                int temp = r;
                r = x_new[r][c];
                c = y_new[temp][c];
                continue;
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    bool ans=obj.isReached();
    cout<<endl;
    cout<<endl;

    if(ans)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    cout<<endl;
    cout<<endl;
    return 0;
}