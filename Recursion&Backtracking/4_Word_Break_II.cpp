// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    vector<string>res;

    /* A utility function to check whether a word
  is present in dictionary or not.  An array of
  strings is used for dictionary.  Using array
  of strings for dictionary is definitely not
  a good idea. We have used for simplicity of
  the program*/

    bool Contain(vector<string>&dict,string word)
    {
        int n=dict.size();
        for(int i=0;i<n;i++)
        {
            if(dict[i].compare(word)==0)
            {
                return true;
            }
        }
        return false;
    }
    void Word(vector<string>&dict,string s,int n,string str)
    {
        // Check for every substring one by one
        for(int i=1;i<=n;i++)
        {
            //Process substring from 0 to i
            string pre=s.substr(0,i);


            // If dictionary conatins this prefix, then
        // we check for remaining string. Otherwise
        // we ignore this prefix (there is no else for
        // this if) and try next

            if(Contain(dict,pre))
            {
                if(i==n)
                {
                    str+=pre;
                    res.push_back(str);
                    return;
                }
                Word(dict,s.substr(i,n-i),n-i,str+pre+" ");
            }
        }
    }
    
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        string str="";
        Word(dict,s,s.size(),str);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends