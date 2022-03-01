#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        int top=0;
        int left=0;
        int bottom=n-1;
        int right=m-1;
        vector<int>v;
        int val=0;
        while(top<=bottom && left<=right)
        {
            if(val==0)
            {
                for(int i=left;i<=right;i++)
                {
                    v.push_back(a[top][i]);
                    val++;
                }
                top++;
                val=1;
            }
            else if(val==1)
            {
                for(int i=top;i<=bottom;i++)
                {
                    v.push_back(a[i][right]);
                    val++;
                }
                right--;
                val=2;
            }
            
            else if(val==2)
            {
                for(int i=right;i>=left;i--)
                {
                    v.push_back(a[bottom][i]);
                    val++;
                }

                bottom--;
                val=3;
            }
            else if(val==3)
            {
                for(int i=bottom;i>=top;i--)
                {
                    v.push_back(a[i][left]);
                    val++;
                }
                left++;
                val=0;
            }
        }
        return v;
        
    }
};