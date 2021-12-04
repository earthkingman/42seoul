#include "PhoneBook.hpp"
#include <string>

void PhoneBook::addContact()
{
    int idx;
    int max;
    std::string temp;

    max = this->getMaxNum();
    idx = this->getIdx();
    if (idx >= max)
    {
        std::cout << "Full Contact"
                  << "\n";
        return;
    }
    this->setIdx(idx + 1);
    std::cout << "Input first name: ";
    std::cin >> temp;
    contactList[idx].SetFirstName(temp);
    std::cout << "Input last name: ";
    std::cin >> temp;
    contactList[idx].SetLastName(temp);
    std::cout << "Input nick name: ";
    std::cin >> temp;
    contactList[idx].SetNickName(temp);
    std::cout << "Input phone numbers: ";
    std::cin >> temp;
    contactList[idx].SetPhoneNumber(temp);
    std::cout << "Input darkest secret: ";
    std::cin >> temp;
    contactList[idx].SetDarkest_secret(temp);
};

void PhoneBook::showAllContact()
{
    int max = getIdx();
    if (this->idx == 0)
    {
        std::cout << "No Contact"
                  << "\n";
        return;
    }
    std::cout << ".----------.----------.----------.----------." << std::endl;
    std::cout << "|index     |first name|last name |nickname  |" << std::endl;
    std::cout << ".----------.----------.----------.----------." << std::endl;

    for (int i = 0; i < max; i++)
    {
        std::cout << "|";
        std::string temp = std::to_string(i);
        printContact(temp);
        std::cout << "|";
        printContact(this->contactList[i].GetFirstName());
        std::cout << "|";
        printContact((this->contactList[i].GetLastName()));
        std::cout << "|";
        printContact((this->contactList[i].GetNickName()));
        std::cout << "|";
        std::cout << "\n.----------.----------.----------.----------.\n";
    }
}
void PhoneBook::showOneContact()
{
    int now_max = getIdx();
    int showIdx;
    int max = this->getMaxNum();
    if (this->idx == 0)
    {
        std::cout << "No Contact"
                  << "\n";
        return;
    }
    std::cout << "\nEnter the index of the contact you want to search: ";
    std::cin >> showIdx;

    if (std::cin.fail()) //문자 등 비정상 입력 들어오면 잡음
    {
        std::cin.clear();                                                   //failbit 초기화해서 정상 작동하게 해줌
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //입력 버퍼의 문자를 읽어와 버림
        std::cout << "Wrong input! Please enter a number.\n";
        return;
    }

    if (showIdx < 0 || showIdx > max || showIdx > now_max)
    {
        std::cout << "Wrong index!\n";
        return;
    }
    std::cout << "First name: " << this->contactList[showIdx].GetFirstName() << std::endl;
    std::cout << "Last name: " << this->contactList[showIdx].GetLastName() << std::endl;
    std::cout << "Nickname: " << this->contactList[showIdx].GetNickName() << std::endl;
    std::cout << "Phone number: " << this->contactList[showIdx].GetPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << this->contactList[showIdx].GetDarkest_secret() << std::endl;
}

int PhoneBook::getMaxNum()
{
    return this->max_num;
};

void PhoneBook::setMaxNum(int max_num)
{
    this->max_num = max_num;
};

int PhoneBook::getIdx()
{
    return this->idx;
};

void PhoneBook::setIdx(int idx)
{
    this->idx = idx;
};

void PhoneBook::printContact(std::string str)
{
    int blank = 0;

    if (str.length() > 10)
    {
        str = str.substr(0, 9);
        str.push_back('.');
        std::cout << str;
    }
    else
    {
        std::cout << std::setw(10) << str;
    }
}
