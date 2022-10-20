#include <bits/stdc++.h>
using namespace std;

bool Check(int arr[], int speed, int n, int hours)
{
    int totalHourSpent = 0;
    for (int i = 0; i < n; i++)
    {
        totalHourSpent += ceil((double)arr[i] / (double)speed);
    }
    return totalHourSpent <= hours ? true : false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for (auto &it : arr)
        cin >> it;
    int hours;
    cin >> hours;
    sort(arr, arr + n);
    int low = 1;
    int high = arr[n - 1];
    while (low < high)
    {
        int speed = (high + low) / 2;
        bool canEat = Check(arr, speed, n, hours);
        if (canEat)
        {
            high = speed;
        }
        else
        {
            low = speed + 1;
        }
    }
    cout << high << endl;
    return 0;
}