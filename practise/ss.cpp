#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int temp=n;
    string str;
    char bin=' ';
    while(n!=0)
    {
        bin=n%2+'0';
        str+=bin;
        n/=2;
    }
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    cout<<bitset<8>(temp)<<endl;
    // cout<<(all_bits^temp)<<endl;
}