#include <iostream>

class Contact
{
    private:

        std::string Name;

        std::string LastName;
        
        std::string Nickname;

        std::string PhoneNumber;

        std::string DarkestSecret;

    public:

        Contact();

        ~Contact();

        void SetName(std::string s);

        void SetLastName(std::string s);

        void SetNickName(std::string s);

        void SetPhoneNumber(std::string s);

        void SetDarkestSecret(std::string s);

        std::string GetName();

        std::string GetLastName();

        std::string GetNickName();

        std::string GetPhoneNumber();

        std::string GetDarkestSecret();

};

Contact::Contact()
{
}

Contact::~Contact()
{
}

