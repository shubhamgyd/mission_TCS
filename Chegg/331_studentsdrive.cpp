#include <iostream>
#include <iomanip>
#include <cstring>
#include "Students.h"

const int SIZE = 3;

// Function prototypes
char *getID();
double getGPA();
char *getName();
void getInput(Students *ptrStu, const int SIZE);
void displayAllStudentsInfo(const Students *ptrStu, const int SIZE);

int main()
{
    Students *ptrStu = new Students[SIZE];
    displayAllStudentsInfo(ptrStu, SIZE);
    getInput(ptrStu, SIZE);
    displayAllStudentsInfo(ptrStu, SIZE);
    delete[] ptrStu;
    return 0;
}

char *getID()
{
    char *id = new char[51];
    std::cout << "Enter student ID: ";
    std::cin.getline(id, 51);
    return id;
}

double getGPA()
{
    double gpa = 0;
    std::cout << "Enter student GPA: ";
    std::cin >> gpa;
    std::cin.ignore(1000, '\n'); // Ignore the rest of the input buffer
    return gpa;
}

char *getName()
{
    char *name = new char[51];
    std::cout << "Enter student name: ";
    std::cin.getline(name, 51);
    return name;
}

void getInput(Students *ptrStu, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "Enter information for student " << i + 1 << ":\n";
        ptrStu[i].setStudentNumber(getID());
        ptrStu[i].setGPA(getGPA());
        ptrStu[i].setStudentName(getName());
        std::cout << std::endl;
    }
}

void displayAllStudentsInfo(const Students *ptrStu, const int SIZE)
{
    std::cout << std::left << std::setw(10) << "ID" << std::setw(20) << "Name" << std::setw(10) << "GPA" << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << std::left << std::setw(10) << ptrStu[i].getStudentNumber() << std::setw(20) << ptrStu[i].getStudentName() << std::setw(10) << ptrStu[i].getStudentGPA() << std::endl;
    }
    std::cout << std::endl;
}
