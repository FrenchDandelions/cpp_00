#include "PhoneBook.hpp"
#include <cctype>

void PhoneBook::EnterName()
{
    std::string str;
    std::cout << "Enter Name :" << std::endl;
    while(1)
    {
        std::cin >> str;
        if(!str[0])
            continue;
        Book[NbContacts].SetName(str);
        break;
    }
}

void PhoneBook::EnterLastName()
{
    std::string str;
    std::cout << "Enter Last Name :" << std::endl;
    while(1)
    {
        std::cin >> str;
        if(!str[0])
            continue;
        Book[NbContacts].SetLastName(str);
        break;
    }
}

void PhoneBook::EnterNickName()
{
    std::string str;
    std::cout << "Enter Nickname :" << std::endl;
    while(1)
    {
        std::cin >> str;
        if(!str[0])
            continue;
        Book[NbContacts].SetNickName(str);
        break;
    }
}

bool IsOnlyDigits(const std::string &str){
    for(int i = 0; str[i]; i++)
    {
        if(std::isdigit(str[i]) == 0)
        {
            std::cout << "Phone Number must contain digits only" << std::endl;
            return(false);
        }
    }
    return(true);
}

void PhoneBook::EnterPhoneNumber()
{
    std::string str;
    std::cout << "Enter Phonenumber :" << std::endl;
    while(1)
    {
        std::cin >> str;
        if(!str[0] || IsOnlyDigits(str) == false)
            continue;
        Book[NbContacts].SetPhoneNumber(str);
        break;
    }
}

void PhoneBook::EnterDarkestSecret()
{
    std::string str;
    std::cout << "Enter DarkestSecret :" << std::endl;
    while(1)
    {
        std::cin >> str;
        if(!str[0])
            continue;
        Book[NbContacts].SetDarkestSecret(str);
        break;
    }
}

void PhoneBook::SetContact(){

    const Contact Contact;
    
    AddNbContacts();
    Book[NbContacts] = Contact;
    EnterName();
    EnterLastName();
    EnterNickName();
    EnterPhoneNumber();
    EnterDarkestSecret();
}
