#include "StatsCalculator.h"

StatsCalculator::StatsCalculator(const vector<DailyDataEntry> &data) : monthlyData(data), workingDays(data.size()) {}

//calculation peak footfall in last month
void StatsCalculator::findPeakFootfallInLastMonth()
{
    peakFootfallInLastMonth.second = numeric_limits<int>::min();

    for (int i_singleDayEntry = 0; i_singleDayEntry < workingDays; i_singleDayEntry++)
    {
        if (monthlyData[i_singleDayEntry].getNumberOfEntries() > peakFootfallInLastMonth.second)
        {
            peakFootfallInLastMonth.first = monthlyData[i_singleDayEntry].getDate();
            peakFootfallInLastMonth.second = monthlyData[i_singleDayEntry].getNumberOfEntries();
        }
    }
}

//calculating weekly footfall data
//first int is the sum of fottfall on a particular day (like: on monday only)
//second int is number of times that day is in the month (like: August 2020 has 5 mondays)
vector<pair<int, int>> StatsCalculator::calculateWeeklyFootfallData()
{
    vector<pair<int, int>> weeklyData(7);
    for (int i_singleDayEntry = 0; i_singleDayEntry < workingDays; i_singleDayEntry++)
    {
        weeklyData[monthlyData[i_singleDayEntry].getDay()].first =
            weeklyData[monthlyData[i_singleDayEntry].getDay()].first +
            monthlyData[i_singleDayEntry].getNumberOfEntries();

        weeklyData[monthlyData[i_singleDayEntry].getDay()].second++;
    }
    return weeklyData;
}

//calculating day-wise average shown over a week
void StatsCalculator::calculateDailyAverageOverAWeek()
{
    vector<pair<int, int>> weeklyData = calculateWeeklyFootfallData();

    string dayName[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thrusday", "Friday", "Saturday"};

    for (int i_WeekDay = 0; i_WeekDay < 7; i_WeekDay++)
    {
        if (weeklyData[i_WeekDay].second > 0)
        {
            pair<string, int> weekDayAverage;
            weekDayAverage.first = dayName[i_WeekDay];
            weekDayAverage.second = round((double)weeklyData[i_WeekDay].first / weeklyData[i_WeekDay].second);
            dailyAverageOverAWeek.push_back(weekDayAverage);
        }
        else
        {
            pair<string, int> weekDayAverage;
            weekDayAverage.first = dayName[i_WeekDay];
            weekDayAverage.second = 0;
            dailyAverageOverAWeek.push_back(weekDayAverage);
        }
    }
}

//calculating hourly Average shown over a day
void StatsCalculator::calculateHourlyAverageOverADay()
{
    for (int i_singleDayEntry = 0; i_singleDayEntry < workingDays; i_singleDayEntry++)
    {
        pair<string, int> oneDayHourlyAverage;
        oneDayHourlyAverage.first = monthlyData[i_singleDayEntry].getDate();
        oneDayHourlyAverage.second = round((double)monthlyData[i_singleDayEntry].getNumberOfEntries() / working_hours);

        hourlyAverageOverADay.push_back(oneDayHourlyAverage);
    }
}

string StatsCalculator::toString()
{
    string allStatsData = "Peak daily footfall in the last month\n";

    allStatsData = allStatsData + "Date" + "," + "Peak Footfall" + "\n";

    allStatsData = allStatsData + peakFootfallInLastMonth.first + "," + to_string(peakFootfallInLastMonth.second) + "\n\n";

    allStatsData = allStatsData + "Average daily footfalls in a week\n";

    allStatsData = allStatsData + "Day" + "," + "Daily Avearge" + "\n";

    for (int i_WeekDay = 0; i_WeekDay < 7; i_WeekDay++)
    {
        allStatsData = allStatsData + dailyAverageOverAWeek[i_WeekDay].first + "," + to_string(dailyAverageOverAWeek[i_WeekDay].second) + "\n";
    }

    allStatsData = allStatsData + "\nAverage footfalls per hour shown over a day(" + to_string(working_hours) + " working hours)\n";

    allStatsData = allStatsData + "Date" + "," + "Hourly Avearge" + "\n";

    for (int i_singleDayEntry = 0; i_singleDayEntry < workingDays; i_singleDayEntry++)
    {
        allStatsData = allStatsData + hourlyAverageOverADay[i_singleDayEntry].first + "," + to_string(hourlyAverageOverADay[i_singleDayEntry].second) + "\n";
    }

    return allStatsData;
}