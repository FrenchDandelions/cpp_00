#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook Book1;

    while(1)
    {
        std::string str;
        std::cout << "Enter Command > " << std::flush;
        std::cin >> str;
        if(str == "ADD")
        {
            std::cout << "Adding User" << std::endl;
            Book1.SetContact();
            std::cout << "Added User" << std::endl;
        }
        else if (str == "SEARCH")
        {
            std::cout << "Searching User..." << std::endl;
            Book1.PrintContacts();
            std::cout << "Users found" << std::endl;
        }
        else if(str == "EXIT" || !str[0])
        {
            if(!str[0])
                std::cout << std::endl;
            std::cout << "Exiting..." << std::endl;
            break;
        }
        else
            std::cout << "Command not found" << std::endl;
    }
}