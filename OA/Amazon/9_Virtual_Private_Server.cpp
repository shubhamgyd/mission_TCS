/*
The virtual private server on Amazon's Web Service cloud is used to run programs that help
perform calculations on large data sets. Recently, the performance of some programs has degraded.

Technical support has recommended that processes that consume a lot of main memory should be deleted.
Unfortunately, the command line shell that you use only lets you delete processes that form a single
contiguous segment of a given fixed size. The size of a contiguous segment is the number of contiguous
processes in the main memory.

Find the minimum amount of main memory used by all of your processes in your Instance after you delete
a contiguous segment of processes.

Example

processes[10, 4, 8, 13, 20] m=2

The processes in main memory are visualized below:
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int m;
    cin >> m;
    int windowSum = 0;
    for (int i = 0; i < m; i++)
    {
        windowSum += arr[i];
    }
    int res = sum - windowSum;
    int j = 0;
    for (int i = m; i < n; i++)
    {
        windowSum += arr[i] - arr[j];
        res = min(res, sum - windowSum);
        j++;
    }
    cout << res << endl;
    return 0;
}