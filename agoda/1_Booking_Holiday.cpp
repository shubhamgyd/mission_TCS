#include <bits/stdc++.h> 
using namespace std;

#define MAX_N 100005

int parent[MAX_N],sizeset [MAX_N];

void make(int v){

parent[v]=v; 
sizeset[v]=1;

}

int find(int v){

if(v==parent[v]) return v; 
return parent[v]=find (parent[v]);

}

void uni(int a,int b){

a=find(a);

b=find(b);

 if(a!=b){

    if(sizeset[a] <sizeset [b]) swap(a,b);

    parent[b]=a; 
    sizeset [a]+=sizeset [b];

}

}

string ans (int a,int b){

a=find(a);

b=find(b);

return (a==b)? "YES": "NO";

}

int main(){

ios_base::sync_with_stdio(false);

cin.tie(NULL);

int n,m,q;
cin>>n>>m>>n;


 for(int i=1;i<=n;i++) make(i);

for(int i=0;i<m;i++){ 

int a,b;
cin>>a>>b; 
uni(a,b);

}

while(q--){

int a,b; cin>>a>>b; 
cout<<ans (a,b)<<'\n';

}
}