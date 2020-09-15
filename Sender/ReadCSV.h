#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>


using namespace std ;


class ReadCSV
{
private :
    string fileName;
    string delimeter;

public :
    ReadCSV(const string& filename, const string& delm) ;
    vector<string> readCSVData() ;

};
