#include "DailyDataEntry.h"

//splits the input string by spaces
//returns a vector of words
vector<string> splitStringBySpaces(string str)
{
    //declaration of empty vector
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

            //initialized new word
            word = "";
        }
    }

    //pushing single word of input string into vector
    singleDayEntry.push_back(word);

    return singleDayEntry;
}

//default constructor
DailyDataEntry::DailyDataEntry() {}

//parameterized constructor
DailyDataEntry::DailyDataEntry(const string &date, int day, int numberOfEntries)
    : date(date), day(day), numberOfEntries(numberOfEntries) {}

//getter for date
std::string DailyDataEntry::getDate() { return date; }

//getter for day
int DailyDataEntry::getDay() { return day; }

//getter for numberOfEntries
int DailyDataEntry::getNumberOfEntries() { return numberOfEntries; }

//read all the sender data from the console
//return a vector of DailyDataEntry object type
//vector has all the data needed for calculating aggregates
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