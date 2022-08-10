#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{

	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;

    // O(sqrt(n))
	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

int nextPrime(int N)
{
    // base condition
	if (N <= 1)
	{
		return 2;
	}

	int num = N;
	bool found = false;

	while (!found)
	{
		num++;
		if (isPrime(num))
		{
			found = true;
		}
	}
	return num;
}


int prevPrime(int n)
{
    if (n & 1)
    {
		n -= 2;
	}
    else
    {
		n--;
	}
    int i, j;
    for (i=n;i>=2;i-=2) 
	{
        if (i%2==0)
        {
			continue;
		}
        for (j=3;j<=sqrt(i); j+=2) 
		{
            if (i % j == 0)
            {
				break;
			}
        }
        if (j>sqrt(i))
        {
			return i;
		}
    }
    return -1;
}

int main()
{
	int n;
	cin >> n;
	int nextPrimeNumber=nextPrime(n);
	int prevPrimeNumber=prevPrime(n);
	
	if(nextPrimeNumber!=-1 and prevPrimeNumber!=-1)
	{
		int diff1=abs(n-prevPrimeNumber);
		int diff2=abs(n-nextPrimeNumber);
		if(diff1==diff2)
		{
			cout<<prevPrimeNumber<<" "<<nextPrimeNumber<<endl;
		}
		else if(diff1<diff2)
		{
			cout<<prevPrimeNumber<<endl;
		}
		else
		{
			cout<<nextPrimeNumber<<endl;
		}
	}
	else if(prevPrimeNumber==-1)
	{
		cout<<nextPrimeNumber<<endl;
	}
	else
	{
		cout<<prevPrimeNumber<<endl;
	}
	return 0;
}