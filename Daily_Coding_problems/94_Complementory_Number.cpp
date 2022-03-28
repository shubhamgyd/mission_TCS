/*
Given a positive number, return its complementary number.
Note: The complement of a number is the number that results from flipping every bit in the 
original number. (i.e. zero bits become one bits and one bits become zero bits).

Ex: Given the following number…

number = 27, return 4.
27 in binary (not zero extended) is 11011.
Therefore, the complementary binary is 00100 which is 4.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int num=n;
    num|=num>>1;
    num|=num>>2;
    num|=num>>4;
    num|=num>>8;
    num|=num>>16;
    cout<<num<<endl;
    cout<<(n^num)<<endl;
}