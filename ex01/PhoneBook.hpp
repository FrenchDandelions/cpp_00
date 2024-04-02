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

        void SetContact(int &exit);

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

        void EnterName(int &exit);

        void EnterLastName(int &exit);

        void EnterNickName(int &exit);

        void EnterPhoneNumber(int &exit);

        void EnterDarkestSecret(int &exit);

        void PrintContacts(int &exit);

};
