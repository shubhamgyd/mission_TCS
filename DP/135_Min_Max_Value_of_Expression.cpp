#include <bits/stdc++.h>
using namespace std;
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long

pair<int,int> MaxMin(string str,int x,int y,int dp[1001][1001][2])
{
    if(x==y) return {str[x]-'0',str[x]-'0'};
    if(x>y) return {INT_MIN,INT_MAX};
    if(dp[x][y][0]!=-1 && dp[x][y][1]!=-1)
    {
        return {dp[x][y][0],dp[x][y][1]};
    }
    int mx=INT_MIN;
    int mn=INT_MAX;
    for(int i=x;i<y;i++)
    {
        pair<int,int>p=MaxMin(str,x,i-1,dp);
        pair<int,int>q=MaxMin(str,i+1,y,dp);

        if(str[i]=='+')
        {
            mx=max(mx,p.first+q.first);
            mn=min(mn,p.second+q.second);
        }
        if(str[i]=='*')
        {
            mx=max(mx,p.first*q.first);
            mn=min(mn,p.second*q.second);
        }
    }
    return {dp[x][y][0]=mx,dp[x][y][1]=mn};
}

int32_t main()
{
// #ifndef ONLINE_JUDGE
//     freopen("inputf.in", "r", stdin);
//     freopen("outputf.out", "w", stdout);
// #endif
    // fast();
    // string str;
    // cin>>str;
    string str="1+2*3+4*5";
    // getline(cin,str);
    int dp[1001][1001][2];
    memset(dp,-1,sizeof(dp));
    pair<int,int> p=MaxMin(str,0,str.length()-1,dp);
    cout<<"Max: "<<p.first<<endl;
    cout<<"Min: "<<p.second<<endl;
    return 0;
}














// C++ program to get maximum and minimum 
// values of an expression 
#include <bits/stdc++.h> 
using namespace std; 


// method prints minimum and maximum value 
// obtainable from an expression 
pair<int,int> printMinAndMaxValueOfExp(string exp,int x,int y,int dp[1001][1001][2]) 
{ 
  	if(x==y) return {exp[x]-'0',exp[x]-'0'};
	if(y<x) return {INT_MIN,INT_MAX};
  	if(dp[x][y][0]!=-1 && dp[x][y][1]!=-1)
    {
      return {dp[x][y][0],dp[x][y][1]};
    }
  	int mx=INT_MIN,mn=INT_MAX;
  	for(int i=x;i<y;i++)
    {
      		pair <int,int> p=printMinAndMaxValueOfExp(exp,x,i-1,dp);
      		pair <int,int> q=printMinAndMaxValueOfExp(exp,i+1,y,dp);
         if(exp[i]=='+')
         {
           mx=max(mx,p.first+q.first);
           mn=min(mn,p.second+q.second);
         }
          
       	 else if(exp[i]=='*')
         {
           mx=max(mx,p.first*q.first);
           mn=min(mn,p.second*q.second);
         }
          
    }
  return {dp[x][y][0]=mx,dp[x][y][1]=mn};
} 


// Driver code to test above methods 
int32_t main() 
{ 
	string expression ="1+2*3+4*5"; 
  	int dp[1001][1001][2];
  	memset(dp,-1,sizeof dp);
	pair<int,int> p=printMinAndMaxValueOfExp(expression,0,expression.length()-1,dp); 
  	cout<<p.first<<" "<<p.second<<endl;
	return 0; 
} 
