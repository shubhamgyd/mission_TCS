/*

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str = "zero";
    int arr[4];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    int total = 1;
    int j = 0;
    while (total < n)
    {
        int res = 1;
        arr[j % n]++;
        for (int i = 0; i < 4; i++)
        {
            res *= arr[i];
        }
        j++;
        total = res;
    }
    int len = 0;
    for (int i = 0; i < 4; i++)
    {
        len += arr[i];
    }
    cout << len << endl;
    return 0;
}