#include "WriteCSV.h"

WriteCSV::WriteCSV(const string& data) : finalData(data) {}

void WriteCSV::writeDataToCSV(string fileName)
{
    ofstream myfile(fileName);

    myfile << finalData;

    myfile.close();
}