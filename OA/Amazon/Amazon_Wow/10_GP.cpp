#include<bits/stdc++.h>
using namespace std;

int main()
{
    double second,third,n;
    cin>>second>>third>>n;
    double commonRatio=third/second;
    double first=second/commonRatio;
    double rPow=pow(commonRatio,n-1);
    double nthTermp=first*rPow;
    cout<<"first: "<<first<<endl;
    cout<<"commonRation: "<<commonRatio<<endl;
    cout<<"rPow: "<<rPow<<endl;
    cout<<fixed<<setprecision(3)<<nthTermp<<endl;
    return 0;

}