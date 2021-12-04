#include<bits/stdc++.h>
using namespace std;


int main()
{
	multiset<int>st;
	for(int i=1;i<=10;i+=2)
	{
		st.insert(i);
	}
	for(auto it:st)
	{
		cout<<it<<" ";
	}
	cout<<endl;
	auto it=st.lower_bound(6);
	cout<<*it<<endl;
}