#include<bits/stdc++.h>
using namespace std;

// function find the factorial of a number
unsigned factorial(unsigned int num)
{
	unsigned int res = 1, i;
    for (i = 2; i <= num; i++)
    {
		res *= i;
	}
    return res;
}

// function to find the gcd of two numbers
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


// function to check given number is prime or not
bool isPrime(int n)
{
	int i;
	bool is_prime=true;
	if (n == 0 || n == 1) 
	{
    	is_prime = false;
 	}

  // loop to check if n is prime
  for (i = 2; i <= n/2; ++i) {
    if (n % i == 0) {
      is_prime = false;
      break;
    }
  }
  
  // if given number is prime , then return true
  if (is_prime) return true;

  // else return false;
  return false;
}

int main()
{
	cout<<"Enter two numbers:";
	int a,b;
	cin>>a>>b;

	// finding the factorial of a and b
	unsigned int fact1=factorial(a);
	unsigned int fact2=factorial(b);

	// finding gcd of a and b
    cout<<endl;
	int GCD=gcd(a,b);
	cout<<a<<"!="<<fact1<<endl;
	cout<<b<<"!="<<fact2<<endl;
    cout<<endl;
	if(GCD>1)
	{
		cout<<"GCD of "<<a<<" and "<<b<<" is = "<<GCD<<endl;
		if(isPrime(GCD))
		{
			cout<<GCD<<" is a prime number."<<endl;
		}
		else
		{
			cout<<GCD<<" is not a prime number."<<endl;
		}
	}
	else
	{
		cout<<"No GCD > 1 of "<<a<<" and "<<b<<" found!"<<endl;
	}
	return 0;
}