#include "Menu.h"

int main(int argc, char **argv)
{
  Menu m;

  m.startUp();
  string answer;

  while(true)
  {
    m.printMenu();
    cout << "Please enter your command (lowercase only): ";
    cin >> answer;

    if(answer == "ds")
    {
      m.displayAllStudents();
    }
    else if(answer == "df")
    {
      m.displayAllFaculty();
    }
    else if(answer == "fs")
    {
      //find student
    }
    else if(answer == "ff")
    {
      //find faculty
    }
    else if(answer == "fa")
    {
      //find advisor
    }
    else if(answer == "fas")
    {
      //find advisees
    }
    else if(answer == "as")
    {
      //add student
    }
    else if(answer == "af")
    {
      //add faculty
    }
    else if(answer == "dls")
    {
      //delete student
    }
    else if(answer == "dlf")
    {
      //delete faculty
    }
    else if(answer == "ra")
    {
      //reassign advisor
    }
    else if(answer == "ras")
    {
      //remove advisee
    }
    else if(answer == "u")
    {
      //rollback
    }
    else if(answer == "e")
    {
      m.shutDown();
      cout << "Saving trees and exiting." << endl;
      break;
    }
    else
    {
      cout << "Not a valid command." << endl;
    }
  }
}
