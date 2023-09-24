#include <iostream>

#include "admissions.h"

int main()
{
    StudentDetails &x = *(new StudentDetails); //implementation of dynamic objects
    priorAcademicDetails &y = *(new priorAcademicDetails);
    FinancialAid &z = *(new FinancialAid);
    double *fees = new double(800000); //implementation of dynamic memory
    x.inputDetails();
    if (y.eligibilityByMarks() && y.eligibilityByExtracurriculars())
        std::cout << "You are eligible to apply to KREA university. Your application will be reviewed and the result will be given to you at a later date." << std::endl;
    else
        exit(0); 
    z.checkFinAidEligibility(x);
    std::cout << "Your payable fees is: " << ((100.0 - z.FinAidPercent)/100 * *fees) << std::endl;

    delete fees;
    return 0;
}