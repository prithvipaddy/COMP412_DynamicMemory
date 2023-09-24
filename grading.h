#ifndef GRADING_H_
#define GRADING_H_

#include <fstream>
#include <iostream>
#include <vector>

class Student 
{
    //storing these variables as private
    std::string *studentID = new std::string;
    std::vector<float> grade; 
    std::vector<std::string> subject;
public:
    std::string name;
    int numOfSubjects;
    void inputStudentDetails();
    void inputGrades(); // inputs the grades for each subject
    void getGradeReport(); // shows what the grade report will look like
    void createReportFile(); //creates a file in which the grade report will be stored
    float avgGrade();
    bool confirmReport(); //confirms with the user whether this is the report they want
};

#endif /*GRADING_H_*/