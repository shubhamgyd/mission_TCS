#include <iostream>
using namespace std;

int main()
{
    // Input of numberOfOutfits
    int numberOfOutfits;
    cin >> numberOfOutfits;
    // If outFits are greater than 18
    if (numberOfOutfits > 18)
    {
        cout << "Need more than one suitcase\n";
    }
    // if outFits are greater than equal to 7 and less than 18
    else if (numberOfOutfits >= 7 and numberOfOutfits < 18)
    {
        cout << "Large suitcase\n";
    }
    // if outFits are greater than equal to 1 and less than equal to 6
    else if (numberOfOutfits >= 1 and numberOfOutfits <= 6)
    {
        cout << "Mid-sized suitcase\n";
    }
    // else if outfits are less than 1
    else if (numberOfOutfits < 1)
    {
        cout << "Invalid number\n";
    }
    return 0;
}