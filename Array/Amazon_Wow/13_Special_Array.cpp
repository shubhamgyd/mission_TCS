#include<bits/stdc++.h>
using namespace std;

// https://www.careercup.com/question?id=5204882156421120

bool isCheck(string num1)
{
    string str=num1;
    int num=stoi(num1);
    int n=str.length();
    if( (num<20 and num%2==0 ) or (n==2 and num%11==0)) return true;
    if(n<=2 and num%2!=0) return false;
    char first=str[0];
    char second=str[1];
    string s="";
    for(int i=2;i<n-2;i++)
    {
        s.push_back(str[i]);
    }
    char third=str[n-2];
    char forth=str[n-1];
    if(first=='1')
    {
        if(second==forth)
        {
            string temp=s;
            if(third!='0')
            {
                int t=(third-'0');
                t-=1;
                char c=(t+'0');
                temp.push_back(c);
            }
            else
            {
                temp.push_back('9');
            }
            // int number=stoi(temp);
            isCheck(temp);
        }
        else if((second-'0')-1==(forth-'0'))
        {
            string temp="1";
            temp+=s;
            if(third!='0')
            {
                int t=(third-'0');
                t-=1;
                char c=(t+'0');
                temp.push_back(c);
            }
            else
            {
                temp.push_back('9');
            }
            // int number=stoi(temp);
            isCheck(temp);
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(first==forth)
        {
            string temp="";
            temp.push_back(second);
            temp+=s;
            temp.push_back(third);
            // int number=stoi(temp);
            isCheck(temp);
        }
        else if((first-'0')-1==(forth-'0'))
        {
            string temp="1";
            temp.push_back(second);
            temp+=s;
            temp.push_back(third);
            // int number=stoi(temp);
            isCheck(temp);
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<string>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(isCheck(res[i])) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
    
}