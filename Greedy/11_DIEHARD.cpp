// In this problem we are going to find how much timer we will survive in three phse
/*
The game is simple. You initially have ‘H’ amount of health and ‘A’ amount of armor. At any instant you can live in any of the three places - fire, water and air. After every unit time, you have to change your place of living. For example if you are currently living at fire, you can either step into water or air.

If you step into air, your health increases by 3 and your armor increases by 2

If you step into water, your health decreases by 5 and your armor decreases by 10

If you step into fire, your health decreases by 20 and your armor increases by 5

If your health or armor becomes <=0, you will die instantly

Find the maximum time you can survive.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a==0 || b==0)
        {
            cout<<0<<endl;
        }
        else
        {
            int t=1;
            a+=3;
            b+=2;
            while(1)
            {
                if(a>5 && b>10)
                {
                    a-=2;
                    b-=8;
                    t+=2;
                }
                else if(a>20 && b<=10)
                {
                    a-=17;
                    b+=7;
                    t+=2;
                }
                else
                {
                    cout<<t<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}