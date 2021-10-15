#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono;
#define endl '\n'
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define lli long long int
#define str string

void AlternativeBinary(int arr[],int n,int x)
{
  int k=0;
    for(int b=n/2;b>=1;b/=2)
    {
      while(k+b<n&&arr[k+b]<=x)
      {
          k+=b;
      }
    }
    if(arr[k]==x)
    {
      cout<<"Element found at index: "<<k<<endl;
    }
    else
    {
      cout<<"Element is not present in the given array "<<endl;
    }
    return;
}

int main()
{
    fast();
    auto start = high_resolution_clock::now();
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=9;
    AlternativeBinary(arr,n,x);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}
