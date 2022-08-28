#include<iostream>
using namespace std;

int main()
{
    string largeString,smallString;
    cin>>largeString>>smallString;
    int len=largeString.length();
    int j=0;
    for(int i=0;i<smallString.length();i++)
    {
        char currChar=smallString[i];
        bool found=false;
        while(j<len)
        {
            if(largeString[j]==currChar)
            {
                found=true;
                break;
            }
            j++;
        }
        if(!found)
        {
            cout<<"No\n";
            return 0;
        }
        j++;
    }
    cout<<"Yes\n";
    return 0;
}