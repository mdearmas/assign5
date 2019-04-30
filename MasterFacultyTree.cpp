/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 5: Building a Database with Binary Search Trees
Purpose: This file, MasterFacultyTree.cpp, contains the out-of-class member functions for MasterFacultyTree.
*/

#include "MasterFacultyTree.h"

MasterFacultyTree::MasterFacultyTree() //constructor
{
  tree = new BST<Faculty>();
  stack = new Rollback<Faculty>();
}

MasterFacultyTree::~MasterFacultyTree() //destructor
{
  delete tree;
  delete stack;
}

void MasterFacultyTree::save() //serializes from the root
{
  ofstream fout;
  fout.open("facultyTable.csv", ios::out); //uses comma-separated value file type for ease
  serialize(tree->root, fout);
}

void MasterFacultyTree::load() //deserializes from the root
{
  ifstream fin;
  fin.open("facultyTable.csv", ios::in); //uses comma-separated value file type for ease
  if(fin.is_open()) //checks if the file was opened correctly
  {
    deserialize(fin);
  }
}

void MasterFacultyTree::serialize(TreeNode<Faculty> *s, ofstream& f) //recursive serialization
{
  if(s == NULL) //if the root is null, print marker '#'
  {
    f << "#" << endl;
    return;
  }
  else
  {
    Faculty placeholder = s->data; //saves a copy of the faculty data for easy access

    f << placeholder.getID() << ',' << placeholder.getName() << ',' << placeholder.getLevel() << ',' << placeholder.getDepartment() << ',' << placeholder.getAdvisees() << endl; //prints the faculty to the file separated by commas
    serialize(s->left, f); //goes to the left node
    serialize(s->right, f); //goes to the right node
  }
}

void MasterFacultyTree::deserialize(ifstream& f) //deserialization
{
  //variables needed to reconstruct new nodes
  int i;
  string n, l, d, a;

  //for parsing through the csv file
  vector<string> row;
  string line, word;

  while(getline(f, line)) //while there are lines in the file
  {
    if(line != "#") //aka: if it isn't a NULL node
    {
      row.clear(); //clear the existing vector

      stringstream str(line); //now we can iterate through the line like a file

      while(getline(str, word, ',')) //separate the line by comma
      {
        row.push_back(word);
      }

      //assign the elements of the vector to their respective variables
      i = stoi(row[0]);
      n = row[1];
      l = row[2];
      d = row[3];
      a = row[4];

      Faculty new_faculty(i, n, l, d, a); //construct a new faculty

      tree->insertBST(i, new_faculty); //add to the tree
    }
  }
}

int MasterFacultyTree::addFaculty() //add a new faculty to the tree based on user input
{
  //variables needed for constructing a new faculty
  int i, a, s;
  string n, l, d;

  try
  {
    cout << "Enter the faculty's ID: ";
    cin >> i;
    if(cin.fail()) //if input is not an integer (does not account for decimals unfortunately)
    {
      throw BadInputException("Not a valid ID number.");
    }
    cin.ignore();

    cout << "Enter the faculty's name: ";
    getline(cin, n);

    cout << "Enter the faculty's position: ";
    getline(cin, l);

    cout << "Enter the faculty's department: ";
    getline(cin, d);

    Faculty new_faculty(i, n, l, d); //constructs a new Faculty

    cout << "How many advisees does this faculty member have? ";
    cin >> a;
    if(cin.fail()) //if not an integer (again, does not account for decimal error)
    {
      throw BadInputException("Not a valid number of advisees.");
    }
    cin.ignore();

    for(int k = 0; k < a; ++k)
    {
      cout << "Enter the advisee's student ID: ";
      cin >> s;
      if(cin.fail()) //if not an integer (again, does not account for decimal error)
      {
        tree->insertBST(i, new_faculty); //adds whatever exists already to the tree, then exits via throwing an exception
        throw BadInputException("Not a valid ID number.");
      }
      cin.ignore();
      new_faculty.addAdvisee(s); //add advisee to list
    }
    tree->insertBST(i, new_faculty); //if you make it out of the loop, then everything was successful and the Faculty can be added no problem
    cout << "Faculty added successfully. Press [ENTER] to continue.";
    return i; //returns the id of the Faculty that was just added, helps with Menu operations
  }
  catch(BadInputException& e)
  {
    cout << e.getErrorMessage() << endl;
  }
}

void MasterFacultyTree::deleteFaculty(int id) //deletes a Faculty
{
  bool success = tree->deleteBST(id);
  if(!success)
    cout << "Was unable to delete the requested faculty. " << endl;
}

void MasterFacultyTree::print() //prints the Faculty members in order of ascending id
{
  tree->printTree();
}

void MasterFacultyTree::store() //stores the most recent version of the tree to the stack
{
  stack->store(tree);
}

void MasterFacultyTree::undo() //undos the latest operation
{
  if(stack->possible()) //ensures that the stack has something to pop
    tree = stack->undo();
  else
    cout << "Nothing left to undo to the faculty database." << endl;
}

Faculty MasterFacultyTree::lookup(int id) //returns a copy of the Faculty member at the passed ID
{
  if(tree->contains(id)) //ensures the tree contains the passed id
  {
    return (tree->find(id));
  }
}

Faculty* MasterFacultyTree::lookupPointer(int id) //returns a pointer to the Faculty member at the passed ID
{
  if(tree->contains(id)) //ensures the tree contains the passed id
  {
    return (tree->returnPointer(id));
  }
}
