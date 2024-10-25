//=================================================================================== 
// Name: AdvisingAssistance.cpp
// Author: Chrysanthemum Gribble Gilbert
// Version: 1.0
// Copyright: N/A
// Description: An Advising Assistant Prgram to check for possible prerequisites
// ==================================================================================

#include <cctype>
#include <ios>
#include <iostream>
#include <limits>
#include <vector>

#include "CSVparser.hpp"
#include "CourseBinarySearchTree.h"
#include "Course.h"

using namespace std;

// Making some global definitions visible to all methods

/**
 * A method to display the menu
 */
void diplayMenu() {
    cout << "1: Load Data Structure." << endl;
    cout << "2: Print Course List." << endl;
    cout << "3: Print Course." << endl;
    cout << "9: Exit" << endl;
    cout << "\nWhat would you like to do?" << endl;
}

void loadCourses(string csvPath, CourseBinarySearchTree* bst) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);


    try
    {
        // loop to read the rows of the CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++)
        {
            // Creates the data structure to hold the collection of courses
            Course course;
            course.courseNumber = file[i][0];
            course.courseTitle = file[i][1];
            // Now we need to load prerequisites if they exist
            for (unsigned int j = 2; j < file[i].size(); j++)
            {
                if (!file[i][j].empty())
                {
                    course.coursePrereqs.push_back(file[i][j]);
                }
            }
            bst->Insert(course);
        }
    }
    catch (csv::Error &e)
    {
        std::cerr << e.what() << endl;
    }
}
void findAndPrintCourse(string courseNumber, CourseBinarySearchTree* searchTree) 
{
    for (unsigned int i = 0; i < courseNumber.size(); i++)
    {
        courseNumber[i] = (char)toupper(courseNumber[i]);
    }
    Course course = searchTree->Search(courseNumber);
    
    if (course.isEmpty())
    {
        cout << "Error: Course Not Found!!!" << endl;
    }
    else 
    {
        course.PrintCoursePrereq();
    }
}
    
void whichCourse(CourseBinarySearchTree* searchTree)
{
    cout << "Which course do you want to know about?" << endl;

    string input;

    cin >> input;

    findAndPrintCourse(input, searchTree);
}

/**
 * The one...
 * the only... 
 * MAIN
 * METHOD!!!
 * main()
 */
int main() {

    CourseBinarySearchTree courseList;
    int choice = 0;
    
    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {
        diplayMenu();

        // Input validation
        while (!(cin >> choice))
        {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                loadCourses("./rsc/ABCU_Advising_Program_Input.csv", &courseList);
                break;
            case 2:
                courseList.InOrder();
                break;
            case 3:
                whichCourse(&courseList);
                break;
            case 9:
                cout << endl << "Thank you for using the course planner!" << endl;
                return 0;
            default:
                cout << endl << "No Option Associated with " << choice << "." << endl;
        }
    }
    
    return 0;
}
