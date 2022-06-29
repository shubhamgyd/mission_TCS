#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    int k;
    cin >> k;
    // Brute Force
    vector<int> temp = res;
    sort(temp.begin(), temp.end());
    cout << "Kth Smallest: " << temp[k - 1] << endl;
    cout << "Kth Largest: " << temp[n - k] << endl;
    // T:O(nlogn)
    // S:O(1)

    // using heap
    // kth Smallest
    priority_queue<int> pq;
    for (auto it : res)
    {
        pq.push(it);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    cout << "Kth Smallest: " << pq.top() << endl;

    // kth Largest
    priority_queue<int, vector<int>, greater<int>> pq1;
    for (auto it : res)
    {
        pq1.push(it);
        if (pq1.size() > k)
            pq1.pop();
    }
    cout << "Kth Largest: " << pq1.top() << endl;
    //     Time complexity: O(k+(n-k)*log(k))  , n = size of array
    // Space complexity: O(k)


    // for O(n) Time Complexity : Refer
    // https://takeuforward.org/data-structure/kth-largest-smallest-element-in-an-array/
}