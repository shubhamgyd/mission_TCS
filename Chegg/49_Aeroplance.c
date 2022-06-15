#include<stdio.h>
#include<math.h>



int main()
{
    float acceleration=3.2;       // meter/(sec^2)
    float time=30;                // sec

    // Formula d=1/2*(a*(t*t))


    // Calculating timeSquare
    float timeSquare=pow(time,2);

    // Calculating 1/2 in floating format
    // because if we calculate 1/2 as in integer format, then it will give 0

    // Intuition behind taking float is, we want floating numbers instead of 0
    float num=1;
    float denom=2;
    float temp=num/denom;

    float distance=temp*(acceleration*timeSquare);   // By formula

    // printing double;
    printf("\nAcceleration =  %f",acceleration);
    printf("\nSecond       =  %f",time);
    printf("\nDistance     =  %f",distance);        // meter unit
    return 0;
    
}