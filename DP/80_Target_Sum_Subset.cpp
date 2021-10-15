#include<bits/stdc++.h>
using namespace std;


void printTargetSumSubsets(vector<int>&arr, int idx, string st, int sos, int tar) {
        if(sos > tar){
            return;
        }

        if(idx == arr.size()){
            if(sos == tar){
                cout<<st<<""<<endl;
            }
            return;
        }


        printTargetSumSubsets(arr, idx + 1, st+to_string(arr[idx]) + ",", sos + arr[idx], tar);
        printTargetSumSubsets(arr, idx + 1, st, sos, tar);
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    printTargetSumSubsets(arr,0,"",0,30);
    return 0;
}