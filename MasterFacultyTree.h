#ifndef MASTER_FACULTY_TREE_H_
#define MASTER_FACULTY_TREE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "GenBST.h"
#include "Faculty.h"

class MasterFacultyTree {
public:
  MasterFacultyTree();
  ~MasterFacultyTree();

  void save(); //serialize from root
  void load(); //deserialize from root
  void serialize(TreeNode<Faculty> *s, ofstream& f); //recursive serialization
  void deserialize(ifstream& f);

  void addFaculty();
  void print();

private:
  BST<Faculty> *tree;
};

#endif
