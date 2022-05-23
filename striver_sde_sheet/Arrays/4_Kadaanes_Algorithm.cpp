/*
Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and return its sum and print the subarray.
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &res, vector<int> &arr)
{
    int mx = 0;
    int n = res.size();
    if (n == 1)
    {
        return res[0];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += res[k];

                // if the sum is greater than the mx_sum
                if (sum > mx)
                {
                    // erase last pair indices
                    arr.clear();
                    mx = sum;         // update sum
                    arr.push_back(i); // make new pair of indices
                    arr.push_back(j);
                }
            }
        }
    }

    return mx;
}
// Time complexity:O(n^3)
// Space Complexity:O(1)

int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }

    /*
    Approach 1: Using three for loops, we will get all possible subarrays in two loops and
    their sum in another loop, and then return the maximum of them.
    */
    vector<int> arr;
    int mx = solve(res, arr);
    cout << "Longest subarray sum is: " << mx << endl;
    cout << "Longest subarray is: " << endl;
    for (int i = arr[0]; i <= arr[1]; i++)
    {
        cout << res[i] << " ";
    }

    // Approach 2
    /*
     We can also do this problem using only two for loop,
     starting the function with ( max_sum ) variable which will have the final answer. We can get the sum of all possible subarrays in this way and then return the maximum so far.
    */

    int max_sum = INT_MIN;
    vector<int> subarray;
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += res[j];
            if (curr_sum > max_sum)
            {
                subarray.clear();
                max_sum = curr_sum;
                subarray.push_back(i);
                subarray.push_back(j);
            }
        }
    }
    cout << "\nLongest subarray sum is: " << mx << endl;
    cout << "Longest subarray is: " << endl;
    for (int i = subarray[0]; i <= subarray[1]; i++)
    {
        cout << res[i] << " ";
    }
    // Time Complexity: O(N^2)

    // Space Complexity: O(1)

    // Approach : 3
    /*
        Intuition: Basically this problem can be done in linear time complexity with Kadane’s algorithm along with that will also get the subarray which is giving the largest positive-sum.

        Approach:

        -> We will have the following variables in the beginning :

        msf – max so far, meh – max end here, start – to get the starting index of ans’s subarray, end – to get the ending index of ans’s subarray.

        -> Traverse the array starting with adding the ith element with max_end_here(meh) , now we will check that adding the element gives greater value than max_so_far(msf) , if yes then we will update our meh and also update the starting and ending index .

        for(int i=0;i<res.size();i++){

        meh+=res[i];

        if(meh>msf){ msf=meh; start=s; end=i; }

        if(meh<0){meh=0; s=i+1;}

        }

        ->Now in this step, we will print the answer subarray using the start and end variables.

        ->Return the largest subarray sum that is:- msf.
    */
    int msf = res[0], meh = 0;
    int s = 0;
    vector<int>ans;
    for (int i = 0; i < res.size(); i++)
    {
        meh += res[i];
        if (meh > msf)
        {
            subarray.clear();
            msf = meh;
            ans.push_back(s);
            ans.push_back(i);
        }
        if (meh < 0)
        {
            meh = 0;
            s = i + 1;
        }
    }

   /*
    Time Complexity: O(N) 

    Space Complexity:O(1)
   */
}
