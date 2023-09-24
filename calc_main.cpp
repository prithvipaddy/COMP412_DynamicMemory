#include <iostream>
#include <cassert>

#include "calc.h"

int main() 
{
    Input &i = *(new Input);
    i.input();
    bool flag = true;
    std::string opt;
    while(flag == true)
    {
        assert(flag==true);
        try{
        std::cout << "Would you like to continue calculating? (Y/N): " << std::endl;
        std::cin >> opt;
        if(opt == "Y" || opt == "y")
        {
            flag = true;
            i.input();
        }
        else if(opt == "N" || opt == "n")
        {
            flag = false;
            std::cout << "Exiting..." << std::endl;
        }
        else
            throw opt;
    }
    catch(std::string opt)
    {
        std::cout << "The input recieved doesn't match any of the options. " << std::endl;
    }}

    return 0;
}