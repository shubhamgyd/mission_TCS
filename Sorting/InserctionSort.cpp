#include<bits/stdc++.h>
using namespace std;

void InserctionSort(vector<int>&v , int n,int& inversion)
{
    for(int i=1;i<n;i++)
    {
        int value=v[i]; // c1: Both of this statement executed in (n-1) times
        int hole=i;
        while(hole>0 && v[hole-1]>value) //c2: Executing depend on input size of array
        {
            v[hole]=v[hole-1];
            hole=hole-1;
            inversion++;
        }
        v[hole]=value; //c3: Execute in (n-1) time
    } 
}

// So total time complexity T(n)= (n-1)*(c1+c3) +n*(n-1)/2 ==O(n^2)

//For average case, we can assume that T(n) = (c1+c3)*(n-1)+{1+2+3+4+ ... +n-1}*(c2/2)
// We can assume that inner loop will run i/2  times for each i, and not i times. 
//So, 2nd term in expression will be n(n-1)*c2/2 .. Still it will be something like an^2 + bn + c

int main()
{
    vector<int>v;
    int n;
    cout<<" Enter a number: ";
    cin>>n;
    int inversion=0;
    while(n--)
    {
        int a;cin>>a;
        v.push_back(a);
    }
    InserctionSort(v,v.size(),inversion);
    cout<<"Sorted array by Inserction sort:";
    for(auto &ele:v)
    {
        cout<<ele<<" ";
    }
    cout<<"\nInversion are: "<<inversion<<endl;
    return 0;
}