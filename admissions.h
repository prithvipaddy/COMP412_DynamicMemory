#ifndef ADMISSIONS_H_
#define ADMISSIONS_H_


class StudentDetails
{
private:
    std::string aadharNum; 
    std::string documents;
protected:
    double annSalary;
    std::string bankNum;
public:
    friend class FinancialAid; 
    std::string majorPreference;
    std::string name;
    std::string DOB;
    char gender;
    std::string emailID;
    std::string phoneNum;
    void inputDetails();
    void validAadhar();
    void validDOB();
    void validPhone();
};

class priorAcademicDetails
{
public:
    float twelfthMarks;
    float tenthMarks;
    int numOfExtracurriculars;
    bool eligibilityByMarks();
    bool eligibilityByExtracurriculars();
};

class FinancialAid
{
private:
    float FinAidPercent;  
public:
    friend int main(); // makes FinAidPercent accesible in the main function.
    void checkFinAidEligibility(StudentDetails& x);
};

#endif