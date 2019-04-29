#include "MasterStudentTree.h"

MasterStudentTree::MasterStudentTree()
{
  tree = new BST<Student>();
}

MasterStudentTree::~MasterStudentTree()
{
  delete tree;
}

void MasterStudentTree::save()
{
  ofstream fout;
  fout.open("masterStudent.csv", ios::out);
  serialize(tree->root, fout);
}

void MasterStudentTree::load()
{
  ifstream fin;
  fin.open("masterStudent.csv", ios::in);
  if(fin.is_open())
  {
    deserialize(fin);
  }
}

void MasterStudentTree::serialize(TreeNode<Student> *s, ofstream& f)
{
  if(s == NULL)
  {
    f << "#" << endl;
    return;
  }
  else
  {
    Student placeholder = s->data;
    f << placeholder.getID() << ',' << placeholder.getName() << ',' << placeholder.getLevel() << ',' << placeholder.getMajor() << ',' << placeholder.getGPA() << ',' << placeholder.getAdvisor() << endl;
    serialize(s->left, f);
    serialize(s->right, f);
  }
}

void MasterStudentTree::deserialize(ifstream& f)
{
  int i, a;
  string n, l, m;
  double g;

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
      m = row[3];
      g = stod(row[4]);
      a = stoi(row[5]);

      Student new_student(i, n, l, a, m, g);
      tree->insertBST(i, new_student);
    }
  }
}

void MasterStudentTree::addStudent()
{
  int i, a;
  string n, l, m;
  double g;

  try
  {
    cout << "Enter the student's ID: ";
    cin >> i;
    if(cin.fail())
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
    if(cin.fail())
    {
      throw BadInputException("Not a valid GPA.");
    }
    cin.ignore();

    cout << "Enter the student's advisor: ";
    cin >> a;
    if(cin.fail())
    {
      throw BadInputException("Not a valid GPA.");
    }
    cin.ignore();

    Student new_student(i, n, l, a, m, g);
    tree->insertBST(i, new_student);
    cout << "Student added successfully. Press [ENTER] to continue.";
  }
  catch(BadInputException& e)
  {
    cout << e.getErrorMessage() << endl;
  }
}

void MasterStudentTree::print()
{
  tree->printTree();
}

Student MasterStudentTree::lookup(int id)
{
  if(tree->contains(id))
  {
    Student s = tree->find(id);
    return s;
  }
}

Student* MasterStudentTree::lookupPointer(int id)
{
  if(tree->contains(id))
  {
    return (tree->returnPointer(id));
  }
}
