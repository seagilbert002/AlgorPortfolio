#include "Course.h"

using namespace std;

Course::Course(){}

bool std::Course::isEmpty() const 
{
    return this->courseNumber.empty() && courseTitle.empty() && coursePrereqs.empty();
}

void Course::PrintCoursePrereq() 
{
    if (this->isEmpty()) 
    {
        cout << "Error: Course not found!";
    }
    else
    {
        cout << this->courseNumber << ", " << this->courseTitle << endl;

        // checks for prereqs
        if (!this->coursePrereqs.empty()) 
        {
            cout << "Prerequisites: " << this->coursePrereqs.at(0);

            if (this->coursePrereqs.size() > 1)
            {
                for (int i = 1; i < this->coursePrereqs.size(); i++)
                {
                    cout << ", " <<  this->coursePrereqs.at(i);
                }
            }
            cout << endl;
        }
    }

}

void Course::PrintCourse()
{
    cout << this->courseNumber << ", " << this->courseTitle << endl;

    return;
}
