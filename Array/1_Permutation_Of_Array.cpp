// In this program we are going to find the lexiographically next permutation of array
#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int>&nums) {
    if(nums.size()==1)
        {
            return nums;
        }
        int i=nums.size()-2;
        while(i>=0 && nums[i+1]<=nums[i])
        {
            i--;
        }
        if(i>=0)
        {
            int j=nums.size()-1;
            while(nums[j]<=nums[i])
            {
                j--;
            }
            swap(nums[j],nums[i]);
            
        }
        reverse(nums.begin()+(i+1),nums.end());
        return nums;
}