#include <bits/stdc++.h>
using namespace std;
string findOdd(vector<string> &series)
{
    int n = series.size();
    map<vector<int>, vector<string>> mp;
    for (int i = 0; i < n; i++)
    {
        vector<int> nums;
        string str = series[i];
        for (int j = 0; j < str.length() - 1; j++)
        {
            int num = (str[j + 1] - 'a') - (str[j] - 'a');
            nums.push_back(num);
        }
        mp[nums].push_back(str);
    }
    for (auto it : mp)
    {
        if (it.second.size() == 1)
        {
            return it.second[0];
        }
    }
    return "";
}

int main()
{
    int n;
    cin >> n;
    vector<string> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    cout << findOdd(res) << endl;
    return 0;
}