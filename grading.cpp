#include <fstream>
#include <iostream>
#include <vector>

#include "grading.h"

void Student::inputStudentDetails()
{
    std::cout << "Enter the student's name and then their student ID number: " << std::endl;
    std::cin >> name;
    std::cin >> *studentID;
    std::cout << "Enter the number of subjects the student has taken: " << std::endl;
    std::cin >> numOfSubjects;
}
void Student::inputGrades() // inputs the grades for each subject
{
    for (int i=0; i < numOfSubjects; i++)
    {
        std::string newSubject;
        float newGrade;
        std::cout << "Enter the subject name and then the grade received in it: " << std::endl;
        std::cin >> newSubject;
        std::cin >> newGrade;
        grade.push_back(newGrade);
        subject.push_back(newSubject);
    }
}
void Student::getGradeReport() // shows what the grade report will look like
{
    std::cout << "Student Name: " << name << std::endl;
    std::cout << "Student ID: " << *studentID << "\n\n";
    for(int i=0; i < numOfSubjects; i++)
    {
        std::cout << subject.at(i) << ": " << grade.at(i) << std::endl;
    }
    std::cout << "\nAverage grade: " << avgGrade() << std::endl;

}
void Student::createReportFile() //creates a file in which the grade report will be stored
{
    std::string filename = name + "_GradeReport.txt"; 
    // names the report according to the students name
    
    std::ofstream fout(filename);
    fout << "Student: " << name << "\n";
    fout << "Student ID: " << *studentID << "\n \n";

    for (int i=0; i<numOfSubjects; i++)
    {
        fout << subject.at(i) << ": " << grade.at(i) << "\n";
    }

    fout << "\nAverage grade: " << avgGrade() << "\n";
    fout.close();
}
float Student::avgGrade()
{
    float avg = 0;
    for(int i=0;i < numOfSubjects;i++)
    {
        avg = avg + grade.at(i);
    }
    avg = avg / numOfSubjects;
    return avg;
}

bool Student::confirmReport()
{
    std::string confirmation;
    std::cout << "This is the report that will be generated: " << "\n\n" ;
    getGradeReport();
    std::cout << "Enter y to confirm, or anything else to re-enter details: " << std::endl;
    std::cin >> confirmation;
    if (confirmation == "y" || confirmation == "Y")
    return true;
    else
    return false;  
}