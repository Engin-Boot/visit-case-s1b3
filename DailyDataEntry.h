#ifndef DAILY_DATA_ENTRY
#define DAILY_DATA_ENTRY
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class DailyDataEntry
{
private:
    string date;
    int day;
    int numberOfEntries;

public:
    DailyDataEntry();
    DailyDataEntry(const string &, int, int);

    string getDate();
    int getDay();
    int getNumberOfEntries();

    vector<DailyDataEntry> getDailyDataEntryFromSender();
};

//helper method
vector<string> splitStringBySpaces(string);

#endif