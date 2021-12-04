#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
    std::string str;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        str += argv[i];
    }
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }
    std::cout << str << "\n";
    return 0;
}