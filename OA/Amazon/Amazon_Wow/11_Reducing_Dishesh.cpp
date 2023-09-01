#include<bits/stdc++.h>
using namespace std;

int maxpick(int ind,vector<int>&arr,int time){
    if(ind>=arr.size()){
        return 0;
    }

    int take = arr[ind]*(time) + maxpick(ind+1,arr,time+1);
    int nottake = 0 + maxpick(ind+1, arr,time);

    return max(take,nottake);
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    //vector<int>dp(n,-1);
    int ans = maxpick(0, arr,1);
    cout<<ans<<endl;
}