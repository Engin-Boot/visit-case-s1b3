#include <iostream>
#include <string>
#include <vector>
#include "DailyDataEntry.h"
#include "StatsCalculator.h"
#include "WriteCSV.h"

using namespace std;

int main()
{
    //take input from console
    //store it in a 2D vector of string
    vector<vector<string>> inputData;
    string singleLineString;
    while (getline(cin, singleLineString))
    {
        //split the string by space to get date day and numberOfEntries
        vector<string> splittedString = splitStringBySpaces(singleLineString);
        inputData.push_back(splittedString);
    }

    DailyDataEntry receiver;

    //receive all data from the console
    vector<DailyDataEntry> monthlyData = receiver.getDailyDataEntryFromSender(inputData);

    //initialize a StatsCalculator class object with monthlyData
    StatsCalculator stats(monthlyData);

    //calculating average from the monthlyData
    stats.calculateHourlyAverageOverADay();
    stats.calculateDailyAverageOverAWeek();
    stats.findPeakFootfallInLastMonth();

    //convert all aggregates in csv formatted string
    string computedStatsData = stats.toString();

    //initialize a WriteCSV class object with computedStatsData
    WriteCSV wrtCsv(computedStatsData);

    //write computedStatsData to CSV
    wrtCsv.writeDataToCSV("outputCSV.csv");

    return 0;
}