/*
Q1. Given a sequence of coins each one facing upward (Head) or downward 
(Tail), we say it is a 'beautiful' 
sequence if all heads are before the tails.
More formally, a beatiful sequence is of the form HH...TTT. For example HHTT, 
HHHTT, HTTT are beatiful sequences while HHTHT, THHTT are not.
Note that also only heads or only tails sequence are considered beautiful, e.g. HHH or TTT.
Write a program that takes as input a string representing the coins sequence and 
output the minimum number of coin flips (H -> T or T->H) necessary to make the sequence beatiful.

For example, given the sequence HHTHTT, the answer should be 1 since it sufficient to 
flip the last H to make it beatiful (HHTTTT).
*/


#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    int n=str.length();
    int flip=0;
    int tail=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='H')
        {
            if(tail==0)
            {
                continue;
            }
            flip++;
        }
        else
        {
            tail++;
        }
        if(tail<flip)
        {   
            flip=tail;
        }
    }
    cout<<flip<<endl;
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(1)