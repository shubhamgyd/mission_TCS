#include <bits/stdc++.h>
using namespace std;

void findMissing(int arr[], int n)
{
    int repeat = 0;
    int miss = 0;
    int i = 0;
    while (i < n)
    {
        if (arr[i] == arr[arr[i] - 1])
        {
            i++;
        }
        else
        {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {

        if (arr[i] != i + 1)
        {
            repeat = arr[i];
            miss = i + 1;
            break;
        }
    }
    cout << repeat << " " << miss << endl;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    findMissing(arr, n);
    return 0;
}