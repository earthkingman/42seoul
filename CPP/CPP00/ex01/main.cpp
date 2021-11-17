#include <iostream>
#include <cstring>

int main(void){

    std::string str;
    while(1)
    {
        std::cin >> str;
        if (str == "ADD")
            return 0;
        else if (str == "SEARCH")
            return 0;
        else if (str == "EXIT")
            return 0;        
    }
}