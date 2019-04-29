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
  cout << "Enter the student's id: ";
  cin >> id;
  if(cin.fail())
    cout << "Not a valid ID number." << endl;
  else
  {
    if(s_tree.valid(id))
    {
      Student s = s_tree.lookup(id);
      int faculty_target = s.getAdvisor();
      if(f_tree.valid(faculty_target))
      {
        Faculty f = f_tree.lookup(faculty_target);
        cout << "Student " << id << "'s advisor is " << faculty_target << " " << f << endl;
      }
      else
      {
        cout << "Student " << id << "'s advisor does not exist in the database. " << endl;
      }
    }
    else
    {
      cout << "This student does not exist in the database. " << endl;
    }
  }
}

void Menu::findAdvisees()
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
      string temp_list = f.getAdvisees();
      string student;

      vector<int> iterable_list;

      stringstream temp(temp_list);

      bool first = true;

      while(getline(temp, student, '/'))
      {
        if(first)
          first = false;
        else
        {
          iterable_list.push_back(stoi(student));
        }
      }

      if(iterable_list.size() == 0)
        cout << "Faculty " << id << " is not currently advising any students." << endl;
      else
      {
        Student s;

        cout << "Faculty " << id << " is currently advising the following students: " << endl;
        for(int i = 0; i < iterable_list.size(); ++i)
        {
          if(s_tree.valid(iterable_list[i]))
          {
            s = s_tree.lookup(iterable_list[i]);
            cout << iterable_list[i] << " " << s << endl;
          }
          else
          {
            cout << "Student " << iterable_list[i] << " does not exist in the database. " << endl;
          }
        }
      }
    }
    else
    {
      cout << "This faculty does not exist in the database. " << endl;
    }
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
