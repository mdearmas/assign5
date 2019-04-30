/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 5: Building a Database with Binary Search Trees
Purpose: This file, Faculty.cpp, contains the out-of-member class functions for Faculty.
*/
#include "Faculty.h"

void Faculty::addAdvisee(int student_id) //adds an advisee to the list
{
  advisee_list = advisee_list + to_string(student_id) + '/';
}

void Faculty::removeAdvisee(int student_id) //removes an advisee from the list
{
  vector<int> advisee_vector;
  string number;
  string placeholder = "/"; //will become the new advisee list
  stringstream s(advisee_list);

  bool first = true; //prevents an out of range error with stoi

  while(getline(s, number, '/')) //converts the string advisee_list into an iterable vector of ints
  {
    if(first)
      first = false;
    else
    {
      advisee_vector.push_back(stoi(number));
    }
  }

  for(int i = 0; i < advisee_vector.size(); ++i)
  {
    if(advisee_vector[i] != student_id) //if the id does not match the target to delete, add it to the new list
    {
      placeholder = placeholder + to_string(advisee_vector[i]) + '/';
    }
  }

  advisee_list = placeholder;
}

bool Faculty::containsAdvisee(int student_id) //returns true if the parameter is already a part of the list
{
  vector<int> advisee_vector;
  string number;
  string placeholder = "/";
  stringstream s(advisee_list);

  bool first = true; //prevents an out of range error with stoi

  while(getline(s, number, '/')) //converts the string advisee_list into an iterable vector of ints
  {
    if(first)
      first = false;
    else
    {
      advisee_vector.push_back(stoi(number));
    }
  }

  for(int i = 0; i < advisee_vector.size(); ++i)
  {
    if(advisee_vector[i] == student_id)
    {
      return true;
    }
  }
  return false;
}
