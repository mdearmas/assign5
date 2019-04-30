/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 5: Building a Database with Binary Search Trees
Purpose: This file, MasterFacultyTree.h, contains the definition of both the MasterFacultyTree class and the BadInputException
that is used to aid in error checking. Includes options for serialization and deserialization. Supports Rollback operations.
*/

#ifndef MASTER_FACULTY_TREE_H_
#define MASTER_FACULTY_TREE_H_

#include <iostream>
#include <fstream>
#include <sstream> //for parsing through the csv
#include <vector> //for parsing through the csv

#include "GenBST.h"
#include "Faculty.h"
#include "Rollback.h" //gives us access to Rollback operations

class MasterFacultyTree {
public:
  MasterFacultyTree(); //constructor
  ~MasterFacultyTree(); //destructor

  void save(); //serialize from root
  void load(); //deserialize from root
  void serialize(TreeNode<Faculty> *s, ofstream& f); //recursive serialization
  void deserialize(ifstream& f); //deserialization

  int addFaculty(); //adds a Faculty member to the tree based on user input
  void deleteFaculty(int id); //deletes a faculty member
  void print(); //prints the contents of the Faculty tree

  void store(); //stores the current tree on the stack
  void undo(); //checks if undo is a valid operation and then resets the tree if so

  Faculty lookup(int id); //returns a copy of the Faculty attached to the passed key
  Faculty* lookupPointer(int id); //returns a direct pointer to the Faculty attached to the passed key

  int getRootID() { return (tree->getRootKey()); } //returns the id of the root Faculty member
  int getNextID() { return (tree->getNextKey()); } //returns a different potential ID, used for reassignment later

  bool valid(int id) { return (tree->contains(id)); } //checks if the tree contains the passed key
  bool empty() { return (tree->isEmpty()); } //checks if the tree is empty

private:
  BST<Faculty> *tree; //the main BST
  Rollback<Faculty> *stack; //the Rollback stack
};

#endif

#ifndef BAD_INPUT_EXCEPTION_H_
#define BAD_INPUT_EXCEPTION_H_

class BadInputException //class definition for an exception that is thrown if the user input does not match the required type
{
public:
  BadInputException(string message) : error_message(message) { } //constructor with initializer list
  string getErrorMessage() { return error_message; } //accessor that returns the error message
private:
  string error_message; //the error message associated with the error object
};
#endif
