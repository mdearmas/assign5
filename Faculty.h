/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 5: Building a Database with Binary Search Trees
Purpose: This file, Faculty.h, contains the class definition for the Faculty class (child of Person).
Adds a department as well as a list of advisees to the existing Person object, and the respective
accessor and modifier methods. The << operator is also overloaded.
*/
#ifndef FACULTY_H_
#define FACULTY_H_

#include <sstream> //accesses string stream for parsing advisee list
#include <vector> //accesses vector for parsing advisee list
#include "Person.h"

class Faculty : public Person {
public:
  Faculty():Person() //default constructor
  {
    department = "Unassgined";
    advisee_list = "/";
  }

  Faculty(int i, string n, string l, string d):Person(i, n, l) //overloaded constructor
  {
    department = d;
    advisee_list = "/";
  }

  Faculty(int i, string n, string l, string d, string a):Person(i, n, l) //overloaded constructor 2, used specifically for deserialization
  {
    department = d;
    advisee_list = a;
  }

  virtual ~Faculty() {}; //nothing allocated with new so nothing destroyed

  //new accessor methods
  string getDepartment() { return department; }
  string getAdvisees() { return advisee_list; }

  //modifier methods for the advisees list
  void addAdvisee(int student_id);
  void removeAdvisee(int student_id);

  bool containsAdvisee(int student_id); //returns true if the advisee list contains the passed parameter

  friend ostream& operator<<(ostream& os, const Faculty& s)
  {
    os << "/ " << s.name << " / " << s.level << " / " << s.department;
    return os;
  }

protected:
  string department;
  string advisee_list; //a list of integers collected into a single string divided by the delimiter '/'; makes for easier serialization and deserialization; can be parsed into a vector of ints

};

#endif
