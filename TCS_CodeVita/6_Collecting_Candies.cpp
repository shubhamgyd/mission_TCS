/*
Question:- Krishna loves candies a lot, so whenever he gets them, 
he stores them so that he can eat them later whenever he wants to.

He has recently received N boxes of candies each containing Ci 
candies where Ci represents the total number of candies in the ith box. Krishna wants to store them in a single box. The only constraint is that he can choose any two boxes and store their joint contents in an empty box only. Assume that there are an infinite number of empty boxes available.

At a time he can pick up any two boxes for transferring and if both the 
boxes contain X and Y number of candies respectively, then it takes him 
exactly X+Y seconds of time. As he is too eager to collect all of them he 
has approached you to tell him the minimum time in which all the candies can be collected.

Input Format:

The first line of input is the number of test case T
Each test case is comprised of two inputs
The first input of a test case is the number of boxes N
The second input is N integers delimited by whitespace denoting the number of candies in each box
Output Format: Print minimum time required, in seconds, for each of the test cases. Print each output on a new line.

Constraints:

1 < T < 10
1 < N< 10000
1 < [Candies in each box] < 100009

1	1
4
1 2 3 4	19
2	1
5
1 2 3 4	34
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>res(n);
        for(int i=0;i<n;i++)
        {
            cin>>res[i];
        }
        priority_queue<int,vector<int>,greater<int>>pq(res.begin(),res.end());
        int sum=0;
        while(pq.size()!=1)
        {
            int num1=pq.top();
            pq.pop();
            int num2=pq.top();
            pq.pop();
            sum+=num1+num2;
            int res=num1+num2;
            pq.push(res);
        }
        cout<<sum<<endl;
        return 0;
    }
}