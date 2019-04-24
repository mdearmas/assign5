#include "MasterStudentTree.h"

MasterStudentTree::MasterStudentTree()
{
  tree = new BST<Student>();
}

MasterStudentTree::~MasterStudentTree()
{
  delete tree;
}

void MasterStudentTree::save(ofstream& os)
{
  serialize(tree->root, os);
}

void MasterStudentTree::load(ifstream& is)
{
  deserialize(tree->root, is);
}

void MasterStudentTree::serialize(TreeNode<Student> *s, ofstream& os)
{
  if(s == NULL)
  {
    //print a NULL marker to file
  }
  else
  {
    //print the node to the file
    serialize(s->left, os);
    serialize(s->right, os);
  }
}

void MasterStudentTree::deserialize(TreeNode<Student> *s, ifstream& is)
{
  int i;
  string n;
  string l;
  int a;
  string m;
  double g;

  //if there are no other items in file or a NULL marker is found, return
  //else read in the info to the corresponding variables

  Student temp(i, n, l, a, m, g); //creates new student with info

  tree->insertBST(i, temp); //insert into tree
  deserialize(s->left, is);
  deserialize(s->right, is);
}
