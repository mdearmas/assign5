#include "Faculty.h"

void Faculty::addAdvisee(int student_id)
{
  advisees->insertFront(student_id);
}

void Faculty::removeAdvisee(int student_id)
{
  advisees->removeContent(student_id);
}

void Faculty::printAdvisees()
{
  advisees->printList();
}
