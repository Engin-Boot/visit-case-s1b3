#include "ReadCSV.h"
// This file contains all the constructors and member functions of the ReadCSV class

// Parameterized constructor which takes two inputs
// 1. Reference to the string which stores the path to the file
// 2. Reference to the string which acts as the delimiter in the csv file
ReadCSV::ReadCSV(const string &file, const string &delm) : fileName(file), delimeter(delm) {}


// Member function which reads each row of the csv file as a string and appends it into a vector
vector<string> ReadCSV::readCSVData()
{

    ifstream file(fileName);
    vector<string> dataList;
    string line = "";
    while (getline(file, line))
    {
        dataList.push_back(line);
    }
    file.close();
    return dataList;
}
