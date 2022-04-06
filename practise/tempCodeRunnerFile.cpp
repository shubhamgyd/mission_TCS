#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int>res={1,2,3,6,7,8,9};
    auto ale=upper_bound(res.begin(),res.end(),4)-res.begin();
    cout<<ale<<endl;
    return 0;
}