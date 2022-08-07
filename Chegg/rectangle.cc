#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s=to_string(n);
    replace( s.begin(), s.end(), '0', '5');
    cout<<s<<endl;
    return 0;
}