#include <bits/stdc++.h>
using namespace std;

int OPP(int num)
{
    int new_num = 0;
    string str = to_string(num);
    for (int i = 0; i < str.length(); i++)
    {
        if (i % 2 == 0)
        {
            new_num = new_num * 10 + (str[i] - '0');
        }
    }
    return new_num;
}

int count_pairs(vector<int> &arr)
{
    int n = arr.size();
    vector<int> opr_arr;
    for (auto it : arr)
    {
        opr_arr.push_back(OPP(it));
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + opr_arr[j] == arr[j] + opr_arr[i])
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    vector<int> arr = {12345, 6789, 2468, 1357, 8642};
    cout << count_pairs(arr) << endl;
    return 0;
}