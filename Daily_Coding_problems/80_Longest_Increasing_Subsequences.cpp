/*
This problem was asked by Microsoft.

Given an array of numbers, find the length of the longest increasing subsequence in the array.
The subsequence does not necessarily have to be contiguous.

For example, given the array [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15], the
longest increasing subsequence has length 6: it is 0, 2, 6, 9, 11, 15.
*/

#include <bits/stdc++.h>
using namespace std;

/* To make use of recursive calls, this
function must return two things:
1) Length of LIS ending with element arr[n-1].
    We use max_ending_here for this purpose
2) Overall maximum as the LIS may end with
    an element before arr[n-1] max_ref is
    used this purpose.
The value of LIS of full array of size n
is stored in *max_ref which is our final result
*/
int _lis(vector<int> &arr, int n, int *max_ref)
{
    /* Base case */
    if (n == 1)
        return 1;

    // 'max_ending_here' is length of LIS
    // ending with arr[n-1]
    int res, max_ending_here = 1;

    /* Recursively get all LIS ending with arr[0],
    arr[1] ... arr[n-2]. If arr[i-1] is smaller
    than arr[n-1], and max ending with arr[n-1]
    needs to be updated, then update it */
    for (int i = 1; i < n; i++)
    {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }

    // Compare max_ending_here with the overall
    // max. And update the overall max if needed
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;

    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}

// The wrapper function for _lis()
int lis(vector<int> &arr, int n)
{
    // The max variable holds the result
    int max = 1;

    // The function _lis() stores its result in max
    _lis(arr, n, &max);

    // returns max
    return max;
}
// Time Complexity: Exponential
// Auxilary Space: O(1)





// DP
void LongestLength(vector<int>&res,int n)
{
    vector<int>ans(n);
    ans[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(res[i]>res[j] && ans[i]<ans[j]+1)
            {
                ans[i]=ans[j]+1;
            }
        }
    }
    cout<<*max_element(ans.begin(),ans.end())<<endl;
}
// Time Complexity:O(n*n)
// Auxilary Space :O(n)




// Another O(n^2)

int LongestSequence(vector<int>&res,int n)
{
    vector<int>ans(n,1);
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            if(res[i]<res[j])
            {
                ans[i]=max(ans[i],1+ans[j]);
            }
        }
    }
    return (*max_element(ans.begin(),ans.end()));
}



void mxLength(vector<int>&res,int n)
{
    set<int> s;
    for (auto a : res)
    {
        if (s.find(a) != s.end()) continue;
        s.insert(a);
        auto it = s.upper_bound(a);
        cout<<"position: "<<*it<<endl;
        if (it != s.end()){
            s.erase(it);
        }
    }
    cout<<s.size()<<endl;
}

// Time Complexity:O(nlogn)
// Auxilay Space :O(n)

int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    // int length=1;
    int length = lis(res, n);
    cout << length << endl;

    mxLength(res,n);
    LongestLength(res,n);
    return 0;
}