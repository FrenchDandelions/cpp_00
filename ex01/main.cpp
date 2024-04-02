#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook Book1;
    int exit = 0;

    while(1)
    {
        std::string str;
        std::cout << "Enter Command > " << std::flush;
        if (!getline(std::cin, str) || std::cin.eof()) {
            std::cout << std::endl << "Exiting..." << std::endl;
            break;
        }
        if(str == "ADD")
        {
            Book1.SetContact(exit);
            if(exit == 1|| std::cin.eof())
            {
                std::cout << "Exiting..." << std::endl;
                break;
            }
        }
        else if (str == "SEARCH")
        {
            std::cout << "Searching User..." << std::endl;
            Book1.PrintContacts(exit);
            if(exit == 1)
            {
                std::cout << std::endl << "Exiting..." << std::endl;
                break;
            }
            std::cout << "Users found" << std::endl;
        }
        else if(str == "EXIT")
        {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        else if(str.empty())
            continue;
        else
            std::cout << "Command not found" << std::endl;
    }
}