#include "Faculty.h"

void Faculty::addAdvisee(int student_id)
{
  advisee_list = advisee_list + to_string(student_id) + '/';
}

void Faculty::removeAdvisee(int student_id)
{
  vector<int> advisee_vector;
  string number;
  string placeholder = "";
  stringstream s(advisee_list);

  while(getline(s, number, '/')) //converts the string advisee_list into an iterable vector of ints
  {
    advisee_vector.push_back(stoi(number));
  }

  for(int i = 0; i < advisee_vector.size(); ++i)
  {
    if(advisee_vector[i] != student_id)
    {
      placeholder = placeholder + to_string(advisee_vector[i]) + '/';
    }
  }

  advisee_list = placeholder;
}

void Faculty::printAdvisees()
{
  cout << advisee_list << endl;
}
