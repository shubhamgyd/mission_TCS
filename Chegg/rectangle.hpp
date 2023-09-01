#include <iostream>
#include <cmath>

int main()
{
    // loop to first 25 numbers
    for (int i = 1; i <= 25; i++)
    {
        // get ith odd number
        int odd_number = i * 2 - 1;
        // get square root of ith odd number
        double square_root = std::sqrt(odd_number);
        // print number and square root
        std::cout << "The square root of " << odd_number << " is " << square_root << std::endl;
    }
    return 0;
}
