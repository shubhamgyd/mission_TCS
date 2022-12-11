/*
There is an array of n integers called num. The array can be reduced by element by performing a move. Each move consists of the following three steps:

1. Pick two different elements num and num

2. Remove the two selected elements from the array

3. Add the sum of the two selected elements to the end of the array

Each move has a cost associated with it the sum of the two elements removed from the array during the move. Calculate the minimum total cost of reducing the array to one element.

Example num [4.68]

Remove 4 and 6 in the first move at a cost of 4-6-10 and the resultant array is num (8,10) Remove 8 and 10 in the second move at a cost of 8-10-18 and the resultant array is num=[18]

The total cost of reducing this array to one element using this sequence of moves is 10 18-28 This is just one set of possible moves. For instance, one could have started with 4 and 8 Then 4-8-12 num -[6.1216-12-18, num=118) cost-12-18-30

Function Description Complete the function reductionCost in the editor bel

reduction Cost has the following parameters int numin) an array of integers
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        pq.push(arr[i]);
    }
    int cost = 0;
    while (pq.size() != 1)
    {
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        cost += (num1 + num2);
        pq.push(num1 + num2);
    }
    cout << cost << endl;
    return 0;
}
// Time Complexity:O(nlogn)
// Space Complexity:O(n)