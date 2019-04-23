#include "Student.h"
#include "Faculty.h"

int main(int argc, char **argv)
{
  Student s(2278209, "Makenzie De Armas", "Junior", 14, "Creative Writing", 3.75);
  Student t(2278209, "Makenzie De Armas", "Junior", 14, "Creative Writing", 3.75);

  if(s == t)
    cout << s << endl;

  Faculty f(14, "Rene German", "Professor", "Computer Science");
  cout << f << endl;
  f.addAdvisee(2278209);
  f.removeAdvisee(10);
  f.addAdvisee(23431235);
  f.removeAdvisee(2278209);
  f.addAdvisee(1234325);
  f.addAdvisee(98475322);
  f.printAdvisees();
}
