#include "DailyDataEntry.h"

//splits the input string by spaces
//returns a vector of words
vector<string> splitStringBySpaces(string str)
{
    //declaration of empty vector
    //will contain words
    vector<string> singleDayEntry;

    //initialized new word
    string word = "";

    //traverse input string
    for (unsigned int i_char = 0; i_char < str.length(); i_char++)
    {
        if (str[i_char] != ' ')
        {
            //adding characters to the word
            word = word + str[i_char];
        }
        else
        {
            //pushing single word of input string into vector
            singleDayEntry.push_back(word);

            //initialized next new word
            word = "";
        }
    }

    //pushing single word of input string into vector
    singleDayEntry.push_back(word);

    //return vector of words
    return singleDayEntry;
}

//default constructor
DailyDataEntry::DailyDataEntry() {}

//parameterized constructor
//initialize data member
DailyDataEntry::DailyDataEntry(const string &date, int day, int numberOfEntries)
    : date(date), day(day), numberOfEntries(numberOfEntries) {}

//getter for date
std::string DailyDataEntry::getDate() { return date; }

//getter for day
int DailyDataEntry::getDay() { return day; }

//getter for numberOfEntries
int DailyDataEntry::getNumberOfEntries() { return numberOfEntries; }

//return a vector of DailyDataEntry object type
//vector has all the data needed for calculating aggregates
vector<DailyDataEntry> DailyDataEntry::getDailyDataEntryFromSender(const vector<vector<string>> &senderData)
{
    //check for input
    if (senderData.empty())
        throw runtime_error("No Input");

    //number of input strings
    unsigned int n = senderData.size();

    //declare vector of DailtDataEntry type of n size
    vector<DailyDataEntry> monthlyEntryData;

    for (unsigned int i_singleDayEntry = 0; i_singleDayEntry < n; i_singleDayEntry++)
    {
        //create a DailyDataEntry object having date day numberOfEntries
        DailyDataEntry data(senderData.at(i_singleDayEntry).at(0),
                            stoi(senderData.at(i_singleDayEntry).at(1)),
                            stoi(senderData.at(i_singleDayEntry).at(2)));

        //write single day data (DailyDataEntry object) into vector
        monthlyEntryData.push_back(data);
    }

    //return vector having all sender data
    return monthlyEntryData;
}