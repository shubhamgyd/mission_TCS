/*
Problem Statement: Given an array of integers A of size N and an integer B.

The College library has N bags, the ith book has A[i] number of pages.

You have to allocate books to B number of students so that the maximum number of pages allocated to a student is minimum.

Conditions given :

A book will be allocated to exactly one student.

Each student has to be allocated at least one book.

Allotment should be in contiguous order, for example, A student cannot be allocated book 1 and book 3, skipping book 2.

Calculate and return the minimum possible number. Return -1 if a valid assignment is not possible.

Examples:

Example 1:

Input: A = [12, 34, 67, 90]
       B = 2

Output: 113

Explaination: Let’s see all possible cases of how books can be allocated for each student.
*/

#include<bits/stdc++.h>
using namespace std;



int isPossible(vector < int > & A, int pages, int students) {
  int cnt = 0;
  int sumAllocated = 0;
  for (int i = 0; i < A.size(); i++) {
    if (sumAllocated + A[i] > pages) {
      cnt++;
      sumAllocated = A[i];
      if (sumAllocated > pages) return false;
    } else {
      sumAllocated += A[i];
    }
  }
  if (cnt < students) return true;
  return false;
}


int books(vector<int> &A, int B) {
     if (B > A.size()) return -1;
  int low = A[0];
  int high = 0;
  //to find minimum value and sum of all pages
  for (int i = 0; i < A.size(); i++) {
    high = high + A[i];
    low = min(low, A[i]);
  }
  //binary search
  while (low <= high) {
    int mid = (low + high) >> 1;
    if (isPossible(A, mid, B)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}


bool Check(vector<int>&res,int mid,int k)
{
    int cnt=0;
    int sum=0;
    for(int i=0;i<res.size();i++)
    {
        
        if(sum+res[i]>mid)
        {
            sum=res[i];
            cnt++;
            if(sum>mid) return false;
        }
        else
        {
            sum+=res[i];
        }
    }
    if(cnt<k)
    {
        return true;
    }
    return false;
}


int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    int sum=0;
    int mn=res[0];
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
        sum+=res[i];
        mn=min(mn,res[i]);
    }
    int k;
    cin>>k;
    sort(res.begin(),res.end());
    int low=mn;
    int high=sum;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(Check(res,mid,k))
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<low<<endl;
}