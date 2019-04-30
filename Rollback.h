/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 5: Building a Database with Binary Search Trees
Purpose: This file, Rollback.h, contains the template for a Rollback action on a BST that allows the user to undo their
modifications to a BST. Using the array-based GenStack as its base, this has operations for storing and undoing/popping a
copy of a BST. The template allows a BST storing any type of data to be saved in the Rollback.
*/

#ifndef ROLLBACK_H_
#define ROLLBACK_H_

#include <iostream>

#include "GenStack.h"
#include "GenBST.h"

using namespace std;

template <typename T>
class Rollback {
public:
  Rollback() //default constructor
  {
    core = new GenStack<BST<T>*>(100);
  }

  ~Rollback() //destructor
  {
    delete core;
  }

  void store(BST<T>* current) //adds a copy of the passed tree to the stack
  {
    BST<T>* temp = current->copy();
    core->push(temp);
  }

  BST<T>* undo() //pops the most recent copy off the stack
  {
    return core->pop();
  }

  bool possible() //checks to see if an undo action is even possible (aka: whether or not the stack is empty) to prevent a segfault
  {
    return !(core->isEmpty());
  }

private:
  GenStack<BST<T>*> *core; //the stack that forms the base of the Rollback operation

};

#endif
