/*
Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }

    // Approach 1: Find all permutation and search the given input , print the next permutation of found input
    vector<int>ans=res;
    sort(ans.begin(),ans.end());
    vector<vector<int>>temp;
    do
    {
        temp.push_back(ans);
    }while(next_permutation(ans.begin(),ans.end()));

    int ind=-1;
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i]==res)
        {
            ind=i;
            break;
        }
    }
    if(ind==temp.size()-1)
    {
        sort(ans.begin(),ans.end());
        for(auto it:ans) cout<<it<<" ";
    }
    else
    {
        for(auto it:temp[ind+1])
        {
            cout<<it<<" ";
        }

    }
    cout<<endl;

    // Approach 2: inbuild function
    next_permutation(res.begin(),res.end());
    for(auto it:res)
    {
        cout<<it<<" ";
    }



    // Approach 3: 
    /*
    Approach :

    Step 1: Linearly traverse array from backward such that ith index value of the array is less than (i+1)th index value. Store that index in a variable.

    Step 2: If the index value received from step 1 is less than 0. This means the given input array is the largest lexicographical permutation. Hence, we will reverse the input array to get the minimum or starting permutation. Linearly traverse array from backward. Find an index that has a value greater than the previously found index. Store index another variable.

    Step 3: Swap values present in indices found in the above two steps.

    Step 4: Reverse array from index+1 where the index is found at step 1 till the end of the array.
    */
    int k=n-2;
    int l;
    for(k;k>=0;k--)
    {
        if(res[k]<res[k+1])
        {
            break;
        }
    }
    if(k<0)
    {
        reverse(res.begin(),res.end());
    }
    else
    {
        for(l=n-1;l>k;l--)
        {
            if(res[l]>res[k])
            {
                break;
            }
        }
        swap(res[k],res[l]);
        reverse(res.begin()+k+1,res.end());
    }
    /*
    Time Complexity: For the first iteration backward, the second interaction backward and reversal at the end takes O(N) for each, where N is the number of elements in the input array. This sums up to 3*O(N) which is approximately O(N).

    Space Complexity: Since no extra storage is required. Thus, its complexity is O(1).
    */
}