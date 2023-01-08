/*
 In order to reduce the water bill in hissociety, You decided to switch to a new water supply system.

You are given an array TargetWaterSupply of size N denoting the target monthly water consumption in liters of N houses.

At the start of the month, let' say that all the houses have 0 liters of water present. You came accross a unique water supply system where he can do 2 operations:

Increase the quantity of a specific house by 1 liter.

Double the quantity of all houses.

To avoid wastage, you want the exact amount of water to be generated as required by the houses. To minimize the bill he needs to achieve this task in minimum no. of operations. Write a code to achieve that.

Constrains:

0<=N<=4*10^5.

0<= TargetWaterSupply[i] <=10^9.

Example 1:

Input

TargetWaterSupply=[1,5,4,8]

Output

8

Explanation:

operation 1: [0,0,0,1] operation 2: [0,0,0,2] operation 3: [0,0,1,2] operation 4: [0,1,1,2] operation 5: [0,2,2,4] operation 6: [0,4,4,8] operation 7: [0,5,4,8] operation 8: [1,5,4,8]

Example 2:

Input

TargetWaterSupply=[]

Output

0

Example 3:

Input

TargetWaterSupply=[0]

Output

0


we can also solve by reverse
what we can do is we will traverse all elements and check ii it is odd element decrease element by 1. now in next step we will only have even elements we can divide all by 2. we will again repeat step one if anyone is odd. and the step 2. so on.
Complexity will be nlogn because at alternate step we are dividing element by 2.

*/

#include <bits/stdc++.h>
using namespace std;

int MinOperations(vector<int> &TargetWaterSupply)
{
    sort(TargetWaterSupply.begin(), TargetWaterSupply.end());
    int ans = 0, maxDouble = 0;
    for (int ele : TargetWaterSupply)
    {
        int inc = 0, multiply = 0;
        while (ele > 0)
        {
            if (ele % 2 == 0)
            {
                multiply++;
                ele /= 2;
            }
            else
            {
                inc++;
                ele--;
            }
        }
        if (multiply > maxDouble)
        {
            maxDouble = multiply;
        }
        else
            multiply = 0;
        ans += inc + multiply;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}