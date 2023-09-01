#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Input of event name
    string evenName;
    cout << "Event Name: ";
    getline(cin, evenName);
    // Input of adult ticket sold
    double adultTicket;
    cout << "Adult Ticket: $";
    cin >> adultTicket;
    // Input  of child ticket sold
    double childTicket;
    cout << "Child Ticket: $";
    cin >> childTicket;
    // calculate gross profit by using the given information
    double grossProfit = adultTicket * 30.0 + childTicket * 20.0;
    // Display gross profit
    cout << "Gross Profit: $" << fixed << setprecision(2) << grossProfit << endl;
    // calculate net profit by keeping 25%
    double netProfit = (grossProfit * 25.0) / 100.0;
    // display net profit
    cout << "Net Profit: $" << netProfit << endl;
    // calculate amount paid to accociation
    double amountToAssociation = grossProfit - netProfit;
    // Display amount paid to association
    cout << "Amount Paid to Association: $" << amountToAssociation << endl;
    return 0;
}