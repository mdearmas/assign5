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
  store();
  int i = s_tree.addStudent();
  cout << endl;
  int adv = s_tree.lookupPointer(i)->getAdvisor();
  if(f_tree.valid(adv))
    f_tree.lookupPointer(adv)->addAdvisee(i);
  else
    cout << "WARNING: This student's advisor is not in the database. " << endl;
}

void Menu::addFaculty()
{
  store();
  int i = f_tree.addFaculty();
  cout << endl;

  string advisee_list = f_tree.lookupPointer(i)->getAdvisees();

  vector<int> iterable_list;
  stringstream temp(advisee_list);

  bool first = true;
  string student;

  while(getline(temp, student, '/'))
  {
    if(first)
      first = false;
    else
    {
      iterable_list.push_back(stoi(student));
    }
  }

  for(int j = 0; j < iterable_list.size(); ++j)
  {
    if(s_tree.valid(iterable_list[j]))
    {
      s_tree.lookupPointer(iterable_list[j])->reassignAdvisor(i);
    }
    else
    {
      cout << "WARNING: Student " << iterable_list[j] << " is not in the database. " << endl;
    }
  }
}

void Menu::deleteStudent()
{
  int id;
  cout << "Enter the student's id: ";
  cin >> id;
  if(cin.fail() || !s_tree.valid(id))
    cout << "Not a valid ID number." << endl;
  else
  {
    store();
    int advisor_id = s_tree.lookupPointer(id)->getAdvisor();
    removeAdviseeBase(advisor_id, id);
    s_tree.deleteStudent(id);
  }
}

void Menu::deleteFaculty()
{
  int id;
  cout << "Enter the faculty's id: ";
  cin >> id;
  if(cin.fail() || !f_tree.valid(id))
    cout << "Not a valid ID number." << endl;
  else
  {
    store();

    string advisee_list = f_tree.lookupPointer(id)->getAdvisees();
    f_tree.deleteFaculty(id);

    vector<int> iterable_list;
    stringstream temp(advisee_list);

    bool first = true;
    string student;

    while(getline(temp, student, '/'))
    {
      if(first)
        first = false;
      else
      {
        iterable_list.push_back(stoi(student));
      }
    }

    for(int i = 0; i < iterable_list.size(); ++i)
    {
      if(s_tree.valid(iterable_list[i]))
      {
        if(f_tree.empty())
        {
          cout << "The faculty tree is empty. Defaulting to an advisor id of -1." << endl;
          reassignAdvisorBase(iterable_list[i], f_tree.getNextID());
        }
        else
        {
          reassignAdvisorBase(iterable_list[i], f_tree.getRootID());
        }
      }
    }
  }
}

void Menu::reassignAdvisor()
{
  int id1, id2;
  cout << "Enter the student's id: ";
  cin >> id1;
  if(cin.fail() || !s_tree.valid(id1))
    cout << "Not a valid ID number." << endl;
  else
  {
    cin.ignore();
    cout << "Enter the new advisor's id: ";
    cin >> id2;
    if(cin.fail())
      cout << "Not a valid ID number." << endl;
    else
    {
      store();
      removeAdviseeBase(s_tree.lookupPointer(id1)->getAdvisor(), id1);
      reassignAdvisorBase(id1, id2);
    }
  }
}

void Menu::removeAdvisee()
{
  int id1, id2;
  cout << "Enter the faculty's id: ";
  cin >> id1;
  if(cin.fail() || !f_tree.valid(id1))
    cout << "Not a valid ID number." << endl;
  else
  {
    cin.ignore();
    cout << "Enter the student's id: ";
    cin >> id2;
    if(cin.fail())
      cout << "Not a valid ID number." << endl;
    else
    {
      store();
      removeAdviseeBase(id1, id2);
      if(id1 != f_tree.getRootID())
        reassignAdvisorBase(id2, f_tree.getRootID());
      else
      {
        if(f_tree.empty())
          cout << "The faculty tree is empty. Defaulting to an advisor id of -1." << endl;
        reassignAdvisorBase(id2, f_tree.getNextID());
      }
    }
  }
}

void Menu::reassignAdvisorBase(int student_id, int faculty_id)
{
  if(s_tree.valid(student_id))
  {
    s_tree.lookupPointer(student_id)->reassignAdvisor(faculty_id);
    if(f_tree.valid(faculty_id))
      f_tree.lookupPointer(faculty_id)->addAdvisee(student_id);
  }
}

void Menu::removeAdviseeBase(int faculty_id, int student_id)
{
  if(f_tree.valid(faculty_id))
  {
    f_tree.lookupPointer(faculty_id)->removeAdvisee(student_id);
  }
}

void Menu::store()
{
  s_tree.store();
  f_tree.store();
}

void Menu::undo()
{
  s_tree.undo();
  f_tree.undo();
}
