#include "Menu.h"

Menu::Menu()
{
  MasterFacultyTree f_tree;
  MasterStudentTree s_tree;
}

void Menu::startUp()
{
  f_tree.load();
  s_tree.load();
}

void Menu::shutDown()
{
  f_tree.save();
  s_tree.save();
}

void Menu::printMenu()
{
  cout << "ACTION (command): " << endl;
  cout << "Display Students (ds)    Display Faculty (df)" << endl;
  cout << "Find Student (fs)   Find Faculty (ff)" << endl;
  cout << "Find Advisor (fa)   Find Advisees (fas)" << endl;
  cout << "Add Student (as)     Add Faculty (af)" << endl;
  cout << "Delete Student (dls)   Delete Faculty (dlf)" << endl;
  cout << "Reassign Advisor (ra)    Remove Advisee (ras)" << endl;
  cout << "Undo (u)   Exit (e)" << endl;
}

void Menu::displayAllStudents()
{
  s_tree.print();
}

void Menu::displayAllFaculty()
{
  f_tree.print();
}

void Menu::findStudent()
{
  int id;
  cout << "Enter the student's id: ";
  cin >> id;
  if(cin.fail())
    cout << "Not a valid ID number." << endl;
  else
  {
    if(f_tree.valid(id))
    {
      Student s = s_tree.lookup(id);
      cout << id << " " << s << endl;
    }
    else
    {
      cout << "Student does not exist." << endl;
    }
  }
  cin.clear();
}

void Menu::findFaculty()
{
  int id;
  cout << "Enter the faculty's id: ";
  cin >> id;
  if(cin.fail())
    cout << "Not a valid ID number." << endl;
  else
  {
    if(f_tree.valid(id))
    {
      Faculty f = f_tree.lookup(id);
      cout << id << " " << f << endl;
    }
    else
    {
      cout << "Faculty does not exist." << endl;
    }
  }
  cin.clear();
}

void Menu::findAdvisor()
{
  int id;
  cout << "Enter the faculty's id: ";
  cin >> id;
  if(cin.fail())
    cout << "Not a valid ID number." << endl;
  else
  {
    f_tree.lookup(id);
  }
}

void Menu::addStudent()
{
  s_tree.addStudent();
}

void Menu::addFaculty()
{
  f_tree.addFaculty();
}
