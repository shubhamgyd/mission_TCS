#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {

            sum += nums[j];
            if (sum == k)
            {
                for (int k = i; k < j; k++)
                {
                    cout << nums[k] << ",";
                }
                cout << nums[j] << endl;
            }
        }
    }
    return 0;
}