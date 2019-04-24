#include "MasterFacultyTree.h"

MasterFacultyTree::MasterFacultyTree()
{
  tree = new BST<Faculty>();
}

MasterFacultyTree::~MasterFacultyTree()
{
  delete tree;
}

void MasterFacultyTree::save(ofstream& os)
{
  serialize(tree->root, os);
}

void MasterFacultyTree::load(ifstream& is)
{
  deserialize(tree->root, is);
}

void MasterFacultyTree::serialize(TreeNode<Faculty> *s, ofstream& os)
{
  if(s == NULL)
  {
    //print a NULL marker to file
  }
  else
  {
    //print the node to the file — how do I deal with the list of advisees?
    serialize(s->left, os);
    serialize(s->right, os);
  }
}

void MasterFacultyTree::deserialize(TreeNode<Faculty> *s, ifstream& is)
{
  int i;
  string n;
  string l;
  string d;
  //how to get advisee info??

  //if there are no more items or a NULL marker is found, return
  //else, fill in info from file

  Faculty temp(i, n, l, d); //create another faculty object
  //add advisees?

  tree->insertBST(i, temp);
  deserialize(s->left, is);
  deserialize(s->right, is);
}
