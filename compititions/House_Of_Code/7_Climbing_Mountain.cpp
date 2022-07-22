#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],answer=0;
    for(int i=0;i<n;i++)
    cin>>a[i];
    answer=a[0];
    for(int i=0;i<n-1;i++)
    {
        if(a[i]<a[i+1])
        {
            answer+=a[i+1]-a[i];
        }
    }
    cout<<answer;
    return 0;
}