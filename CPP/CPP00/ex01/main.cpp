#include <iostream>
#include <cstring>
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phoneBook;
    std::string str;
    phoneBook.setIdx(0);
    phoneBook.setNowNum(0);
    phoneBook.setMaxNum(8);
    while (1)
    {
        std::cout << "Please, Choose a command from ADD, SEARCH, or EXIT:\n";
        std::cin >> str;
        if (str == "ADD")
        {
            phoneBook.addContact();
        }

        else if (str == "SEARCH")
        {
            phoneBook.showAllContact();
            phoneBook.showOneContact();
        }
        else if (str == "EXIT")
            return 0;
        else
            std::cout << "Wrong command! Input a right command.\n";
    }
}