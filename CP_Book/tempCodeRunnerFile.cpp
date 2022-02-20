#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


bool checkPrime(int n)
{

    if (n < 2)
    {
        return false;
    }
    else if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }

    return true;
}

int SumOfPrimeDivisors(int n)
{

    long long int range = (long long int)sqrt(n);
    int sum = 0;

    for (int i = 1; i <= range; i++)
    {
        if (n % i == 0)
        {

            if (i == n / i && checkPrime(i))
            {
                sum += i;
            }
            else
            {

                if (checkPrime(i))
                {
                    sum += i;
                }
                if (checkPrime(n / i))
                {
                    sum += (n / i);
                }
            }
        }
    }

    return sum;
}


int32_t main(){
    int n;
    cin>>n;
    cout<<SumOfPrimeDivisors(n)<<endl;
    // vector<int>res;
    // for(int i=0;i<10;i++)
    // {
    //     res.push_back(i);
    // }
    // vector<int>temp(res.begin()+0,res.begin()+2+1);
    // for(auto it:temp)
    // {
    //     cout<<it<<" ";
    // }
    return 0;
}