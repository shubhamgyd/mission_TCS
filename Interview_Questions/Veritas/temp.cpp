#include<bits/stdc++.h>
using namespace std;

void foo(char w[])
{
    w++;
    cout<<(*w)<<endl;
    w++;
    cout<<(*w)<<endl;
}

int main()
{
    char ch[100];
    ch[0]='a';
    ch[1]='b';
    ch[2]='c';
    ch[4]='d';
    foo(ch);

}