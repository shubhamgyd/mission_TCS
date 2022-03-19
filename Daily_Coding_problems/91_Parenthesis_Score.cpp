/*
Given a string of parentheses, write a function to compute the minimum number of 
parentheses to be removed to make the string valid (i.e. each open parenthesis is 
eventually closed).

For example, given the string "()())()", you should return 1. Given the string ")(", 
you should return 2, since we must remove all of them.
*/

#include<bits/stdc++.h>
using namespace std;


int minRemovals(string str)
{
    int bal = 0;    // keep track on the balanced parenthesis
    int ans = 0;    // kep track on the final ans
 
    for (int i = 0; i < str.length(); ++i) {
 
        bal += str[i] == '(' ? 1 : -1;
 
        // if at any index we have found that , unbalanced parenthessis , means closeing parenthesis is
        // greater than the opening parenthesis
        // It is guaranteed bal >= -1
        if (bal == -1) {
            ans += 1;
            bal += 1;
        }
    }
    
    // return final ans
    return bal + ans;
}
// Time Complexity:O(n)
// Space Complexity:O(1)


bool Pair(char open,char close)
{
    return (open=='(' && close==')');
}

int main()
{
    string str;
    cin>>str;
    cout<<minRemovals(str)<<endl;
    stack<char>st;
    int count=0;
    for(auto ch:str)
    {
        if(ch=='(')
        {
            st.push(ch);
        }
        else if(ch==')')
        {
            if(st.empty() || !Pair(st.top(),ch))
            {
                count++;
            }
            else
            {
                st.pop();
            }
        }
    }
    count+=st.size();
    cout<<count<<endl;
    return 0;
}

// Time Complexity:O(n)
// Space Complexity:O(n)