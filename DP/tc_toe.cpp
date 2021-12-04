#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    auto it=str.find('a');
    if(it!=string::npos)
    {
        str.erase(str.begin()+it);
    }
    cout<<str<<endl;
}