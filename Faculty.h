#ifndef FACULTY_H_
#define FACULTY_H_

#include "Person.h"
#include "DoublyLinkedList.h"

class Faculty : public Person {
public:
  Faculty():Person() //default constructor
  {
    department = "Unassgined";
    advisee_list = "";
  }

  Faculty(int i, string n, string l, string d):Person(i, n, l) //overloaded constructor
  {
    department = d;
    advisee_list = "";
  }

  Faculty(int i, string n, string l, string d, string a):Person(i, n, l) //overloaded constructor 2
  {
    department = d;
    advisee_list = a;
  }

  virtual ~Faculty()
  {
    //delete advisees;
  }

  string getDepartment() { return department; }
  string getAdvisees() { return advisee_list; }

  void addAdvisee(int student_id);
  void removeAdvisee(int student_id);
  //void printAdvisees();
  //int numberOfAdvisees();
  //int* adviseeArray();

  friend ostream& operator<<(ostream& os, const Faculty& s)
  {
    os << s.id << " / " << s.name << " / " << s.level << " / " << s.department;
    return os;
  }

protected:
  string department;
  string advisee_list;

};

#endif
