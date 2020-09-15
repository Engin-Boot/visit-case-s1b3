#include "WriteCSV.h"

//parameterized constructor
//initialize data member
WriteCSV::WriteCSV(const string &data) : finalData(data) {}

//create a new csv file if not exists
//write data in that csv file
void WriteCSV::writeDataToCSV(string fileName)
{   
    //get the file named fileName
    ofstream myfile(fileName);
    
    //write in the file named fileName
    myfile << finalData;

    myfile.close();
}