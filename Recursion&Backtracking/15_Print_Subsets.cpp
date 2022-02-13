//  In this problem we are going to find all subsets of a string/array

#include<bits/stdc++.h>
using namespace std;

void solve(string str,string op)
{
    if(str.length()==0)
    {
        cout<<op<<endl;
        return ;
    }
    string op1=op;
    string op2=op;
    op1.push_back(str[0]);
    str.erase(str.begin()+0);
    solve(str,op1);
    solve(str,op2);
    return;
}

int main()
{
    string str;
    cin>>str;
    solve(str,"");
    return 0;
}

/*
Time complexity  Analysis:
T(n)=O(2^n)
*/

