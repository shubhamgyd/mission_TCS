#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define nline "\n"
string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
map<string, int> mp = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
void solve(){
    string s;
    cin >> s;
    vector<int> v(200, 0);
    vector<int> res(10, 0);

    for(char c : s) v[c]++;
    int i = 0;
    while(i < 9){
        bool f = true;
        for(char c : arr[i]){
            if(!v[c]){
                f = false;
                break;
            }
        }
        if(f){
            for(char c : arr[i]) v[c]--;
            res[mp[arr[i]]]++;
        }else{
            i++;
        }
    }
    string ans = "";
    for(int i = 1; i <= 9; i++){
        while(res[i]){
            ans += to_string(i);
            res[i]--;
        }
        if(ans.size()) break;
    }
    while(res[0]){
        ans += '0';
        res[0]--;
    }
    for(int i = 2; i <= 9; i++){
        while(res[i]){
            ans += to_string(i);
            res[i]--;
        }
    }
    while(ans.size() > 1 && ans.back() == '0'){
        ans.pop_back();
    }
    cout << ans << nline;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin>>tc;
    while(tc--) {
        solve();
    }
    return 0;
}