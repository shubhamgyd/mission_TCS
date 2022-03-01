// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     cout<<"****** MULTIPLICATION TABLE ******"<<endl;
//     cout<<endl;

//     // It will show the table of particular number
//     for(int i=10;i>=1;i--)
//     {
//         cout<<setw(5)<<i<<" ";
//     }
//     cout<<endl;
//     cout<<"------------------------------------------------------------"<<endl;

//     int j=1;
//     int i=10;
//     // loop will iterate until we reached 100(maximum value of 10th table)
//     while(j*i<=100)
//     {
//         // this number is the starting number of 10th table
//         int number=i*j;

//         // here we will display number of every table , of particular multiplacant
//         while(number>0)
//         {
//             cout<<setw(5)<<number<<" ";
//             number-=j;
//         }
//         cout<<endl;
//         j++;
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     // Total number of students
//     cout<<"Enter the number of students: ";
//     int n;
//     cin>>n;

//     // Inetare over n is greater than 0
//     while(n--)
//     {
//         // Input of studet id, name
//         cout<<"Enter the student id and marks: ";
//         string id,name;
//         cin>>id>>name;
//         int count=0;
//         int sum=0;
//         int marks;
//         // run until student break it
//         while(true)
//         {
//             cout<<"Enter a marks, -1 to  stop: ";
//             cin>>marks;
//             // if student enter -1 then it will come out of the loop(will stop taking marks input)
//             if(marks==-1)
//             {
//                 break;
//             }

//             // if student enter marks greater than 0, then it will added to total sum
//             else
//             {
//                 sum+=marks;
//                 count++;          // count total subjects, which helps us to find the average
//             }
//         }
//         // finding average
//         double average=(double)sum/(double)count;

//         // Displaying student information
//         cout<<setw(4)<<id<<" "<<setw(4)<<name<<" ";
//         cout<<fixed<<setprecision(2)<<average<<endl;
//     }
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     // Total number of intervals
//     cout<<"Enter the number of intervals: ";
//     int n;
//     cin>>n;
//     // Here firstInterval keep track on sum of lower bound
//     //  and secondInterval keep track in sum if the upper bound
//     int firstInterval=0,secondInterval=0;
//     for(int i=0;i<n;i++)
//     {
//         cout<<"Enter the lower and upper bounds of the interval: ";
//         int a,b;
//         cin>>a>>b;
//         firstInterval+=a;
//         secondInterval+=b;
//     }
//     // Total sum of lower bound abd upper bound
//     cout<<"The sum of the "<<n<<" intervals is ["<<firstInterval<<", "<<secondInterval<<"]"<<endl;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:

//     // if s[i] is one of '(', it finds out the corresponding ')'
//     // if s[i] is one of ')', just return true and have a double check in f1()
//     bool f(const string& s, int& i){

//         // base case
//         // if we have find all valid balanced paranthesis, then return true
//         if(i==s.size()){
//             return true;
//         }

//         else if(i>s.size()){
//             return false;
//         }

//         // if we founc open parenthesis, then we need to find the closing paranthesis
//         if(s[i]=='('){

//             // here we are calling function to find the if we get closing parenthesis or not
//             if(f1(s,i)){
//                 return f(s,i);
//             }
//             else{
//             return false;
//             }
//         }
//         return true;
//     }

//     // Utility function return , wheather we get the desired closing parenthesei or not
//     bool f1(const string& s , int& i){

//         // if we have reached to the last index it mean we have founc valid parenthesis
//         if(i==s.size()){
//             return true;
//         }
//         else if(i>s.size()){
//             return false;
//         }
//         if(!f(s,++i)){
//             return false;
//         }

//         // we have founc closing parenthesis, then check for next parenthesis
//         if(i<s.size()&&s[i]==')'){
//             return f(s,++i);
//         }
//         else{
//             return false;
//         }

//     }

// // Utility function, to check given string is valid paranthesis of not
//     bool isValid(string s) {
//         if(s.empty()){
//             return true;
//         }
//         int i=0;
//         if(f(s,i)){
//             return i==s.size();
//         }
//         return false;

//     }
// };

// int main()
// {
//     string str;
//     cin >> str;
//     Solution obj;
//     bool ans=obj.isValid(str);
//     cout<<ans<<endl;
//     return 0;
// }

/*
Code first checks the index. If index is equal to the size of string, controls return true i.e. we have validate the string. If it is an opening character ( i.e it is '(' ), searches for the closing match of it. While searching the closing match, if encounters the same opening character, it increments the skip variable to be able to skip the closing character for the second opening character after it.
If it cannot finds the closing character returns false. If it finds the closing character, calls the same function recursively for the substring between opening and closing character.

I hope my explanation is not too much confusing. If so please let me know.

*/

// #include <bits/stdc++.h>
// using namespace std;

// int fib(int N,int memo[])
// {
//     // base case
//     if (N == 0)
//         return 0;
//     if (N == 1)
//         return 1;

//     // if we have already calculated the valur of this number
//     // then instead of calculating it again, just return it from our memoization array
//     if(memo[N]!=-1)
//     {
//         return memo[N];
//     }

//     //store and return it, so that it will help us for next value
//     return memo[N]=fib(N - 1,memo) + fib(N - 2,memo);
// }

// int main()
// {
//     int N;
//     cin >> N;

//     // here we will store the precalculated valur
//     int memo[N+1];
//     // fill with -1
//     memset(memo,-1,sizeof(memo));
//     cout<<fib(N,memo)<<endl;
//     return 0;
// }



// C++ program for decimal to binary
// conversion using recursion
// #include <bits/stdc++.h>
// using namespace std;


// // Utility function convert decial to binary number
// int findBinary(int number)
// {
// 	if (number == 0){
//         return 0;
//     }
// 	else
// 	{
//         return (number % 2 + 10 *findBinary(number / 2));
//     }
// }

// int main()
// {
// 	int number;
//     cin>>number;
// 	cout << findBinary(number);
// 	return 0;
// }


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
	int GCD=gcd(a,b);
	cout<<a<<"!="<<fact1<<endl;
	cout<<b<<"!="<<fact2<<endl;
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
		cout<<"No GCD>1 of "<<a<<" and "<<b<<" found!"<<endl;
	}
	return 0;
}