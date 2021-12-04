#include <bits/stdc++.h>
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
#define mod 1000000007
#define MAX_N 1000001
using namespace std;

struct info
{
    char name[50];
    int age;
    int id;
}Info[10];

int32_t main()
{
    fast();
    int user;
    deque<int>dq;
    cout<<"Enter number of users: ";
    cin>>user;
    if(user<3)
    {
        cout<<"Please enter number of users greter than 3..!!"<<endl;
        main();
    }
    for(int i=0;i<user;i++)
    {
        cin>>Info[i].name;
        cin>>Info[i].age;
        cin>>Info[i].id;
    }
    for(int i=0;i<user;i++)
    {
        cout<<Info[i].name<<" "<<Info[i].age<<" "<<Info[i].id<<endl;
    }
    return 0;
}
