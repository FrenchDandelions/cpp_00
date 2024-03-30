#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    private:

        static const int MaxContact = 8;

        Contact Book[MaxContact];

        int NbContacts;

    public:

        PhoneBook();

        ~PhoneBook();

        void SetContact();

        void ResetContacts(){
            if(NbContacts == 7)
                NbContacts = 0;
        }

        void AddNbContacts(){
            NbContacts++;
            ResetContacts();
        }

        int GetNbContacts(){
            return(NbContacts);
        }

        void EnterName();

        void EnterLastName();

        void EnterNickName();

        void EnterPhoneNumber();

        void EnterDarkestSecret();

};

PhoneBook::PhoneBook() : NbContacts(0)
{
    std::cout << "Creating Phonebook" << std::endl;
}

PhoneBook::~PhoneBook()
{
    std::cout << "Destroying Phonebook" << std::endl;
}


