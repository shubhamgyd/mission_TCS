// 
#include<bits/stdc++.h>
using namespace std;


inline void TOH(int d,char tower1 , char tower2 ,char tower3)
{
    if(d==1)
    {
        cout<<"Shift top disk from tower "<<tower1<<" to tower "<<tower2<<endl;
        return;
    }
    TOH(d-1,tower1,tower3,tower2);
    cout<<"Shift top disk from tower "<<tower1<<" to tower "<<tower2<<endl;
    TOH(d-1,tower3,tower2,tower1);
}
int main()
{
    cout<<"Enter number of disks: ";
    int disk;cin>>disk;
    if(disk==1)
    {
        cout<<"There are no disks to shift: "<<endl;
        cout<<"Please Enter more than 1 disks: "<<endl;
        main();
    }
    else
    {
        cout<<"There are "<<disk<<" disks in tower 1"<<endl;
    }
    TOH(disk,'1','2','3');
    cout<<disk<<" disks in tower 1 are shifted to tower 2"<<endl;
    return 0;
}