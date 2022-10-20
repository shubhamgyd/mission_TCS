#include <stdio.h>

void ConvertTime(int totalMinutes, int *usrHours, int *usrMinutes)
{
    // to get hours divide the totalMinues by 60
    // because in 1 hours there are 60 minutes
    int tempHrs = totalMinutes / 60;
    *usrHours = tempHrs;
    // usrHours = totalMinutes / 60;

    // now substract those minutes(i.e. used to to get hours)
    // from totalMinutes
    // multiply by 60 so it will get resulting minutes
    totalMinutes -= (tempHrs)*60;

    // now remaining minutes is usrMinutes
    *usrMinutes = totalMinutes;
}

int main()
{
    // Declaration of variables
    // to store tht hours, minutes and totalMinues respectively
    int usrHours;
    int usrMinutes;
    int totalMinutes;
    // Input of totalMinues
    scanf("%d", &totalMinutes);

    // Function call to convert totalMinues into hours and minues
    ConvertTime(totalMinutes, &usrHours, &usrMinutes);
    // Display hours and minutes
    printf("%d hours and %d minutes\n", usrHours, usrMinutes);
    return 0;
}