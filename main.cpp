#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

#define ll long long;
#define matrix vector<vector<int>>;

const double PI = 3.1415192;
const double PHI = 1.61803;
const int INF = 1e9;

using namespace std;

int main()
{
    vector<pair<string, int>>DataBase;
    string path = "database.txt";
    while(true)
    {
        string command;
        cout << "Enter command [new, print, search]\n";
        cin >> command;
        if(command == "new")
        {
            cout << "Enter parameters in format [Name Number]\n";
            string name, number;
            cin >> name >> number;

            ofstream fout;
            fout.open(path, ofstream::app);
            if(!fout.is_open())
            {
                cout << "Error! DataBase did not found!\n";  
            }else{
                fout << name << '\t' << number << '\n';
            }
            fout.close();
        }
        if(command == "print")
        {
            ifstream fin;
            fin.open(path);
            cout << "Name\tNumber\n"; 
            if(!fin.is_open())
            {
                cout << "Error! You can't open DataBase!\n";
            }else{
                string str;
                while(!fin.eof())
                {
                    str = "";
                    getline(fin, str);
                    cout << str << '\n';
                }
            }
            fin.close();
        }

        if(command == "search")
        {
            string client;
            cout << "Enter name of client or number\n";
            cin >> client;

            ifstream fin;
            fin.open(path);
            if(!fin.is_open())
            {
                cout << "Error! You can't open DataBase!\n";
            }else{
                string str;
                while(!fin.eof())
                {
                    str = "";
                    getline(fin, str);
                    if(str.find(client) != string::npos)
                    {
                        cout << "Client: " << str << '\n';
                    }
                }
            }
            fin.close();
        }
    }
}