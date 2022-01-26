#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int>res={1,2,3,5,7};
    auto ele=lower_bound(res.begin(),res.end(),6);
    cout<<*ele<<endl;
    return 0;
}