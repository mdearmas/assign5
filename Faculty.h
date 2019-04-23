#ifndef FACULTY_H_
#define FACULTY_H_

#include "Person.h"
#include "DoublyLinkedList.h"

class Faculty : public Person {
public:
  Faculty():Person() //default constructor
  {
    department = "Unassgined";
    advisees = new DoublyLinkedList<int>();
  }

  Faculty(int i, string n, string l, string d):Person(i, n, l) //overloaded constructor
  {
    department = d;
    advisees = new DoublyLinkedList<int>();
  }

  virtual ~Faculty()
  {
    delete advisees;
  }

  string getDepartment() { return department; }
  DoublyLinkedList<int>* getAdvisees() { return advisees; }

  void addAdvisee(int student_id);
  void removeAdvisee(int student_id);
  void printAdvisees();

  friend ostream& operator<<(ostream& os, const Faculty& s)
  {
    os << s.id << "   " << s.name << "   " << s.level << " " << s.department;
    return os;
  }

protected:
  string department;
  DoublyLinkedList<int>* advisees;

};

#endif
