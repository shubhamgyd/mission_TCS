/*
Alexa is given n piles of equal or unequal heights. In one step, Alexa can remove any 
number of boxes from the pile which has the maximum height and try to make it equal to 
the one which is just lower than the maximum height of the stack. Determine the minimum 
number of steps required to make all of the piles equal in height.

Example 1:

Input: piles = [5, 2, 1]
Output: 3
Explanation:
Step 1: reducing 5 -> 2 [2, 2, 1]
Step 2: reducing 2 -> 1 [2, 1, 1]
Step 3: reducing 2 -> 1 [1, 1, 1]
So final number of steps required is 3.
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
    sort(nums.rbegin(),nums.rend());
    int steps=0;
    for(int i=0;i<n-1;i++)
    {
        if(nums[i]!=nums[i+1])
        {
            steps+=(i+1);
        }
    }
    cout<<steps<<endl;
    return 0;
}
// Time Complexity:O(nlogn)
// Space Complxity:O(1)