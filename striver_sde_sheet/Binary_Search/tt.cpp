#include<iostream>
using namespace std;



int x=19;
int main()
{
    int x=21;
    {
        int x=41;
        cout<<::x<<x<<::x<<endl;
    }
}