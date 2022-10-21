#include<bits/stdc++.h>
using namespace std;


void closestNumbers(vector<int>numbers)
{
    sort(numbers.begin(),numbers.end());
    vector<int> diff;
    vector<int> res;
    
    for(int i=1;i<numbers.size();i++){
        diff.push_back(numbers[i]-numbers[i-1]);
    }
    int mn=*min_element(diff.begin(),diff.end());
    
    for(int i=0;i<diff.size();i++){
        if(diff[i]==mn){
            res.push_back(numbers[i]);
            res.push_back(numbers[i+1]);
        }
    }
    
    for(int i=0;i<res.size();i+=2){
        cout<<res[i]<<" "<<res[i+1]<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    {
        cin>>res[i];
    }
    closestNumbers(res);
}




// #include <bits/stdc++.h>
// #define fast()                        \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL);
// #define int  long long 
// using namespace std;
// #define endl '\n'

// int x=0;

// void solve(){
//     int num;cin>>num;int mNum = num;int sumNum = 0;vector<int> vec;
//     while(mNum > 0){
//         int res = mNum%10;sumNum += res;vec.push_back(res);mNum = mNum/10;
//     }
//     reverse(vec.begin(),vec.end());int length = vec.size();
//     int valueLength = 9 - (sumNum%9);
//     if(valueLength <= vec[0]){
//         int uNum = vec[length-1];vec.push_back(uNum);length = vec.size();
//         for(int i=length;i>=1;i--){ vec[i] = vec[i-1];}
//         vec[0] = valueLength;
//     }else{vec.push_back(valueLength);length = vec.size();
//     }
//     int ansFinal = 0;
//     for(int i=0;i<length;i++){ansFinal = ansFinal *10+vec[i];}
//     cout<<"Case #"<<++x<<": "<<ansFinal<<endl;
// }






// signed main()
// {
// #ifndef ONLINE_JUDGE
//         freopen("inputf.in", "r", stdin);
//         freopen("outputf.out", "w", stdout);
// #endif
//     fast();
//     int t;
//     cin >> t;
//     for(int ii=1;ii<=t;ii++)
//     {
//         solve();
//     }
    
//     return 0;
// }