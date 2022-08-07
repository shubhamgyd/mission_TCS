#include <iostream>
using namespace std;

bool isPrime(unsigned int);
void displayMultiple(unsigned int, unsigned int);
void naturalFactors(unsigned int);
void additiveReverse(unsigned int);
bool evenOdd(unsigned int);
void summation(unsigned int);
void reverse(unsigned int);

int main()
{

    unsigned int number;
    cout << "This prgoram repeatedly reads a natural number ";
    while(true)
    {
        cout<<"\nEnter number: ";
        cin >> number;
        if (number == 0)
        {
            cout << "Termitting...!!" << endl;
            return 0;
        }
        while (true)
        {
            cout << "Press 1 to check if th input number is prime. \n";
            cout << "Press 2 to display all the natural multiples of the input number in range r. \n";
            cout << "Press 3 to display all the natural factors of the input number. \n";
            cout << "Press 4 to display the addictive revers of the number. \n";
            cout << "Press 5 to check if the number is even or odd. \n";
            cout << "Press 6 to see the summation of digits. \n";
            cout << "Press 7 to see the reverse of the number. \n";
            cout << "Press 8 to read new number \n";
            int choice;
            cin >> choice;
            bool isBreak=false;
            switch (choice)
            {
                case 1:
                {
                    cout<<"\nNumber is: "<<number<<endl;
                    bool result = isPrime(number);
                    if (result == true)
                        cout << "this number is prime \n";
                    else
                        cout << "this number is not prime \n";
                    break;
                }
                case 2:
                {
                    cout<<"\nNumber is: "<<number<<endl;
                    unsigned int range;
                    cout<<"Enter Range: ";
                    cin >> range;
                    displayMultiple(number, range);
                    break;
                }

                case 3:
                {
                    cout<<"\nNumber is: "<<number<<endl;
                    naturalFactors(number);
                    break;
                }
                case 4:
                {
                    cout<<"\nNumber is: "<<number<<endl;
                    additiveReverse(number);
                    break;
                }
                case 5:
                {
                    cout<<"\nNumber is: "<<number<<endl;
                    bool result = evenOdd(number);
                    if (result == true)
                        cout << "this number is even \n";
                    else
                        cout << "this number is odd \n";
                    break;
                }
                case 6:
                {
                    cout<<"\nNumber is: "<<number<<endl;
                    summation(number);
                    break;
                }

                case 7:
                {
                    cout<<"\nNumber is: "<<number<<endl;
                    reverse(number);
                    break;
                }
                case 8:
                {
                    cout<<"\nNumber is: "<<number<<endl;
                    isBreak=true;
                    break;
                }

                default:
                    cout << " You did not entered in the range of 1 to 8 \n";
                    break;
                }

            system("pause");
            if(isBreak)
            {
                break;
            }
        }
    }
    return 0;
}

// No1: check whether the natural number is prime .

bool isPrime(unsigned int number)
{
    int count = 0;
    for (unsigned int a = 1; a <= number; a++)
    {
        if (number % a == 0)
        {
            count++;
        }
    }
    if (count == 2)
    {
        return true;
    }

    else
    {
        return false;
    }
}

// No2: display all the natural multiples of the inpit number in rnge r

void displayMultipe(unsigned int number, unsigned int r)
{

    int i = 1;
    unsigned int multiple = number;
    while (multiple <= r)
    {
        unsigned int multipes = i * number;
        cout << multiple<<", ";
        i++;
    }
    cout<<endl;
}
void displayMultiple(unsigned int number1, unsigned int r1)
{
    int i = 1;
    unsigned int multiple = number1;
    while (i*multiple<=r1)
    {
        unsigned int multipes = i * number1;
        cout << multipes<<", ";
        i++;
    }
    cout<<endl;
}


// No.3 display all the natural factors of the imput number

void naturalFactors(unsigned int number)
{
    unsigned int i = 1;
    while (number >= i)
    {
        if (number % i == 0)
            cout << i << endl;
        i++;
    }
    cout<<endl;
}

// No.4 display the additive reverse of the number

void additiveReverse(unsigned int number)
{
    int multiple = -1 * number;
    cout << multiple << endl;
}

// No.5 to check if the number is even or odd

bool evenOdd(unsigned int number)
{

    if (number % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// No.6 to see the sumation ofdigits

void summation(unsigned int number)
{
    int sum = 0;
    while (number != 0)
    {
        int remainder = number % 10;
        sum = sum + remainder;
        number = number / 10;
    }
    cout << sum<<endl;
}

// No.7 to display the reverse of the number

void reverse(unsigned int number)
{
    int reversedNumber = 0, remainder;
    while (number != 0)
    {
        remainder = number % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        number /= 10;
    }
    cout << "Reversed Number = " << reversedNumber<<endl;
}