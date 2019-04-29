#ifndef MASTER_STUDENT_TREE_H_
#define MASTER_STUDENT_TREE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "GenBST.h"
#include "Student.h"

using namespace std;

class MasterStudentTree {
public:
  MasterStudentTree();

  ~MasterStudentTree();

  void save(); //serialize from root
  void load(); //deserialize from root
  void serialize(TreeNode<Student> *s, ofstream& f); //recursive serialization
  void deserialize(ifstream& f);

  void addStudent();
  void print();

  Student lookup(int id);

  bool valid(int id) { return (tree->contains(id)); }

private:
  BST<Student> *tree;
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
