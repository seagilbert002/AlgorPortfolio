#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <iostream>

namespace std
{
    class Course
    {
        public:
            string courseNumber;
            string courseTitle;
            vector<string> coursePrereqs;

            // default constructor
            Course();

            // checks if empty
            bool isEmpty() const;
            void PrintCoursePrereq();
            void PrintCourse();

    };
}

#endif
