#include<bits/stdc++.h>
using namespace std;

int countDivisors(int n) { 
    int sum=0;
    int flag=0;
    int cnt = 0; 
    int f1=0;
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            // If divisors are equal, 
            // count only one 
            if (n / i == i) 
            {   sum+=i;
                cnt++; 
            }
            else // Otherwise count both 
            {    
                cnt = cnt + 2; 
                sum+=i;
                sum+=n/i;
            }

            // if(cnt>4)
            // {
            //     flag=1;
            //     break;
            // }
        }
        
    }
    return cnt==4?sum:0;
    //return cnt; 
} 

int main()
{
    cout<<countDivisors(21)<<endl;
    return 0;
}