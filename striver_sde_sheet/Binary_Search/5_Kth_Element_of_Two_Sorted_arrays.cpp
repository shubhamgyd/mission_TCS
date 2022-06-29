/*
Problem Statement: Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the kth position of the final sorted array.

Examples :

Input: m = 5
       n = 4
       array1 = [2,3,6,7,9]
       array2 = [1,4,8,10]
       k = 5

Output:
 6

Explanation: Merging both arrays and sorted. Final array will be -
 [1,2,3,4,6,7,8,9,10]
We can see at k = 5 in the final array has 6.
*/

#include <bits/stdc++.h>
using namespace std;

int kthelement(vector<int>&arr1, vector<int>&arr2, int n, int m, int k) {
    if(m > n) {
        return kthelement(arr2, arr1, n, m, k); 
    }
        
    int low = max(0,k-m), high = min(k,n);
        
    while(low <= high) {
        int cut1 = (low + high) >> 1; 
        int cut2 = k - cut1; 
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
        int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1; 
        }
    }
    return 1; 
}

int main()
{
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        cin >> res[i];
    int m;
    cin >> m;
    vector<int> res1(m);
    for (int i = 0; i < m; i++)
        cin >> res1[i];
    int K;
    cin >> K;

    // brute force;
    int arr[n + m +1];
    memset(arr,0,sizeof(arr));
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n and j < m)
    {
        if (res[i] <= res1[j])
        {
            arr[k++] = res[i++];
        }
        else
        {
            arr[k++] = res1[j++];
        }
    }
    while (i < n)
        arr[k++] = res[i++];
    while (j < m)
        arr[k++] = res1[j++];
    
    for(int i=0;i<(n+m);i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout << arr[K - 1] << endl;
    // T:O:(min(n,m))
    // S:O(n+m)



    // Brute Force: Space Optimize
    int p1 = 0, p2 = 0, counter = 0, answer = 0;

    while (p1 < n && p2 < m)
    {
        if (counter == K)
            break;
        else if (res[p1] < res1[p2])
        {
            answer = res[p1];
            ++p1;
        }
        else
        {
            answer = res1[p2];
            ++p2;
        }
        ++counter;
    }
    if (counter != K)
    {
        if (p1 != m - 1)
            answer = res[K - counter];
        else
            answer = res1[K - counter];
    }
    cout<<answer<<endl;





    // uisng binary search
    int ans1=kthelement(res,res1,n,m,K);
    cout<<ans1<<endl;
    return 0;
}