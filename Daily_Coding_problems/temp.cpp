#include<bits/stdc++.h>
using namespace std;

string StringChallenge(string str) {
  
  // code goes here
  string  res="";
  string res1="";
  int n=str.length();
  bool ok=false;
  for(int i=0;i<n;i++)
  {
    if(str[i]=='*')
    {
      ok=true;
      continue;
    }
    if(ok==false)
    {
      res.push_back(str[i]);
    }
    if(ok)
    {
      res1.push_back(str[i]);
    }
  }
  string ans="";
  int sz1=res.length();
  int sz2=res1.length();
  int i=0;
  int j=0;
  while(i<sz1 || j<sz2)
  {
    if(i<sz1)
    {
      ans.push_back(res[i]);
    }
    if(j<sz2)
    {
      ans.push_back(res1[j]);
    }
    i++;
    j++;
  }
  return ans;

}

int main(void) { 
   
  // keep this function call here
  string str;
  cin>>str;
  cout << StringChallenge(str);
  return 0;
    
}