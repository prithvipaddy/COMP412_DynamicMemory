#ifndef PRITHVI_SCIENTIFICCALC_H_
#define PRITHVI_SCIENTIFICCALC_H_

template <class X>
class Calculator
{
public:
    X x,y;
    void add();
    void subtract();
    void mult();
    void div();
    void perc();
    void root();
    void square();
    void power();
    void ln();
    void logarithm();
};

class Input : public Calculator<double>
{
public:
    int in;
    void input();
    void twoInput();
    void oneInput();
    void catchError();
};

#endif