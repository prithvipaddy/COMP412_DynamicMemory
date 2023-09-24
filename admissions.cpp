#include <iostream>
#include <regex>

#include "admissions.h"

void StudentDetails::inputDetails()
{
    std::cout << "Enter your name: " << std::endl;
    std::cin >> name;
    validDOB();
    validPhone();
    std::cout << "Enter your gender: " << std::endl;
    std::cin >> gender;
    validAadhar();
    std::cout << "Enter your email ID: " << std::endl;
    std::cin >> emailID;
    std::cout << "Enter what major you would like to choose: " << std::endl;
    std::cin >> majorPreference;
    std::cout << "Enter a google drive link with the  following documents: " << std::endl;
    std::cout <<"1. Birth certificate \n2. Aadhar card \n3.Passport photo \n4.Tenth and twelfth marks card \n" << std::endl;
    std::cin >> documents;
}

bool isNumber(std::string x)
{
    for(int i=0; i< x.length(); i++)
    {
        if(!std::isdigit(x[i]))
        return false;
    }
    return true;
}

void StudentDetails::validPhone()
{
    bool flag = false;
    while(flag==false)
    {
        std::cout << "Enter your phone number: " << std::endl;
        std::cin >> phoneNum;
        if(phoneNum.length()==10 && isNumber(phoneNum))
        flag = true;
        else
        std::cout << "The phone number is invalid, enter again. \n" << std::endl;
    }
}
void StudentDetails::validDOB()
{
    bool flag = false;
    while(flag==false)
    {
        std::cout << "Enter your date of birth (DD-MM-YYYY): " << std::endl;
        std::cin >> DOB;
        std::regex datePattern("\\b\\d{2}[-]\\d{2}[-]\\d{4}\\b");
        if(std::regex_match(DOB,datePattern))
        flag=true;
        else
        std::cout << "The date format is incorrect. Enter again.\n" << std::endl;
    }
}

void StudentDetails::validAadhar()
{
    bool flag = false;
    while (flag == false)
    {
        std::cout << "Enter your Aadhar number: " << std::endl;
        std::cin >> aadharNum;
        if (aadharNum.length()==12 && isNumber(aadharNum)==true)
            flag = true;
        else
        std::cout << "The Aadhar Number is invalid, enter again." << std::endl;
    }
}

bool priorAcademicDetails::eligibilityByMarks()
{
    std::cout << "Enter 10th marks, then 12th marks: " << std::endl;
    std::cin >> tenthMarks;
    std::cin >> twelfthMarks;
    if (twelfthMarks > 90 && tenthMarks > 80)
    return true;
    else
    {
        std::cout << "You are not eligible for admission at KREA due to poor academic scores." << std::endl;
        return false;
    }
}

bool priorAcademicDetails::eligibilityByExtracurriculars()
{
    std::cout << "Enter the number of your extracurriculars: ";
    std::cin >> numOfExtracurriculars;
    if (numOfExtracurriculars > 3)
    {
        std::string extracurriculars[numOfExtracurriculars - 1];
        for(int i=0; i<numOfExtracurriculars; i++)
        {
            std::cout << "Enter your extracurriculars: ";
            std::cin >> extracurriculars[i];
        }
        return true;
    }
    else{
        std::cout << "You are not eligible for admission to KREA due to lack of extracurriculars.";
        return false;
    }
}

void FinancialAid::checkFinAidEligibility(StudentDetails& x)
{
    std::cout << "Enter your bank number: " <<std::endl;
    std::cin >> x.bankNum;
    std::cout << "Enter your annual salary: " << std::endl;
    std::cin >> x.annSalary;
    if (x.annSalary < 1000000)
    {
        std::cout << "You are eligible for financial aid!" <<std::endl;
        if (x.annSalary < 200000)
            FinAidPercent = 100.0;
        else if (x.annSalary < 500000)
            FinAidPercent = 75.0;
        else if (x.annSalary < 800000)
            FinAidPercent = 50.0;
        else
            FinAidPercent = 25.0;
    }
    else
    FinAidPercent = 0.0;
}