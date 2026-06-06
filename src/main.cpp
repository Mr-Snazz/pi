#include <iostream>

int main(int ArgC, char* ArgV[])
{
    while (true)
    {
        system("clear");
        std::string Input;
        std::cout << "> ";
        std::getline(std::cin, Input);

        if (Input == "e") break;


    }

    return 0;
}