// In this problem we are going to see , which strings are same in a array of strings

#include<bits/stdc++.h>
using namespace std;

long long int compute_hash(string const& s)
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


vector<vector<int>> group_identical_strings(vector<string> const& v)
{
    int n=v.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {compute_hash(v[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}
int32_t main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    vector<string>v;
    cout<<"Enter strings : ";
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        v.push_back(str);
    }
    vector<vector<int>>sg{group_identical_strings(v)};
    for(auto it=sg.begin();it!=sg.end();++it)
    {
        cout<<it->front()<<endl;
    }
    return 0;
}