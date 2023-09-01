#include<bits/stdc++.h>
using namespace std;

static string  base64_encode(const string &in)
{
    string out;
    int val=0,valb=-6;
    for(auto c:in)
    {
        val=(val<<8)+c;
        valb+=8;
        while(valb>=0)
        {
            out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val>>valb)&0x3F]);
            valb-=6;
        }
    }
    if(valb>-6)
    {
        out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val<<8)>>(valb+8))&0X3F]);
    }
    while(out.size()%4)
    {
        out.push_back('=');
    }
    return out;
}

// static string base64_decode(const string &in)
// {
//     string out;
//     vector<int>res(256,-1);
//     for(int i=0;i<64;i++)
//     {
//         res["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]]=i;
//     }

//     int val=0,valb=-8;
//     for(auto it:in)
//     {
//         if(res[it]==-1) break;
//         val=(val<<6)+res[it];
//         valb+=6;
//         if(valb>=0)
//         {
//             out.push_back(char((val>>valb)&0xFF));
//             valb-=8;
//         }
//     }
//     return out;
// }

int32_t main()
{
    int n=5;
    map<char,string>mp;
    char ch='a';
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        mp[ch++]=str;
    }
    string str;
    cin>>str;
    map<char,string>mp1;
    for(auto it:mp)
    {
        string temp=it.second;

        if(temp.size()>=10 && temp.size()<=12)
        {
            int flag=0;
            int lower=0;
            int upper=0;
            int num=0;
            int special=0;
            string sp="#$@!%&*?";
            for(int i=0;i<temp.size()-1;i++)
            {
                if(islower(temp[i]))
                {
                    if(islower(temp[i+1]))
                    {
                        lower++;
                    }
                }
                else if(isupper(temp[i]))
                {
                    if(isupper(temp[i+1]))
                    {
                        upper++;
                    }
                }
                else if(isdigit(temp[i]))
                {
                    num++;
                }
                else if(sp.find(temp[i])!=string::npos)
                {
                    special++;
                }
            }
            if(num==0)
            {
                if(isdigit(temp[temp.size()-1]))
                {
                    num++;
                }
            }
            if(special==0)
            {
                if(sp.find(temp[temp.size()-1])!=string::npos)
                {
                    special++;
                }
            }

            if(lower==0)
            {
                flag=1;
                cout<<"Password must contain atleast two consecutive occurence of lower case characters"<<endl;
            }
            if(upper==0)
            {
                flag=1;
                cout<<"Password must contain atleast two consecutive occurence of upper case characters"<<endl;
            }
            if(num==0)
            {
                flag=1;
                cout<<"Password must contain atleast one digit"<<endl;
            }
            if(special==0)
            {
                flag=1;
                cout<<"Password must contain atleast one special character"<<endl;
            }
            if(flag)
            {
                continue;
            }

        }
        else
        {
            cout<<"Password must contain atleast 10 characters and at most 12 characters"<<endl;
            continue;
        }
        string ans=base64_encode(temp);
        mp1[it.first]=ans;
        cout<<"Encoded password for system-"<<it.first<<": "<<ans<<endl;
    }
    // string aa=base64_decode(str)
    if(mp.find(str[str.length()-1])!=mp.end())
    {
    cout<<"Reading Security Password for "<<str<<"....."<<mp[str[str.size()-1]]<<endl;
    }
    else
    {
        cout<<"Entered system is not available....."<<str<<endl;
    }
    return 0;
}