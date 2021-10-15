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


// #include <bits/stdc++.h>
// using namespace std;

// void Generator(vector<string>&gen,string res,int open,int close)
// {
//     if(open==close)
//     {
//         gen.push_back(res);
//         return;
//     }
//     if(open!=0)
//     {
//         string op=res;
//         op.push_back('(');
//         Generator(gen,op,open-1,close);
//     }
//     if(close>open)
//     {
//         string op1=res;
//         op1.push_back(')');
//         Generator(gen,op1,open,close-1);
//     }
//     return;
// }

// vector<string> PArenthesis(int n)
// {
//     int close=n;
//     int open=n;
//     vector<string>gen;
//     string res="";
//     Generator(gen,res,open,close);
//     return gen;
// }

// int32_t main()
// {
// // #ifndef ONLINE_JUDGE
// //     freopen("input.txt", "r", stdin);
// //     freopen("output.txt", "w", stdout);
// // #endif
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n;
//     cin>>n;
//     vector<string>v={PArenthesis(n)};
//     for(auto it:v)
//     {
//         cout<<it<<endl;
//     }
//     return 0;
// }