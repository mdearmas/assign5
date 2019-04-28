#ifndef MASTER_STUDENT_TREE_H_
#define MASTER_STUDENT_TREE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "GenBST.h"
#include "Student.h"

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
  void lookup(int id);

private:
  BST<Student> *tree;
};

#endif
