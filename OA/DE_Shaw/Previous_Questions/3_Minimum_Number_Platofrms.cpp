/*
Given the arrival and departure times of all trains that reach a railway station,
the task is to find the minimum number of platforms required for the railway station
so that no train waits. We are given two arrays that represent the arrival and departure
times of trains that stop.
*/

// this problem is based on the number of overlapping intervals

// Brute Force
// C++ program to implement the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of platforms
// required
int findPlatform(int arr[], int dep[], int n)
{
    // plat_needed indicates number of platforms
    // needed at a time
    int plat_needed = 1, result = 1;

    // Run a nested for-loop to find the overlap
    for (int i = 0; i < n; i++)
    {

        // Initially one platform is needed
        plat_needed = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                // Increment plat_needed when there is an
                // overlap
                if (arr[i] >= arr[j] && dep[j] >= arr[i])
                    plat_needed++;
        }

        // Update the result
        result = max(plat_needed, result);
    }
    return result;
}

// Driver Code
int main()
{

    // Train 1 => Arrival : 01:00, Departure : 09:00
    // Train 2 => Arrival : 03:00, Departure : 04:00
    // Train 3 => Arrival : 05:00, Departure : 06:00
    int arr[] = {100, 300, 500};
    int dep[] = {900, 400, 600};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findPlatform(arr, dep, n);
    return 0;
}

// Optimize

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int apart[n];
    for (int i = 0; i < n; i++)
    {
        cin >> apart[i];
    }
    int depart[n];
    for (int i = 0; i < n; i++)
    {
        cin >> depart[i];
    }
    vector<pair<int, int>> train;
    for (int i = 0; i < n; i++)
    {
        train.push_back({apart[i], depart[i]});
    }
    sort(begin(train), end(train));
    int cnt = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(train[0].second);
    for (int i = 2; i < n; i++)
    {
        if (train[i].first <= pq.top())
        {
            ++cnt;
        }
        else
        {
            pq.pop();
        }
        pq.push(train[i].second);
    }
    cout << cnt << endl;
    return 0;
}

/*
Time Complexity: O(N*log(N)), Heaps take log(n) time for pushing element and there are n elements.
Auxiliary Space: O(N), Space required by heap to store the element.
*/