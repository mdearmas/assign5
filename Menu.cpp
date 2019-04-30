/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 5: Building a Database with Binary Search Trees
Purpose: This file, Menu.cpp, contains the out-of-class member functions for Menu.
*/

#include "Menu.h"

Menu::Menu() //sontructor
{
  MasterFacultyTree f_tree;
  MasterStudentTree s_tree;
}

void Menu::startUp() //deserializes both trees
{
  f_tree.load();
  s_tree.load();
}

void Menu::shutDown() //serializes both trees
{
  f_tree.save();
  s_tree.save();
}

void Menu::printMenu() //prints all available commands to the user
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

void Menu::displayAllStudents() //displays all the students in the tree
{
  s_tree.print();
}

void Menu::displayAllFaculty() //displays all the faculty in the tree
{
  f_tree.print();
}

void Menu::findStudent() //finds a student
{
  int id;
  cout << "Enter the student's id: ";
  cin >> id;
  if(cin.fail()) //if the id isn't a valid input (may not account for decimals)
    cout << "Not a valid ID number." << endl;
  else
  {
    if(s_tree.valid(id)) //ensures that the student does exist in the tree
    {
      Student s = s_tree.lookup(id); //finds and prints a copy of the student's info the the console
      cout << id << " " << s << endl;
    }
    else
    {
      cout << "Student does not exist." << endl;
    }
  }
  cin.clear(); //clears the input stream
}

void Menu::findFaculty() //finds a faculty member
{
  int id;
  cout << "Enter the faculty's id: ";
  cin >> id;
  if(cin.fail()) //if the id isn't a valid input (may not account for decimals)
    cout << "Not a valid ID number." << endl;
  else
  {
    if(f_tree.valid(id)) //ensures the id does exist in the faculty tree
    {
      Faculty f = f_tree.lookup(id); //prints a copy of the faculty at the id's location to the console
      cout << id << " " << f << endl;
    }
    else
    {
      cout << "Faculty does not exist." << endl;
    }
  }
  cin.clear(); //clears input stream
}

void Menu::findAdvisor() //finds the info for a student's advisor
{
  int id;
  cout << "Enter the student's id: ";
  cin >> id;
  if(cin.fail()) //if the id isn't a valid input (may not account for decimals)
    cout << "Not a valid ID number." << endl;
  else
  {
    if(s_tree.valid(id)) //ensures the student exists in the tree
    {
      Student s = s_tree.lookup(id);
      int faculty_target = s.getAdvisor(); //retrieves the student's advisor's id
      if(f_tree.valid(faculty_target)) //ensures the student's advisor actually exists
      {
        Faculty f = f_tree.lookup(faculty_target); //prints a copy of the data to the console
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

void Menu::findAdvisees() //prints a list of a faculty's advisors
{
  int id;
  cout << "Enter the faculty's id: ";
  cin >> id;
  if(cin.fail()) //if the id isn't a valid input (may not account for decimals)
    cout << "Not a valid ID number." << endl;
  else
  {
    if(f_tree.valid(id)) //ensures the faculty actually exists in the database
    {
      Faculty f = f_tree.lookup(id);
      string temp_list = f.getAdvisees();

      //for parsing through the advisee list
      string student;
      vector<int> iterable_list;

      stringstream temp(temp_list); //now we can treat the string like a file

      bool first = true; //avoids out-of-range error with stoi

      while(getline(temp, student, '/'))
      {
        if(first)
          first = false;
        else
        {
          iterable_list.push_back(stoi(student));
        }
      }

      if(iterable_list.size() == 0) //if there were no advisees
        cout << "Faculty " << id << " is not currently advising any students." << endl;
      else
      {
        Student s;

        cout << "Faculty " << id << " is currently advising the following students: " << endl;
        for(int i = 0; i < iterable_list.size(); ++i)
        {
          if(s_tree.valid(iterable_list[i])) //ensures the student's actually exist in the database
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

void Menu::addStudent() //adds a student to the database
{
  store(); //stores the trees prior to changes
  int i = s_tree.addStudent(); //saves the id of the recently added student
  cout << endl;
  int adv = s_tree.lookupPointer(i)->getAdvisor(); //saves the id of the newly added student's advisor
  if(f_tree.valid(adv)) //if the id of the advisor is a valid entry in the faculty database, add the student to the faculty's list of advisors
    f_tree.lookupPointer(adv)->addAdvisee(i);
  else //else, warn the user that there has been a mistake
    cout << "WARNING: This student's advisor is not in the database. " << endl;
}

void Menu::addFaculty() //adds a faculty to the database
{
  store(); //stores the trees prior to changes
  int i = f_tree.addFaculty(); //saves the id of the recently added faculty
  cout << endl;

  string advisee_list = f_tree.lookupPointer(i)->getAdvisees(); //gets the list of student advisees

  //for iterating through the list
  vector<int> iterable_list;
  string student;

  bool first = true; //avoids an out-of-range error

  stringstream temp(advisee_list);

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
    if(s_tree.valid(iterable_list[j])) //if the student id actually exists in the database, make sure the advisor matches
      s_tree.lookupPointer(iterable_list[j])->reassignAdvisor(i);
    else //else, warn the user that there has been a mistake
      cout << "WARNING: Student " << iterable_list[j] << " is not in the database. " << endl;
  }
}

void Menu::deleteStudent() //removes a student
{
  int id;
  cout << "Enter the student's id: ";
  cin >> id;
  if(cin.fail() || !s_tree.valid(id)) //if the id isn't a valid input (may not account for decimals) OR if the input id doesn't correspond to an existing student
    cout << "Not a valid ID number." << endl;
  else
  {
    store(); //stores trees before changes
    int advisor_id = s_tree.lookupPointer(id)->getAdvisor(); //saves the id of the old advisor
    removeAdviseeBase(advisor_id, id); //removes the student from their advisor's list
    s_tree.deleteStudent(id); //delete the student node
  }
}

void Menu::deleteFaculty() //removes a faculty
{
  int id;
  cout << "Enter the faculty's id: ";
  cin >> id;
  if(cin.fail() || !f_tree.valid(id)) //if the id isn't a valid input (may not account for decimals) OR if the input id doesn't correspond to an existing faculty
    cout << "Not a valid ID number." << endl;
  else
  {
    store(); //store the trees before the changes

    string advisee_list = f_tree.lookupPointer(id)->getAdvisees(); //saves the list of advisees
    f_tree.deleteFaculty(id); //deletes the faculty node

    //for iterating through the advisee list
    vector<int> iterable_list;
    string student;

    bool first = true; //avoids an out-of-range error

    stringstream temp(advisee_list);

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
        if(f_tree.empty()) //if no faculty are left, default to a -1 id
        {
          cout << "The faculty tree is empty. Defaulting to an advisor id of -1." << endl;
          reassignAdvisorBase(iterable_list[i], f_tree.getNextID());
        }
        else //else, reassign the students to the root faculty member
        {
          reassignAdvisorBase(iterable_list[i], f_tree.getRootID());
        }
      }
    }
  }
}

void Menu::reassignAdvisor() //reassigns a student's advisor
{
  int id1, id2;
  cout << "Enter the student's id: ";
  cin >> id1;
  if(cin.fail() || !s_tree.valid(id1))  //if the id isn't a valid input (may not account for decimals) OR if the input id doesn't correspond to an existing student
    cout << "Not a valid ID number." << endl;
  else
  {
    cin.ignore(); //strips input stream
    cout << "Enter the new advisor's id: ";
    cin >> id2;
    if(cin.fail()) //if the id isn't a valid input (may not account for decimals)
      cout << "Not a valid ID number." << endl;
    else
    {
      store(); //store the trees before changes
      removeAdviseeBase(s_tree.lookupPointer(id1)->getAdvisor(), id1); //removes the student from their old advisor's list
      reassignAdvisorBase(id1, id2); //reassigns the student
    }
  }
}

void Menu::removeAdvisee() //removes a student from a faculty's advisee list
{
  int id1, id2;
  cout << "Enter the faculty's id: ";
  cin >> id1;
  if(cin.fail() || !f_tree.valid(id1)) //if the id isn't a valid input (may not account for decimals) OR if the input id doesn't correspond to an existing faculty
    cout << "Not a valid ID number." << endl;
  else
  {
    cin.ignore();
    cout << "Enter the student's id: ";
    cin >> id2;
    if(cin.fail()) //if the id isn't a valid input (may not account for decimals)
      cout << "Not a valid ID number." << endl;
    else
    {
      store(); //stores the trees before changes are made
      removeAdviseeBase(id1, id2); //removes the student from the advisor's list
      if(id1 != f_tree.getRootID()) //if the advisor isn't already the root, then reassign the student to the root
        reassignAdvisorBase(id2, f_tree.getRootID());
      else //else, find the "next" available id
      {
        if(f_tree.empty()) //if there are no faculty left, the program will default to a -1 id
          cout << "The faculty tree is empty. Defaulting to an advisor id of -1." << endl;
        reassignAdvisorBase(id2, f_tree.getNextID());
      }
    }
  }
}

void Menu::reassignAdvisorBase(int student_id, int faculty_id) //reassigns advisor sans user input
{
  if(s_tree.valid(student_id)) //ensures the student exists
  {
    s_tree.lookupPointer(student_id)->reassignAdvisor(faculty_id); //reassigns the advisor to the student
    if(f_tree.valid(faculty_id)) //ensures the faculty exists
      f_tree.lookupPointer(faculty_id)->addAdvisee(student_id); //adds the student to the new faculty's advisee list
  }
}

void Menu::removeAdviseeBase(int faculty_id, int student_id) //removes advisee sans user input
{
  if(f_tree.valid(faculty_id)) //ensures faculty exists
  {
    f_tree.lookupPointer(faculty_id)->removeAdvisee(student_id); //removes the advisee from the faculty's list
  }
}

void Menu::store() //stores both the student tree and the faculty tree to their respective rollback stacks
{
  s_tree.store();
  f_tree.store();
}

void Menu::undo() //undoes the last operations to both the student tree and the faculty tree
{
  s_tree.undo();
  f_tree.undo();
}
