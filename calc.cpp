#include <iostream>
#include <cmath>
#include <cassert>

#include "calc.h"

void Input::input()
{
    std::cout << "These are the choices for calculation:- " <<
    "\n1. Addition" <<
    "\n2. Subtraction" <<
    "\n3. Multiplication" <<
    "\n4. Division" <<
    "\n5. Percentage" <<
    "\n6. Square root" <<
    "\n7. Square" <<
    "\n8. Power (x^y)" <<
    "\n9. ln" <<
    "\n10. Log" <<
    "\n\nPlease enter the serial number for calculation: "
    << std::endl;
    catchError();
    assert(typeid(in)==typeid(int));
    switch(in)
    {
        case 1:
        {
            std::cout << "Enter numbers to add: " << std::endl;
            twoInput();
            add();
            break;
        }
        case 2:
        {
            std::cout << "Enter numbers to subtract: " << std::endl;
            twoInput();
            subtract();
            break;
        }
        case 3:
        {
            std::cout << "Enter numbers to multiply: " << std::endl;
            twoInput();
            mult();
            break;
        }
        case 4:
        {
            std::cout << "Enter numbers to divide: " << std::endl;
            twoInput(); 
            // I was going to include exception handling for division by 0
            // i.e. not letting the second input be 0, but c++ division already
            // handles that and gives the result as infinity, which is a viable answer.
            div();
            break;
        }
        case 5:
        {
            std::cout << "Enter numbers for percentage: " << std::endl;
            twoInput();
            perc();
            break;
        }
        case 6:
        {
            std::cout << "Enter number for square root: " << std::endl;
            oneInput();
            root();
            break;
        }
        case 7:
        {
            std::cout << "Enter number for square: " << std::endl;
            oneInput();
            square();
            break;
        }
        case 8:
        {
            std::cout << "Enter numbers for power: " << std::endl;
            twoInput();
            power();
            break;
        }
        case 9:
        {
            std::cout << "Enter number for ln: " << std::endl;
            oneInput();
            ln();
            break;
        }
        case 10:
        {
            std::cout << "Enter number for log: " << std::endl;
            oneInput();
            logarithm();
            break;
        }
        default:
        {
            std::cout << "The input recieved doesn't match any of the options" << std::endl;
        }
    }

}

template<class X> void Calculator<X>::add()
{
    std::cout << "The result is: " << (X)(x+y) << std::endl;
}

template<class X> void Calculator<X>::subtract()
{
    std::cout << "The result is: " << (X)(x-y) << std::endl;
}

template<class X> void Calculator<X>::mult()
{
    std::cout << "The result is: " << (X)(x*y) << std::endl;
}

template<class X> void Calculator<X>::div()
{
    std::cout << "The result is: " << (X)(x/y) << std::endl;
}

template<class X> void Calculator<X>::perc()
{
    std::cout << "The result is: " << (X)(x/y * 100) << "%" << std::endl;
}

template<class X> void Calculator<X>::root()
{
    std::cout << "The result is: " << (X)sqrt(x) << std::endl;
}

template<class X> void Calculator<X>::square()
{
    std::cout << "The result is: " << (X)(x*x) << std::endl;
}

template<class X> void Calculator<X>::power()
{
    std::cout << "The result is: " << (X)pow(x,y) << std::endl;
}

template<class X> void Calculator<X>::ln()
{
    std::cout << "The result is: " << (X)log(x) << std::endl;
}

template<class X> void Calculator<X>::logarithm()
{
    std::cout << "The result is: " << (X)log10(x) << std::endl;
}

void Input::oneInput()
{
    while(true){
    try{
        std::cin >> x;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            throw std::runtime_error("Invalid input, please enter a number.\n");
        }
    break;
    }
    catch (const std::exception& e){
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
    }
}

void Input::twoInput()
{
    while(true){
    try{
        std::cin >> x;
        std::cin >> y;

        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            throw std::runtime_error("Invalid input, please enter numbers.\n");
        }
    break;
    }
    catch (const std::exception& e){
        std::cerr << "ERROR: " << e.what() << std::endl;
    }
    }
}

void Input::catchError()
{
    while(true)
    {
        try
        {
            std::cin >> in;
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                throw std::runtime_error("Invalid input, please enter a number.\n");
            }
        break;
        }
        catch(const std::exception& e){
            std::cerr << "ERROR: " << e.what() << std:: endl;
        }
    }
}