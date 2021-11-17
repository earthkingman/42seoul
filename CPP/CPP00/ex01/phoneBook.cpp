#include <cstring>
#include <iostream>
#include "contact.hpp"

class PhoneBook 
{
    private:
    Contact contactList[10];
    PhoneBook();

    public:
    void addContact(Contact contact);
};