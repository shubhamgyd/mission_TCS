#include <bits/stdc++.h>

using namespace std;

vector<string> sep(string s){
    vector<string> vec;
    string str="";
   for(int i=0;i<s.length();i++){
       if(s[i]!=' '){
           str+=s[i];
       }
       else{
           vec.push_back(str);
           str="";
       }
   }
   vec.push_back(str);
   
   return vec;
    
}

int main()
{
   string s="I am using HackerRank to improve programming";
   string c="am HackerRank to improve";
   
   vector<string> vec=sep(s);
   vector<string> comp=sep(c);
   
   vector<string> res;
   
   for(int i=0,j=0;i<vec.size();i++){
       if(vec[i]!=comp[j]){
           res.push_back(vec[i]);
       }
       else{
           j++;
       }
   }
   
   for(string i:res){
       cout<<i<<endl;
   }
   
   return 0;
}