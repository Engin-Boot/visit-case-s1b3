#ifndef STATS_CALCULATOR
#define STATS_CALCULATOR
#include <vector>
#include <string>
#include <limits>
#include "DailyDataEntry.h"
#include <cmath>
#define working_hours 12

using namespace std;

class StatsCalculator
{
private:
    vector<DailyDataEntry> monthlyData;
    int workingDays;
    pair<string, int> peakFootfallInLastMonth;
    vector<pair<string, int>> dailyAverageOverAWeek;
    vector<pair<string, int>> hourlyAverageOverADay;

public:
    explicit StatsCalculator(const vector<DailyDataEntry> &);

    pair<string, int> getPeakFootfallInLastMonth(){return peakFootfallInLastMonth;};
    vector<pair<string, int>> getDailyAverageOverAWeek(){return dailyAverageOverAWeek;};
    vector<pair<string, int>> getHourlyAverageOverADay(){return hourlyAverageOverADay;};

    void findPeakFootfallInLastMonth();

    vector<pair<int, int>> calculateWeeklyFootfallData();
    void calculateDailyAverageOverAWeek();

    void calculateHourlyAverageOverADay();

    string toString();
};

#endif