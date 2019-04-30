/*
Makenzie De Armas
ID: 2278709
dearm102@mail.chapman.edu
CPSC 350-01
Assignment 5: Building a Database with Binary Search Trees
Purpose: This file, main.cpp, runs the actual menu and allows for user interaction.
Based off the menu object, the main program allows the user to input a command and then runs the respective operation.
The menu continues to run until the user exits.
*/
#include "Menu.h"

int main(int argc, char **argv)
{
  Menu m; //creates a menu object

  m.startUp(); //runs the start up that loads the data tables
  string answer;

  while(true)
  {
    m.printMenu(); //prints the menu options
    cout << "Please enter your command (lowercase only): ";
    cin >> answer;

    if(answer == "ds") //display all students
    {
      m.displayAllStudents();
    }
    else if(answer == "df") //displays all faculty
    {
      m.displayAllFaculty();
    }
    else if(answer == "fs") //finds a student's info based on an input ID
    {
      m.findStudent();
    }
    else if(answer == "ff") //finds a faculty's info based on an input ID
    {
      m.findFaculty();
    }
    else if(answer == "fa") //finds an advisor based on an input student ID
    {
      m.findAdvisor();
    }
    else if(answer == "fas") //finds and lists the advisees of a faculty
    {
      m.findAdvisees();
    }
    else if(answer == "as") //adds a student
    {
      m.addStudent();
    }
    else if(answer == "af") //adds a faculty
    {
      m.addFaculty();
    }
    else if(answer == "dls") //deletes a student
    {
      m.deleteStudent();
    }
    else if(answer == "dlf") //deletes a faculty
    {
      m.deleteFaculty();
    }
    else if(answer == "ra") //reassigns an student's advisor
    {
      m.reassignAdvisor();
    }
    else if(answer == "ras") //removes an advisee from a faculty's list
    {
      m.removeAdvisee();
    }
    else if(answer == "u") //undos the previous action that changed the trees
    {
      m.undo();
    }
    else if(answer == "e") //exits the menu
    {
      m.shutDown(); //saves the trees
      cout << "Saving trees and exiting." << endl;
      break;
    }
    else //if the command was not one listed
    {
      cout << "Not a valid command." << endl;
    }

    //clears the input stream
    cin.clear();
    cin.ignore(1024, '\n');
    cout << endl;
  }
}
