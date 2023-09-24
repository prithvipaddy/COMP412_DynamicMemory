#include <iostream>

#include "grading.h"

int main()
{
    std::cout << "Enter the number of students for whom you want grade reports:" << std::endl;
    int* numOfStudents = NULL;
    numOfStudents = new int;
    if(!numOfStudents)
        std::cout << "Allocation of memory failed" << std::endl;
    
    std::cin >> *numOfStudents;
    Student x[*numOfStudents]; //creates multiple objects based on number of students inputted
    
    for(int i=0; i < *numOfStudents; i++) // loops through each object and creates reports for each student
    {
        x[i].inputStudentDetails();
        x[i].inputGrades();
        if (x[i].confirmReport())
            x[i].createReportFile();
        else
            i--; // reduces the i value so that the details for the student can be inputted again
    }
    std::cout << "All the grade reports have been created for the students and are ready to be opened.";

    delete numOfStudents;
   return 0;
}