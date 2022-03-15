#include<bits/stdc++.h>
#include<sstream>
using namespace std;
class st
{
public:
        int ID1;
        double PER1;
        string COL1, COL2, COL3;
        st(int ID2,double PER2,string COL11,string COL21,string COL31)
        {
            ID1=ID2;  PER1=PER2;
            COL1=COL11;  COL2=COL21;  COL3=COL31;
        }
};

static bool compare(st a,st b)
{
    if(a.PER1==b.PER1)
        return a.ID1<b.ID1;
    return a.PER1>b.PER1;
}

void RES()
{
    int C,N;
    cin>>C>>N;
    vector<int>myres(C+1);
    for(int i=1;i<=C;i++)
        cin>>myres[i];
    vector<st>data;
    for(int i=0;i<N+1;i++)
    {
        int ID, j=0;
        double PER;
        string C1,C2,C3,IN,w;
        getline(cin,IN);
        replace(IN.begin(), IN.end(), ',', ' ');
        stringstream mystring(IN);
        while(mystring>>w)
        {
            if(j==0)
            {
                string temp=w.substr(8);
                ID=stoi(temp);  j++;
            }
            else if(j==1)
            {
                PER=atof(w.c_str());  j++;
            }
            else if(j==2)
            {
                C1=w;  j++;
            }
            else if(j==3)
            {
                C2=w;  j++;
            }
            else if(j==4)
            {
                C3=w;  j++;
            }
        }
        data.push_back(st(ID,PER,C1,C2,C3));
    }
    sort(data.begin(),data.end(),compare);
    vector<double>CutOff(C+1,200.00);
    for(int i=0;i<N;i++)
    {
        int id,c1,c2,c3;
        id=data[i].ID1;
        c1=stoi(data[i].COL1.substr(2));  c2=stoi(data[i].COL2.substr(2));  c3=stoi(data[i].COL3.substr(2));
        if(myres[c1]>0)
        {
            // cout<<"Student-"<<id<<" "<<data[i].COL1<<'\n';
            CutOff[c1]=min(CutOff[c1],data[i].PER1);
            myres[c1]--;
        }
        else if(myres[c2]>0)
        {
            // cout<<"Student-"<<id<<" "<<data[i].COL2<<'\n';
            CutOff[c2]=min(CutOff[c2],data[i].PER1);
            myres[c2]--;
        }
        else if(myres[c3]>0)
        {
            // cout<<"Student-"<<id<<" "<<data[i].COL3<<'\n';
            CutOff[c3]=min(CutOff[c3],data[i].PER1);
            myres[c3]--;
        }
    }
    sort(CutOff.begin(),CutOff.end());
}


int main()
{
    RES();
    return 0;
}