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

static bool cmp(st a,st b)
{
    if(a.PER1==b.PER1)
        return a.ID1<b.ID1;
    return a.PER1>b.PER1;
}

static bool Comparator(pair<int,int>a,pair<int,int>b)
{
    return (a.first>b.first);
}

static bool Comp(pair<double,int>a,pair<double,int>b)
{
    return a.first>b.first;
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
    sort(data.begin(),data.end(),cmp);
    vector<double>finAns[C+1];
    for(int i=0;i<N;i++)
    {
        bool ok=false;
        int id,c1,c2,c3;
        double percentage=data[i].PER1;
        id=data[i].ID1;
        c1=stoi(data[i].COL1.substr(2));  c2=stoi(data[i].COL2.substr(2));  c3=stoi(data[i].COL3.substr(2));
        if(myres[c1]>0)
        {
            ok=true;
            finAns[c1].push_back(percentage);
            myres[c1]--;
        }
        else if(myres[c2]>0)
        {
            ok=true;
            finAns[c2].push_back(percentage);
            myres[c2]--;
        }
        else if(myres[c3]>0)
        {
            ok=true;
            finAns[c3].push_back(percentage);
            myres[c3]--;
        }
        if(!ok)
        {
            vector<pair<int,int>>temp;
            for(int i=1;i<=C;i++)
            {
                if(myres[i]>0)
                {
                    temp.push_back({myres[i],i});
                }
            }
            sort(temp.begin(),temp.end(),Comparator);
            int college=temp[0].second;
            finAns[college].push_back(percentage);
            myres[college]--;
        }
    }
    for(int i=1;i<C+1;i++)
    {
        sort(finAns[i].begin(),finAns[i].end());
    }
    vector<pair<double,int>>Output;
    vector<int>Rem;
    for(int i=1;i<=C;i++)
    {
        if(finAns[i].size()>0)
        {
            // cout<<"C-"<<i<<" "<<finAns[i][0]<<endl;
            Output.push_back({finAns[i][0],i});
        }
        else
        {
            Rem.push_back(i);
        }
    }
    sort(Output.begin(),Output.end(),Comp);
    for(auto it:Output)
    {
        cout<<"C-"<<it.second<<" "<<it.first<<endl;
    }
    for(auto it:Rem)
    {
        cout<<"C-"<<it<<" "<<"n/a"<<endl;
    }
}


int main()
{
    RES();
    return 0;
}