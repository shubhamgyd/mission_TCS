#include <iostream>
using namespace std;

int main()
{
    // Variables
    int totalSeconds; // To hold a number of seconds (entered by user)
    int minutes;      // To hold a number of minutes
    int hours;        // To hold a number of hours
    int days;         // To hold a number of days
    int remainder_seconds_in_day, remainder_seconds_in_hour, remainder_seconds_in_minute;
    while (true)
    {
        // Get a number of seconds.
        cout << "Enter a number of seconds (or negative number to EXIT): ";
        cin >> totalSeconds;
        int temp = totalSeconds;
        // if the user enter negetive number then this loop is exited
        if (totalSeconds < 0)
        {
            break;
        }
        int SECONDS_PER_HOUR = 3600;
        int SECONDS_PER_MINUTE = 60;

        // days calculating
        days = totalSeconds / (24 * SECONDS_PER_HOUR);
        // hours calculatuing
        totalSeconds = totalSeconds % (24 * SECONDS_PER_HOUR);
        hours = totalSeconds / SECONDS_PER_HOUR;
        // minutes calculating
        totalSeconds %= SECONDS_PER_HOUR;
        minutes = totalSeconds / SECONDS_PER_MINUTE;
        // seconds calculating
        totalSeconds %= SECONDS_PER_MINUTE;
        int seconds = totalSeconds;
        // If anything equal to zero break out of the loop so that output will not be printed
        if (days == 0 || hours == 0 || minutes == 0 || seconds == 0)
        {
            break;
        }
        // printing the results cout<<"Total Seconds = "<<temp;
        // if there is only seconds in the result this condition is executed
        cout << " : "
             << " Days = " << days << " Hours = " << hours << " Minutes = " << minutes << " Seconds = " << seconds;
        cout << endl;
    }
    return 0;
    // end of the program }
}