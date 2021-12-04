#include "Contact.hpp"

std::string Contact::GetFirstName()
{
    return this->first_name;
};
std::string Contact::GetLastName()
{
    return this->last_name;
};
std::string Contact::GetNickName()
{
    return this->nickname;
};
std::string Contact::GetPhoneNumber()
{
    return this->phone_number;
};
std::string Contact::GetDarkest_secret()
{
    return this->darkest_secret;
}
void Contact::SetFirstName(std::string first_name)
{
    this->first_name = first_name;
};
void Contact::SetLastName(std::string last_name)
{
    this->last_name = last_name;
};
void Contact::SetNickName(std::string nickname)
{
    this->nickname = nickname;
};
void Contact::SetPhoneNumber(std::string phoneNumber)
{
    this->phone_number = phoneNumber;
};

void Contact::SetDarkest_secret(std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}
