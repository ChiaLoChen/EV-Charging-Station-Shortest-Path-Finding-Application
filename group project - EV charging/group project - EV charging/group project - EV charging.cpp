// group project - EV charging.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
using namespace std;

class nodes {

};

int main()
{
    string myText;
    string file_contents;
    ifstream MyReadFile("");
    if (MyReadFile.is_open()) {
        while (getline(MyReadFile, myText)) {
            stringstream ss(myText);
            string token;

            getline(ss, token, ',');
            id = stoi(token);

            getline(ss, token, ',');
            name = trim(token);

            getline(ss, token, ',');
            price = stof(token);

            getline(ss, token, ',');
            category = trim(token);

            ss >> id >> name >> price >> category;
            products.push_back(Product(id, name, price, category));
        }
    }
}
