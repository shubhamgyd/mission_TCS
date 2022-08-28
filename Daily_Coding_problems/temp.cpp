#include<bits/stdc++.h>
using namespace std;


void rotate_right(char* input1,int input2)
{
	int len=strlen(input1);
	char *arr;
	arr=(char*)malloc(len*1);
	if(input2>=len) printf("%s",input1);
	int ind=0;
	for(int i=len-input2;i<len;i++)
	{
		arr[ind]=input1[i];
		ind++;
	}
	for(int i=0;i<len-input2;i++)
	{
		arr[ind]=input1[i];
		ind++;
	}
	printf("%s",arr);
	// return (char *)arr;
}

char* left_rotate(char* input1,int input2)
{
	int len=strlen(input1);
	if(len>=input2) return input1;
	char *arr;
	arr=(char*)malloc(len*1);
	int ind=0;
	for(int i=input2;i<len;i++)
	{
		arr[ind]=input1[i];
		ind++;
	}
	for(int i=0;i<input2;i++)
	{
		arr[ind]=input1[i];
		ind++;
	}
	// printf("%s",arr);
	return (char *)arr;
}

int main()
{
	// char arr[7]
	// char *arr;
	// arr=(char*)malloc(7*1);
	char arr[8]="abcdxyz";
	rotate_right(arr,2);
	// printf("%s",ans);
	
	// ios_base::sync_with_stdio(0);
	// cout.tie(0);
	// cout.tie(0);
	// int n;
	// cin>>n;
	// string str;
	// cin>>str;
	// str.resize(n);
	// int mx=0;
	// for(int i=0;i<n;i++)
	// {
	// 	int num=str[i]-'0';
	// 	mx=max(mx,num);
	// }
	// cout<<mx<<"\n";
	return 0;
}