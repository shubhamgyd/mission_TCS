#include<bits/stdc++.h>
using namespace std;


void Optimise(vector<int>&A,vector<int>&B)
{

    int A_Sum=0,B_Sum=0;
    for(int i=0;i<A.size();i++)
    {
        A_Sum+=A[i];
    }
    for(int i=0;i<B.size();i++)
    {
        B_Sum+=B[i];
    }
    cout<<A_Sum*B_Sum<<endl;
}
// Time Complexity:O(n)
// Space Complexity:O(1)


void BruteForce(vector<int>&A,vector<int>&B)
{
    int prod=0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<B.size();j++)
        {
            prod+=A[i]*B[j];
        }
    }
    cout<<prod<<endl;
}
// Time Complexity:O(n*n)
// Space Complexity:O(1)


int main()
{
    int n;
    cin>>n;
    vector<int>A(n),B(n);
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }
    BruteForce(A,B);
    Optimise(A,B);
    return 0;
}