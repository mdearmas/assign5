#include "Student.h"
#include "Faculty.h"
#include "GenBST.h"

int main(int argc, char **argv)
{
  BST<char>* b = new BST<char>();
  b->insertBST(13, 'm');
  b->insertBST(26, 'z');
  b->insertBST(1, 'a');
  b->insertBST(7, 'g');
  b->insertBST(16, 'p');
  b->insertBST(9, 'i');
  b->insertBST(20, 't');
  b->printTree();

  cout << endl;

  if(b->contains(7))
    b->deleteBST(7);
    
  b->printTree();
}
