#ifndef MENU_H_
#define MENU_H_

#include <iostream>

#include "MasterFacultyTree.h"
#include "MasterStudentTree.h"

using namespace std;

class Menu {
public:
  Menu();

  void startUp();
  void shutDown();
  void printMenu();

  void displayAllStudents();
  void displayAllFaculty();

  void findStudent();
  void findFaculty();

  void findAdvisor();
  void findAdvisees();

  void addStudent();
  void addFaculty();

  void deleteStudent(int id);
  void deleteFaculty(int id);

  void reassignAdvisor(int student_id, int faculty_id);
  void removeAdvisee(int faculty_id, int student_id);

private:
  MasterFacultyTree f_tree;
  MasterStudentTree s_tree;

};

#endif
