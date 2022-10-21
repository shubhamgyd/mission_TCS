#include<bits/stdc++.h>
using namespace std;

int changeAds(int base10){
    
    int n = (int)(log2(base10));
    
    return (base10 ^ (1<<(n+1))-1);
    
}