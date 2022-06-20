/*
Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).

What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

Example 1:

Input Format: N = 5, array[] = {1,2,3,4,5}

Result: 0

Explanation: we have a sorted array and the sorted array
has 0 inversions as for i < j you will never find a pair
such that A[j] < A[i]. More clear example: 2 has index 1
and 5 has index 4 now 1 < 5 but 2 < 5 so this is not an
*/

#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int inv_count = 0;
    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int merge_Sort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = (left + right) / 2;

        inv_count += merge_Sort(arr, temp, left, mid);
        inv_count += merge_Sort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }

    // Brute Force
    // Two for loos to count the pairs
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (res[i] > res[j])
                count++;
        }
    }
    cout << count << endl;
    // Time Complexity:O(n^2)
    // Space Complexity:O(1)

    // using merge sort
    int temp[n];
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = res[i];
    }
    int ans = merge_Sort(arr, temp, 0, n - 1);
    cout << ans << endl;
    // Time Complexity:O(logn)
    // Space Complexity:O(n)

    // Using STL
    vector<int> a(n);
    set<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        st.insert(res[i]);
        auto it = st.lower_bound(res[i]);
        int dist = distance(st.begin(), it);
        a[i] = dist;
    }
    for(auto it:a)
    {
        cout<<it<<" ";
    }
    // Time Complexity:O(nlgon)
    // Space Complexity:O(n)
    cout<<endl;
}