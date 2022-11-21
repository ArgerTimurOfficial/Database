#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main()
{
    std::string path = "database.txt";
    while(true)
    {
        std::string command;
        std::cout << "Enter command [new, print, search, close]\n";
        std::cin >> command;
        if(command == "new")
        {
            std::cout << "Enter parameters in format [Name Number]\n";
            std::string name, number;
            std::cin >> name >> number;

            std::ofstream fout;
            fout.open(path, std::ofstream::app);
            if(!fout.is_open())
            {
                std::cout << "Error! Database did not found!\n";  
            }else{
                fout << name << "\t" << number << '\n';
            }
            fout.close();
        }
        if(command == "print")
        {
            std::ifstream fin;
            fin.open(path);
            std::cout << "Name\tNumber\n"; 
            if(!fin.is_open())
            {
                std::cout << "Error! You can't open Database!\n";
            }else{
                std::string str;
                while(!fin.eof())
                {
                    str = "";
                    getline(fin, str);
                    std::cout << str << '\n';
                }
            }
            fin.close();
        }

        if(command == "search")
        {
            std::string client;
            std::cout << "Enter name of client or number\n";
            std::cin >> client;

            std::ifstream fin;
            fin.open(path);
            if(!fin.is_open())
            {
                std::cout << "Error! You can't open Database!\n";
            }else{
                std::string str;
                while(!fin.eof())
                {
                    str = "";
                    getline(fin, str);
                    if(str.find(client) != std::string::npos)
                    {
                        std::cout << "Client: " << str << '\n';
                    }
                }
            }
            fin.close();
        }
        if(command == "close")
        {
            return 0;
        }
    }
    return 0;
}