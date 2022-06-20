#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> input(n);

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    vector<bool> check_ans(n, false);
    for (int i = 0; i < n; i++)
    {
        if (check_ans[i] == false)
        {
            check_ans[i] = i;
        }
    }

    vector<int> ans(n);
    for (int i = 0; i < check_ans.size(); i++)
    {
        if (check_ans[i] == false)
        {
            ans.push_back(check_ans[i]);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}