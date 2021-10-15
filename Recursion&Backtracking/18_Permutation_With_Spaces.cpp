// WE are going to print all the permutations with the given condition
/*
is S="ABC"
ans: A_B_C
     AB_C
     A_BC
     .
     .
     .
     so on
here _ means space

this question is similar kind of generate all valid parenthesis
*/


#include<bits/stdc++.h>
using namespace std;

void solve(string ip,string op)
{
    if(ip.length()==0)
    {
        cout<<op<<endl;
        return;
    }
    string op1=op;
    string op2=op;
    op1.push_back(' ');
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op1);
    solve(ip,op2);
    return;
}

int main()
{
    string str;
    cin>>str;
    string op;
    op.push_back(str[0]);
    str.erase(str.begin()+0);
    solve(str,op);
    return 0;
}


/*
Time Complexity: O(2^n)
*/