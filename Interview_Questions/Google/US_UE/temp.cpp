#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>nums={2,3,4,8,9,10};
    auto it=lower_bound(nums.begin(),nums.end(),6)-nums.begin();
    cout<<it<<endl;
}