#include<bits/stdc++.h>
using namespace std;
// #define int long long

string revers(string str)
{
    if(str.length()<=1) return str;
    string s=string(1,str[0]);
    string ss=string(str.substr(1));
    return revers(ss)+s;
}

void solve(vector<string>&s)
{
    for(int i=0;i<s.size();i++)
    {
        if(s[i].size()==0)
        {
            s.erase(s.begin()+i);
        }
    }
}

template<typename A,typename B>
void fun(A a,B& b)
{
    a+=1;
    b.push_back(1);
}




int main()
{
    function<int(int)>f;
    f=[&f](int n)->int{return (n<=1)?1:n*(f(n-1));};
    int ans=f(4);
    cout<<ans<<endl;
    int a=0;
    vector<int>b;
    fun(a,b);
    cout<<a<<"[";
    for(auto it:b)
    {
        cout<<it;
    }
    cout<<"]";
   
}



