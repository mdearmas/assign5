# assign5
CPSC 350, Assignment 5

STUDENT INFORMATION — Makenzie De Armas; ID: 2278709; dearm102@mail.chapman.edu

SOURCE FILES SUBMITTED — Faculty.cpp // Faculty.h // facultyTable.csv // GenBST.h // GenStack.h // main.cpp // Makefile // MasterFacultyTree.cpp // MasterFacultyTree.h // MasterStudentTree.cpp // MasterStudentTree.h // Menu.cpp // Menu.h // Person.h // README.md // Rollback.h // Student.cpp // Student.h // studentTable.csv //

ERRORS — cin.fail(), when used in regards to checking integer input, will allow a decimal input by taking all the numbers prior to the decimal point as the input and then passing the rest to the next cin stream. The default -1 Advisor ID doesn't work if the user decides to use negative integers as valid ID numbers. (Not necessarily an error, but I am aware that my code probably isn't the most efficient regarding memory and execution. This is mainly due to my lack of experience. I'm still learning...and forgetting a lot of things. Apologies.)

RESOURCES — https://stackoverflow.com/questions/34170164/destructor-for-binary-search-tree (For GenBST.h's recursive destructor, as I was struggling to understand how to iteratively destruct the tree.) // https://www.geeksforgeeks.org/csv-file-management-using-c/ (For learning how to use csv files.) // https://en.cppreference.com/w/cpp/language/operators (For overloading comparison and equality operators.) // https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=vs-2019 (For overloading the output operator.) // http://www.cplusplus.com/reference/vector/vector/?kw=vector (For additional help with learning how to parse.) // https://cboard.cprogramming.com/cplusplus-programming/122401-how-do-i-allow-spaces-cin.html (For taking in input with spaces.) //

INSTRUCTIONS FOR RUNNING THE ASSIGNMENT — (1.) make all (2.) ./assignment5.exe (3.) Follow the program's prompts.
