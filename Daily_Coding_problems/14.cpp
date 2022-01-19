/*

This question is asked by Google. Given a string, return whether or not it uses capitalization 
correctly. A string correctly uses capitalization if all letters are capitalized, no letters are 
capitalized, or only the first letter is capitalized.

Ex: Given the following strings...

"USA", return true
"Calvin", return true
"compUter", return false
"coding", return true

*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    string str;
    cin>>str;
    bool ok1=all_of(str.begin(),str.end(),[](unsigned char c){return isupper(c);});
    bool ok2=all_of(str.begin(),str.end(),[](unsigned char c){return islower(c);});
    bool ok3=all_of(str.begin()+1,str.end(),[](unsigned char c){return islower(c);});
    bool ok4=isupper(str[0]);
    if(ok1 || ok2 || (ok4 && ok3))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}
// Time Complexity:O(n)
// Space Complexity:O(1)