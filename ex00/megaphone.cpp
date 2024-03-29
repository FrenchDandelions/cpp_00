#include <iostream>
#include <cctype>
#include <string>

void transform(std::string &str)
{
    for(int i = 0; str[i]; i++)
        str[i] = std::toupper(str[i]);
}

int main(int argc, char **argv)
{
    if(argv[1])
    {
        for(int i = 1; i < argc; i++)
        {
            std::string str = argv[i];
            transform(str);
            std::cout << str;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}