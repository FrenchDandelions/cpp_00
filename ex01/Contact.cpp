#include "Contact.hpp"

void Contact::SetName(std::string s){
    Name = s;
}

void Contact::SetLastName(std::string s){
    LastName = s;
}

void Contact::SetNickName(std::string s){
    Nickname = s;
}

void Contact::SetPhoneNumber(std::string s){
    PhoneNumber = s;
}

void Contact::SetDarkestSecret(std::string s){
    DarkestSecret = s;
}

std::string Contact::GetName(){
    return(Name);
}

std::string Contact::GetLastName(){
    return(LastName);
}

std::string Contact::GetNickName(){
    return(Nickname);
}

std::string Contact::GetPhoneNumber(){
    return(PhoneNumber);
}

std::string Contact::GetDarkestSecret(){
    return(DarkestSecret);
}