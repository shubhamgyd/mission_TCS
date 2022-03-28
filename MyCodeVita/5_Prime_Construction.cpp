#include<bits/stdc++.h>
using namespace std;
long long int gcd(int x, int y, int z)
{
    long max,lcom, count, flag=0;
        if(x>=y&&x>=z)
                max=x;
        else if(y>=x&&y>=z)
                max=y;
        else if(z>=x&&z>=y)
                max=z;
        for(count=1;flag==0;count++)
        {
                lcom=max*count;
                if(lcom%x==0 && lcom%y==0 && lcom%z==0)
                {
                        flag=1;
                }
        }
        return lcom;

}

bool check_prime(int n) {
  bool is_prime = true;


  if (n == 0 || n == 1) {
    is_prime = false;
  }

  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      is_prime = false;
      break;
    }
  }

  return is_prime;
}
int main()
{
        int a,b,c,d, flag,h=0,ans = 0,k;
        cin>>a>>b>>c>>d;
        h = gcd(a,b,c);
        ans = h + d;
        k = check_prime(ans);
        if(k == 1)
        cout<<ans<<endl;
        else if(k == 0)
        cout<<"None"<<endl;

}