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

    f << placeholder.getID() << ',' << placeholder.getName() << ',' << placeholder.getLevel() << ',' << placeholder.getDepartment() << ',' << placeholder.getAdvisees() << endl;
    serialize(s->left, f);
    serialize(s->right, f);
  }
}

void MasterFacultyTree::deserialize(ifstream& f)
{
  int i;
  string n, l, d, a;

  vector<string> row;
  string line, word;

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
      a = row[4];

      Faculty new_faculty(i, n, l, d, a);

      tree->insertBST(i, new_faculty);
    }
  }
}

void MasterFacultyTree::addFaculty()
{
  int i, a, s;
  string n, l, d;

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

  cout << "How many advisees does this faculty member have? ";
  cin >> a;
  cin.ignore();

  for(int k = 0; k < a; ++k)
  {
    cout << "Enter the advisee's student ID: ";
    cin >> s;
    cin.ignore();
    new_faculty.addAdvisee(s);
  }

  tree->insertBST(i, new_faculty);
}
