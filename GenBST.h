#ifndef GEN_BST_H_
#define GEN_BST_H_

#include <iostream>

using namespace std;

template <typename T>
class TreeNode {
public:
  TreeNode()
  {
    left = NULL;
    right = NULL;
  }

  TreeNode(int k, T obj)
  {
    key = k;
    data = obj;
    left = NULL;
    right = NULL;
  }

  ~TreeNode()
  {
    left = NULL;
    right = NULL;
  }

  int key;
  T data;
  TreeNode<T> *left;
  TreeNode<T> *right;
};

//defining Tree class
template <typename T>
class BST {
public:
  BST()
  {
    root = NULL;
  }

  ~BST()
  {
    destroyRec(root);
  }

  void destroyRec(TreeNode<T>* node)
  {
    if(node != NULL)
    {
      destroyRec(node->left);
      destroyRec(node->right);
      delete node;
    }
  }

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

  T find(int k)
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
      return curr->data;
    }
    else
    {
      cout << "Error: Can not find requested value." << endl;
    }
  }

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

  bool isEmpty() { return (root == NULL); }

  void printTree()
  {
    inOrderPrint(root);
  }

  void inOrderPrint(TreeNode<T>* n)
  {
    if(n == NULL)
      return;

    inOrderPrint(n->left);
    cout << n->key << " " << n->data << endl;
    inOrderPrint(n->right);
  }

  BST* copy()
  {
    BST* copy = new BST();
    recursiveCopy(root, copy);
    return copy;
  }

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

  TreeNode<T>* root;
};

#endif
