#include <iostream>
#include <string>
#include "DailyDataEntry.h"
#include "StatsCalculator.h"
#include "WriteCSV.h"

using namespace std;

int main()
{

    DailyDataEntry receiver;

    //receive all data from the console
    vector<DailyDataEntry> monthlyData = receiver.getDailyDataEntryFromSender();

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