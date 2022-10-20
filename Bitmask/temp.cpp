#include <bits/stdc++.h>
using namespace std;

int find_max_tip(vector<int> ai, vector<int> bi, int no_of_integers, int X, int Y)
{
    int n = no_of_integers;
    vector<int> c(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ai[i];
        c[i] = bi[i] - ai[i];
    }
    sort(begin(c), end(c), greater<int>());
    long long res = -1;
    for (int i = 0; i < Y; i++)
    {
        sum += c[i];
        if (i >= n - X)
        {
            res = max(res, sum);
        }
    }
    return (int)res;
}

int make_square_plots(int length, int breadth)
{
    int num = length * breadth;
    int g = __gcd(length, breadth);
    int ans = num / (g * g);
    return ans;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << make_square_plots(x, y) << endl;
    // cin >> n >> x >> y;
    // vector<int> a(n), b(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    // for (int i = 0; i < n; i++)
    //     cin >> b[i];
    // cout << find_max_tip(a, b, n, x, y) << endl;
    return 0;
}