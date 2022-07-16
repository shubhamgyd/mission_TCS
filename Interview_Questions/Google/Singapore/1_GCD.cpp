/*
GCD (Greatest Common Divisor) of two positive integers is the largest positive 
integer that divides both numbers without a remainder.
Siblings: Nodes with the same parent are called siblings.
Level of a tree: Level of a tree is the number of edges on the longest path from 
the root node to a leaf.
You are given nodes of a binary tree of leven n as input.
Caluclate the GCD of each pair of siblings and then find the max & min GCD among them. 
Print the difference of max & min GCD ( max GCD - min GCD)

Note:
Print -1 if input tree is empty i.e level of tree is -1.
Consider those nodes which have a sibling
Print 0 if no such pair of siblings found
Input Format:
The input is in the following format:

The first line takes an integer n as input which represents the level of tree 
(the root node is at 0 level). (if level is equal to -1, means empty tree)
Next n+1 lines contain the nodes in the tree level order. Each i'th line 
represents the nodes present in the binary tree in i'th level.
1st line contains level 0 nodes. (i.e. root node).
2nd line contains nodes for level 1.
3rd line contains nodes for level 2 and so on.
Each node is represented by an integer value. Node value of -1 denotes an empty 
node(no node present at that place).

Output Format:
A single integer i.e., the difference of max & min GCD (max GCD - min GCD)

Constraints:
-1 <= level of tree <= 20
0 < element at nodes of tree <= 500
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int mnGCD=INT_MAX;
    int mxGCD=INT_MIN;
    for(int i=0;i<=n;i++)
    {
        if(i==0)
        {
            continue;
        }
        else
        {
            for(int j=0;j<pow(2,i);j+=2)
            {
                int a,b;
                cin>>a>>b;
                if(a==-1 or b==-1) continue;
                else
                {
                    int newGCD=__gcd(a,b);
                    mnGCD=min(mnGCD,newGCD);
                    mxGCD=max(mxGCD,newGCD);
                }
            }
        }
    }
    if(mnGCD==INT_MAX and mxGCD==INT_MIN)
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<mxGCD-mnGCD<<endl;
    }
    return 0;
}