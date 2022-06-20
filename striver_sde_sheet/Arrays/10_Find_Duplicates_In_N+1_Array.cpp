/*
Problem Statement: Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number, your task is to find the duplicate number.

Examples:

Example 1:

Input: arr=[1,3,4,2,2]

Output: 2

Explanation: Since 2 is the duplicate number the answer will be 2.

Example 2:

Input: [3,1,3,4,2]

Output:3

Explanation: Since 3 is the duplicate number the answer will be 3.
*/

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

    // brute force
    vector<int> temp = res;
    sort(temp.begin(), temp.end());
    set<int> st;
    for (int i = 0; i < n - 1; i++)
    {
        if (temp[i] == temp[i + 1])
        {
            st.insert(temp[i]);
        }
    }
    for (auto it : st)
    {
        cout << it << " ";
    }
    cout << endl;
    /*
    Time Complexity:O(Nlogn + N)

    Reason: NlogN for sorting the array and O(N) for traversing through the array and checking if adjacent elements are equal or not. But this will distort the array.

    Space Complexity:O(1)
    */

    // Using frequency Sort
    int freq[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        if (freq[temp[i]] == 0)
        {
            freq[temp[i]]++;
        }
        else
        {
            cout << temp[i] << " ";
            freq[temp[i]]++;
        }
    }
    cout << endl;
    /*
    Time Complexity: O(N), as we are traversing through the array only once.

    Space Complexity: O(N), as we are using extra space for frequency array.
    */

    // Using Bit Manupulation
    int x_or = temp[0];
    for (int i = 1; i < n; i++)
    {
        x_or ^= temp[i];
    }
    cout << x_or << endl;
    /*
    Time Complexity:O(n)
    Space Coplexity:O(1)
    */

    // Using LinkedList
    // using slow and fast method
    int slow=temp[0];
    int fast=temp[temp[0]];
    while(slow!=fast)
    {
        slow=temp[slow];
        fast=temp[temp[fast]];
    }
    fast=0;
    while(fast!=slow)
    {
        slow=temp[slow];
        fast=temp[fast];
    }
    // slow is an entry point of circle
    cout<<slow<<endl;
    // Time complexity:O(n)
    // Space Complexity:O(1)
}