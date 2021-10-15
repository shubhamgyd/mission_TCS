//remove invalid paranthesis
//generate all valid paranthesis

#include<bits/stdc++.h>
using namespace std;

//Approach
//"(" then take it or dont take it (2 choices at each step) recursion
//")" take only have "(" in count 
//generate all possible valid sequences;
//cnt_a will have the count of "("
//cnt_b will have the cnt of ")"
//if both are equal then it is valid
//")" will be pushed accordingly

vector<string> v;
int max_length=0;


int func(string str,int index,int cnt_a,int cnt_b,string ans)
{
    
    if(cnt_a==cnt_b && cnt_a>0)
    {
        string temp=ans;
        v.push_back(ans);
        
        if(max_length<ans.size())
        {
            max_length=ans.size();
        }
        
    }
    
    if(index>=str.size())
    {
        return 0;
    }
    
    if(str[index]=='(')
    {
        
        //either take or move to the next one
        string temp=ans;
        temp.push_back('(');
        func(str,index+1,cnt_a+1,cnt_b,temp)+func(str,index+1,cnt_a,cnt_b,ans);
        
    }
    else if(str[index]==')')
    {
        if(cnt_b+1<=cnt_a)//check if can push
        {
            string temp=ans;
            temp.push_back(')');
            func(str,index+1,cnt_a,cnt_b+1,temp)+func(str,index+1,cnt_a,cnt_b,ans);
        }
        else//can  just move to the next one
        {
            func(str,index+1,cnt_a,cnt_b,ans);
        }
    }
    else
    {
        string temp=ans;
        temp.push_back(str[index]);
        func(str,index+1,cnt_a,cnt_b,temp);
    }
    return 0;
}


int main()
{
    string str;
    cout<<"Enter the string\n";
    cin>>str;
    
    int cnt_a=0;
    int cnt_b=0;
    
    string ans;
    
    func(str,0,cnt_a,cnt_b,ans);
    
    vector<string> final_ans;
    
    for(int i=0;i<v.size();i++)
    {
        if(v[i].size()==max_length)
        {
            int flag=1;
            
            //check if dont repeat
            for(int j=0;j<final_ans.size();j++)
            {
                if(final_ans[j]==v[i])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                //avoid repetition
                final_ans.push_back(v[i]);
                cout<<v[i]<<" ";
            }
        }
    }
    
    return 0;
}