#include<iostream>
using namespace std;

class TimeObject
{
    int hour,minute,second;
public:

    // By default values of hour,minute and second are zero
    TimeObject(int h=0,int m=0,int s=0)
    {
        // assignig values of hour,minute, and second
        this->hour=h;
        this->minute=m;
        this->second=s;
    }

    // This is automatically call when '+' is used with
    // between two TimeObjects objects
    TimeObject operator +(TimeObject const &t2)
    {
        TimeObject t3;   // result

        // adding hours,minutes,second of two timeObjects
        t3.hour=hour+t2.hour;
        t3.minute=minute+t2.minute;
        t3.second=second+t2.second;

        // Now, we have to check the validations
        // i.e minute is less than 60 or not
        // second is less than 60 or not
        // hours is less than 23 or not


        // validating second
        int extraMinute=0;
        int newSecond=t3.second;
        if(t3.second>=60)
        {
            extraMinute+=(t3.second)/60;       // finding extra minutes
            newSecond=(t3.second)%60;          // finding new seconds
        }


        // validating minute
        int extraHours=0;
        int newMinute=t3.minute;

        // first add the extraMinute into the toal minute
        // i.e in previous step we have extracted extraSecond add them into our minute
        // to finding the newMinute and extraMinute

        int totalMinute=t3.minute+extraMinute;
        newMinute=totalMinute;
        if(totalMinute>=60)
        {
            extraHours+=(totalMinute)/60;    // finding extra hours
            newMinute=(totalMinute)%60;      // finding new minute
        }

        // validating hours
        int newHours=t3.hour;

        // add the extraHours into our hours, so that we can validate it between into 0-23
        int totalHours=t3.hour+extraHours;
        newHours=totalHours;
        if(totalHours>=24)
        {
            newHours=(totalHours)%24;    // rounding in 24 hours format
        }
        // cout<<t3.hour<<endl;


        // Creating new Object
        TimeObject t4;
        t4.hour=newHours;
        t4.minute=newMinute;
        t4.second=newSecond;

        return t4;
    }

    // Printing timeObject
    void showTime()
    {
        cout<<hour<<":"<<minute<<":"<<second<<endl;
    }
};


int main()
{
    cout<<endl;
    cout<<"Enter Time for t1 Object: "<<endl;
    int hours1,minute1,second1;
    bool isValidT1=false;

    // Input until validate
    while(!isValidT1)
    {
        // Input hours,minute,second
        cout<<"Please Enter Hours(0-23), Minute(0,59), Second(0,59): "<<endl;
        cout<<"Enter Hours: ";
        cin>>hours1;
        cout<<"Enter Minutes: ";
        cin>>minute1;
        cout<<"Enter Second: ";
        cin>>second1;


        // If all the conditions satisfied then break input and take T2 input
        if(hours1>=0 and hours1<=23 and minute1>=0 and minute1<=59 and second1>=0 and second1<=59)
        {
            isValidT1=true;
        }
        else
        {
            cout<<"Invalid Format...!!!!!"<<endl;
        }
    }

    // TimeObject T1
    TimeObject t1(hours1,minute1,second1);

    cout<<endl;
    cout<<"Enter Time for t2 Object: "<<endl;
    int hours2,minute2,second2;
    bool isValidT2=false;

    // Input validate
    while(!isValidT2)
    {
        cout<<"Please Enter Hours(0-23), Minute(0,59), Second(0,59): "<<endl;
        cout<<"Enter Hours: ";
        cin>>hours2;
        cout<<"Enter Minutes: ";
        cin>>minute2;
        cout<<"Enter Second: ";
        cin>>second2;


        // If all the conditions satisfied then break input and take T2 input
        if(hours2>=0 and hours2<=23 and minute2>=0 and minute2<=59 and second2>=0 and second2<=59)
        {
            isValidT2=true;
        }
        else
        {
            cout<<"Invalid Format...!!!!!"<<endl;
        }
    }

    // timeObject t2
    TimeObject t2(hours2,minute2,second2);

    TimeObject t3=t1+t2;

    cout<<"\nResult: ";
    // Show Time
    t3.showTime();

}