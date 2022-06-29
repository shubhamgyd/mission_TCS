/*
Problem Statement: Given two sorted arrays arr1 and arr2 of size m and n respectively, return the median of the two sorted arrays.

Example 1:

Input format: arr1 = [1,4,7,10,12], arr2 = [2,3,6,15]

Output format : 6.00000

Explanation:
Merge both arrays. Final sorted array is [1,2,3,4,6,7,10,12,15]. We know that
to find the median we find the mid element. Since, the size of the element is odd. By formula, the median will be at [(n+1)/2]th position of the final sorted array. Thus, for this example, the median is at [(9+1)/2]th position which is [5]th = 6.
*/

#include <bits/stdc++.h>
using namespace std;


double solve(vector<int>&res,vector<int>&res1,int n,int m)
{
    if(n>m) return solve(res1,res,m,n);
    int low=0;
    int high=n;
    while(low<=high)
    {
        int cut1=(high+low)>>1;
        int cut2=(n+m+1)/2-cut1;

        int left1=cut1==0?INT_MIN:res[cut1-1];
        int left2=cut2==0?INT_MIN:res1[cut2-1];

        int right1=cut1==n?INT_MAX:res[cut1];
        int right2=cut2==m?INT_MAX:res1[cut2];

        // now we have to check the cross numbers are less or greater
        // left1 \ / right1
        //       / \      
        // left2/   \ right2
        // i.e left1<=right2 and left2<=rigth1
        if(left1<=right2 and left2<=right1)
        {
            if((n+m)%2==0)
            {
                return (max(left1,left2)+min(right1,right2))/2.0;
            }
            else
            {
                return max(left1,left2);
            }
        }
        else if(left1>right2)
        {
            high=cut1-1;
        }
        else
        {
            low=cut1+1;
        }
    }
    return 0.0;
}
/*
Time Complexity : O(log(m,n))
Reason – We are applying binary search on the array which has a minimum size.

Space Complexity: O(1)
Reason – No extra array is used.
*/

int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    int m;
    cin >> m;
    vector<int> res1(m);
    for (int i = 0; i < m; i++)
    {
        cin >> res1[i];
    }

    // brute force
    vector<int> ans;
    for (auto it : res)
        ans.push_back(it);
    for (auto it : res1)
        ans.push_back(it);

    sort(ans.begin(), ans.end());
    if (ans.size() % 2 == 1)
    {
        cout << ans[ans.size() / 2] << endl;
    }
    else
    {
        cout << (ans[ans.size() / 2] + ans[ans.size() / 2 + 1]) << endl;
    }
    // T:O(nlgon)
    // S:O(n+m)

    //  Using Binary Search
    //     Approach :

    // We will do a binary search in one of the arrays which have a minimum size among the two.

    // Firstly, calculate the median position with (n+1)/2. Point two-pointer, say low and high, equal to 0 and size of the array on which we are applying binary search respectively. Find the partition of the array. Check if the left half has a total number of elements equal to the median position. If not, get the remaining elements from the second array. Now, check if partitioning is valid. This is only when l1<=r2 and l2<=r1. If valid, return max(l1,l2)(when odd number of elements present) else return (max(l1,l2)+min(r1,r2))/2.
    // If partitioning is not valid, move ranges. When l1>r2, move left and perform the above operations again. When l2>r2, move right and perform the above operations.
    double ans1=solve(res,res1,n,m);
    cout<<ans1<<endl;
    return 0;
}