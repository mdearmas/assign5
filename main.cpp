#include "Student.h"
#include "Faculty.h"
#include "GenBST.h"
#include "MasterStudentTree.h"
#include "MasterFacultyTree.h"

int main(int argc, char **argv)
{
  /*MasterStudentTree s;
  s.load();
  s.addStudent();
  s.save();*/

  MasterFacultyTree m;

  m.load();
  m.addFaculty();
  m.save();
}
