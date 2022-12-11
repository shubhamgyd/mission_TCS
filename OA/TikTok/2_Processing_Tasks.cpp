/*
There is a task recorded in the two-dimensional array tasks in the format (start, end, period), indicating that the task needs to be completed within the time range start to end, and period indicates the length of time required to complete the task. Note:

1. The period can be discontinuous time

2. The start and end are included.

3. The computer can handle an unlimited number of tasks at the same time, Please calculate the minimum time that the

computer can process all the tasks.

Example:

Input: tasks = [[1,3,2], [2,5,3], [5,6,2]]

Output: 4

Explanation:

tasks[0] selects time points 2, 3,

tasks[1] selects time points 2, 3, 5. tasks[2] selects time points 5, 6.

So the computer only needs to be on at time points

7,3,5 and 5 to complete the task.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> nums;
    for (int i = 0; i < n; i++)
    {
        vector<int> task(3);
        cin >> task[0] >> task[1] >> task[2];
    }
}