/*

Given an int array nums of length n. Split it into strictly decreasing subsequences. Output the min number of subsequences you can get by splitting.

Example 1:

Input: [5, 2, 4, 3, 1, 6]
Output: 3
Explanation:
You can split this array into: [5, 2, 1], [4, 3], [6]. And there are 3 subsequences you get.
Or you can split it into [5, 4, 3], [2, 1], [6]. Also 3 subsequences.
But [5, 4, 3, 2, 1], [6] is not legal because [5, 4, 3, 2, 1] is not a subsuquence of the original array.
Example 2:

Input: [2, 9, 12, 13, 4, 7, 6, 5, 10]
Output: 4
Explanation: [2], [9, 4], [12, 10], [13, 7, 6, 5]
Example 3:

Input: [1, 1, 1]
Output: 3
Explanation: Because of the strictly descending order you have to split it into 3 subsequences: [1], [1], [1]
*/


/*
Intuition:
    The number of decreasing subsequence partitions is equal to the length of the longest 
    non-decreasing subsequence, because every non-decreasing number represents a point where 
    a continuation of a previous decreasing subsequence is impossible. We don't care what the 
    subsequences are, so the length is enough to tell us how many times a new decreasing 
    subsequence is required.



    Technically the reason given here shows that the minimum number of needed decreasing 
    sequences is at least equal to the length of longest non-decreasing subsequence, 
    so one still has to show that a solution can be constructed given the length of longest 
    non-decreasing subsequence.
    It can be done by contradiction as your name suggested. Assuming that there exists a 
    sequence for which the length of longest non-increasing subsequence is k, and the 
    minimum number of decreasing subsequences needed is however larger than k. 
    Without loss of generality, assuming that A[0], ..., A[n] can be covered in k 
    decreasing subsequences, but there is no valid way to do so for A[0], ..., A[n], A[n+1]. 
    One can construct the k decreasing subsequences for A[0] -> A[n] such that the tail 
    (smallest) element of each decreasing subsequence can form a non-decreasing subsequence, 
    which can lead to a non-decreasing subsequence of length k+1 when combined with A[n+1], 
    and that contradicts the assumption.
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    // Problem of longest increasing subsequences
    set<int>st;
    for(auto it:nums)
    {
        if(st.find(it)!=st.end()) continue;
        st.insert(it);
        auto ptr=st.upper_bound(it);
        if(ptr!=st.end())
        {
            st.erase(ptr);
        }
    }
    cout<<st.size()<<endl;

    
    return 0;
    // T:O(nlogn)
    // S:O(n)

}