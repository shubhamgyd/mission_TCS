// In this problem we are going to search the pattern in the given string by using KMP  Algorithm

#include<bits/stdc++.h>
using namespace std;

void ComputeArray(string pat,int lps[],int m)
{
    // Length of the previous longest prefix suffix
    int len=0;

    // lps[0] is always 0
    lps[0]=0;

    int i=1;
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else      // pat[i]!=pat[j]
        {
            if(len!=0)
            {
                len=lps[len-1];
                // Also, note that we do not increment
                // i here
            }
            else
            {
                lps[i]=0;
                i+=1;
            }
        }
    }


}

void KMPSearch(string txt,string pat)
{
    int n=txt.length();
    int m=pat.length();

    int lps[m];
    ComputeArray(pat,lps,m);
    for(int i=0;i<m;i++)
    {
        cout<<lps[i]<<" ";
    }
    cout<<endl;
    int i=0;
    int j=0;
    while(i<n)
    {
        if(pat[j]==txt[i])
        {
            j++;
            i++;
        }
        if(j==m)
        {
            cout<<"Pattern matched at the index: "<<i-j<<endl;
            j=lps[j-1];
        }
         // mismatch after j matches
        else if (i < n && pat[j] != txt[i]) 
        {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

int main()
{
    string txt="heavymetalisheavymetal";
    string pat="metal";
    KMPSearch(txt,pat);
}












// #include<bits/stdc++.h>
// using namespace std;
// #define lli    long long int

// string st;
// int lps[1000001];

// void ComputeArray()
// {
// 	int m=st.length();
//     // Length of the previous longest prefix suffix
//     int len=0;

//     // lps[0] is always 0
//     lps[0]=0;

//     int i=1;
//     while(i<m)
//     {
//         if(st[i]==st[len])
//         {
//             len++;
//             lps[i]=len;
//             i++;
//         }
//         else      // pat[i]!=pat[j]
//         {
//             if(len!=0)
//             {
//                 len=lps[len-1];
//                 // Also, note that we do not increment
//                 // i here
//             }
//             else
//             {
//                 lps[i]=0;
//                 i+=1;
//             }
//         }
//     }


// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);
// 	lli t , k;
// 	cin>>t;
// 	while(t--)
// 	{
//         cin>>st>>k;
// 		//scanf("%s %d",st,&k);
// 		ComputeArray();
// 		int n = st.size();
// 		cout<<n + (k - 1) * (n - lps[n-1])<<endl;
// 		//int num= (n+(k-1)*(n-lps[n-1]));
// 		//printf("%d\n",num);
// 	}
// 	return 0;
// }