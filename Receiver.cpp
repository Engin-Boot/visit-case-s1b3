#include <iostream>
#include <string>
#include "DailyDataEntry.h"
#include "StatsCalculator.h"
#include "WriteCSV.h"

using namespace std;

int main()
{
    DailyDataEntry receiver;

    vector<DailyDataEntry> monthlyData = receiver.getDailyDataEntryFromSender();

    //creating an object having monthlyData
    StatsCalculator stats(monthlyData);

    //calculating average from the monthlyData
    stats.calculateHourlyAverageOverADay();
    stats.calculateDailyAverageOverAWeek();
    stats.findPeakFootfallInLastMonth();

    string computedStatsData = stats.toString();

    //creating an object having computedStatsData
    WriteCSV wrtCsv(computedStatsData);

    //writing computedStatsData to CSV
    wrtCsv.writeDataToCSV("outputCSV.csv");

    return 0;
}