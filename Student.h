#ifndef STUDENT_H
#define STUDENT_H

class Student
{
private:
    int id;
    char name[50];
    int age;
    char course[50];
    float marks;

public:
    void input();
    void display() const;

    int getId() const;
    void setMarks(float marks);
};

#endif
