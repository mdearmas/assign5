#include "Student.h"
#include "Faculty.h"
#include "GenBST.h"
#include "MasterStudentTree.h"

int main(int argc, char **argv)
{
  MasterStudentTree m;

  m.load();
  m.addStudent();
  m.save();
}
