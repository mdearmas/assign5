#include "Student.h"

int main(int argc, char **argv)
{
  Student s(2278209, "Makenzie De Armas", "Junior", 14, "Creative Writing", 3.75);
  Student t(2278209, "Makenzie De Armas", "Junior", 14, "Creative Writing", 3.75);

  if(s == t)
    cout << s;
}
