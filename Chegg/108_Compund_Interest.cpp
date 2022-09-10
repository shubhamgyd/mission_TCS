#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>

using namespace std;

int main()
{
    // declare variables
    string name;
    double principle=0.0;
    double rateOfInterest=0.0;
    int timePeriod=0;
    double interestEarned=0.0;
    double finalBalance=0.0;
    cout<<"Enter Account Holder Name: ";
    getline(cin,name);
    cout<<"Enter Rate of Intereset: ";
    cin>>rateOfInterest;
    cout<<"Enter Time Period: ";
    cin>>timePeriod;
     cout<<"Enter Principle: ";
    cin>>principle;
    double calc=pow(1+(rateOfInterest/400),4*timePeriod);
    interestEarned=principle*(pow((1+(rateOfInterest/400)),4*timePeriod));
    finalBalance=principle+interestEarned;
    cout<<left<<setw(20)<<"Accountholder: "<<right<<setw(20)<<name<<endl;
    cout<<left<<setw(20)<<"Interest Rate: "<<right<<setw(20)<<rateOfInterest<<endl;
    cout<<left<<setw(20)<<"Times Compounded: "<<right<<setw(20)<<timePeriod<<endl;
    cout<<fixed<<setprecision(2)<<left<<setw(20)<<"Principle: "<<right<<setw(10)<<"$"<<right<<setw(10)<<principle<<endl;
    cout<<fixed<<setprecision(2)<<left<<setw(20)<<"Interest Earned: "<<right<<setw(10)<<"$"<<right<<setw(10)<<interestEarned<<endl;
    cout<<fixed<<setprecision(2)<<left<<setw(20)<<"Final Balance: "<<right<<setw(10)<<"$"<<right<<setw(10)<<finalBalance<<endl;
}