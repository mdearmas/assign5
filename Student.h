/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 5: Building a Database with Binary Search Trees
Purpose: This file, Student.h, contains the class definition for the Student class (child of Person).
Adds an advisor ID, a major, and a GPA to the existing Person object, and the respective
accessor and modifier methods. The << operator is also overloaded.
*/
#ifndef STUDENT_H_
#define STUDENT_H_

#include "Person.h"

class Student : public Person {
public:
  Student():Person() //default constructor
  {
    advisor = -1;
    major = "Undeclared";
    gpa = -1.00;
  }

  Student(int i, string n, string l, int a, string m, double g):Person(i, n, l) //overloaded constructor
  {
    advisor = a;
    major = m;
    gpa = g;
  }

  virtual ~Student(){} //nothing new was allocated, so nothing needs to be destroyed

  //accessor methods
  int getAdvisor() { return advisor; }
  string getMajor() { return major; }
  double getGPA() { return gpa; }

  //modifier methods
  void reassignAdvisor(int new_advisor);

  //overloaded << operator
  friend ostream& operator<<(ostream& os, const Student& s)
  {
    os << "/ " << s.name << " / " << s.level << " / " << s.major;
    os << " / " << s.advisor;
    os << " / " << s.gpa;
    return os;
  }

protected:
  int advisor;
  string major;
  double gpa;
};

#endif
