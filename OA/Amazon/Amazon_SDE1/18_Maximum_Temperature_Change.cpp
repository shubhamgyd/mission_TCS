/*
Question 1 - The maximum aggregate temperature change
Alexa is Amazon's virtual AI assistant. It makes it easy to set up your Alexa-enabled devices, listen to music, get weather updates, and much more. The team is working on a new feature that evaluates the aggregate temperature change for a period based on the changes in temperature of previous and upcoming days.

Taking the change in temperature data of n days, the aggregate temperature change evaluated on the ith day is the maximum of the sum of the changes in temperatures until the ith day, and the sum of the change in temperatures in the next (n - i) days, with the ith day temperature change included in both.

Given the temperature data of n days, find the maximum aggregate temperature change evaluated among all the days.

Example
tempChange = [6, -2, 5]

The aggregate temperature change on each day is evaluated as:


For day 1, there are no preceding days' information, but the day itself is included in the calculation. Temperature changes = [6] for the before period.
For succeeding days, there are values [6,-2,5] and 6 + (-2) + 5 = 9. Again, the change for day 1 is included. The maximum of 6 and 9 is 9.
For day 2, consider [6, -2] -> 6 + (-2) = 4, and [-2, 5] -> (-2) + 5 = 3. The maximum of 3 and 4 is 4.
For day 3, consider [6, -2, 5] -> 6 + (-2) + 5 = 9, and [5]. The maximum of 9 and 5 is 9.

The maximum aggregate temperature change is max(9, 4, 9) = 9.

Constraints

1 ≤ n ≤ 105
-109 ≤ tempChange[i] ≤ 109 where, 1 ≤ i ≤ n.
Input Format For Custom Testing

The first line contains an integer, n, the number of elements in tempChange.
Each line i of the n subsequent lines (where 0 ≤ i < n) contains an integer, tempChange[i].
Sample Case 0
Sample Input For Custom Testing
STDIN
3
-1
2
3

tempChange[] size n = 3
tempChange = [-1, 2, 3]

Sample Output
5
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int res[n];
    res[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        res[i]=res[i+1]+arr[i];
    }
    int mx=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        mx=max(mx,res[i]);
    }
    cout<<mx<<endl;
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(n)
