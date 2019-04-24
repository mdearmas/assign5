#ifndef MASTER_STUDENT_TREE_H_
#define MASTER_STUDENT_TREE_H_

#include <iostream>
#include <fstream>

#include "GenBST.h"
#include "Student.h"

class MasterStudentTree {
public:
  MasterStudentTree();

  ~MasterStudentTree();

  void save(ofstream& os); //serialize from root
  void load(ifstream& is); //deserialize from root
  void serialize(TreeNode<Student> *s, ofstream& os); //recursive serialization
  void deserialize(TreeNode<Student> *s, ifstream& is);
  void setup(); //finds the file (if it exists) and loads the tree into this object

private:
  BST<Student> *tree;
};

#endif
