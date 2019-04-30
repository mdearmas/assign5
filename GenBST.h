/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 5: Building a Database with Binary Search Trees
Purpose: This file, GenBST.h, contains the templates for both a BST key-value pair tree node and a BST.
Includes all the functionality of a BST interface [insert, delete, contains, find, isEmpty, etc.] as well as
a few unique methods like copy, getRootKey, and getNextKey that assist with the specific needs of this assignment.
*/

#ifndef GEN_BST_H_
#define GEN_BST_H_

#include <iostream>

using namespace std;

//Tree Node template
template <typename T>
class TreeNode {
public:
  TreeNode() //default constructor
  {
    left = NULL;
    right = NULL;
  }

  TreeNode(int k, T obj) //overloaded constructor
  {
    key = k;
    data = obj;
    left = NULL;
    right = NULL;
  }

  ~TreeNode() //destructor, since nothing is allocated with new, the pointers are just nulled out
  {
    left = NULL;
    right = NULL;
  }

  int key; //the int key used for sorting
  T data;
  TreeNode<T> *left;
  TreeNode<T> *right;
};

//template Tree class
template <typename T>
class BST {
public:
  BST() //default constructor
  {
    root = NULL;
  }

  ~BST()//virtual destructor (in the event that we want to construct a red-black tree or other self balancing tree)
  {
    destroyRec(root); //iterates through the tree starting at the root
  }

  void destroyRec(TreeNode<T>* node) //recursive destructor, iterates through the tree and destorys the allocated nodes
  {
    if(node != NULL)
    {
      destroyRec(node->left);
      destroyRec(node->right);
      delete node;
    }
  }

  //inserts a new node into the tree
  void insertBST(int k, T v)
  {
    if(!contains(k)) //check if key already exists, if not continue
    {
      TreeNode<T>* node = new TreeNode<T>(k, v); //key is now set to value

      if(isEmpty()) //empty tree
      {
        root = node;
      }
      else //not an empty tree, need to find insertion point
      {
        TreeNode<T>* curr = root;
        TreeNode<T>* parent;
        while(true)
        {
          parent = curr;
          if( k < curr->key) //if the key is less than the current key
          {
            curr = curr->left;
            if(curr == NULL)
            {
              parent->left = node;
              break;
            }
          }
          else //if the key is greater than the current key
          {
            curr = curr->right;
            if(curr == NULL)
            {
              parent->right = node;
              break;
            }
          }
        }
      }
    }
  }

  //checks if the tree already contains a key
  bool contains(int k)
  {
    if(isEmpty())
      return false;
    else //tree is not empty
    {
      TreeNode<T>* curr = root;
      while(k != curr->key)
      {
        if(k < curr->key)
          curr = curr->left;
        else
          curr = curr->right;

        if(curr == NULL)
          return false;
      }
    }

    return true;
  }

  //returns a copy of the data associated with an input key
  T find(int k)
  {
    if(!isEmpty() && contains(k)) //as long as the tree is not empty and does contain the passed key, continue
    {
      TreeNode<T>* curr = root;
      while(k != curr->key)
      {
        if(k < curr->key)
          curr = curr->left;
        else
          curr = curr->right;
      }
      return curr->data;
    }
    else
    {
      cout << "Error: Can not find requested value." << endl;
    }
  }

  //returns a pointer to the data stored in a tree rather than a copy
  T* returnPointer(int k)
  {
    if(!isEmpty() && contains(k))
    {
      TreeNode<T>* curr = root;
      while(k != curr->key)
      {
        if(k < curr->key)
          curr = curr->left;
        else
          curr = curr->right;
      }
      return &(curr->data);
    }
    else
    {
      cout << "Error: Can not find requested value." << endl;
    }
  }

  //finds the node that will succeed another in a deletion
  TreeNode<T>* getSuccessor(TreeNode<T>* d)
  {
    TreeNode<T> *sp = d; //successor's parent
    TreeNode<T> *successor = d;
    TreeNode<T> *curr = d->right;

    while(curr != NULL)
    {
      sp = successor;
      successor = curr;
      curr = curr->left;
    }

    if(successor != d->right)
    {
      sp->left = successor->right;
      successor->right = d->right;
    }

    return successor;
  }

  //deletes a tree node corresponding to the passed key
  bool deleteBST(int k)
  {
    if(isEmpty()) //if the tree is empty, nothing can be deleted
      return false;

    if(!contains(k)) //if the tree doesn't contain the key
      return false;

    TreeNode<T> *curr = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while(curr->key != k)
    {
      parent = curr;

      if(k < curr->key)
      {
        isLeft = true;
        curr = curr->left;
      }
      else
      {
        isLeft = false;
        curr = curr->right;
      }

      if(curr == NULL)
        return false;
    }

    //at this point we've found our node
    if(curr->left == NULL && curr->right == NULL) //no children
    {
      if(curr == root)
        root = NULL;
      else if(isLeft)
      {
        parent->left = NULL;
      }
      else
      {
        parent->right = NULL;
      }
    }
    else if (curr->right == NULL) //only no right child
    {
      if(curr == root)
        root = root->left;
      else if(isLeft)
      {
        parent->left = curr->left;
      }
      else
      {
        parent->right = curr->left;
      }
    }
    else if (curr->left == NULL) //only no left child
    {
      if(curr == root)
        root = root->right;
      else if(isLeft)
      {
        parent->left = curr->right;
      }
      else
      {
        parent->right = curr->right;
      }
    }
    else
    {
      TreeNode<T> *successor = getSuccessor(curr);

      if(curr == root)
        root = successor;
      else if(isLeft)
      {
        parent->left = successor;
      }
      else
      {
        parent->right = successor;
      }
      successor->left = curr->left;
    }
    return true;
  }

  //checks if the tree contains any data
  bool isEmpty() { return (root == NULL); }

  //prints the entire tree in ascending key order
  void printTree()
  {
    inOrderPrint(root);
  }

  //recursively iterates through a tree to print nodes in ascending order
  void inOrderPrint(TreeNode<T>* n)
  {
    if(n == NULL)
      return;

    inOrderPrint(n->left);
    cout << n->key << " " << n->data << endl;
    inOrderPrint(n->right);
  }

  //returns a pointer to the copy of a whole tree
  BST* copy()
  {
    BST* copy = new BST();
    recursiveCopy(root, copy);
    return copy;
  }

  //copies a subtree based on parameters
  void recursiveCopy(TreeNode<T>* node, BST* b)
  {
    if(node == NULL)
      return;
    else
    {
      recursiveCopy(node->left, b);
      b->insertBST(node->key, node->data);
      recursiveCopy(node->right, b);
    }
  }

  //returns the key associated with a root
  int getRootKey() { return root->key; }

  //gets the key of the successor, with special exception if the tree is empty. this helps later with advisor reassignment.
  int getNextKey()
  {
    if(isEmpty())
      return -1;
    else if(root->left != NULL)
      return root->left->key;
    else
      return root->right->key;
  }

  TreeNode<T>* root;
};

#endif
