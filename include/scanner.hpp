#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

namespace scanner
{
    /**
         * @brief this is a class from reading data from terminal besides that get and corrected 
         * some exceptions that can happens when the user enter the information 
        */
    class Scanner
    {
    private:
        /* data */
    public:
        /**
         * @brief this is a function that get the values of the strings from the terminalbesides checks that dont be entered emoty strings
         * @param name name of the data is going to be readed
         * @return the string that has been readed
        */
        static string scanData(string name);

        template <typename T>

        /**
         * @brief this is a generic function for reading data from terminal, 
         * this function will be running until be able to get a data from the correct type
         * @param name name of the data is going to be readed is for information to the user
         * @param type type of the data is going to be readed in case that the value inserted dont belong to the expected type is going to be asked to the user that inserted the value again with correct type
         * @return dataIn a generic variable with the data readed from the terminal
        */
        static T scanData(string name, string type);

        /**
         * @brief this is a function to convert a line of string with values separated by an specific character, in a vector of longs
         * @param data  data is going to be proccesed
         * @param separator character that separate the values
         * @return a vector with the values got in the processing
        */
        static vector<long> splitData(string data, string separator = ",");
    };

    string Scanner::scanData(string name)
    {
        string data;
        bool error;
        string copyData;
        error = false;
        int size=0;
        cout << "----------------------------------------" << endl;
        do
        {
            cout << "Enter the " << name << " data: ";
            getline(std::cin, data);
            copyData = data;
            copyData.erase(remove(copyData.begin(), copyData.end(), ' '), copyData.end());
            size=copyData.size();
            if(!size){
                cout<<"Empty string please enter a value"<<endl;
            }
        } while (!size);

        cout << "The value data of " << name << " is :" << data << endl;
        cout << "----------------------------------------" << endl<< endl;
        return data;
    }

    template <typename T>
    T Scanner::scanData(string name, string type)
    {
        T dataIn;
        string data;
        bool error;
        cout << "----------------------------------------" << endl;
        do
        {
            error = false;
            cout << "Enter the " << name << " data: ";
            getline(std::cin, data);
            std::stringstream ss(data);
            ss >> dataIn;
            if (ss.fail())
            {
                cout << "Invalid type of data insert again remember the data type must be " << type << endl;
                error = true;
            }
        } while (error);

        cout << "The value data of " << name << " is :" << dataIn << endl;
        cout << "----------------------------------------" << endl
             << endl;

        return dataIn;
    }

    vector<long> Scanner::splitData(string data, string separator)
    {
        std::vector<long> numbers;
        long position;
        do
        {
            position = data.find(separator);
            long temp = stoi(data.substr(0, position).data());
            numbers.push_back(temp);
            data = data.substr(position + 1);
        } while (position != string::npos);
        return numbers;
    }

}