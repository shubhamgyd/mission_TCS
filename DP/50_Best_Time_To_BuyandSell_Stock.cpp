// Hard problem 

#include<bits/stdc++.h>
using namespace std;

// Returns maximum profit with
// two transactions on a given
// list of stock prices, price[0..n-1]

int MaxProfit(int arr[],int n)
{
    // Create profit array and
	// initialize it as 0
    int* profit=new int[n];
    memset(profit,0,sizeof(profit));

	/* Get the maximum profit with
	only one transaction
	allowed. After this loop,
	profit[i] contains maximum
	profit from price[i..n-1]
	using at most one trans. */

    int max_price=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
		// max_price has maximum
		// of price[i..n-1]
        if(arr[i]>max_price)
        {
            max_price=arr[i];
        }


		// we can get profit[i] by taking maximum of:
		// a) previous maximum, i.e., profit[i+1]
		// b) profit by buying at price[i] and selling at
		// max_price
        profit[i]=max(profit[i+1],max_price-arr[i]);
    }



	/* Get the maximum profit with two transactions allowed
	After this loop, profit[n-1] contains the result */

    int min_price=arr[0];
    for(int i=1;i<n;i++)
    {
		// min_price is minimum price in price[0..i]
        if(min_price>arr[i])
        {
            min_price=arr[i];
        }



		// Maximum profit is maximum of:
		// a) previous maximum, i.e., profit[i-1]
		// b) (Buy, Sell) at (min_price, price[i]) and add
		// profit of other trans. stored in profit[i]
        profit[i]=max(profit[i-1],profit[i]+(arr[i]-min_price));
    }
    int result=profit[n-1];
    delete[] profit; // To avoid memory leak
    return result;
}

int main()
{
    int arr[]={ 3,3,5,0,0,3,1,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum Profit is : ";
    cout<<MaxProfit(arr,n)<<endl;
    return 0;
}