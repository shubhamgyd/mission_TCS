/*
This question is asked by Amazon. Given a string s consisting of only letters and digits, 
where we are allowed to transform any letter to uppercase or lowercase, 
return a list containing all possible permutations of the string.

Ex: Given the following string…
S = "c7w2", return ["c7w2", "c7W2", "C7w2", "C7W2"]
*/

#include<bits/stdc++.h>
using namespace std;


vector<string>ans;

void solve(string str,string output)
{
    if(str.length()==0)
    {
        ans.push_back(output);
        return ;
    }
    if(isalpha(str[0]))
    {
        string op1=output;
        string op2=output;
        op1.push_back(toupper(str[0]));
        op2.push_back(tolower(str[0]));
        str.erase(str.begin()+0);
        solve(str,op1);
        solve(str,op2);
    }
    else
    {
        string op1=output;
        op1.push_back(str[0]);
        str.erase(str.begin()+0);
        solve(str,op1);
    }
}
// Time Complexity: exponential
// Space Complexity:O(2^no of chars)

int main()
{
    string str;
    cin>>str;
    string op="";
    solve(str,op);
    for(string str:ans)
    {
        cout<<str<<" ";
    }
    return 0;
}



/*
Another approach:
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        find the index of letters and store them into index vector
        let's take n is size of index vector 
        build all possible binary numbers of n bits
        here in our case "a1b2" has two letters a and b
        index contains = {0,2}
        size of index is 2
        we get 2^2 = 4 possible combinations of strings
        00, 01, 10, 11
        1 means lower case and 0 means upper case
        A1B2, A1b2, a1B2, a1b2 this is very much similar to binary representation
        
        vector <string> ans;
        vector <int> index;
        
        for(int i=0;i<S.size();i++)
        {
            if(isalpha(S[i]))
                index.push_back(i);
        }
        
        for(int i=0;i<1<<index.size();i++)
        {
            string temp=S;
            int num=i;
            for(int j:index)
            {
                if(num&1)
                    temp[j]=tolower(temp[j]);
                else
                    temp[j]=toupper(temp[j]);
                num>>=1;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

*/