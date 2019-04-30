
/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 5: Building a Database with Binary Search Trees
Purpose: This file, main.cpp, runs the actual Registrar Simulation. It allows the user to input a filename and then,
via the Simulation object, reports to the console the events of the simulation before finally outputting the statistics
of the simulation.
*/
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
      m.findStudent();
    }
    else if(answer == "ff")
    {
      m.findFaculty();
    }
    else if(answer == "fa")
    {
      m.findAdvisor();
    }
    else if(answer == "fas")
    {
      m.findAdvisees();
    }
    else if(answer == "as")
    {
      m.addStudent();
    }
    else if(answer == "af")
    {
      m.addFaculty();
    }
    else if(answer == "dls")
    {
      m.deleteStudent();
    }
    else if(answer == "dlf")
    {
      m.deleteFaculty();
    }
    else if(answer == "ra")
    {
      m.reassignAdvisor();
    }
    else if(answer == "ras")
    {
      m.removeAdvisee();
    }
    else if(answer == "aas")
    {
      m.addAdvisee();
    }
    else if(answer == "u")
    {
      m.undo();
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

    cin.clear();
    cin.ignore(1024, '\n');
    cout << endl;
  }
}
