/*
Given an integer denoting a total number of wheels, help Amazon Logistics find the number of 
different ways to choose a fleet of vehicles from an infinite supply of two-wheeled and four 
wheeled vehicles such that the group of chosen vehicles has that exact total number of wheels.
Two ways of choosing vehicles are considered to be different if and only if they contain different 
numbers of two-wheeled or four-wheeled vehicles.

For example, if our array wheels = [4,5,6] our return array would be res = [2, 0, 2]. 
Case by case, we can have 1 four-wheel or 2 two-wheel to have 4 wheels. We cannot have 5 wheels. 
We can have 1 four-wheel and 1 two-wheel or 3 two-wheel vehicles in the final case.

Function Description

Complete the function chooseFleets in the editor below. The function should return an array of
 integers representing the answer for each wheels[i].

chooseFleets has the following parameter(s): wheels[wheels[0].wheels[n-1]): an array of integers
*/

#include<bits/stdc++.h>
using namespace std;

int  main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<int>ans(n);
    for(int i=0;i<n;i++)
    {
        if(nums[i]%2!=0)
        {
            ans[i]=0;
        }
        else
        {
            int twoWheeler=nums[i]/2;
            int fourWheeler=nums[i]/4;
            int res=min(twoWheeler,fourWheeler)+1;
            ans[i]=res;
        }
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;

}


//  def countsubsetsum(coins, n, amount):
//         t = [[0 for i in range(amount+1)] for i in range(n+1)]
//         for row in t:
//             row[0] = 1
        
        
//         for i in range(1, n+1):
//             for j in range(1, amount+1):
                
//                 if coins[i-1] <= j:
//                    t[i][j] = t[i-1][j] + t[i][j-coins[i-1]]
//                 else:
//                     t[i][j] = t[i-1][j]
                    
//         return t[n][amount]

// for num_wheels in ip:
//     ans = []
//     wheels = [2,4]
//     ans.append( countsubsetsum(wheels, n, num_wheels) )