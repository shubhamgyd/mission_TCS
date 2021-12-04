#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);                    
        cout.tie(NULL);
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else if (nums[m] < nums[r]) {
                r = m;
            } else {  // if nums[l]==nums[m]==nums[h]
                r--;
            }
        }
        return nums[l];
        
    }
};