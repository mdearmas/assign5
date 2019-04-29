#ifndef ROLLBACK_H_
#define ROLLBACK_H_

#include <iostream>

#include "GenStack.h"
#include "GenBST.h"

using namespace std;

template <typename T>
class Rollback {
public:
  Rollback()
  {
    core = new GenStack<BST<T>*>(100);
  }

  ~Rollback()
  {
    delete core;
  }

  void store(BST<T>* current)
  {
    BST<T>* temp = current->copy();
    core->push(temp);
  }

  BST<T>* undo()
  {
    core->pop();
  }

private:
  GenStack<BST<T>*> *core;

};

#endif
