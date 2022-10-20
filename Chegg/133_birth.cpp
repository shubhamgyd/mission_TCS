#include <iostream>
#include <map>
using namespace std;

int main()
{
    cout << endl;
    cout << endl;
    // HashMap to sore the monthNumber and monthDays respectively
    // we are consiering no leap year
    map<int, int> monthNumber;
    monthNumber[1] = 31;
    monthNumber[2] = 28;
    monthNumber[3] = 31;
    monthNumber[4] = 30;
    monthNumber[5] = 31;
    monthNumber[6] = 30;
    monthNumber[7] = 31;
    monthNumber[8] = 31;
    monthNumber[9] = 30;
    monthNumber[10] = 31;
    monthNumber[11] = 30;
    monthNumber[12] = 31;

    // Input of month and day
    int month, day;
    cin >> month >> day;
    // validate month
    // if entered month is less than 1 or greater than 12->Error
    if (month < 1 or month > 12)
    {
        cout << "Error: month must be in between 1 and 12." << endl;
    }
    else
    {
        // validate day in monthDays
        int monthDays = monthNumber[month];
        // If entered day is less than 0 or greater than monthDays->Error
        if (day < 0 or day > monthDays)
        {
            cout << "Error: day must be in betwwen 1 and " << monthDays << endl;
            return 0;
        }
        // Else print valid data
        else
        {
            cout << "Valid data" << endl;
            cout << "day: " << day << endl;
            cout << "month: " << month << endl;
        }
    }
    return 0;
}