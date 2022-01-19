/*
Given a stream of numbers, generate a random number from the stream. 
You are allowed to use only O(1) space and the input is in the form of a stream, 
so can’t store the previously seen numbers. 
*/


#include<bits/stdc++.h>
using namespace std;

int selectRandom(int ele)
{
    static int count=0;
    static int res;
    count++;
    if(count==1)
    {
        res=ele;
    }
    else
    {
        int rand_new=rand()%count;
        if(rand_new==count-1)
        {
            res=ele;
        }
    }
    return res;
}
// Time Complexity:O(n)
// Space Complexity:O(1)

int main()
{
    vector<int>res={1,2,3,4,5,6,7,8,9};
    int n=res.size();
    for(int i=0;i<n;i++)
    {
        cout<<"Random number from the first "<<i+1<<" numbers is: "<<selectRandom(res[i])<<endl;
    }
    return 0;
}