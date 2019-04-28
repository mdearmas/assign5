#ifndef MENU_H_
#define MENU_H_

class Menu {
public:
  Menu();

  void startUp();
  void printMenu();

  void displayAllStudents();
  void displayAllFaculty();

  void findStudent(int id);
  void findFaculty(int id);

  void findAdvisor(int id);
  void findAdvisees(int id);

  void addStudent();
  void addFaculty();

  void deleteStudent(int id);
  void deleteFaculty(int id);

  void reassignAdvisor(int student_id, int faculty_id);
  void removeAdvisee(int faculty_id, int student_id);
}

#endif
