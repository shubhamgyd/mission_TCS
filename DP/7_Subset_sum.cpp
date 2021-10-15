// Check Wheather given  sum is present in array or not


//Recursive
#include<bits/stdc++.h>
using namespace std;

bool solve(int arr[],int n,int sum)
{
    // if we have found the given sum
    if(sum==0)
    {
        return true;
    }

    // if number of elements are zero 
    if(n<=0)
    {
        return false;
    }

    // We have two choices either consider the current element or leave it
    return solve(arr,n-1,sum-arr[n-1]) || solve(arr,n-1,sum);
}

int main()
{
    int arr[]={1,2,3,4,5};
    int sum=9;
    int n=sizeof(arr)/sizeof(arr[0]);
    if(solve(arr,n,sum))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}

/*
Time Complexity: O(2^n)
*/















// Memoization Appraoch
#include <bits/stdc++.h>
using namespace std;

// Taking the matrix as globally
int tab[2000][2000];

// Check if possible subset with
// given sum is possible or not
int subsetSum(int a[], int n, int sum)
{
	
	// If the sum is zero it means
	// we got our expected sum
	if (sum == 0)
		return 1;
		
	if (n <= 0)
		return 0;

	// If the value is not -1 it means it
	// already call the function
	// with the same value.
	// it will save our from the repetition.
	if (tab[n - 1][sum] != -1)
		return tab[n - 1][sum];

	// if the value of a[n-1] is
	// greater than the sum.
	// we call for the next value
	if (a[n - 1] > sum)
		return tab[n - 1][sum] = subsetSum(a, n - 1, sum);
	else
	{
		
		// Here we do two calls because we
		// don't know which value is
		// full-fill our criteria
		// that's why we doing two calls
		return tab[n - 1][sum] = subsetSum(a, n - 1, sum) ||
					subsetSum(a, n - 1, sum - a[n - 1]);
	}
}

int main()
{
	// Storing the value -1 to the matrix
	memset(tab, -1, sizeof(tab));
	int n = 5;
	int a[] = {1, 5, 3, 7, 4};
	int sum = 12;

	if (subsetSum(a, n, sum))
	{
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
}
/*
Time Complexity: O(n*m)
Space Somplexity: O(n*m)
*/





















// Dp Approach
#include<bits/stdc++.h>
using namespace std;

//int dp[100][100];

bool subsetsum(int arr[],int n, int sum)
{
    //Declaration of array
    int dp[n+1][sum+1];

    //Initialization of array 
    //dp[0][0]=true;
    //first col =true
    //first row = false;
    // Think about it.
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }

    for(int i=1;i<=sum;i++)
    {
        dp[0][i]=false;
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            // If element if less than or equal to given sum , then we have two choices
            // Either taken or not taken
            if(arr[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            // If element is greater than given sum ,  then take the value from the previos 
            // upper array block
            // Discard it , store the previous valid flag
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    // Final ans will get by usinng this block 
    // Either true or false
    return dp[n][sum];
}


bitset<1000001>can;

int main()
{
    int arr[]={3, 34, 4, 12, 5, 2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=9;
    if(subsetsum(arr,n,sum)==true)
    {
        cout<<"Yes Sum Present"<<'\n';
    }
    else
    {
        cout<<"Given Sum Not Ptesent"<<'\n';
    }


    cout<<endl;
    cout<<"Altrnative approach and faster than DP : ";
    // Time complexity of the given function is O(sum/32)
    can[0]=true;
    for(int id=0;id<n;id++)
    {
        can|=(can<<arr[id]);
    }
    puts(can[sum]?"YES":"NO");
    return 0;

}

/*
Time Complexity: O(n*m)
Space Somplexity: O(n*m)
*/
