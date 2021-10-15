#include<iostream>
#include<cmath>
using namespace std;

void tugOfWarUtil(int arr[],int n,int index,int sum,int cnt,bool vis[],bool soln[],int total,int *ans)
{
    int i;
    if(cnt>n/2)
    return;
    if(index>=n)
        return;
    if(cnt==n/2)
    {
        if(abs(total-2*sum)<(*ans))
        {
            (*ans)=abs(total-2*sum);
            for(i=0;i<n;i++)
            {
                soln[i]=vis[i];
            }
        }
    }
    // include
    vis[index]=true;
    tugOfWarUtil(arr,n,index+1,sum+arr[index],cnt+1,vis,soln,total,ans);
    //do not include
    vis[index]=false;
    tugOfWarUtil(arr,n,index+1,sum,cnt,vis,soln,total,ans);
}

void tugOfWar(int arr[],int n)
{
    int i,sum=0;
    bool vis[n+1],soln[n+1];
    for(i=0;i<n;i++)
        sum+=arr[i],vis[i]=false,soln[n+1]=false;
        int ans=10000;
    tugOfWarUtil(arr,n,0,0,0,vis,soln,sum,&ans);
    for(i=0;i<n;i++)
        if(soln[i])
        cout<<arr[i]<<" ";
    cout<<"\n";
    for(i=0;i<n;i++)
        if(!soln[i])
        cout<<arr[i]<<" ";
    cout<<"\n";
    cout<<(ans);
}
int main()
{
    cout<<ceil(1/2)<<endl;
    return 0;
}
