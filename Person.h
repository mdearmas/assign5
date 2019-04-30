/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 5: Building a Database with Binary Search Trees
Purpose: This file, Person.h, contains the base class header for both the Faculty and Student classes.
Includes overloaded operators for comparison.
*/
#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

using namespace std;

class Person {
public:
  Person() //default constructor
  {
    id = -1;
    name = "NONE";
    level = "NONE";
  }

  Person(int i, string n, string l) //overloaded constructor
  {
    id = i;
    name = n;
    level = l;
  }

  virtual ~Person(){} //virtual destructor to account for child classes

  //accessor methods
  int getID() { return id; }
  string getName() { return name; }
  string getLevel() { return level; }

  //overloaded comparison operators
  friend bool operator<(const Person& p, const Person& q) { return (p.id < q.id); }
  friend bool operator>(const Person& p, const Person& q) { return q < p; }
  friend bool operator<=(const Person& p, const Person& q) { return !(p > q); }
  friend bool operator>=(const Person& p, const Person& q) { return !(p < q); }

  //overloaded equality operators
  friend bool operator==(const Person& p, const Person& q) { return (p.id == q.id); }
  friend bool operator!=(const Person& p, const Person& q) { return !(p == q); }

protected:
  int id;
  string name;
  string level;
};

#endif
