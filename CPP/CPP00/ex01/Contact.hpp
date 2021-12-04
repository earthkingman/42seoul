
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
    std::string darkest_secret;

public:
    std::string GetFirstName();
    std::string GetLastName();
    std::string GetNickName();
    std::string GetPhoneNumber();
    std::string GetDarkest_secret();
    void SetFirstName(std::string first_name);
    void SetLastName(std::string last_name);
    void SetNickName(std::string nickname);
    void SetPhoneNumber(std::string phone_number);
    void SetDarkest_secret(std::string darkest_secret);
};

#endif
