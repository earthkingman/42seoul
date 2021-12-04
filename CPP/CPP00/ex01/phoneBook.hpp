#include <cstring>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{

private:
    Contact contactList[8];
    int idx;
    int max_num;
    int now_num;

public:
    void setMaxNum(int maxnum);
    int getMaxNum();
    int getIdx();
    void setIdx(int idx);
    void addContact();
    void showAllContact();
    void showOneContact();
    void printContact(std::string str);
};