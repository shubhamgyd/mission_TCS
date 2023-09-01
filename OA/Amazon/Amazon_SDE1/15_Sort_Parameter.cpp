#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<string,pair<int,int>>a,pair<string,pair<int,int>>b)
{
    return a.first<b.first;
}


bool cmp1(pair<string,pair<int,int>>a,pair<string,pair<int,int>>b)
{
    return a.second.first<b.second.first;
}


bool cmp2(pair<string,pair<int,int>>a,pair<string,pair<int,int>>b)
{
    return a.second.second<b.second.second;
}




bool cmp10(pair<string,pair<int,int>>a,pair<string,pair<int,int>>b)
{
    return a.first>b.first;
}


bool cmp11(pair<string,pair<int,int>>a,pair<string,pair<int,int>>b)
{
    return a.second.first>b.second.first;
}


bool cmp12(pair<string,pair<int,int>>a,pair<string,pair<int,int>>b)
{
    return a.second.second>b.second.second;
}



int main()
{
    int n;
    cin>>n;
    vector<pair<string,pair<int,int>>>res;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        int a,b;
        cin>>a>>b;
        res.push_back({str,{a,b}});
    }
    int sParam;
    cin>>sParam;
    int sOrder;
    cin>>sOrder;
    int perPage,Page;
    cin>>perPage>>Page;
    if(sOrder==0 && sParam==0)
    {
        sort(res.begin(),res.end(),cmp);
    }
    else if(sOrder==0 && sParam==1)
    {
        sort(res.begin(),res.end(),cmp1);
    }
    else if(sOrder==0 && sParam==2)
    {
        sort(res.begin(),res.end(),cmp2);
    }

    else if(sOrder==1 && sParam==0)
    {
        sort(res.begin(),res.end(),cmp10);
    }

    else if(sOrder==1 && sParam==1)
    {
        sort(res.begin(),res.end(),cmp11);
    }

    else if(sOrder==1 && sParam==2)
    {
        sort(res.begin(),res.end(),cmp12);
    }

    int ct=0;
    int i=0;
    while(i<n && ct!=Page)
    {
        i+=perPage;
        ct++;
    }
    for(i;i<i+perPage && i<n;i++)
    {
        cout<<res[i].first<<" ";
    }
    return 0;
}