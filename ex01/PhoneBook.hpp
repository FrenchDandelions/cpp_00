#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    private:

        static const int MaxContact = 8;

        Contact Book[MaxContact];

        int NbContacts;

        int CurrContact;

    public:

        PhoneBook();

        ~PhoneBook();

        void SetContact();

        void ResetContacts(){
            if(NbContacts > 7 && CurrContact > 7)
                CurrContact = 0;
        }

        void AddNbContacts(){
            if(NbContacts < 8)
                NbContacts++;
            CurrContact++;
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

        void PrintContacts();

};




