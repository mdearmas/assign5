#include "MasterFacultyTree.h"

MasterFacultyTree::MasterFacultyTree()
{
  tree = new BST<Faculty>();
}

MasterFacultyTree::~MasterFacultyTree()
{
  delete tree;
}

void MasterFacultyTree::save()
{
  ofstream fout;
  fout.open("masterFaculty.csv", ios::out);
  serialize(tree->root, fout);
}

void MasterFacultyTree::load()
{
  ifstream fin;
  fin.open("masterFaculty.csv", ios::in);
  if(fin.is_open())
  {
    deserialize(fin);
  }
}

void MasterFacultyTree::serialize(TreeNode<Faculty> *s, ofstream& f)
{
  if(s == NULL)
  {
    f << "#" << endl;
    return;
  }
  else
  {
    Faculty placeholder = s->data;
    /*int* array = placeholder.adviseeArray();
    string advisee_string = "";
    for(int k = 0; k < placeholder.numberOfAdvisees(); ++k)
    {
      advisee_string = advisee_string + to_string(array[k]) + '/';
    }*/

    f << placeholder.getID() << ',' << placeholder.getName() << ',' << placeholder.getLevel() << ',' << placeholder.getDepartment() << endl;
    serialize(s->left, f);
    serialize(s->right, f);
  }
}

void MasterFacultyTree::deserialize(ifstream& f)
{
  int i;
  string n;
  string l;
  string d;

  vector<string> row, advisees;
  string line, word, number, temp;

  while(getline(f, line))
  {
    if(line != "#")
    {
      row.clear();

      stringstream str(line);

      while(getline(str, word, ','))
      {
        row.push_back(word);
      }

      i = stoi(row[0]);
      n = row[1];
      l = row[2];
      d = row[3];

      /*stringstream array(row[4]);
      while(getline(array, number, '/'))
      {
        advisees.push_back(number);
      }*/

      Faculty new_faculty(i, n, l, d);
      /*for(int k = 0; k < advisees.size(); ++k)
      {
        new_faculty.addAdvisee(stoi(advisees[k]));
      }*/
      tree->insertBST(i, new_faculty);
    }
  }
}

void MasterFacultyTree::addFaculty()
{
  int i;
  string n;
  string l;
  string d;
  int a;
  int s;

  cout << "Enter the faculty's ID: ";
  cin >> i;
  cin.ignore();

  cout << "Enter the faculty's name: ";
  getline(cin, n);

  cout << "Enter the faculty's position: ";
  getline(cin, l);

  cout << "Enter the faculty's department: ";
  getline(cin, d);

  Faculty new_faculty(i, n, l, d);

  /*cout << "How many advisees does this faculty member have? ";
  cin >> a;
  cin.ignore();

  for(int k = 0; k < a; ++k)
  {
    cout << "Enter the advisee's student ID: ";
    cin >> s;
    cin.ignore();
    new_faculty.addAdvisee(s);
  }*/

  //new_faculty.printAdvisees();

  tree->insertBST(i, new_faculty);
}
