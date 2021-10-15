#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>ans;
        int rem=nums.size()-k;    // minimum number of elements leave so that we can pick up in future
        
        for(auto it:nums)
        {
            // run the loop until stack not empty and the top of stack is greater than current element
            while(ans.size() && rem && it<ans.back())
            {
                ans.pop_back();
                rem--;
            }
            ans.push_back(it);
        }

        // If the size are still greater thean zero( i.e. from remainin elements)
        while(rem)
        {
            ans.pop_back();
            rem--;
        }
        return ans;
    }
};