#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Declaring the array of size 10
    // means we are storing the count of each digit occurs in a given number
    long long int arr[10];

    // initialise with 0
    for(int i=0;i<10;i++)
    {
        arr[i]=0;
    }

    // Iterate from start to end and count the occurance of each digit in each number
    for(long long int i=9999;i<=99999999;i++)
    {
        long long int num=i;
        // Digit counting
        while(num)
        {
            int reminder=num%10;
            arr[reminder]++;
            num/=10;
        }
    }

    // Printing the occurance of digits
    cout<<"Number"<<setw(10)<<"Occurnace"<<endl;
    for(int i=0;i<=9;i++)
    {
        cout<<i<<setw(15)<<arr[i]<<endl;
    }
    return 0;
}