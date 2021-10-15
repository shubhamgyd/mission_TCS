#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define MOD 1000000007
#define num1 1000000
#define pie 3.14
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define Bob cout<<"Bob"<<endl
#define Alice cout<<"Alice"<<endl
#define sz(x) (int)(x).size()
#define newMOD 1000000006
const int MAX = 10000000;
const int size=2*1e9;


ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a)%MOD;
        a = (a * a)%MOD;
        b >>= 1;
    }
    return res;
}


//Time complexity of below algorithm is O(sqrt(n))
int phi1(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int modpow(int x, int n, int m) {
    if (n == 0) return 1%m;
    long long u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}

tuple<int,int,int> extended_gcd(int a,int b)
{
    if(b==0)
    {
        return{1,0,a};
    }
    else
    {
        int x,y,g;
        tie(x,y,g)=extended_gcd(b,a%b);
        return {y,x-(a/b)*y,g};
    }
}

ll mul(ll a, ll b)
{
    return (1LL*a*b)%MOD;
}

ll ModPower(ll x , ll y , ll p)
{
    int ans=1;
    x=x%p;
    if(x==0)
    return 0;
    while(y>0)
    {
        if(y&1)
        {
            ans=(ans*x)%MOD;
        }
        y=y>>1;
        x=(x*x)%p;
    }
    return ans;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}



void Insertion(vector<int>&v,int n,int& inversion)
{
    int v1,v2;
    for(int i=1;i<n;i++)
    {
        int hole=i;
        int value=v[i];
        while(hole>0 && value<v[hole-1])
        {
            v[hole]=v[hole-1];
            hole--;
            inversion++;
            v1=v[hole-1];
            v2=v[hole];
        }
    }
    if(inversion==1)
    {
        yes;
        cout<<v1<<" "<<v2<<endl;
    }
    else
    {
        no;
    }
}


bool cmp(pair<char,pair<int,int>>p, pair<char,pair<int,int>>p1)
{
    if(p.second.second!=p1.second.second)
    {
        return p.second.second>p1.second.second;
    }
    else
    {
        return p.second.first<p1.second.first;
    }
}

int MinimumCost(int X[],int Y[],int m, int n)
{
    sort(X,X+m,greater<int>());
    sort(Y,Y+n,greater<int>());
    int vert=1,horiz=1;
    int i=0,j=0;
    int res=0;
    while(i<m && j<n)
    {
        if(X[i]>Y[j])
        {
            res+=X[i]*vert;
            horiz++;
            i++;
        }
        else
        {
            res+=Y[j]*horiz;
            vert++;
            j++;
        }
    }

    int total=0;
    while(i<m)
    {
        total+=X[i++];
    }
    res+=total*vert;

    total=0;
    while(j<n)
    {
        total+=Y[j++];
    }
    res+=total*horiz;
    return res;

}
bool cmp(int a,int b)
{
    return a>b;
}

bool compare(pair<int,int>a,pair<int,int>b)
{
    return a.first>b.first;
}

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())
        {
            return 0;
        }
        if(wordList.size()==2)
        {
            if(wordList[0]==beginWord && wordList[1]==endWord)
            {
                return 0;
            }
        }
        if(beginWord==endWord)
        {
            return 0;
        }
        string word=beginWord;
        cout<<"Initial Word: "<<word<<endl;
        int count=0;
        cout<<"Initial Count: "<<count<<endl;
        for(int i=0;i<wordList.size();i++)
        {
            //int x=word.compare(wordList[i]);
            if(word.length()==1 && wordList[i].length()==1 && word!=wordList[i])
            {
                break;
            }
            if(wordList[i]==endWord)
            {
                break;
            }
            int hash1[26]={0};
            int hash2[26]={0};
            for(int i=0;i<word.length();i++)
            {
                hash1[word[i]-'a']++;
            }
            string str=wordList[i];
            cout<<i<<"th string: "<<str<<endl;
            for(int i=0;i<str.length();i++)
            {
                hash2[str[i]-'a']++;
            }
            int ct=0;
            for(int i=0;i<26;i++)
            {
                cout<<hash1[i]<<" "<<hash2[i]<<endl;
                if(hash1[i]!=hash2[i])
                {
                    ct++;
                }
            }
            cout<<endl;
            if(ct/2==1)
            {
                count++;
                word=wordList[i];
            }
            else if(ct>1)
            {
                break;
            }
            
        }
        return count+2;
    }
};

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    fast();
    long long n;
    cin>>n;
    long long m;
    cin>>m;
    string str=to_string(n);
    sort(str.rbegin(),str.rend());
    string final="";
    for(long long int i=0;i<m;i++)
    {
        int k,l;
        cin>>k>>l;
        string ss="";
        for(int i=0;i<k;i++)
        {
            ss+=str[i];
        }
        final+=ss[l-1];

    }
    cout<<final<<endl;
    return 0;
}



//        6
//       / \
//     4    7
//    / \  / \
//   5   8 9  1

//   Depth=2
//   value=10
//   You have to insert value at Depth=2
//   like
       
//         6
//       /   \
//     4      7
//    / \     /  \
//   10   10 10   10
//   /    \  /     \
//   5     8 9      1    

//   consider depth starting from 0