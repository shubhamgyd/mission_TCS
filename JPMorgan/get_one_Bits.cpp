#include<bits/stdc++.h>
using namespace std;


vector<int> getOneBits(int n)
{
    vector<int> result;
    int count = 0;
    vector<int> arr;
    while(n>0)
    {
        int rem = n%2;
        if(rem == 1)
        {
            count++;
        }
        arr.push_back(rem);
        n = n/2;
    }
    reverse(arr.begin(), arr.end());
    result.push_back(count);
    for(int i = 0;i<arr.size();i++)
    {
        if(arr[i] == 1)
        {
            result.push_back(i+1);
        }
    }
    
    return result;
}

// int getBits(int n)
// {
//     vector<int> vec;
// while(n>0){
//   vec.push_back(n%2);
//   n=n/2;
// }
// reverse(vec.begin(),vec.end());

// for(int i=0;i<vec.size();i++){
//   if(vec[i]==1){
//   cout<<i+1<<" ";
//     }
// }
// }