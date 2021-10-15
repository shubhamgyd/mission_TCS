// In this problem we are going to generate all possible parenthesis 


#include<bits/stdc++.h>
using namespace std;

class Solution {
    void balanced(vector<string>&v,int open,int close,string op)
    {
        if(open==0 && close==0)
        {
            v.push_back(op);
            return;
        }
        if(open!=0)
        {
            string op1=op;
            op1.push_back('(');
            balanced(v,open-1,close,op1);
        }
        if(close>open)
        {
            string op2=op;
            op2.push_back(')');
            balanced(v,open,close-1,op2);
        }
        return;
    }
    
public:
    vector<string> generateParenthesis(int n) {
        int open=n;
        int close=n;
        vector<string>v;
        string op="";
        balanced(v,open,close,op);
        return v;
    }
};


int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("ip.txt", "r", stdin);
//     freopen("op.txt", "w", stdout);
// #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            vector<string>vs={obj.generateParenthesis(a)};
            for(auto ele:vs)
            {
                cout<<ele<<" ";
            }
            cout<<endl;
        }
    }
}