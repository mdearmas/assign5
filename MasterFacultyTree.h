#ifndef MASTER_FACULTY_TREE_H_
#define MASTER_FACULTY_TREE_H_

#include <iostream>
#include <fstream>

#include "GenBST.h"
#include "Faculty.h"

class MasterFacultyTree {
public:
  MasterFacultyTree();

  ~MasterFacultyTree();

  void save(ofstream& os); //serialize from root
  void load(ifstream& is); //deserialize from root
  void serialize(TreeNode<Faculty> *s, ofstream& os); //recursive serialization
  void deserialize(TreeNode<Faculty> *s, ifstream& is);
  void setup(); //finds the file (if it exists) and loads the tree into this object

private:
  BST<Faculty> *tree;
};

#endif
