/*
Problem Statement: Given an array of integers A and an integer B. 
Find the total number of subarrays having bitwise XOR of all elements equal to B.
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
    int b;
    cin>>b;


    // Brute Force
    // Intuition: The brute force solution is to generate all possible subarrays. 
    // For each generated subarray we get the respective XOR and then check if this XOR 
    // is equal to B. If it is then we increment the count. In the end, we will get the count of all possible subarrays that have XOR equal to B.
    int count=0;
    for(int i=0;i<n;i++)
    {
        int x_or=0;
        for(int j=i;j<n;j++)
        {
            x_or^=res[j];
            if(x_or==b)
            {
                count++;
            }
        }
    }
    cout<<"Total: "<<count<<endl;
    // T:O(n*n)
    // S:O(1)


    // Using Prefix sum and Hahsmap

    //Intuition: The main idea is to observe the prefix xor of the array. Prefix Xor is just another array, where each index contains XOR of all elements of the original array starting from index 0 up to that index. In other words
    // prefix_xor[i] = XOR(a[0], a[1], a[2],……,a[I])

    // Once we have made the prefix xor array, we observe a fact:

    // P = xor(a[0], a[1], a[2],……, a[q], a[q+1],….., a[p])
    // Q = xor(a[0], a[1], a[2],……, a[q])

    // Therefore,
    // P^Q = xor(a[q+1],….., a[p]) = M                                
    // So, now we understand that from the prefix xor array when we XOR two elements at different indices we get the xor of the elements (in the original array) that were between those indices.
    // Let’s say we did XOR(P, B) and we got Q (B is the integer given in question). What does this mean?
    // This means that the subarray between q and p is having xor = B. To understand this we just use simple equations:
    // P^B = Q
    // => P^B^P = Q^P
    // => B = Q^P  

    // And we already know by fact 1 that Q^P will give xor of all elements between q and p. Therefore, the subarray between q and p has xor = B.
    // Suppose we did XOR(P, B) and we got Q (B is the integer given in question). But there is more than one Q before p.

    // In this case, there are two subarrays that have XOR = B. Subarrays between q1 to p and q2 to p. 

    // IMP NOTE: although we talk about prefix xor “array”, it should be noted that at a time we need only one element of this array. Hence, we can just use a variable to maintain the prefix xor. 

    unordered_map<int,int>mp;
    int cor=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cor^=res[i];
        if(cor==b)
        {
            cnt++;
        }
        int temp=cor^b;
        if(mp.find(temp)!=mp.end())
        {
            cnt+=mp[temp];
        }
        mp[cor]++;
    }
    cout<<"Total: "<<cnt<<endl;
    // T: O(n)
    // S:O(n)
}