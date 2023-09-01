#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

class Solution
{
public:
    double dist(int x, int y, int a, int b)
    {
        return sqrt((x - a) * (x - a) + (y - b) * (y - b));
    }

    int count_Points(std::vector<int> &dim1, std::vector<int> &dim2)
    {
        int x1 = dim1[0], y1 = dim1[1], r1 = dim1[2];
        int x2 = dim2[0], y2 = dim2[1], r2 = dim2[2];
        int x = -1, y = -1;
        std::deque<std::vector<int>> q;
        q.push_back({x1, y1});
        std::vector<std::vector<bool>> Visited(1001, std::vector<bool>(1001, false)); // Adjust bounds as needed

        while (!q.empty())
        {
            int a = q.front()[0];
            int b = q.front()[1];
            q.pop_front();

            if (dist(a, b, x1, y1) <= r1 && dist(a, b, x2, y2) <= r2)
            {
                x = a;
                y = b;
                break;
            }

            std::vector<std::vector<int>> arr = {{a - 1, b}, {a + 1, b}, {a, b - 1}, {a, b + 1}};
            for (const auto &coord : arr)
            {
                int u = coord[0];
                int v = coord[1];
                if (dist(u, v, x2, y2) < dist(a, b, x2, y2) &&
                    dist(u, v, x1, y1) <= r1 &&
                    !Visited[u][v])
                {
                    Visited[u][v] = true;
                    q.push_back({u, v});
                }
            }
        }

        if (x == -1 && y == -1)
        {
            return 0;
        }

        std::deque<std::vector<int>> q2;
        std::vector<std::vector<bool>> Visit(1001, std::vector<bool>(1001, false)); // Adjust bounds as needed
        int res = 1;
        q2.push_back({x, y});
        Visit[x][y] = true;

        while (!q2.empty())
        {
            int a = q2.front()[0];
            int b = q2.front()[1];
            q2.pop_front();

            std::vector<std::vector<int>> arr = {{a - 1, b}, {a + 1, b}, {a, b - 1}, {a, b + 1}};
            for (const auto &coord : arr)
            {
                int u = coord[0];
                int v = coord[1];
                if (dist(u, v, x1, y1) <= r1 && dist(u, v, x2, y2) <= r2 && !Visit[u][v])
                {
                    res++;
                    Visit[u][v] = true;
                    q2.push_back({u, v});
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution S;
    std::vector<int> c1(3), c2(3);

    for (int i = 0; i < 3; i++)
    {
        std::cin >> c1[i];
    }

    for (int i = 0; i < 3; i++)
    {
        std::cin >> c2[i];
    }

    std::cout << S.count_Points(c1, c2) << std::endl;

    return 0;
}
