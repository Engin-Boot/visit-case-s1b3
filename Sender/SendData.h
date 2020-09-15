#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std ;

class SendData{

private:
    vector <string> csvData ;
    vector<string> allDates ;
    vector<int> allDays ;
    vector<int> totalVisitsPerDay ;
    vector<string> finalOutput ;

public:
    explicit SendData(const vector <string>& data) ;
    vector<string> getDates() ;
    int dayOfWeek(int d, int m, int y) ;
    vector<int> getDays(vector<string> dates) ;
    int getNumberOfDays() ;
    int summation(vector<int> arr) ;
    vector<int> getTotalVisitsPerDay(vector<string> dates) ;
    // void toConsole(vector<string> dataList) ;
    vector<string> toString(const vector<string>& dataList) ;

};
