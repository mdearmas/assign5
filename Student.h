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

  int getAdvisor() { return advisor; }
  string getMajor() { return major; }
  double getGPA() { return gpa; }

  void reassignAdvisor(int new_advisor);

  friend ostream& operator<<(ostream& os, const Student& s)
  {
    os << s.id << "   " << s.name << "   " << s.level << " " << s.major;
    os << "   Advisor: " << s.advisor;
    os << "   GPA: " << s.gpa << endl;
    return os;
  }

protected:
  int advisor;
  string major;
  double gpa;
};

#endif
