/*
You are given an integer array nums. In one move, you can choose one element of nums and 
change it by any value.

Return the minimum difference between the largest and smallest value of nums after 
performing at most three moves.

Example 1:

Input: nums = [5,3,2,4]
Output: 0
Explanation: Change the array [5,3,2,4] to [2,2,2,2].
The difference between the maximum and minimum is 2-2 = 0.
Example 2:

Input: nums = [1,5,0,10,14]
Output: 1
Explanation: Change the array [1,5,0,10,14] to [1,1,0,1,1]. 
The difference between the maximum and minimum is 1-0 = 1.
*/

/*
Intuition
If we can do 0 move, return max(A) - min(A)
If we can do 1 move, return min(the second max(A) - min(A), the max(A) - second min(A))
and so on.


Explanation
We have 4 plans:

kill 3 biggest elements
kill 2 biggest elements + 1 smallest elements
kill 1 biggest elements + 2 smallest elements
kill 3 smallest elements
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    // case 1:
    int num1=nums[n-4]-nums[0];

    // case 2:
    int num2=nums[n-3]-nums[1];

    // case 3:
    int num3=nums[n-2]-nums[2];

    // case 4:
    int num4=nums[n-1]-nums[3];

    cout<<min({num1,num2,num3,num4})<<endl;
}