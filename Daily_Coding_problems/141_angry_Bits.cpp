/*



You are given an integer, n, and a binary number represented as an integer array, binary. 
Each of the one bits in binary must be separated by at least one zero bit otherwise the bits become angry. 
Return whether or not it’s possible to flip at least n zero bits to one bits without making the bits angry.

Ex: Given the following binary and n…

binary = [1, 0, 0, 1], n = 1, return false.
Ex: Given the following binary and n…

binary = [0, 1, 0, 0, 1, 0, 0, 0, 1], n = 1, return true.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sz;
    cin>>sz;
    vector<int>nums(sz);
    for(int i=0;i<sz;i++)
    {
        cin>>nums[i];
    }
    int n;
    cin>>n;
    int i=1;
    while(i<sz-1 and n)
    {
        if(nums[i]==0 and nums[i-1]==0 and nums[i+1]==0)
        {
            n--;
            nums[i]=1;
        }
        i++;
    }
    if(n)
    {
        cout<<"false"<<endl;
    }
    else
    {
        cout<<"true"<<endl;
    }
    return 0;
}