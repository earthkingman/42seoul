
#ifndef CONTACT_H
#define CONTACT_H
#include <cstring>
#include <iostream>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string last_name;
    std::string login;
    std::string postal_address;
    std::string email_address;
    std::string birthday_date;
    std::string favorite_meal;
    std::string underwear_color;
    std::string darkest_secret;

    Contact();

public:
    std::string GetFirstName();
    std::string GetLastName();
    std::string GetNickName();
    std::string GetPhoneNumber();
    std::string GetLastName();
    void SetFirstName();
    void SetLastName();
    void SetNickName();
    void SetPhoneNumber();
    void SetLastName();
};

#endif