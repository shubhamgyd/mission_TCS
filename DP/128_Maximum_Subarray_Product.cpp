#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod=nums[0];
        
        for(int i=1,imax=max_prod,imin=max_prod;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                swap(imax,imin);
            }
            imax=max(nums[i],imax*nums[i]);
            imin=min(nums[i],imin*nums[i]);
            max_prod=max(max_prod,imax);
            cout<<"Max: "<<imax<<endl;
            cout<<"Min: "<<imin<<endl;
        }
        return max_prod;
    }
};