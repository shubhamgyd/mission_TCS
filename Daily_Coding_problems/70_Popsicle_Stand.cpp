/*
This question is asked by Amazon. You’re running a popsicle stand where each popsicle costs $5. 
Each customer you encountered pays with either a $5 bill, a $10 bill, or a $20 bill and only
 buys a single popsicle. the customers that come to your stand come in the ordered given by 
 the customers array where customers[i] represents the bill the ith customer pays with.
  Starting with $0, return whether or not you can serve all the given customers while 
  also giving the correct amount of change.

Ex: Given the following customers…

customers = [5, 10], return true
collect $5 from the first customer, pay no change.
collet $10 from the second customer and give back $5 change.

Ex: Given the following customers…

customers = [10], return false
collect $10 from the first customer and we cannot give back change.

Ex: Given the following customers…

customers = [5,5,5,10,20], return true
collect $5 from the first 3 customers.
collet $10 from the fourth customer and give back $5 change.
collect $20 from the fifth customer and give back $10 change ($10 bill and $5 bill).

*/

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
    int five=0;
    int ten=0;
    int total=0;
    for(int i=0;i<n;i++)
    {
        if(res[i]==5)
        {
            five++;
            // cout<<"Total five is: "<<five<<endl;
            total+=res[i];
        }
        else
        {
            if(res[i]==10)
            {
                if(five)
                {
                    total+=10;
                    ten++;
                    five--;
                    total-=5;
                }
                else
                {
                    cout<<"False"<<endl;
                    return 0;
                }
            }
            else if(res[i]==20)
            {
                if(five and ten)
                {
                    five--;
                    ten--;
                    total+=20;
                    total-=10;
                    total-=5;
                }
            }
        }
    }
    // total=5*five+10*ten;
    cout<<"True"<<" "<<total<<endl;
    return 0;
}

// Time Complexity:O(n)
// Space Complexity:O(1)