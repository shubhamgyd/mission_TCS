#include <bits/stdc++.h>
using namespace std;

int* countOccruance(int *arr, int len , int value)
{
    int i,temp;
    int originalLen=len;
    for(int i = 0; i<originalLen/2; i++){
        temp = arr[i];
        arr[i] = arr[originalLen-i-1];
        arr[originalLen-i-1] = temp;
    }
    return arr;
    
}

int main()
{
    int arr[4]={1,2,3,4};
    countOccruance(arr,4,5);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p = log2(n) + 1;
        int X = n + 1;
        for (int i = 0; i < p; i++)
        {
            int count = 0;
            if (n & (1 << i))
            {
                count++;
            }
            if (count > (n / 2))
            {

                X += (1 << i);
            }
        }
        cout<<(n^X)<<endl;
    }
    return 0;
}