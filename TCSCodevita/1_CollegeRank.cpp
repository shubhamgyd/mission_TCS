#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


struct Student
{
    int id;
    double percentage;
    string c1;
    string c2;
    string c3;
    Student(int id1,double percentage1,string c11,string c21,string c31)
    {
        id=id1;
        percentage=percentage1;
        c1=c11;
        c2=c21;
        c3=c31;
    }
};

static bool cmp(Student a,Student b)
{
    if(a.percentage==b.percentage)
    {
        return a.id<b.id;
    }
    return a.percentage>b.percentage;
}

void solve()
{
    int c,n;
    cin>>c>>n;
    vector<int>res(c+1);
    for(int i=1;i<=c;i++)
    {
        cin>>res[i];
    }
    vector<Student>data;
    for(int i=0;i<n+1;i++)
    {
        int id;
        double percentage;
        string c1,c2,c3;
        string inp;
        getline(cin,inp);
        replace(inp.begin(), inp.end(), ',', ' ');
        int j=0;
        stringstream ss(inp);
        string word;
        while(ss>>word)
        {
            if(j==0)
            {
                string temp=word.substr(8);
                id=stoi(temp);
                j++;
            }
            else if(j==1)
            {
                percentage=atof(word.c_str());
                j++;
            }
            else if(j==2)
            {
                c1=word;
                j++;
            }
            else if(j==3)
            {
                c2=word;
                j++;
            }
            else if(j==4)
            {
                c3=word;
                j++;
            }
        }
        data.push_back(Student(id,percentage,c1,c2,c3));
    }
    sort(data.begin(),data.end(),cmp);
    for(int i=0;i<n;i++)
    {
        int id=data[i].id;
        int c1=stoi(data[i].c1.substr(2));
        int c2=stoi(data[i].c2.substr(2));
        int c3=stoi(data[i].c3.substr(2));
        if(res[c1]>0)
        {
            cout<<"Student-"<<id<<" "<<data[i].c1<<'\n';
            res[c1]--;
        }
        else if(res[c2]>0)
        {
            cout<<"Student-"<<id<<" "<<data[i].c2<<'\n';
            res[c2]--;
        }
        else if(res[c3]>0)
        {
            cout<<"Student-"<<id<<" "<<data[i].c3<<'\n';
            res[c3]--;
        }
    }
}


int main()
{
    solve();
    return 0;
}