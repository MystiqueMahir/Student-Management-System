#include <iostream>
#include <fstream>
#include <cstdio>

#include "StudentManager.h"
#include "Student.h"

using namespace std;

void StudentManager::addStudent()
{
    Student student;

    student.input();

    ofstream file(
        "students.dat",
        ios::binary | ios::app);

    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }

    file.write(
        reinterpret_cast<char *>(&student),
        sizeof(student));

    file.close();

    cout << "\nStudent added successfully.\n";
}

void StudentManager::displayStudents()
{
    Student student;

    ifstream file(
        "students.dat",
        ios::binary);

    if (!file)
    {
        cout << "No records found.\n";
        return;
    }

    while (
        file.read(
            reinterpret_cast<char *>(&student),
            sizeof(student)))
    {
        student.display();
    }

    file.close();
}

void StudentManager::searchStudent()
{
    int id;

    cout << "Enter Student ID: ";
    cin >> id;

    Student student;

    ifstream file(
        "students.dat",
        ios::binary);

    bool found = false;

    while (
        file.read(
            reinterpret_cast<char *>(&student),
            sizeof(student)))
    {
        if (student.getId() == id)
        {
            cout << "\nStudent Found:\n";
            student.display();

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent not found.\n";
    }

    file.close();
}

void StudentManager::updateStudent()
{
    int id;

    cout << "Enter Student ID to update: ";
    cin >> id;

    Student student;

    fstream file(
        "students.dat",
        ios::binary | ios::in | ios::out);

    bool found = false;

    while (
        file.read(
            reinterpret_cast<char *>(&student),
            sizeof(student)))
    {
        if (student.getId() == id)
        {
            float newMarks;

            cout << "Enter New Marks: ";
            cin >> newMarks;

            student.setMarks(newMarks);

            file.seekp(
                -static_cast<int>(sizeof(student)),
                ios::cur);

            file.write(
                reinterpret_cast<char *>(&student),
                sizeof(student));

            found = true;

            cout << "\nRecord updated successfully.\n";

            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent not found.\n";
    }

    file.close();
}

void StudentManager::deleteStudent()
{
    int id;

    cout << "Enter Student ID to delete: ";
    cin >> id;

    Student student;

    ifstream file(
        "students.dat",
        ios::binary);

    ofstream temp(
        "temp.dat",
        ios::binary);

    bool found = false;

    while (
        file.read(
            reinterpret_cast<char *>(&student),
            sizeof(student)))
    {
        if (student.getId() == id)
        {
            found = true;
            continue;
        }

        temp.write(
            reinterpret_cast<char *>(&student),
            sizeof(student));
    }

    file.close();
    temp.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
    {
        cout << "\nStudent deleted successfully.\n";
    }
    else
    {
        cout << "\nStudent not found.\n";
    }
}
