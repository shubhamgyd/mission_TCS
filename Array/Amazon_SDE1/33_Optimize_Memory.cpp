/*
Your team at Amazon is working on a system that divides applications to a mixed cluster of computing 
devices. Each application is identified by an integer ID, requires a fixed non-zero amount of memory 
to execute, and is defined to be either a foreground or background application. IDs are guaranteed to
 be unique within their own application type, but not across types.

Each device should be assigned two applications at once, one foreground application and one background 
application. Devices have limited amounts of memory and cannot execute applications that require more 
memory than the available memory. The goal of the system is to maximize the total utilization of the 
memory of a given device. A

foreground/background application pair is considered to be optimal if there does not exist another pair 
that uses more memory than this pair, and also has a total less than or equal to the total memory of 
the device. For example, if the device has 10MB memory, a foreground/background pair using a sum total 
of 9MB memory would be optimal if there does not exist a pair that uses a sum total of 10 MB, but would
 not be optimal if such a pair did exist.

Write an algorithm to find the sets of foreground and background application pairs that optimally 
utilize the given device for a given list of foreground applications and a given list of background 
applications.


Input:
a = [[1, 2], [2, 4], [3, 6]]
b = [[1, 2]]
target = 7

Output: [[2, 1]]

Explanation:
There are only three combinations [1, 1], [2, 1], and [3, 1], which have a total sum of 4, 6 and 8, respectively.
Since 6 is the largest sum that does not exceed 7, [2, 1] is the optimal pair.



Example 2:

Input:
a = [[1, 3], [2, 5], [3, 7], [4, 10]]
b = [[1, 2], [2, 3], [3, 4], [4, 5]]
target = 10

Output: [[2, 4], [3, 2]]

Explanation:
There are two pairs possible. Element with id = 2 from the list `a` has a value 5, and element with id = 4 from the list `b` also has a value 5.
Combined, they add up to 10. Similarily, element with id = 3 from `a` has a value 7, and element with id = 2 from `b` has a value 3.
These also add up to 10. Therefore, the optimal pairs are [2, 4] and [3, 2].


Example 3:

Input:
a = [[1, 8], [2, 7], [3, 14]]
b = [[1, 5], [2, 10], [3, 14]]
target = 20

Output: [[3, 1]]
Example 4:

Input:
a = [[1, 8], [2, 15], [3, 9]]
b = [[1, 8], [2, 11], [3, 12]]
target = 20

Output: [[1, 3], [3, 2]]
*/

#include<bits/stdc++.h>
using namespace std;



int main()
{
    int deviceCapacity;
    cin>>deviceCapacity;
    int n;
    cin>>n;
    vector<pair<int,int>>foregroundList(n);
    for(int i=0;i<n;i++)
    {
        cin>>foregroundList[i].first>>foregroundList[i].second;
    }
    int m;
    cin>>m;
    vector<pair<int,int>>backgroundList(m);
    for(int i=0;i<m;i++)
    {
        cin>>backgroundList[i].first>>backgroundList[i].second;
    }
    sort(foregroundList.begin(),foregroundList.end(),[](pair<int,int>&a,pair<int,int>b){
        return a.second<b.second;
    });
    sort(backgroundList.begin(),backgroundList.end(),[](pair<int,int>&a,pair<int,int>b){
        return a.second<b.second;
    });

    int i=0;
    int j=m-1;
    vector<vector<int>>ans;
    int mx=INT_MIN;
    while(i<n and j>=0)
    {
        int sum=foregroundList[i].second+backgroundList[j].second;
        if(sum>deviceCapacity)
        {
            j--;
        }
        else
        {
            if(mx<=sum)
            {
                if(mx<sum)
                {
                    mx=sum;
                    ans.clear();
                }
                ans.push_back({foregroundList[i].first,backgroundList[j].first});
                int ind=j-1;
                while(ind>=0 and backgroundList[ind].second==backgroundList[ind+1].second)
                {
                    ans.push_back({foregroundList[i].first,backgroundList[ind--].first});
                }
            }
            i++;
        }
    }
    cout<<"[";
    for(int i=0;i<ans.size();i++)
    {
        cout<<"["<<ans[i][0]<<", "<<ans[i][1]<<"], ";
    }
    cout<<"]";
    return 0;
    
}

/*
Time complexity - O(n^2), Space(logn).
just noticed when every possible pair has the same sum, worst case is O(n^2), 
thanks for the heads up. But why do you think space is lgn? Given worst case and taking the 
output array in to consideration space is n^2, if not, then amount of memory you use do not 
change with respect to your input size aka O(1)
*/