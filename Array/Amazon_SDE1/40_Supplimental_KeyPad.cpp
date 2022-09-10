/*
A recently launched supplemental typing keypad gained significant popularity on Amazon 
Shopping due to its flexibility.

This keypad can be connected to any electronic device and has 9 buttons, 
where each button can have up to 3 lowercase English letters. 
The buyer has the freedom to choose which letters to place on a button while 
ensuring that the arrangement is valid. A keypad design is said to be valid if:

All 26 letters of the English alphabet exist on the keypad.

I

• Each letter is mapped to exactly one button.

• A button has at most 3 letters mapped to it.

Examples of some valid keypad designs are:
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int totalClicks=0;
    unordered_map<char,int>mp;
    mp['a']=1;
    mp['j']=2;
    mp['s']=3;
    mp['b']=1;
    mp['o']=2;
    mp['t']=3;
    mp['c']=1;
    mp['p']=2;
    mp['u']=3;
    mp['d']=1;
    mp['k']=2;
    mp['v']=3;
    mp['h']=1;
    mp['m']=2;
    mp['z']=3;
    mp['g']=1;
    mp['l']=2;
    mp['e']=1;
    mp['n']=2;
    mp['w']=3;
    mp['f']=1;
    mp['q']=2;
    mp['x']=3;
    mp['i']=1;
    mp['r']=2;
    mp['y']=3;
    for(auto it:str)
    {
        totalClicks+=mp[it];
    }
    cout<<totalClicks<<endl;
    return 0;
}