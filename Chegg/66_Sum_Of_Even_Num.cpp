#include<iostream>
using namespace std;

// Utility  Function which return the sum of all even numbers less than or equal to given number
int problem4(int number)
{
    // maintian sum of all even numbers
    int sum=0;
    
    // Start with 2
    int num=2;

    // Iterate until given number
    while(num<=number)
    {
        // Add even number into sum
        sum+=num;

        // next even number
        num+=2;
    }
    // Return total sum
    return sum;
}

int main()
{
    // User Input
    cout<<"Enter number: ";
    int number;
    cin>>number;

    // Function call
    int ans=problem4(number);

    // Print sum
    cout<<"Sum of all even number less than or equal to "<<number<<" = "<<ans<<endl;
    return 0;
}