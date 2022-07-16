#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ind=1;
    int res=1;
    while(res<=n)
    {
        string str=to_string(ind);
        if(str.find('2')==string::npos and str.find("14")==string::npos)
        {
            res++;
        }
        ind++;
    }
    cout<<ind-1<<endl;
}