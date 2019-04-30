#ifndef MASTER_FACULTY_TREE_H_
#define MASTER_FACULTY_TREE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "GenBST.h"
#include "Faculty.h"
#include "Rollback.h"

class MasterFacultyTree {
public:
  MasterFacultyTree();
  ~MasterFacultyTree();

  void save(); //serialize from root
  void load(); //deserialize from root
  void serialize(TreeNode<Faculty> *s, ofstream& f); //recursive serialization
  void deserialize(ifstream& f);

  int addFaculty();
  void deleteFaculty(int id);
  void print();

  void store();
  void undo();

  Faculty lookup(int id);
  Faculty* lookupPointer(int id);

  int getRootID() { return (tree->getRootKey()); }
  int getNextID() { return (tree->getNextKey()); }

  bool valid(int id) { return (tree->contains(id)); }
  bool empty() { return (tree->isEmpty()); }

private:
  BST<Faculty> *tree;
  Rollback<Faculty> *stack;
};

#endif

#ifndef BAD_INPUT_EXCEPTION_H_
#define BAD_INPUT_EXCEPTION_H_

class BadInputException //class definition for an exception that is thrown if the file has incorrect format
{
public:
  BadInputException(string message) : error_message(message) { } //constructor with initializer list
  string getErrorMessage() { return error_message; } //accessor that returns the error message
private:
  string error_message; //the error message associated with the error object
};
#endif
