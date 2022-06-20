/*
Problem Statement: You are given a read-only array of N integers with values also in the range [1,N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

Example 1:

Input Format:  array[] = {3,1,2,5,3}

Result: {3,4)

Explanation: A = 3 , B = 4 
Since 3 is appearing twice and 4 is missing
Example 2:

Input Format: array[] = {3,1,2,5,4,6,7,5}

Result: {5,8)

Explanation: A = 5 , B = 8 
Since 5 is appearing twice and 8 is missing
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

    // Brute Force
    map<int,int>mp;
    for(auto it:res)
    {
        mp[it]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(mp[i]==0)
        {
            cout<<"Missing: "<<i<<endl;
        }
        else if(mp[i]>1)
        {
            cout<<"Repeating: "<<i<<endl;
        }
    }
    // Time Complexity:O(nogn+n)
    // Space Complexity:O(n)


    // Using sorting
    vector<int>temp=res;
    sort(temp.begin(),temp.end());
    int start=1;
    int i=0;
    bool ok=false;
    while(i<n)
    {
        if(temp[i]!=start)
        {
            ok=true;
            cout<<"Missing: "<<start<<endl;
        }
        int j=i;
        int ct=0;
        while(j<n and temp[j]==temp[i])
        {
            j++;
            ct++;
        }
        if(ct>1)
        {
            cout<<"Repeating: "<<temp[i]<<endl;
        }
        i=j;
        start++;
    }
    if(!ok)
    {
        cout<<"Missing: "<<start<<endl;
    }

    // Time Complexity:O(nlogn+n)
    // Space Complexity:O(1)



    // Using Math
    int sum=(n*(n+1)/2);
    int sqSum=(n*(n+1)*(2*n+1)/6);
    for(auto it:res)
    {
        sum-=it;
        sqSum-=(it*it);
    }
    int missingNum=(sum+sqSum/sum)/2;
    int repeating=missingNum-sum;
    cout<<"Missing: "<<missingNum<<endl;
    cout<<"Repeating: "<<repeating<<endl;
    // Time Complexity:O(n)
    // Space Complexity:O(1)


    // Using Bit
    vector<int>arr=res;
    int x=0;
    for(int i=0;i<n;i++)
    {
        x^=arr[i];
        x^=(i+1);
    }

    int mask=(x&-x);
    int a=0;
    int b=0;
    for(int i=0;i<n;i++)
    {
        if((mask&arr[i])==0)
        {
            a^=arr[i];
        }
        else
        {
            b^=arr[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        if((mask&i)==0)
        {
            a^=i;
        }
        else
        {
            b^=i;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]==a)
        {
            cout<<"Missing Number -> "<<b<<endl;
            cout<<"Repeating Number -> "<<a<<endl;
            break;
        }
        else if(arr[i]==b)
        {
            cout<<"Missing Number -> "<<a<<endl;
            cout<<"Repeating Number -> "<<b<<endl;
            break;
        }
    }
    // Time Complexity:O(n)
    // Space Complexity:O(1)
}