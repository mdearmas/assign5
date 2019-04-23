/*
  Makenzie De Armas
  ID: 2278709
  dearm102@mail.chapman.edu
  CPSC 350-01
  Assignment 4: Registrar's Office Simulation
  Purpose: This file, DoublyLinkedList.h, contains the template for a Doubly Linked List, a child class of GenList.h.
  This file also contains a template for a ListNode to be used in the Doubly Linked List, as well as an EmptyListException
  that is thrown when a remove operation is attempted on an empty list.
*/
#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "GenList.h"

template <typename T> //class definition for ListNode (doubly linked list specific)
class ListNode {
public:
  ListNode(T obj) //overloaded constructor
  {
    data = obj; //sets obj as data
    next = NULL;
    prev = NULL;
  }

  ~ListNode() //destructor, since nothing has been allocated with new, the destructor just ensures that the node's pointers are nulled out before proceeding
  {
    next = NULL;
    prev = NULL;
  }

  T data;
  ListNode<T>* next; //pointer to the next node
  ListNode<T>* prev; //pointer to the previous node
};

class EmptyListException //class definition for an exception that is thrown if the file has incorrect format
{
public:
  EmptyListException(string message) : error_message(message) { } //constructor with initializer list
  string getErrorMessage() { return error_message; } //accessor that returns the error message
private:
  string error_message; //the error message associated with the error object
};

template <typename T> //class definition of DoublyLinkedList
class DoublyLinkedList : public GenList<T> {
public:
  ListNode<T> *front; //pointer to the front of list
  ListNode<T> *back; //pointer to the end of list
  int size; //number of elements contained in list

  DoublyLinkedList() //default constructor
  {
    front = NULL;
    back = NULL;
    size = 0;
  }

  virtual ~DoublyLinkedList() //destructor
  {
    while(size > 0) //while there are still elements in the list
    {
      ListNode<T> *curr = front; //used to keep track of our position
      if(size > 1) //if there is more than one element left, prevents segfault
      {
        front = front->next; //front is now the next element
        front->prev = NULL; //sets the front's pointer to previous to NULL
        curr->next = NULL; //sets curr's next pointer to NULL to isolate it
      }
      size--; //decrements size
      delete curr; //deletes the node
    }
  }

  void insertFront(T obj) //inserts a node as the new front of the list
  {
    ListNode<T> *node = new ListNode<T>(obj); //allocate a new node

    if(size == 0) //if the list is empty
    {
      back = node; //the back is also set to the front
    }
    else //if there is already a front
    {
      node->next = front; //node's next pointer is set to the current front
      front->prev = node; //set the old front's prev pointer to the new node
    }

    front = node; //sets front to the new node
    size++; //increment list size
  }

  virtual void insertBack(T obj)
  {
    ListNode<T> *node = new ListNode<T>(obj); //allocates a new node

    if(size == 0) //if the list is empty
    {
      front = node; //the front is also sent to the back
    }
    else
    {
      node->prev = back; //node's prev pointer is set to the current back
      back->next = node; //the back's next pointer is set to the new node
    }

    back = node; //sets the back to the new node
    size++; //increments list size
  }

  virtual void insertPos(int k, T obj)
  {
    int key = 0; //used to keep track of the number of nodes
    ListNode<T>* curr = front;
    while(key != k) //while the key does not equal the passed paramenter, iterates through the list
    {
      curr = curr->next;
      ++key;
      if(curr == NULL) //if current equals NULL, that means the key does not exist
        break;
    }

    if(curr != NULL) //if current does not equal NULL, then we have found our target
    {
      if(curr == front) //if this is also the front of the list, use the specific insertFront method
        insertFront(obj);
      else if(curr == back) //if this is also the back of the list, use the specific insertBack method
        insertBack(obj);
      else
      {
        ListNode<T> *node = new ListNode<T>(obj); //allocate a new node
        //moves around the pointers to insert the new node before curr
        node->prev = curr->prev;
        node->next = curr;
        curr->prev->next = node;
        curr->prev = node;
        size++; //increments size of list
      }
    }
  }

  virtual void removeFront() //removes the front element of the list
  {
    try
    {
      if(isEmpty()) //if the list is empty, throw an exception
        throw EmptyListException("ERROR: cannot remove a node from an empty list");
      else
      {
        ListNode<T> *curr = front;
        if(size > 1) //if there is more than one node left, prevents segfault
        {
          front = front->next; //sets the new front
          front->prev = NULL; //nulls new front's prev pointer
          curr->next = NULL; //nulls the curr's next pointer to isolate it
        }
        size--; //decrements size
        delete curr; //deletes the node
      }
    }
    catch(EmptyListException& e)
    {
      cout << e.getErrorMessage() << endl; //prints the error message to the console
    }
  }

  virtual void removeBack() //removes the last element of the list
  {
    try
    {
      if(isEmpty()) //if the list is empty, throw an exception
        throw EmptyListException("ERROR: cannot remove a node from an empty list");
      else
      {
        ListNode<T> *curr = back;
        if(size > 1)
        {
          back = back->prev; //sets the new back
          back->next = NULL; //nulls new back's next pointer
          curr->prev = NULL; //nulls the curr's prev pointer to isolate it
        }
        size--; //decrements size
        delete curr; //deletes node
      }
    }
    catch(EmptyListException& e)
    {
      cout << e.getErrorMessage() << endl; //prints the error message to the console
    }
  }

  virtual void removePos(int k) //removes a node a specific position
  {
    try
    {
      if(isEmpty()) //if the list is empty, throw an exception
        throw EmptyListException("ERROR: cannot remove a node from an empty list");
      else
      {
        int key = 0; //used to keep track of nodes
        ListNode<T> *curr = front;
        while(key != k) //while the key doesn't equal the passed parameter, keep iterating through the list
        {
          curr = curr->next;
          ++key;
          if(curr == NULL) //if curr equals NULL, that means the key does not exist
            break;
        }

        if(curr != NULL) //if curr is not NULL, then we found the key
        {
          if(curr == front) //if curr is also the front, set a new front
            front == curr->next;
          else
          {
            curr->prev->next = curr->next; //sets pointer to skip the to-be-deleted node
          }

          if(curr == back) //if curr is also the back, set a new back
            back == curr->prev;
          else
          {
            curr->next->prev = curr->prev; //sets pointer to skip the to-be-deleted node
          }
          //null out pointers to isolate node
          curr->next = NULL;
          curr->prev = NULL;
          size--; //decrement size
          delete curr; //delete node
        }
      }
    }
    catch(EmptyListException& e)
    {
      cout << e.getErrorMessage() << endl; //prints the error message to the console
    }
  }

  virtual void removeContent(T obj)
  {
    try
    {
      if(isEmpty()) //if the list is empty, throw an exception
        throw EmptyListException("ERROR: cannot remove a node from an empty list");
      else
      {
        ListNode<T> *curr = front;
        T temp = curr->data; //used to keep track of nodes
        while(temp != obj) //while the key doesn't equal the passed parameter, keep iterating through the list
        {
          curr = curr->next;
          if(curr == NULL) //if curr equals NULL, that means the key does not exist
            break;
          else
          {
            temp = curr->data;
          }
        }

        if(curr != NULL) //if curr is not NULL, then we found the key
        {
          if(curr == front) //if curr is also the front, set a new front
            front == curr->next;
          else
          {
            curr->prev->next = curr->next; //sets pointer to skip the to-be-deleted node
          }

          if(curr == back) //if curr is also the back, set a new back
            back == curr->prev;
          else
          {
            curr->next->prev = curr->prev; //sets pointer to skip the to-be-deleted node
          }
          //null out pointers to isolate node
          curr->next = NULL;
          curr->prev = NULL;
          size--; //decrement size
          delete curr; //delete node
        }
      }
    }
    catch(EmptyListException& e)
    {
      cout << e.getErrorMessage() << endl; //prints the error message to the console
    }
  }

  virtual T begin() //returns the data stored in the front node
  {
    try
    {
      if(isEmpty()) //throw an exception if the list is empty
        throw EmptyListException("ERROR: list is empty");
      else
      {
        return front->data;
      }
    }
    catch(EmptyListException& e)
    {
      cout << e.getErrorMessage() << endl; //print error message to the console
    }
  }

  virtual T end() //returns the data stored in the back node
  {
    try
    {
      if(isEmpty()) //throw an expection is the list is empty
        throw EmptyListException("ERROR: list is empty");
      else
      {
        return back->data;
      }
    }
    catch(EmptyListException& e)
    {
      cout << e.getErrorMessage() << endl; //print error message to the console
    }
  }

  virtual bool isEmpty() { return (size <= 0); } //returns true if size is 0 (or less, in case of error)
  int getSize() { return size; } //accessor for the size

  void printList()
  {
    try
    {
      if(isEmpty()) //if the list is empty, throw an exception
        throw EmptyListException("No contents found.");
      else
      {
        ListNode<T> *curr = front;
        while(curr != NULL)
        {
          cout << curr->data << " ";
          curr = curr->next;
        }
        cout << endl;
      }
    }
    catch(EmptyListException& e)
    {
      cout << e.getErrorMessage() << endl; //prints the error message to the console
    }
  }
};

#endif
