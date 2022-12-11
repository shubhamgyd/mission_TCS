#include <iostream>
#include <algorithm>
using namespace std;

int solve(int arr[], int i, int j, int val)
{
    if (i > j)
        return -1;
    if (val >= arr[j])
        return j;
    int mid = (i + j) / 2;
    if (arr[mid] == val)
        return mid;
    if (mid > 0 && arr[mid - 1] <= val && val < arr[mid])
        return mid - 1;
    if (val < arr[mid])
        return solve(arr, i, mid - 1, val);
    return solve(arr, mid + 1, j, val);
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> temp[i];
    }
    sort(temp, temp + n);
    int totalTime = 0;
    int i = 0;
    while (i < n)
    {
        int maxRange = temp[i] + k;
        cout << "mxRange: " << maxRange << endl;
        int ind = solve(temp, i, n - 1, maxRange);
        int items = ind - i + 1;
        cout << "ind: " << ind << endl;
        if (items > m)
        {
            totalTime++;
            i = i + m;
        }
        else
        {
            totalTime++;
            i = ind + 1;
        }
    }
    cout << totalTime << endl;
    return 0;
}