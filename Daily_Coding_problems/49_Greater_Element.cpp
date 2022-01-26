/*
his question is asked by Amazon. Given two arrays of numbers, where the first array 
is a subset of the second array, return an array containing all the next greater 
elements for each element in the first array, in the second array. If there is no 
greater element for any element, output -1 for that number.

Ex: Given the following arrays…

nums1 = [4,1,2], nums2 = [1,3,4,2], return [-1, 3, -1] because no element in nums2 is
 greater than 4, 3 is the first number in nums2 greater than 1, and no element in nums2 
 is greater than 2.
nums1 = [2,4], nums2 = [1,2,3,4], return [3, -1] because 3 is the first greater element 
that occurs in nums2 after 2 and no element is greater than 4.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>num1,num2;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        num1.push_back(a);
        // cin>>num1[i];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        num2.push_back(a);
        // cin>>num2[i];
    }
    vector<int>ans;
    int next=-1;
    for(int i=0;i<n;i++)
    {
        int ind=-1;
        int j=0;
        int val=INT_MIN;
        for(j;j<m;j++)
        {
            if(num1[i]==num2[j])
            {
                ind=j;
                break;
            }
        }

        for(j+1;j<m;j++)
        {
            if(num2[j]>num2[ind])
            {
                val=num2[j];
                break;
            }
        }

        if(ind==-1 || val==INT_MIN)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(val);
        }
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    return 0;
}
// Time Complexity:O(n*m)
// Space Complexity:O(n)