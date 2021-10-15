
#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    if(A.length()==0 || A.length()==1)
		    {
		        return A;
		    }
		    string ans="";
            cout<<"Initial ans: "<<ans<<endl; 
		    string store="";
            cout<<"Initial store: "<<store<<endl;
		    map<char,int>mp;
		    store+=A[0];
		    mp[A[0]]++;
            int j=0;
		    char ch=store[j];
		    ans+=ch;
            cout<<"Initial char: "<<ch<<endl;
		    for(int i=1;i<A.length();i++)
		    {
                cout<<"For char: "<<A[i]<<endl;
                cout<<"Store: "<<store<<endl;
		        if(find(store.begin(),store.end(),A[i])!=store.end())
		        {
                    if(store.length()>1)
                    {
                        ch=store[++j];
                        ans.push_back(ch);
                    }
                    else
                    {
                        ans.push_back('#');
                        cout<<"Modified ans: "<<ans<<endl;
                        if(store.length()==1 && i+1<=A.length()-1)
                        {
                            ch=A[i+1];
                            j++;
                        }
                        else
                        {
                            ch=store[++j];
                        }
                    }
		        }
		        else
		        {
                    store.push_back(A[i]);
		            ans+=ch;
                    cout<<"Modified ans: "<<ans<<endl;
		        }
		    }
		    return ans;
		}

};

int main()
{
    string str="aaabcdefgbbb";
    Solution obj;
    cout<<obj.FirstNonRepeating(str)<<endl;
}