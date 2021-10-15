

/*Problem Name: SUPW
Problem Difficulty: 
Problem Constraints: N < = 1000000
Problem Description:
In ICO School, all students have to participate regularly in SUPW. There is a different SUPW activity each day, and each activity has its own duration. The SUPW schedule for the next term has been announced, including information about the number of minutes taken by each activity.


Nikhil has been designated SUPW coordinator. His task is to assign SUPW duties to students, including himself. The school's rules say that no student can go three days in a row without any SUPW duty.


Nikhil wants to find an assignment of SUPW duty for himself that minimizes the number of minutes he spends overall on SUPW.

Input Format: A single integer N, the number of days in the future for which SUPW data is available.

 N non-negative integers, where the integer in position i represents the number of minutes required for SUPW work on day i.


Sample Input: 10
3 2 1 1 2 3 1 3 2 1
Output Format: The output consists of a single non-negative integer, the minimum number of minutes that Nikhil needs to spend on SUPW duties this term


Sample Output: 4



=====Solution=====
*/


#include<bits/stdc++.h>
#define ll long long int
#define cin(a,n) for(i=0;i<n;i++){cin>>a[i];}
#define fast ios_base:: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define forl(i,a,n) for(i=a;i<n;i++)
#define ld long double
#define cout(a,n) for(int h=0;h<n;h++)cout<<a[h]<<" ";
#define mod 1000000009
#define nl cout<<"\n";
#define de cout<<"here";
using namespace std;
int main()
{
    ll q,q1,j,i,n,m,k,ans=0,x,cnt=0,l=0,r;
    cin>>n;
    ll a[n+1];
    cin(a,n);
    a[n]=0;
    ll sum[n+1];
    sum[0]=a[0];
    sum[1]=a[1];
    sum[2]=a[2];
    forl(i,3,n+1){
        sum[i]=a[i]+min(sum[i-1],min(sum[i-2],sum[i-3]));
    }
    cout<<sum[n];
} 