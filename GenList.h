/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 4: Registrar's Office Simulation
  Purpose: This file, GenList.h, contains the pure virtual base class for the list abstract data type.
  Abstract Data Type template taken from DATA STRUCTURES & ALGORITHMS IN C++ p. 240-241.
*/

#ifndef GENLIST_H_
#define GENLIST_H_

#include <iostream>

using namespace std;

template <typename T>
class GenList {
public:
  virtual void insertFront(T obj) = 0; //inserts new element obj as the first element of the list
  virtual void insertBack(T obj) = 0; //inserts new element obj as the last element of the list
  virtual void insertPos(int k, T obj) = 0; //inserts new element obj at position k

  virtual void removeFront() = 0; //removes the first element of the list
  virtual void removeBack() = 0; //removes the last element of the list
  virtual void removePos(int k) = 0; //removes the element at position k in the list
  virtual void removeContent(T obj) = 0; //removes the node containing the passed parameter

  virtual bool isEmpty() = 0; //returns true if the list has no elements

  virtual T begin() = 0; //returns the data stored in the first element of L
  virtual T end() = 0; //returns the data stored in the last element of L
};

#endif
