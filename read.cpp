#include "readCSV.h"

ReadCSV ::ReadCSV(const string &file, const string &delm) : fileName(file), delimeter(delm) {}

vector<string> ReadCSV ::readCSVData()
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
