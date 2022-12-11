#include <bits/stdc++.h>
using namespace std;

int calculatesum(int n1, int n2)
{
    vector<int> nums;
    for (int i = n1; i < n2; i++)
    {
        if (i > 1)
        {
            bool isPrime = true;
            for (int j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
            {
                nums.push_back(i);
            }
        }
    }
    if (nums.size() == 1)
        return nums[0];
    int sum = 0;
    int largest = nums[nums.size() - 1];
    for (int i = 0; i < nums.size() - 1; i++)
    {
        sum += largest - nums[i];
    }
    return sum;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    cout << calculatesum(n1, n2) << endl;
    return 0;
}