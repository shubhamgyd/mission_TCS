#include<bits/stdc++.h>
using namespace std;


bool CheckReduntant(string str)
{
    stack<char>st;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==')')
        {
            char top=st.top();
            st.pop();
            bool flag=true;
            while(!st.empty() && top!='(')
            {
                if(top=='*' || top=='+' || top=='-' || top=='/')
                {
                    flag=false;
                }
                top=st.top();
                st.pop();
            }
            if(flag==true)
            {
                return true;
            }
        }
        else
        {
            st.push(str[i]);
        }
    }
    return false;
}

int main()
{
    string str="(a+b*(c-d))";
    if(CheckReduntant(str))
    {
        cout<<"Given expression is reduntant: "<<endl;
    }
    else
    {
        cout<<"Given Expression is not reduntant: "<<endl;
    }
}