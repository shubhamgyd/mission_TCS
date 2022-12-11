#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
class point
{
public:
    double x, y;
    point()
    {
    }
    point(double x, double y) : x(x), y(y)
    {
    }
    point operator-(point p)
    {
        return point(x - p.x, y - p.y);
    }
    double operator*(point p)
    {
        return x * p.y - y * p.x;
    }
};

#define eps 1e-8
#define zero(x) (((x) > 0 ? (x) : -(x)) < eps)

double xmult(point p1, point p2, point p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}

point p1, p2;
int graham_cp(const void *a, const void *b)
{
    double ret = xmult(*((point *)a), *((point *)b), p1);
    return zero(ret) ? (xmult(*((point *)a), *((point *)b), p2) > 0 ? 1 : -1) : (ret > 0 ? 1 : -1);
}
void _graham(int n, point *p, int &s, point *ch)
{
    int i, k = 0;
    for (p1 = p2 = p[0], i = 1; i < n; p2.x += p[i].x, p2.y += p[i].y, i++)
        if (p1.y - p[i].y > eps || (zero(p1.y - p[i].y) && p1.x > p[i].x))
            p1 = p[k = i];
    p2.x /= n, p2.y /= n;
    p[k] = p[0], p[0] = p1;
    qsort(p + 1, n - 1, sizeof(point), graham_cp);
    for (ch[0] = p[0], ch[1] = p[1], ch[2] = p[2], s = i = 3; i < n; ch[s++] = p[i++])
        for (; s > 2 && xmult(ch[s - 2], p[i], ch[s - 1]) < -eps; s--)
            ;
}

int graham(int n, point *p, point *convex, int maxsize = 1, int dir = 1)
{
    point *temp = new point[n];
    int s, i;
    _graham(n, p, s, temp);
    for (convex[0] = temp[0], n = 1, i = (dir ? 1 : (s - 1)); dir ? (i < s) : i; i += (dir ? 1 : -1))
        if (maxsize || !zero(xmult(temp[i - 1], temp[i], temp[(i + 1) % s])))
            convex[n++] = temp[i];
    delete[] temp;
    return n;
}

double area(point a, point b, point c)
{
    return fabs((a - c) * (b - c)) / 2;
}

class ElectronicScarecrows
{
public:
    int n;
    int m;
    point ch[100], p[100];
    double dp()
    {
        double mat[100][100];
        double ret = 0;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                mat[i][j] = 0;
                if (j > 0)
                {
                    for (int k = 1; k < i; ++k)
                    {
                        double t = mat[k][j - 1] + area(p[0], p[k], p[i]);
                        if (t > mat[i][j])
                            mat[i][j] = t;
                    }
                }
                if (mat[i][j] > ret)
                    ret = mat[i][j];
            }
        }
        return ret;
    }
    double calc()
    {
        double ret = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                p[(i + j) % n] = ch[j];
            double t = dp();
            if (t > ret)
                ret = t;
        }
        return ret;
    }
    double largestArea(vector<int> x, vector<int> y, int mm)
    {
        n = x.size();
        point p[100];
        for (int i = 0; i < n; ++i)
            p[i] = point(x[i], y[i]);
        n = graham(n, p, ch, 0);
        mm -= 2;
        if (mm > n)
            mm = n;
        m = mm;
        return calc();
    }
};

vector<int> solve(vector<int> A)
{
    vector<int> ans;
    vector<queue<int>> all(A.size() + 1);
    for (int i = 0; i < A.size(); ++i)
        if (A[i] < A.size())
        {
            all[A[i]].push(i);
        }
    for (int i = 0, j = -1; i < A.size(); ++i)
    {
        for (int mex = 0;; ++mex)
        {
            while (!all[mex].empty() && all[mex].front() <= j)
            {
                all[mex].pop();
            }
            if (all[mex].empty())
            {
                ans.push_back(mex);
                j = i;
                break;
            }
            else
            {
                i = max(i, all[mex].front());
            }
        }
    }
    return ans;
}

int main()
{
    ElectronicScarecrows obj;
    int n;
    cin >> n;
    vector<int> res, res1;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        res.push_back(a);
        res1.push_back(b);
    }
    cout << obj.largestArea(res, res1, n) << endl;
}