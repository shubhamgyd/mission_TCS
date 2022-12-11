#include <iostream>
#include <iomanip>
using namespace std;

// Utility function which generate random number between 1 to 2
int coinFlip()
{
    int num = 1 + (std::rand() % (2 - 1 + 1));
    // return generated number
    return num;
}

int main()
{
    // Input of how many coins flipped
    cout << "How many coins flip? ";
    int n;
    cin >> n;
    // get total heads
    int head = 0;
    // get total tails
    int tail = 0;
    // Get n random numbers
    for (int i = 1; i <= 10; i++)
    {
        // get number
        int flip = coinFlip();
        // if flip == 1
        // it is tail and increment the count of tail
        if (flip == 1)
        {
            cout << "1: " << setw(10) << "tails" << endl;
            tail++;
        }
        // else increment the count of head
        else
        {
            cout << "2: " << setw(10) << "head" << endl;
            head++;
        }
    }
    // Print the total heads
    cout << "Total heads: " << head << endl;
    // Print the total tail
    cout << "Total tails: " << tail << endl;
    return 0;
}