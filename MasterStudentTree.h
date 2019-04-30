/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 5: Building a Database with Binary Search Trees
Purpose: This file, MasterStudentTree.h, contains the definition of both the MasterStudentTree class and the BadInputException
that is used to aid in error checking. Includes options for serialization and deserialization. Supports Rollback operations.
*/

#ifndef MASTER_STUDENT_TREE_H_
#define MASTER_STUDENT_TREE_H_

#include <iostream>
#include <fstream>
#include <sstream> //used to parse through csv
#include <vector> //used to parse through csv

#include "GenBST.h"
#include "Student.h"
#include "Rollback.h" //allows Rollback support

using namespace std;

class MasterStudentTree {
public:
  MasterStudentTree(); //constructor

  ~MasterStudentTree(); //destructor

  void save(); //serialize from root
  void load(); //deserialize from root
  void serialize(TreeNode<Student> *s, ofstream& f); //recursive serialization
  void deserialize(ifstream& f); //deserialization

  int addStudent(); //adds a student to the tree based on user input
  void deleteStudent(int id); //deletes a student
  void print(); //prints all the students contained in the tree

  void store(); //stores the most recent version of the tree
  void undo(); //undos the most recent operation to the tree

  Student lookup(int id); //returns a copy of the Student at the passed id
  Student* lookupPointer(int id); //returns a pointer to the student at the passed id

  bool valid(int id) { return (tree->contains(id)); } //checks to see if the student tree contains the passed id

private:
  BST<Student> *tree; //the main BST
  Rollback<Student> *stack; //the rollback stack
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
