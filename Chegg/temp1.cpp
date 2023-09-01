#include <bits/stdc++.h>
using namespace std;

class Person
{
};

class Student : public Person
{
public:
    void fun() {}
};

class Teacher : public Person
{
};
class PhDStudent : public Student
{
};

int main()
{
    // Person p1 = Student();
    PhDStudent phd = Student();
    // Teacher t1 = Person();
}
