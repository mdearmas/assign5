#ifndef FACULTY_H_
#define FACULTY_H_

#include <sstream>
#include <vector>
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

  virtual ~Faculty() {};

  string getDepartment() { return department; }
  string getAdvisees() { return advisee_list; }

  void addAdvisee(int student_id);
  void removeAdvisee(int student_id);
  void printAdvisees();

  bool containsAdvisee(int student_id);

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
