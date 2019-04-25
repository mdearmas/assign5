#include "Student.h"
#include "Faculty.h"
#include "GenBST.h"
#include "MasterStudentTree.h"
#include "MasterFacultyTree.h"

int main(int argc, char **argv)
{
  Faculty f(12, "Scratticus", "Headmaster", "TTRPGS", "34/56/92/");
  f.addAdvisee(103);
  f.removeAdvisee(56);
  cout << f << endl;
  f.printAdvisees();
}
