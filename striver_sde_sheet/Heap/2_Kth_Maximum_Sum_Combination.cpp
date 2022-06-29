/*
Problem Statement
You are given two arrays/lists ‘A’ and ‘B’ of size ‘N’ each. You are also given an integer ‘K’. You have to find the ‘K’ maximum and valid sum combinations from all the possible sum combinations of the arrays/lists ‘A’ and ‘B’.
Sum combination is made by adding one element from array ‘A’ and another element from array ‘B’.
For Example :
A : [1, 3] 
B : [4, 2] 
K : 2
The possible sum combinations can be 5(3 + 2), 7(3 + 4), 3(1 + 2), 5(1 + 4). The 2 maximum sum combinations are 7 and 5. 
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    int maxa = INT_MIN;
    int n = A.size();
        
    for(int i=0;i<n;i++){
        maxa = max({A[i], B[i], maxa});
    }
    maxa++;
    
    vector<int> arr1(maxa,0), arr2(maxa,0);
    
    for(int i=0;i<n;i++){
        arr1[A[i]]++;
        arr2[B[i]]++;    
    }
    
    vector<int> ans;
    
    for(int sum=2*maxa;sum>=2;sum--){
        int cnt = 0;
        for(int i=1;i<min(sum,maxa);i++){
            int second = sum - i;
            if(second>=maxa || second<1) continue;
            cnt+=arr1[i]*arr2[second];
        }
        
        for(int i=0;i<cnt;i++){
            ans.push_back(sum);
            if(ans.size()==C) return ans;
        }
    }
    
    return ans;
}
