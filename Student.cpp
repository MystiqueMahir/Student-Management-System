#include <iostream>
#include "Student.h"

using namespace std;

void Student::input()
{
    cout << "Enter ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(name, 50);

    cout << "Enter Age: ";
    cin >> age;

    cin.ignore();

    cout << "Enter Course: ";
    cin.getline(course, 50);

    cout << "Enter Marks: ";
    cin >> marks;
}

void Student::display() const
{
    cout << "\n------------------------";
    cout << "\nID     : " << id;
    cout << "\nName   : " << name;
    cout << "\nAge    : " << age;
    cout << "\nCourse : " << course;
    cout << "\nMarks  : " << marks;
    cout << "\n------------------------\n";
}

int Student::getId() const
{
    return id;
}

void Student::setMarks(float marks)
{
    this->marks = marks;
}
