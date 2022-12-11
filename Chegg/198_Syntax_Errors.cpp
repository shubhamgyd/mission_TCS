#include <iostream>
using namespace std;

const double TAX_RATE = 0.08;

double totalCost(double, int);

int main()
{

    int selection, numToppings;
    cout << "This Program Calculates the Total Cost of a Pizza\n";
    cout << "Enter 1, 2, 3, or 4\n";
    cout << "#1. 8\" Pizza - $8.00\n";
    cout << "#2. 12\" Pizza - $12.00\n";
    cout << "#3. 16\" Pizza - $16.OO\n";
    cout << "#4. End Program\n";
    cin >> selection;
    if (selection == 4)
        exit(0);
    cout << "How Many Toppings? (each topping costs $1.50): ";
    cin >> numToppings;
    if (selection == 1)
        totalCost(8.00, numToppings);
    if (selection == 2)
        totalCost(12.00, numToppings);
    if (selection == 3)
        totalCost(16.00, numToppings);
    return 0;
}

double totalCost(double price, int numTop)
{

    double total;

    total = ((price + numTop * 1.5)) * (1 + TAX_RATE);

    cout << "Your Total Cost is: $" << total << endl;
    return total;
}