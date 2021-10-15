// Programmm to find the coprime numbers bwteen 1 to n
#include<bits/stdc++.h>
using namespace std;
#define lli long long int


//Time complexity of below algorithm is O(sqrt(n))
int phi1(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}


// // Now optimised version of above algo run in O(nloglogn)
// void phi_1_to_n(int n)
// {
//     vector<int>phi(n+1);
//     phi[0]=0;
//     phi[1]=1;
//     for(int i=2;i<=n;i++)
//     {
//         phi[i]=i;
//     }
//     for(int i=2;i<=n;i++)
//     {
//         if(phi[i]==i)
//         {
//             for(int j=i;j<=n;j++)
//             {
//                 phi[j]-=phi[j]/i;
//             }
//         }
//     }
//     // for(auto ele: phi)
//     // {
//     //     cout<<ele<<" ";
//     // }
//     cout<<phi.size()<<endl;
// }


int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
    lli n;
    cin>>n;
    cout<<phi1(n)<<endl;
    }
    return 0;
}