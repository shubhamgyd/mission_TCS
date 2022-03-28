#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int  long long 
using namespace std;
#define endl '\n'
const int mod=1e9+7;
#define max_pq priority_queue<int>
#define min_pq priority_queue<int,vector<int>,greater<int>>
#define For(i,x,n) for(i=x; i<n; ++i)
#define pb push_back



bool isLeapYear(int year) 
{ 

    if (year % 400 == 0)  return true;  
    if (year % 100 == 0) return false; 
    if (year % 4 == 0) return true; 
    return false; 
} 


int returnDay(int year,int month,int day)
{
    static int tD[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return (year + year/4 - year/100 + year/400 + tD[month-1] + day) % 7;
}

void  Solution()
{
    string input;
    getline(cin,input);
    string dated="";
    string dayofW="";
    int n=0;
    stringstream ss(input);
    string word;
    int i=0;
    while(ss>>word)
    {
        if(i==0)
        {
            dated=word;
            i++;
        }
        else if(i==1)
        {
            dayofW=word;
            i++;
        }
        else if(i==2)
        {
            n=stoi(word);
        }
    }
    int is_prime[366];
    for(int i=0;i<366;i++)
    {
        is_prime[i]=1;
    }
    is_prime[0]=is_prime[1]=0;
    for(int i=2;i<=365;i++)
    {
        if(is_prime[i])
        {
            for(int j=i*i;j<=365;j+=i)
            {
                is_prime[j]=0;
            }
        }
    }

    vector<int>ans;
    for(int i=2;i<=365;i++)
    {
        if(is_prime[i])
        {
            ans.push_back(i);
        }
    }

    map<int,string>Days;
    Days[0]="Sun";
    Days[1]="Mon";
    Days[2]="Tue";
    Days[3]="Wed";
    Days[4]="Thu";
    Days[5]="Fri";
    Days[6]="Sat";

    map<int,int>Month;
    Month[1]=31;
    Month[2]=28;
    Month[3]=31;
    Month[4]=30;
    Month[5]=31;
    Month[6]=30;
    Month[7]=31;
    Month[8]=31;
    Month[9]=30;
    Month[10]=31;
    Month[11]=30;
    Month[12]=31;
    
    int TotalDay=-1;

    int year1=stoi(dated.substr(0,4));
    int month1=stoi(dated.substr(4,2));
    int day1=stoi(dated.substr(6));
    int flag=1;
    for(auto it:ans)
    {
        int year=year1;
       int month=month1;
       int currentDay=day1;
       int tracker=currentDay;
        int dayTotal=day1+it;
        while(tracker!=dayTotal)
        {
            if(month==2 && isLeapYear(year) && currentDay==29)
            {
                month++;
                currentDay=1;
            }
            else if(month==2 && !isLeapYear(year) && currentDay==28)
            {
                month++;
                currentDay=1;
            }
            else if(currentDay==Month[month])
            {
                currentDay=1;
                month++;
            }
            else
            {
                currentDay++;
            }
            tracker++;
            if(month>12)
            {
                month%=12;
                year++;
            }
        }

        string finalDay=Days[returnDay(year,month,currentDay)];
        if(is_prime[month] && finalDay==dayofW)
        {
            flag=1;
            TotalDay=it;
            break;
        }
    }

    if(TotalDay==-1)
    {
        cout<<"No 0";
    }
    else if(TotalDay<=n)
    {
        cout<<"Yes "<<TotalDay;
    }
    else 
    {
        cout<<"No "<<TotalDay;
    }

    
}

signed main()
{
    Solution();
}