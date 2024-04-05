#include "PhoneBook.hpp"
#include <cctype>
#include <string>
#include <sstream>

PhoneBook::PhoneBook() : NbContacts(0) , CurrContact(0)
{
    std::cout << "Creating Phonebook" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Destroying Phonebook" << std::endl;
}

void PhoneBook::EnterName(int &exit)
{
    std::string str;
    std::cout << "Enter Name :" << std::endl;
    while(1)
    {
        if(!getline(std::cin, str)){
            exit = 1;
            break;
        }
        if(str.empty())
            continue;
        Book[CurrContact].SetName(str);
        break;
    }
}

void PhoneBook::EnterLastName(int &exit)
{
    std::string str;
    std::cout << "Enter Last Name :" << std::endl;
    while(1)
    {
        if(!getline(std::cin, str)){
            exit = 1;
            break;
        }
        if(str.empty())
            continue;
        Book[CurrContact].SetLastName(str);
        break;
    }
}

void PhoneBook::EnterNickName(int &exit)
{
    std::string str;
    std::cout << "Enter Nickname :" << std::endl;
    while(1)
    {
        if(!getline(std::cin, str)){
            exit = 1;
            break;
        }
        if(str.empty())
            continue;
        Book[CurrContact].SetNickName(str);
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

bool IsAllDigit(const std::string &str)
{
    for(int i = 0; str[i]; i++)
    {
        if(std::isdigit(str[i]) == 0)
            return(false);
    }
    return(true);
}

void PhoneBook::EnterPhoneNumber(int &exit)
{
    std::string str;
    std::cout << "Enter Phonenumber :" << std::endl;
    while(1)
    {
        if(!getline(std::cin, str)){
            exit = 1;
            break;
        }
        if(str.empty() || IsOnlyDigits(str) == false)
            continue;
        Book[CurrContact].SetPhoneNumber(str);
        break;
    }
}

void PhoneBook::EnterDarkestSecret(int &exit)
{
    std::string str;
    std::cout << "Enter DarkestSecret :" << std::endl;
    while(1)
    {
        if(!getline(std::cin, str)){
            exit = 1;
            break;
        }
        if(str.empty())
            continue;
        Book[CurrContact].SetDarkestSecret(str);
        break;
    }
}

void PhoneBook::SetContact(int &exit){
    EnterName(exit);
    if(exit == 1|| std::cin.eof())
        return;
    EnterLastName(exit);
    if(exit == 1|| std::cin.eof())
        return;
    EnterNickName(exit);
    if(exit == 1|| std::cin.eof())
        return;
    EnterPhoneNumber(exit);
    if(exit == 1|| std::cin.eof())
        return;
    EnterDarkestSecret(exit);
    if(exit == 1|| std::cin.eof())
        return;
    AddNbContacts();
}

void PrintContact(std::string str, int indice){

    if(str.length() <= 10)
    {
        for(int i = 0; i < (10 - (int)str.length()) ; i++)
            std::cout << " " ;
        std::cout << str;
    }
    else
    {
        for(int i = 0; i <= 9; i++)
            std::cout << str[i];
        std::cout << ".";
    }
    if(indice)
        std::cout << "|" << std::endl;
    else
        std::cout << "|";
}

void PrintPrompt(){
    for(int i = 0; i < 45; i++)
        std::cout << "-";
    std::cout << std::endl;
    std::cout << "|"; 
    PrintContact("Index", 0);;
    PrintContact("First Name", 0);;
    PrintContact("Last Name", 0);;
    PrintContact("Nickname", 0);;
    std::cout << std::endl;
    
}

void PhoneBook::PrintContacts(int &exit){

    PrintPrompt();
    for(int i = 0; i < NbContacts; i++)
    {
        if(i == 0)
        {
            for(int i = 0; i < 45; i++)
                std::cout << ".";
            std::cout << std::endl;
        }
        std::string s;
        std::stringstream ss;
        ss << i;
        s = ss.str();
        std::cout << "|"; 
        PrintContact(s, 0);
        s = Book[i].GetName();
        PrintContact(s, 0);
        s = Book[i].GetLastName();
        PrintContact(s, 0);
        s = Book[i].GetNickName();
        PrintContact(s, 1);
        if(i < NbContacts - 1)
        {
            for(int i = 0; i < 45; i++)
                std::cout << ".";
            std::cout << std::endl;
        }
    }
    for(int i = 0; i < 45; i++)
        std::cout << "-";
    std::cout << std::endl;
    if(NbContacts)
    {
        std::cout << "Please Enter Index:" << std::endl;
        while(1)
        {
            std::string str;
            if(!getline(std::cin, str)|| std::cin.eof()){
                exit = 1;
                break;
            }
            if(str.empty())
                continue;
            int index;
            std::stringstream(str) >> index;
            if(str.length() > 1 || index >= NbContacts || IsAllDigit(str) == false)
            {
                std::cout << "Wrong Index, please try again!" << std::endl;
                std::cout << "Please Enter Index:" << std::endl;
                continue;
            }
            std::string s = Book[index].GetName();
            std::cout << "Name : " << s << std::endl;
            s = Book[index].GetLastName();
            std::cout << "Last Name : " << s << std::endl;
            s = Book[index].GetNickName();
            std::cout << "Nickname : " << s << std::endl;
            s = Book[index].GetPhoneNumber();
            std::cout << "Phone Number : " << s << std::endl;
            s = Book[index].GetDarkestSecret();
            std::cout << "Darkest Secret : " << s << std::endl;
            break;
        }
    }
}
