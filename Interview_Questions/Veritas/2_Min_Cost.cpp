#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<int> temp;
    int i = 0;
    int j = 0;
    int cost = 0;
    while (arr.size() - i + temp.size() - j > 1)
    {
        int num1, num2;
        if (i < arr.size() && j < temp.size())
        {
            if (arr[i] <= temp[j])
                num1 = arr[i++];
            else
                num1 = temp[j++];
        }
        else if (i < arr.size())
            num1 = arr[i++];
        else if (j < temp.size())
            num1 = temp[j++];
        if (i < arr.size() && j < temp.size())
        {
            if (arr[i] <= temp[j])
                num2 = arr[i++];
            else
                num2 = temp[j++];
        }
        else if (i < arr.size())
            num2 = arr[i++];
        else if (j < temp.size())
            num2 = temp[j++];

        int sum = num1 + num2;
        temp.push_back(sum);
        cost += sum;
    }
    return cost;
}

int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    int ans = minCost(res);
    cout << ans << endl;
}