// #include<bits/stdc++.h>
// using namespace std;

// int maxScore(int N,int A[])
// {
//     sort(A,A+N);
//     int sum=0;
//     int i=0;
//     int j=N-1;
//     while(i<j)
//     {
//         sum+=A[j];
//         sum-=A[i];
//         i++;
//         j--;
//     }
//     if(N%2==1)
//     {
//         sum+=A[j];
//     }
//     return sum;

// }


// int main()
// {
//     int n;
//     cin>>n;
//     // vector<int>res(n);
//     int res[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>res[i];
//     }
//     int ans=maxScore(n,res);
//     cout<<ans<<endl;
// }


// #include<bits/stdc++.h>
// using namespace std;


// int main()
// {
//     int n;
//     cin>>n;
//     vector<string>res(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>res[i];
//     }
//     map<char,int>mp;
//     for(int i=0;i<n;i++)
//     {
//         for(auto it:res[i])
//         {
//             mp[it]++;
//         }
//     }
//     char ch='z';
//     int cnt=0;
//     for(auto it:mp)
//     {
//         if(it.second>cnt)
//         {
//             cnt=it.second;
//             ch=it.first;
//         }
//     }
//     map<string,int>store;
//     for(int i=0;i<n;i++)
//     {
//         string str=res[i];
//         if(find(str.begin(),str.end(),ch)!=str.end())
//         {
//             store[str]++;
//         }
//     }
//     cout<<ch<<endl;
//     cout<<store.size()<<endl;
//     for(auto it:store)
//     {
//         cout<<it.first<<endl;
//     }
//     return 0;
// }



#include <iostream>

using namespace std;

class hack_base
{
public:

void hack_func1()

{

cout << "One\n";

}

virtual void hack_func2()

cout << "Two\n";

virtual void hack_func3()

(


}

virtual void hack_func4()
{
    cout<<"Four"<<endl;
}
};