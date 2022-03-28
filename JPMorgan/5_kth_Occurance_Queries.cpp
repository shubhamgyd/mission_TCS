#include<bits/stdc++.h>
using namespace std;

int kthoccurence(vector<int>& arr, int fn, int k)
{
    for(int i = 0;i<arr.size();i++)
    {
        if(arr[i] == fn)
        {
            k--;
        }
        if(k == 0)
        {
            return i+1;
        }
    }
    return -1;
}