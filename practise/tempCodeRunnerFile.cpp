// #include<bits/stdc++.h>
// using namespace std;


// int main()
// {
//     int n;
//     cin>>n;
//     vector<int>res(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>res[i];
//     }
//     for(int i=0;i<n;i++)
//     {
//         if(res[i]%2==1)
//         {
//             int num=res[i]*res[i]*res[i];
//             cout<<num<<" ";
//         }
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    sort(res.begin(),res.end());
    if(n<3)
    {
        cout<<0<<endl;
        return 0;
    }
    int num=res[0];
    int num1=res[n-3];
    cout<<num*num1<<endl;
    
    return 0;
}