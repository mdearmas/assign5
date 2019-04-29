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

  try
  {
    cout << "Enter the faculty's ID: ";
    cin >> i;
    if(cin.fail())
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

    Faculty new_faculty(i, n, l, d);

    cout << "How many advisees does this faculty member have? ";
    cin >> a;
    if(cin.fail())
    {
      throw BadInputException("Not a valid number of advisees.");
    }
    cin.ignore();

    for(int k = 0; k < a; ++k)
    {
      cout << "Enter the advisee's student ID: ";
      cin >> s;
      if(cin.fail())
      {
        tree->insertBST(i, new_faculty);
        throw BadInputException("Not a valid ID number.");
      }
      cin.ignore();
      new_faculty.addAdvisee(s);
    }
    tree->insertBST(i, new_faculty);
    cout << "Faculty added successfully. Press [ENTER] to continue." << endl;
  }
  catch(BadInputException& e)
  {
    cout << e.getErrorMessage() << endl;
  }
}

void MasterFacultyTree::print()
{
  tree->printTree();
}

Faculty MasterFacultyTree::lookup(int id)
{
  if(tree->contains(id))
  {
    Faculty f = tree->find(id);
    return f;
  }
  else
  {
    cout << "Faculty " << id << " does not exist." << endl;
  }
}
