#ifndef WRITE_CSV
#define WRITE_CSV
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class WriteCSV
{
private:
    string finalData;

public:
    explicit WriteCSV(const string&);
    void writeDataToCSV(string);
};

#endif