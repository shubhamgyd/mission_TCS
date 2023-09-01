#include <iostream>

#include <cstring>

#include "Students.h"

void Students::_initStudentNumber(const char *number)
{

    studentNumber = new char[51];

    strcpy(studentNumber, number);
}

void Students::_initStudentName(const char *name)
{

    studentName = new char[51];

    strcpy(studentName, name);
}

Students::Students()
{

    _initStudentNumber("00000");

    _initStudentName("none");

    GPA = 0;
}

Students::~Students()
{

    std::cout << studentName << " removed" << std::endl;

    delete[] studentNumber;

    delete[] studentName;
}

void Students::setStudentNumber(const char *number)
{

    _initStudentNumber(number);
}

void Students::setStudentName(const char *name)
{

    _initStudentName(name);
}

void Students::setGPA(double gpa)
{

    GPA = gpa;
}

const char *Students::getStudentNumber() const
{

    return studentNumber;
}

const char *Students::getStudentName() const
{

    return studentName;
}

double Students::getStudentGPA() const
{

    return GPA;
}
