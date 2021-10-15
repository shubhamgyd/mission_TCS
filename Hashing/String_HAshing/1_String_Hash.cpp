// In this program we are going to calculate the hash value of a given string
#include<bits/stdc++.h>
using namespace std;

unsigned long int HashValue(string const& s)
{
    const int p=31;
    const int m=1e9+9;
    long long hash_value=0;
    long long p_pow=1;
    for(char c:s)
    {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow=(p_pow*p)%m;
    }
    return hash_value;

}

// Time complexity = O(n)

int32_t main()
{
    string str;
    cin>>str;
    cout<<"Hash Value of given string is: "<<HashValue(str);
    return 0;
}


