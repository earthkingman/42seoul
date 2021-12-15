#include <iostream>
#include <fstream>
#include <string>

std::string MyReplace(std::string s, std::string &s1, std::string &s2)
{
    int idx = 0;
    size_t i = 0;

    while ((idx = s.find(s1, i)) != std::string::npos) //찾지 못하면 -1을 반환    찾으면 해당 인덱스를 반환
    {
        s.erase(idx, s1.length());
        s.insert(idx, s2);
        i = idx + s2.length();
    }
    return s;
}

int main(int ac, char *av[])
{
    if (ac != 4)
    {
        std::cout << "Wrong number of arguments\n";
        return 0;
    }
    if (*(av[2]) == 0 || *(av[3]) == 0)
    {
        std::cout << "s1 or s2 is empty string!\n";
        return 0;
    }
    std::string s1 = av[2];
    std::string s2 = av[3];

    std::fstream readFile(av[1]);
    if (!readFile.is_open())
    {
        std::cout << "Failed to open " << av[1] << std::endl;
        return 0;
    }

    std::string s = av[1];
    for (int i = 0; i < s.length(); ++i)
    {
        s[i] = toupper(s[i]);
    }
    s.append(".replace");

    std::fstream printFile;
    printFile.open(s, std::ios::out); //출력용으로 열어서 사용
    if (printFile.fail())
    {
        readFile.close();
        std::cout << "Failed to open " << s << std::endl;
        return 0;
    }
    std::string temp;
    while (std::getline(readFile, temp))
    {
        printFile << MyReplace(temp, s1, s2);
        printFile << "\n";
    }
    readFile.close();
    printFile.close();

    return 0;
}