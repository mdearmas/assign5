#include "Faculty.h"

void Faculty::addAdvisee(int student_id)
{
  advisee_list = advisee_list + to_string(student_id) + '/';
}

/*void Faculty::removeAdvisee(int student_id)
{
  advisees.removeContent(student_id);
}

void Faculty::printAdvisees()
{
  advisees.printList();
}

int Faculty::numberOfAdvisees()
{
  advisees.getSize();
}

int* Faculty::adviseeArray()
{
  int* array = advisees.arrayConvert();
  return array;
}*/
