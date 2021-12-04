#include<bits/stdc++.h>
using namespace std;


vector<pair<string,string>> preprocess(vector<string> &list){
    //we will find the string before the first ' '
    vector<pair<string,string>> ans;
    int n=list.size();

    for(int i=0;i<n;i++){
        string s=list[i];
        int index=0;
        while(index<s.size() && s[index]!=' ')
            index++;

        //we will store the data as {metadata,id}
        string id=s.substr(0,index);
        string metadata=s.substr(index+1);
        ans.push_back({metadata,id});
    }
    return ans;
}

vector<string> join(vector<pair<string,string>> &orders){
    vector<string> ans;
    for(int i=0;i<orders.size();i++){
        string id=orders[i].second,metadata=orders[i].first;
        string orderData=id+" "+metadata;
        ans.push_back(orderData);
    }
    return ans;
}

bool compare(const pair<string,string> &a,const pair<string,string> &b){
    //if both orders are prime orders
    string s1=a.first,s2=b.first;
    if((s1[0]>='a' && s1[0]<='z') && (s2[0]>='a' && s2[0]<='z')){
        for(int i=0;i<s1.size(),i<s2.size();i++){
            if(s1[i]<s2[i])
                return true;
            if(s1[i]>s2[i])
                return false;
        }

        //now if both the metadata are equal, we will compare the value
        string id1=a.second,id2=b.second;
        for(int i=0;i<id1.size(),i<id2.size();i++){
            if(id1[i]<id2[i])
                return true;
            if(id1[i]>id2[i])
                return false;
        }

        //if both the id and metadata are equal, maintain the sequence from the order list
        return false;
    }

    //if only first order is prime
    if(s1[0]>='a' && s1[0]<='z')
        return true;

    //if only the second order is prime
    if(s2[0]>='a' && s2[0]<='z')
        return false;

    //if both the orders are non-prime
    return false;
}

vector<string> sortOrders(vector<string> &orderList){
    //separate the id and metadata and then sort
    vector<pair<string,string>> v=preprocess(orderList);
    //sort the pair
    sort(v.begin(),v.end(),compare);
    //again join the pairs to form the resultant string
    vector<string> ans=join(v);
    return ans;
}