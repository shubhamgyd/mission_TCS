#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    cout << endl;
    cout << endl;
    // declare double minute and hours
    double lengthMinutes;
    double lengthHours;
    // Input of minute
    cin >> lengthMinutes;
    // convert minutes to hors using formula miutes/60
    lengthHours = lengthMinutes / (60.0);
    // display hours till 3 decimal places.
    cout << fixed << setprecision(3) << lengthHours << " hours " << endl;
    return 0;
}