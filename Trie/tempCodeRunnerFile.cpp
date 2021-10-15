#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    

    stringstream ss(str);
    string word;
    int count=0;
    while(ss>>word)
    {
        word="$";
        cout<<word<<endl;
        count++;
    }
    
    cout<<count<<endl;
    return 0;
}