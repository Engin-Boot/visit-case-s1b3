#include "DailyDataEntry.h"

//helper method
vector<string> splitStringBySpaces(string str)
{
    vector<string> singleDayEntry;

    string word = "";
    for (unsigned int i_char = 0; i_char < str.length(); i_char++)
    {
        if (str[i_char] != ' ')
        {
            word = word + str[i_char];
        }
        else
        {
            singleDayEntry.push_back(word);
            word = "";
        }
    }

    singleDayEntry.push_back(word);

    return singleDayEntry;
}

DailyDataEntry::DailyDataEntry() {}

DailyDataEntry::DailyDataEntry(const string &date, int day, int numberOfEntries)
    : date(date), day(day), numberOfEntries(numberOfEntries) {}

std::string DailyDataEntry::getDate() { return date; }

int DailyDataEntry::getDay() { return day; }

int DailyDataEntry::getNumberOfEntries() { return numberOfEntries; }

vector<DailyDataEntry> DailyDataEntry::getDailyDataEntryFromSender()
{
    string numberOfWorkingDays_string;
    getline(cin, numberOfWorkingDays_string);

    int numberOfWorkingDays = stoi(numberOfWorkingDays_string);

    vector<DailyDataEntry> monthlyEntryData(numberOfWorkingDays);

    for (int i_singleDayEntry = 0; i_singleDayEntry < numberOfWorkingDays; i_singleDayEntry++)
    {
        string singleDayEntry_string;
        getline(cin, singleDayEntry_string);

        //splitting string to fetch date, day, entries
        vector<string> splitted_singleDayEntry_string = splitStringBySpaces(singleDayEntry_string);

        //creating object of DailyDataEntry
        DailyDataEntry data(
            splitted_singleDayEntry_string[0],
            stoi(splitted_singleDayEntry_string[1]),
            stoi(splitted_singleDayEntry_string[2]));

        //pushing single day data into vector
        monthlyEntryData[i_singleDayEntry] = (data);
    }

    return monthlyEntryData;
}