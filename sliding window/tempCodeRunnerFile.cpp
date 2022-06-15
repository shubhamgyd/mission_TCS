#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    sort(res.begin(),res.end());
    int num=res[n-1];
    int i=n-1;
    int cnt=1;
    while(i>=0 and res[i]==num and cnt!=3)
    {
        i--;
    }
    int num1=res[i];
    cnt++;
    while(i>=0 and res[i]==num1 and cnt!=3)
    {
        i--;
    }
    cnt++;
    int num2=res[i];
    cout<<num-num2<<endl;
    return 0;
}