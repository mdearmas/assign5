/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 5: Building a Database with Binary Search Trees
Purpose: This file, MasterStudentTree.cpp, contains the out-of-class member functions for MasterStudentTree.
*/

#include "MasterStudentTree.h"

MasterStudentTree::MasterStudentTree() //constructor
{
  tree = new BST<Student>();
  stack = new Rollback<Student>();
}

MasterStudentTree::~MasterStudentTree() //destructor
{
  delete tree;
  delete stack;
}

void MasterStudentTree::save() //serializes from the root
{
  ofstream fout;
  fout.open("studentTable.csv", ios::out); //uses comma-separated value file type for ease
  serialize(tree->root, fout);
}

void MasterStudentTree::load() //deserializes from the root
{
  ifstream fin;
  fin.open("studentTable.csv", ios::in); //uses comma-separated value file type for ease
  if(fin.is_open()) //ensures the file was successfully opened
  {
    deserialize(fin);
  }
}

void MasterStudentTree::serialize(TreeNode<Student> *s, ofstream& f) //recursive serialization
{
  if(s == NULL) //if NULL print a marker to the file
  {
    f << "#" << endl;
    return;
  }
  else
  {
    Student placeholder = s->data; //saves a copy of the faculty data for easy access

    f << placeholder.getID() << ',' << placeholder.getName() << ',' << placeholder.getLevel() << ',' << placeholder.getMajor() << ',' << placeholder.getGPA() << ',' << placeholder.getAdvisor() << endl;
    serialize(s->left, f);
    serialize(s->right, f);
  }
}

void MasterStudentTree::deserialize(ifstream& f) //deserialization
{
  //variables needed to construct the new nodes
  int i, a;
  string n, l, m;
  double g;

  //for parsing through the csv file
  vector<string> row;
  string line, word;

  while(getline(f, line)) //while there are lines in the file
  {
    if(line != "#") //if the node isn't NULL
    {
      row.clear(); //clear the existing vector

      stringstream str(line); //now we can iterate through the line like a file

      while(getline(str, word, ',')) //separate the line out by comma
      {
        row.push_back(word);
      }

      //assign the vector's values to the respective variables
      i = stoi(row[0]);
      n = row[1];
      l = row[2];
      m = row[3];
      g = stod(row[4]);
      a = stoi(row[5]);

      Student new_student(i, n, l, a, m, g); //create a new student
      tree->insertBST(i, new_student); //add to the tree
    }
  }
}

int MasterStudentTree::addStudent() //adds a student to the tree based on user input
{
  //variables needed to construct a new student
  int i, a;
  string n, l, m;
  double g;

  try
  {
    cout << "Enter the student's ID: ";
    cin >> i;
    if(cin.fail()) //if input is not an integer (does not account for decimals unfortunately)
    {
      throw BadInputException("Not a valid ID number.");
    }
    cin.ignore();

    cout << "Enter the student's name: ";
    getline(cin, n);

    cout << "Enter the student's grade level: ";
    getline(cin, l);

    cout << "Enter the student's major: ";
    getline(cin, m);

    cout << "Enter the student's GPA: ";
    cin >> g;
    if(cin.fail()) //if input is not a double
    {
      throw BadInputException("Not a valid GPA.");
    }
    cin.ignore();

    cout << "Enter the student's advisor: ";
    cin >> a;
    if(cin.fail()) //if input is not an integer (does not account for decimals unfortunately)
    {
      throw BadInputException("Not a valid GPA.");
    }
    cin.ignore();

    Student new_student(i, n, l, a, m, g); //creates a new student
    tree->insertBST(i, new_student); //adds them to the tree
    cout << "Student added successfully. Press [ENTER] to continue.";
    return i; //returns the id of the student that was just added, assists with Menu operations
  }
  catch(BadInputException& e)
  {
    cout << e.getErrorMessage() << endl;
  }
}

void MasterStudentTree::deleteStudent(int id) //deletes a Student
{
  bool success = tree->deleteBST(id);
  if(!success)
    cout << "Was unable to delete the requested student. " << endl;
}

void MasterStudentTree::print() //prints the Student members in order of ascending id
{
  tree->printTree();
}

void MasterStudentTree::store() //stores the most recent version of the tree to the stack
{
  stack->store(tree);
}

void MasterStudentTree::undo() //undoes the most recent operation
{
  if(stack->possible()) //ensures that the stack has something to pop
    tree = stack->undo();
  else
    cout << "Nothing left to undo to the student database." << endl;
}

Student MasterStudentTree::lookup(int id) //returns a copy of the Student stored at the passed id
{
  if(tree->contains(id))
  {
    Student s = tree->find(id);
    return s;
  }
}

Student* MasterStudentTree::lookupPointer(int id) //returns a pointer to the Student stored at the passed id
{
  if(tree->contains(id))
  {
    return (tree->returnPointer(id));
  }
}
