// #include <bits/stdc++.h>
// using namespace std;

// string trim(string);


// int LXCPS(int N, vector<int> A, int M, vector<int> B) {
//     map<int,int> mp;
//     for(int i=0;i<M;i++)
//     {
//         mp[B[i]]++;
//         for(int j=2;j<=B[i]/2;j++)
//         {
//             if(B[i]%j==0)
//                 mp[j]++;
//         }
//     }
//     int count = 0;
//     for(auto iter=mp.begin();iter!=mp.end();++iter)
//         cout<<int(iter->first)<<"  ";
//     cout<<endl;
//     for(int j=0;j<N;j++)
//     {
//         if(mp[A[j]]==0 && A[j]!=1)
//         {
//             cout<<A[j]<<"  "<<"if"<<"  ";
//             int flag = 0;
//             for(auto iter=mp.begin();iter!=mp.end();++iter)
//             {
//                 cout<<"  "<<int(iter->first)<<"  ";
//                 if(A[j]%int(iter->first)==0 && int(iter->first)!=1)
//                 {
//                     flag = 1;
//                     break;
//                 }
//             }
//             if(flag==0)
//                 count++;
//             cout<<endl;
//         }
//     }
//     if(count==0)
//         return -1;
//     else
//         return count;
// }


// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     string inputline;

//     getline(cin, inputline);
//     int N = stoi(trim(inputline));
    
//     vector<int> A(N);
//     for(int j=0; j<N; j++) {
//         getline(cin, inputline);
//         A[j] = stoi(trim(inputline));
//     }
    
//     getline(cin, inputline);
//     int M = stoi(trim(inputline));
    
//     vector<int> B(M);
//     for(int j=0; j<M; j++) {
//         getline(cin, inputline);
//         B[j] = stoi(trim(inputline));
//     }

//     int result = LXCPS(N, A, M, B);

//     cout << result << "\n";

//     return 0;
// }


// /* Utility functions. Don't modify these */
// string trim(string str){
//   if(str.empty())
//       return str;

//   size_t firstScan = str.find_first_not_of(' ');
//   size_t first     = firstScan == string::npos ? str.length() : firstScan;
//   size_t last      = str.find_last_not_of(' ');
//   return str.substr(first, last-first+1);
// }


#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin>>n;
	vector<int>res(n);
	unordered_map<int,int>mp;
	for(int i=0;i<n;i++)
	{
		cin>>res[i];
		mp[res[i]]++;
	}
	int m;
	cin>>m;
	vector<int>temp(m);
	for(int i=0;i<m;i++)
	{
		cin>>temp[i];
	}
	vector<set<int>>facts(10001);
	vector<bool>visited(10001,true);
	for(int j=0;j<n;j++)
	{
		int num=res[j];
		for(int i=2;i<=sqrt(num);i++)
		{
			if(num%i==0)
			{
				if (num/i == i) facts[num].insert(i);
 
				else{
					facts[num].insert(i);
					facts[num].insert(num/i);
				}
			}
		}
		facts[num].insert(num);
	}

	for(int j=0;j<m;j++)
	{
		int num=temp[j];
		for(int i=2;i<=sqrt(num);i++)
		{
			if(num%i==0)
			{
				if(num/i==i)
				{
					for(int k=2;k<=10000;k++)
					{
						if(visited[k])
						{
							if(facts[k].find(i)!=facts[k].end())
							{
								// cout<<"K: "<<k<<endl;
								visited[k]=false;
							}
						}
					}
				}
				else
				{
					for(int k=2;k<=10000;k++)
					{
						if(visited[k])
						{
							if(facts[k].find(i)!=facts[k].end() || facts[k].find(num/i)!=facts[k].end())
							{
								// cout<<"K: "<<k<<endl;
								visited[k]=false;
							}
						}
					}
				}
			}
		}
		for(int i=2;i<=10000;i++)
			{
				if(facts[i].find(num)!=facts[i].end())
				{
					visited[i]=false;
				}
			}
	}

	int len=0;
	for(int i=2;i<=10000;i++)
	{
		if(visited[i] && facts[i].size()>0)
		{
			len+=mp[i];
		}
	}
	if(len==0)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<len<<endl;
	}
	return 0;
}