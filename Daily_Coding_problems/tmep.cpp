#include<bits/stdc++.h>
using namespace std;


int main()
{
	string s,t;
	cin>>s>>t;
	int k;
	cin>>k;
	bool ok=true;
	int n=s.length();
	for(int i=k;i<n;i++)
	{
		if(s[i]!=t[i])
		{
			ok=false;
			break;
		}
	}
	if(!ok)
	{
		cout<<"No"<<endl;
		return 0;
	}
	vector<int>res;
	for(int i=0;i<k;i++)
	{
		int num1=s[i]-'a';
		int num2=t[i]-'a';
		if(num2<num1)
		{
			int temp=25+num2;
			int ans=temp%26;
			res.push_back(ans);
		}
		else
		{
			int ans=num2-num1;
			res.push_back(ans);
		}
	}
	sort(res.begin(),res.end());
	vector<int>moves(k);
	for(int i=0;i<k;i++)
	{
		moves[i]=i+1;
	}
	if(res==moves)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
}