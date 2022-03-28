#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    string name;
    int Age;
    char Gender;
    string Job;

public:
    class Address
    {

    private:
        string country_Name;
        string Street_Name;
        int Unit_No;

    public:
        Address();
        void Set_Data(Person::Address &Obj);
        static void Display_Address(Person::Address Obj1);
    };
    Person();
    string Get_Name();
    static int Get_Age(Person p);
    char Get_Gender();
    static string Get_Job(Person p);
    Person &Set_Data_Person(Person::Address &Obj);
    static void Display_Person(Person p, Person::Address addr);

    // WRITE HERE -- MEMBER FUNCTIONS DEFINITIONS
};
    int main()
    {
        Person P1;
        Person::Address add;
        P1 = P1.Set_Data_Person(add);
        cout << "-------------------------- Display Info----------" << endl;

        P1.Display_Person(P1, add);
        return 0;
    }