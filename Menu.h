/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 5: Building a Database with Binary Search Trees
Purpose: This file, Menu.h, contains the definition for the Menu class. This class controls the main Faculty and Student databases
and manages their interactions with each other.
*/

#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <vector> //used for parsing through Faculty advisee lists
#include <sstream> //used for parsing through Faculty advisee lists

#include "MasterFacultyTree.h"
#include "MasterStudentTree.h"

using namespace std;

class Menu {
public:
  Menu(); //constructor

  void startUp(); //deserializes the Student and Faculty trees
  void shutDown(); //serializes the Student and Faculty trees
  void printMenu(); //prints the available commands to the user

  void displayAllStudents(); //displays all the students
  void displayAllFaculty(); //displays all the faculty

  void findStudent(); //locates a student
  void findFaculty(); //locates a faculty

  void findAdvisor(); //locates a student's advisor
  void findAdvisees(); //locates a faculty's advisees

  void addStudent(); //adds a student to the tree and aligns advisor requirements accordingly
  void addFaculty(); //adds a faculty to the tree and aligns advisee requirements accordingly

  void deleteStudent(); //deletes a student
  void deleteFaculty(); //deletes a faculty

  void reassignAdvisor(); //reassigns a student's advisor
  void removeAdvisee(); //removes a student from a faculty advisor's list

  void reassignAdvisorBase(int student_id, int faculty_id); //the base operation for reassigning an advisor, does not ask for user input
  void removeAdviseeBase(int faculty_id, int student_id); //the base operation for removing an advisee, does not ask for user input

  void store(); //stores both the Student and the Faculty trees to their respective Rollbacks
  void undo(); //calls the rollback for both the Student and Faculty trees

private:
  MasterFacultyTree f_tree;
  MasterStudentTree s_tree;

};

#endif
