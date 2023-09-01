
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *a[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    sort(res.rbegin(), res.rend());
    if (x == n)
    {
        cout << res[x - 1];
    }
    else
    {
        if (res[x - 1] == res[x])
        {
            cout << -1;
        }
        else
        {
            cout << res[x - 1];
        }
    }
    return 0;
}

// MAXI AND
long long maxiAnd(int n, vector<int> &a)
{
    // value possible than any msb
    // kya ho skti h tf

    // 31 gives us the 3
    int minMsb = 31;
    for (int num : a)
    {
        int msbPos = 31 - __builtin_clz(num);
        minMsb = std::min(minMsb, msbPos);
    }

    long long result = (1 << (minMsb + 1)) - 1;
    return result;
}

// Binary Queries

#include <vector>

std::vector<int> binaryQueries(int n, std::vector<int> &a, int q, std::vector<std::vector<int>> &queries)
{
    std::vector<int> result;

    for (const auto &query : queries)
    {
        int left = query[0];
        int right = query[1];
        int x = query[2];

        // Update the array 'A' according to the query
        for (int i = left; i <= right; i++)
        {
            a[i] ^= x;
        }

        // Calculate the bitwise OR for the specified range
        int orResult = a[left];
        for (int i = left + 1; i <= right; i++)
        {
            orResult |= a[i];
        }

        result.push_back(orResult);
    }

    return result;
}

#include <vector>

std::vector<int> binaryQueries(int n, std::vector<int> &a, int q, std::vector<std::vector<int>> &queries)
{
    std::vector<int> result;

    for (const auto &query : queries)
    {
        int left = query[0];
        int right = query[1];
        int x = query[2];

        // Update the array 'A' according to the query
        for (int i = left; i <= right; i++)
        {
            a[i] ^= x;
        }

        // Calculate the bitwise OR for the specified range
        int orResult = a[left];
        for (int i = left + 1; i <= right; i++)
        {
            orResult |= a[i];
        }

        result.push_back(orResult);
    }

    return result;
}

// Score and Cost

#include <vector>
#include <algorithm>

int scoreAndCost(int n, std::vector<int> &a, std::vector<int> &b, int x)
{
    std::vector<std::pair<int, int>> games; // (cost, score) pairs

    for (int i = 0; i < n; i++)
    {
        games.push_back({b[i], a[i]});
    }

    std::sort(games.begin(), games.end());

    int maxCost = -1;
    int totalScore = 0;

    for (int i = 0; i < n; i++)
    {
        totalScore += games[i].second;

        if (totalScore >= x)
        {
            maxCost = games[i].first;
            break;
        }
    }

    return maxCost;
}

// Count Operation
#include <vector>
#include <algorithm>

std::vector<long long> countOperations(int n, std::vector<int> &a, long long x, int q, std::vector<std::vector<int>> &queries)
{
    std::vector<long long> result;

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    for (int i = 0; i < q; i++)
    {
        int k = queries[i][0];
        int y = queries[i][1];

        sum -= a[k];
        sum += y;
        a[k] = y;

        long long operations = std::max((sum + x - 1) / x, 0LL);
        result.push_back(operations);
    }

    return result;
}

// False Memories
#include <iostream>
#include <vector>
using namespace std;

int falseMemories(int n, int m, vector<int> &a)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] % m != 0)
        {
            count++;
        }
    }

    return count;
}

// Directed Soldiers
int directedSoldiers(int n, vector<int> &a)
{
    int rightCount = 0;
    int distractedCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            rightCount++;
        }
        else if (rightCount > 0)
        {
            distractedCount++;
            rightCount--;
        }
    }

    return distractedCount;
}

long long contributions(int n, std::vector<int> &arr)
{
    long long ans = 0;
    std::unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        int rem = arr[i] % 3;
        freq[rem]++;
    }

    for (auto it = freq.begin(); it != freq.end(); ++it)
    {
        int count = it->second;
        ans += (count * (count - 1) / 2);
    }

    return ans;
}

int getTotalFun(int n, int m, const vector<vector<int>> &graph, const vector<int> &f, int tolerance)
{
        vector<int> visited(n, 0);
        int totalFun = 0;
        queue<int> q;
        q.push(0);
        visited[0] = 1;

        while (!q.empty())
    {
                int city = q.front();
                q.pop();
                totalFun |= f[city];

                for (int neighbor : graph[city])
        {
                        if (visited[neighbor] == 0 && tolerance >= 0)
            {
                                q.push(neighbor);
                                visited[neighbor] = 1;
                           
            }
                   
        }
           
    }

        return totalFun;
}
int fightingTraffic(int n, int m, vector<vector<int>> &roads, vector<int> &t, vector<int> &f, int x)
{
        // Write your code here. 
        int low = 0;   // Minimum traffic tolerance
        int high = 1e9; // Maximum traffic tolerance
        int result = -1;

        while (low <= high)
    {
                int mid = low + (high - low) / 2;
                vector<vector<int>> graph(n);

                for (int i = 0; i < m; i++)
        {
                        int city1 = roads[i][0];
                        int city2 = roads[i][1];
                        int traffic = t[i];

                        if (traffic <= mid)
            {
                                graph[city1].push_back(city2);
                                graph[city2].push_back(city1);
                           
            }
                   
        }

                int totalFun = getTotalFun(n, m, graph, f, mid);
                if (totalFun >= x)
        {
                        result = mid;
                        high = mid - 1;
                   
        }
        else
        {
                      low = mid + 1;
                   
        }
           
    }

        return result;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int findParent(vector<int> &parent, int vertex)
{
        if (parent[vertex] != vertex)
        parent[vertex] = findParent(parent, parent[vertex]);
        return parent[vertex];
}

void unionVertices(vector<int> &parent, vector<int> &size, int vertex1, int vertex2)
{
        int root1 = findParent(parent, vertex1);
        int root2 = findParent(parent, vertex2);

        if (root1 != root2)
    {
                if (size[root1] < size[root2])
        {
                        parent[root1] = root2;
                        size[root2] += size[root1];
                   
        }
        else
        {
                        parent[root2] = root1;
                        size[root1] += size[root2];
                   
        }
           
    }
}

int colorfulGraph(int n, int m, vector<vector<int>> &edges, int k, vector<int> &c)
{
        vector<int> parent(n);
        vector<int> size(n, 1);
        unordered_map<int, unordered_set<int>> colorComponents;

        for (int i = 0; i < n; i++)
        parent[i] = i;

        // Separate vertices based on colors
    for (int i = 0; i < n; i++)
        colorComponents[c[i]].insert(i);

        // Merge components within each color
    for (const auto &component : colorComponents)
    {
                int color = component.first;
                const unordered_set<int> &vertices = component.second;
                int representative = *vertices.begin();

                for (int vertex : vertices)
            unionVertices(parent, size, representative, vertex);
           
    }

        int operations = 0;

        // Merge components across different colors
    for (auto &edge : edges)
    {
                int vertex1 = edge[0];
                int vertex2 = edge[1];

                int root1 = findParent(parent, vertex1);
                int root2 = findParent(parent, vertex2);

                if (root1 != root2)
        {
                        operations++;
                        unionVertices(parent, size, root1, root2);
                   
        }
           
    }

        return operations;
}

int main()
{
        int t;
        cin >> t;

        while (t--)
    {
                int n, m, k;
                cin >> n >> m;

                vector<vector<int>> edges(m, vector<int>(2));

                for (int i = 0; i < m; i++)
        {
                        cin >> edges[i][0] >> edges[i][1];
                   
        }

                cin >> k;

                vector<int> c(n);
                for (int i = 0; i < n; i++)
        {
                        cin >> c[i];
                   
        }

                int minOperations = colorfulGraph(n, m, edges, k, c);
                cout << minOperations << endl;
           
    }

        return 0;
}

import java.util.ArrayList;

public
class Solution
{
    static long contributions(int n, int[] a)
    {
        // Write your code here.
        long sum = 0l;
        ArrayList<Integer> arr0 = new ArrayList<Integer>();
        ArrayList<Integer> arr1 = new ArrayList<Integer>();
        ArrayList<Integer> arr2 = new ArrayList<Integer>();
        for (int i = 0; i < a.length; i++)
        {
            if (a[i] % 3 == 0)
            {
                arr0.add(a[i]);
            }
            else if (a[i] % 3 == 1)
            {
                arr1.add(a[i]);
            }
            else
                arr2.add(a[i]);
        }
        for (int i = 0; i < arr0.size(); i++)
        {
            for (int j = i + 1; j < arr0.size(); j++)
            {
                sum += arr0.get(i) ^ arr0.get(j);
            }
        }

        for (int i = 0; i < arr1.size(); i++)
        {
            for (int j = i + 1; j < arr1.size(); j++)
            {
                sum += arr1.get(i) ^ arr1.get(j);
            }
        }

        for (int i = 0; i < arr2.size(); i++)
        {
            for (int j = i + 1; j < arr2.size(); j++)
            {
                sum += arr2.get(i) ^ arr2.get(j);
            }
        }
        return sum;
    }
}

vector<int>
binaryQueries(int n, vector<int> &a,
              int q, std::vector<std::vector<int>> &queries)
{
    std::vector<int> res;
    for (const auto &query : queries)
    {
        int left = query[0];
        int right = query[1];
        int x = query[2];

        for (int i = left; i <= right; i++)
        {
            a[i] ^= x;
        }
        int orResult = a[left];
        for (int i = left + 1; i <= right; i++)
        {
            orResult |= a[i];
        }
        res.push_back(orResult);
    }
    return res;
}

void dfs(int node, const std::vector<std::unordered_set<int>> &graph, std::vector<bool> &visited, const std::vector<int> &c, std::unordered_set<int> &colors, int k)
{
    visited[node] = true;
    colors.insert(c[node]);

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, graph, visited, c, colors, k);
        }
    }
}
int colorfulGraph(int n, int m, std::vector<std::vector<int>> &edges, int k, std::vector<int> &c)
{
    // Write your code here.
    std::vector<std::unordered_set<int>> graph(n + 1);
    std::vector<bool> visited(n + 1, false);

    // Create adjacency list representation of the graph
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].insert(v);
        graph[v].insert(u);
    }

    // Perform DFS traversal starting from each node
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            std::unordered_set<int> colors;
            dfs(i, graph, visited, c, colors, k);
            if (colors.size() < k)
                return false;
        }
    }

    return true;
}

long long superMovement(int n, vector<int> &a, int k)
{
        vector<long long> v(k - 1, INT_MAX);
        long long ans = 0;
        int j = 0;
        for (int i = 0; i < n - 1; i++)
    {
              if (j == k - 1)
        {
                      j = 0;
                      continue;
                 
        }
              long long x = abs(a[i] - a[i + 1]);
              v[j] = min(v[j], x);
               j++;

           
    }
        for (auto i : v)
    {
              ans += i;
           
    }
        return ans;
}

int butterflies(int n, vector<int> &a)
{
    // Write your code here.

    int y = 0, x = 0, ans = 0;
    for (auto c : a)
    {
        if (c == 1)
            x++;
        else
            y++;
    }
    while (x > 0 || y > 0)
    {
        if (x == 0)
        {
            x++;
            y--;
            ans++;
        }
        if (y == 0)
        {
            x -= 2;
            ans++;
        }
        else
        {
            y--;
            ans++;
        }
    }
    return ans;
}

int getTotalFun(int n, int m, const vector<vector<int>> &graph, const vector<int> &f, int tolerance)
{
    vector<int> visited(n, 0);
    int totalFun = 0;
    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while (!q.empty())
    {
        int city = q.front();
        q.pop();
        totalFun |= f[city];

        for (int neighbor : graph[city])
        {
            if (visited[neighbor] == 0 && tolerance >= 0)
            {
                q.push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }

    return totalFun;
}
int fightingTraffic(int n, int m, vector<vector<int>> &roads, vector<int> &t, vector<int> &f, int x)
{
    // Write your code here.
    int low = 0;    // Minimum traffic tolerance
    int high = 1e9; // Maximum traffic tolerance
    int result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        vector<vector<int>> graph(n);

        for (int i = 0; i < m; i++)
        {
            int city1 = roads[i][0];
            int city2 = roads[i][1];
            int traffic = t[i];

            if (traffic <= mid)
            {
                graph[city1].push_back(city2);
                graph[city2].push_back(city1);
            }
        }

        int totalFun = getTotalFun(n, m, graph, f, mid);
        if (totalFun >= x)
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return result;
}

long long maxiAnd(int n, vector<int> &a)
{
    // Write your code here
    sort(a.begin(), a.end());
    long long int ans = 0;
    int i = 0;
    for (int j = 31; j >= 0; j--)
    {
        int x = a[0] >> j;
        if (x & 1)
        {
            i = j;
            break;
        }
    }

    long long int result = 0;
    for (int j = i; j >= 0; j--)
    {
        result += pow(2, j);
    }

    return result;
}

int getTotalFun(int n, int m, const vector<vector<int>> &graph, const vector<int> &f, int tolerance)
{
    vector<int> visited(n, 0);
    int totalFun = 0;
    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while (!q.empty())
    {
        int city = q.front();
        q.pop();
        totalFun |= f[city];

        for (int neighbor : graph[city])
        {
            if (visited[neighbor] == 0 && tolerance >= 0)
            {
                q.push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }

    return totalFun;
}
int fightingTraffic(int n, int m, vector<vector<int>> &roads, vector<int> &t, vector<int> &f, int x)
{
    // Write your code here.
    int low = 0;    // Minimum traffic tolerance
    int high = 1e9; // Maximum traffic tolerance
    int result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        vector<vector<int>> graph(n);

        for (int i = 0; i < m; i++)
        {
            int city1 = roads[i][0];
            int city2 = roads[i][1];
            int traffic = t[i];

            if (traffic <= mid)
            {
                graph[city1].push_back(city2);
                graph[city2].push_back(city1);
            }
        }

        int totalFun = getTotalFun(n, m, graph, f, mid);
        if (totalFun >= x)
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return result;
}

long long maxiAnd(int n, vector<int> &a)
{
    // Write your code here
    sort(a.begin(), a.end());
    long long int ans = 0;
    int i = 0;

    for (int j = 31; j >= 0; j--)
    {
        int x = a[0] >> j;
        if (x & 1)
        {
            i = j;
            break;
        }
    }
    long long int result = 0;
    for (int j = i; j >= 0; j--)
    {
        result += pow(2, j);
    }
    return result;
}

int getTotalFun(int n, int m, const vector<vector<int>> &graph, const vector<int> &f, int tolerance)
{
        vector<int> visited(n, 0);
        int totalFun = 0;
        queue<int> q;
        q.push(0);
        visited[0] = 1;

        while (!q.empty())
    {
                int city = q.front();
                q.pop();
                totalFun |= f[city];

                for (int neighbor : graph[city])
        {
                        if (visited[neighbor] == 0 && tolerance >= 0)
            {
                                q.push(neighbor);
                                visited[neighbor] = 1;
                           
            }
                   
        }
           
    }

        return totalFun;
}
int fightingTraffic(int n, int m, vector<vector<int>> &roads, vector<int> &t, vector<int> &f, int x)
{
        // Write your code here.
        int low = 0;   // Minimum traffic tolerance
        int high = 1e9; // Maximum traffic tolerance
        int result = -1;

        while (low <= high)
    {
                int mid = low + (high - low) / 2;
                vector<vector<int>> graph(n);

                for (int i = 0; i < m; i++)
        {
                        int city1 = roads[i][0];
                        int city2 = roads[i][1];
                        int traffic = t[i];

                        if (traffic <= mid)
            {
                                graph[city1].push_back(city2);
                                graph[city2].push_back(city1);
                           
            }
                   
        }

                int totalFun = getTotalFun(n, m, graph, f, mid);
                if (totalFun >= x)
        {
                        result = mid;
                        high = mid - 1;
                   
        }
        else
        {
                      low = mid + 1;
                   
        }
           
    }

        return result;
}

import java.util.*;
public
class Solution
{
    static int[] buildingBlocks(int n, int m, int[][] links, int[] a, int k, int[] d)
    {
        // Write your code here.
        int[] ans = new int[k];
        List<Set<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++)
            adj.add(new HashSet<>());
        for (int i = 0; i < m; i++)
        {
            adj.get(links[i][0]).add(links[i][1]);
            adj.get(links[i][1]).add(links[i][0]);
        }
        Set<Integer> decay = new HashSet<>();

        for (int i = 0; i < k; i++)
        {
            if (i != 0)
            {
                removeNode(adj, d[i - 1]);
                decay.add(d[i - 1]);
            }
            ans[i] = solve(adj, decay, a);
        }
        return ans;
    }
    static void removeNode(List<Set<Integer>> adj, int node)
    {
        for (int i = 0; i < adj.size(); i++)
        {
            Set<Integer> curr = adj.get(i);

            if (curr.contains(node))
                curr.remove(node);
        }
    }
    static int solve(List<Set<Integer>> adj, Set<Integer> decay, int[] a)
    {
        int ans = 0;
        int[] visited = new int[adj.size()];
        for (int i = 0; i < adj.size(); i++)
        {
            if (decay.contains(i))
                continue;
            else if (visited[i] == 0)
            {
                ans = Math.max(ans, dfs(adj, i, visited, a));
            }
        }
        return ans;
    }

    static int dfs(List<Set<Integer>> adj, int curr, int[] visited, int[] a)
    {
        visited[curr] = 1;
        int ans = a[curr];
        Set<Integer> set = adj.get(curr);
        for (int i : set)
        {
            if (visited[i] == 0)
            {
                ans ^= dfs(adj, i, visited, a);
            }
        }
        return ans;
    }
}

public class Solution
{
    static int[] binaryQueries(int n, int[] a, int q, int[][] queries)
    {
        // Write your code here.
        int[] B = new int[q];
        for (int i = 0; i < q; i++)
        {
            int L = queries[i][0];
            int R = queries[i][1];
            int x = queries[i][2];
            for (int j = L; j <= R; j++)
            {
                a[j] = a[j] ^ x;
            }
            int result = 0;
            for (int j = L; j <= R; j++)
            {
                result |= a[j];
            }
            B[i] = result;
        }
        return B;
    }
}



from typing import *


def falseMemories(n: int, m: int, a: List[int]) -> int:
    count=0
    for i in range(n):
        if a[i]%m!=0:
            count+=1
    return count

n=input()
m=input()
a=[]

result=falseMemories(n,m,a)
print(result)



bool isSafe(const std::vector<std::vector<int>>& board, int row, int col, int N)
{
        // Check if there is a queen in the same column
    for (int i = 0; i < row; i++)
    {
                if (board[i][col] == 1)
        {
                        return false;
                   
        }
           
    }

        // Check if there is a queen in the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
                if (board[i][j] == 1)
        {
                        return false;
                   
        }
           
    }

        // Check if there is a queen in the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
                if (board[i][j] == 1)
        {
                        return false;
                   
        }
           
    }

        return true;
}

bool solveNQueensUtil(std::vector<std::vector<int>> &board, int row, int N)
{
        if (row == N)
    {
              
        for (int i = 0; i < N; i++)
        {
                        for (int j = 0; j < N; j++)
            {
                               return 1;
                           
            }
                       return 0;
                   
        }

            

        // If you need all possible solutions, you can return false to continue searching
        return false;
           
    }

        for (int col = 0; col < N; col++)
    {
              
         
            board[row][col] = 1;

                    // Recursively solve for the next row
            if (terminal defense(board, row + 1, N))
        {
                            return true; // Return if only one solution is needed
                       
        }

                    
            board[row][col] = 0;
               
    }
       
}

    return false;
}

void terminal defense(int N)
{
        std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));

        if (terminal defenseUtil(board, 0, N))
    {
                std::cout << "No solution exists." << std::endl;
           
    }
}

int main()
{
        int N;
        std::cout << "Enter the number of queens (N): ";
        std::cin >> N;

        solveNQueens(N);

        return 0;
}

int scoreAndCost(int n, vector<int> &a, vector<int> &b, int x)
{
    int minCost = INT_MAX;
    int maxScore = 0;

    for (int i = 0; i < n; i++)
    {
        maxScore = max(maxScore, a[i]);
        if (a[i] >= x)
        {
            minCost = min(minCost, b[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int remainingScore = x - a[i];

        if (remainingScore > 0)
        {
            if (maxScore >= remainingScore)
            {
                minCost = min(minCost, b[i]);
            }
        }
    }

    return (minCost == INT_MAX) ? -1 : minCost;
}

#include <vector>
using namespace std;

typedef long long ll;

bool fn(vector<int> &a, vector<int> &b, ll x, ll mid)
{
        int n = a.size();
        vector<int> vis(n, 0);
        ll sum = 0;

        for (int i = 0; i < n; i++)
    {
                if (b[i] <= mid)
        {
                        sum += a[i];
                        vis[i] = 1;
                   
        }
           
    }

        ll mx = 0;

        for (int i = 0; i < n; i++)
    {
                if (!vis[i])
        {
                        mx = max(mx, static_cast<ll>(a[i]));
                   
        }
           
    }

        return sum + mx >= x;
}

int scoreAndCost(int n, vector<int> &a, vector<int> &b, int x)
{
        ll ans = -1;
        ll s = 0, e = 1e9;

        while (s <= e)
    {
                ll mid = (s + e) / 2;

                if (fn(a, b, x, mid))
        {
                        ans = mid;
                        e = mid - 1;
                   
        }
                else
        {
                        s = mid + 1;
                   
        }
           
    }

        return static_cast<int>(ans);
}

#include <vector>
#include <algorithm>

int terminalDefence(int n, int m, std::vector<int> &a, std::vector<int> &h, std::vector<int> &b, int k)
{
    std::sort(a.begin(), a.end());
    int sentinelIdx = 0;

    for (int i = 0; i < n; i++)
    {
        while (sentinelIdx < m && a[sentinelIdx] < b[i])
            sentinelIdx++;

        if (sentinelIdx == m)
            return 1;

        int distanceToLeftMonster = (sentinelIdx > 0) ? b[i] - a[sentinelIdx - 1] : INT_MAX;
        int distanceToRightMonster = (sentinelIdx < m) ? a[sentinelIdx] - b[i] : INT_MAX;
        int distanceToNearestMonster = std::min(distanceToLeftMonster, distanceToRightMonster);

        if (distanceToNearestMonster <= k)
        {
            if (distanceToNearestMonster == distanceToLeftMonster)
            {
                h[sentinelIdx - 1] -= k;
                if (h[sentinelIdx - 1] <= 0)
                    sentinelIdx--;
            }
            else
            {
                h[sentinelIdx] -= k;
                if (h[sentinelIdx] <= 0)
                    sentinelIdx++;
            }
        }
    }

    return
}

public
class Solution
{
    static int buildingBlocks(int n, int m, int[][] links, int[] a, int k, int[] d)
    {
        // Write your code here. int []B=new int[q];

        int[] ans = new int[k];
        List<Set<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++)
            adj.add(new HashSet<>());
        for (int i = 0; i < m; i++)
        {
            adj.get(links[i][0]).add(links[i][1]);
            adj.get(links[i][1]).add(links[i][0]);
        }
        Set<Integer> decay = new HashSet<>();

        for (int i = 0; i < k; i++)
        {
            if (i != 0)
            {
                removeNode(adj, d[i - 1]);
                decay.add(d[i - 1]);
            }
            ans[i] = solve(adj, decay, a);
        }
        return ans;
    }
    static void removeNode(List<Set<Integer>> adj, int node)
    {
        for (int i = 0; i < adj.size(); i++)
        {
            Set<Integer> curr = adj.get(i);

            if (curr.contains(node))
                curr.remove(node);
        }
    }
    static int solve(List<Set<Integer>> adj, Set<Integer> decay, int[] a)
    {
        int ans = 0;
        int[] visited = new int[adj.size()];
        for (int i = 0; i < adj.size(); i++)
        {
            if (decay.contains(i))
                continue;
            else if (visited[i] == 0)
            {
                ans = Math.max(ans, dfs(adj, i, visited, a));
            }
        }
        return ans;
    }

    static int dfs(List<Set<Integer>> adj, int curr, int[] visited, int[] a)
    {
        visited[curr] = 1;
        int ans = a[curr];
        Set<Integer> set = adj.get(curr);
        for (int i : set)
        {
            if (visited[i] == 0)
            {
                ans ^= dfs(adj, i, visited, a);
            }
        }
        return ans;
            
    }
}