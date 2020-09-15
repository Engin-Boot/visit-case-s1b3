#include "StatsCalculator.h"

//parameterized constructor
//initialize data member (data, workingDays)
StatsCalculator::StatsCalculator(const vector<DailyDataEntry> &data) : monthlyData(data), workingDays(data.size()) {}

//calculate peak footfall in given month data
void StatsCalculator::findPeakFootfallInLastMonth()
{
    //initialize the peak value by min int
    peakFootfallInLastMonth.second = numeric_limits<int>::min();

    for (int i_singleDayEntry = 0; i_singleDayEntry < workingDays; i_singleDayEntry++)
    {
        //check if current numberOfEntry is greater than existing peak
        if (monthlyData[i_singleDayEntry].getNumberOfEntries() > peakFootfallInLastMonth.second)
        {
            //update date and peak footfall
            peakFootfallInLastMonth.first = monthlyData[i_singleDayEntry].getDate();
            peakFootfallInLastMonth.second = monthlyData[i_singleDayEntry].getNumberOfEntries();
        }
    }
}

//calculate weekly footfall data
//first int is the sum of footfall on a particular day (like: on monday only)
//second int is number of times that day is in the month (like: August 2020 has 5 mondays)
vector<pair<int, int>> StatsCalculator::calculateWeeklyFootfallData()
{
    //declare a vector of size 7
    //initialize sum of each day footfall and count of each day with 0
    vector<pair<int, int>> weeklyData(7);

    //traverse each entry
    for (int i_singleDayEntry = 0; i_singleDayEntry < workingDays; i_singleDayEntry++)
    {
        //adding footfall data of each day
        weeklyData[monthlyData[i_singleDayEntry].getDay()].first =
            weeklyData[monthlyData[i_singleDayEntry].getDay()].first +
            monthlyData[i_singleDayEntry].getNumberOfEntries();

        //incrementing count of corresponding day
        weeklyData[monthlyData[i_singleDayEntry].getDay()].second++;
    }

    return weeklyData;
}

//calculating day-wise average shown over a week
void StatsCalculator::calculateDailyAverageOverAWeek()
{
    vector<pair<int, int>> weeklyData = calculateWeeklyFootfallData();

    string dayName[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thrusday", "Friday", "Saturday"};

    //traverse weeklyData for each day data
    for (int i_weekDay = 0; i_weekDay < 7; i_weekDay++)
    {
        //calculate and push the average of current day
        //i_weekDay = 0, average of Sunday
        if (weeklyData[i_weekDay].second > 0) //check if weeklyData has the data of current day
        {
            //declare a pair having string day and int weekDayAverage
            pair<string, int> weekDayAverage;

            //write day in the pair.first
            //for i_weekDay = 0 it is Sunday
            weekDayAverage.first = dayName[i_weekDay];

            //calculate round up weekDayAverage
            //write average to the pair.second
            weekDayAverage.second = round((double)weeklyData[i_weekDay].first / weeklyData[i_weekDay].second);

            //push pair in the vector
            dailyAverageOverAWeek.push_back(weekDayAverage);
        }
        else //push zero as average for missing day data
        {
            //declare a pair having string day and int weekDayAverage
            pair<string, int> weekDayAverage;

            //write day in the pair.first
            //for i_weekDay = 1 it is Monday
            weekDayAverage.first = dayName[i_weekDay];

            //write average to the pair.second
            weekDayAverage.second = 0;

            //push pair in the vector
            dailyAverageOverAWeek.push_back(weekDayAverage);
        }
    }
}

//calculating hourly Average shown over a day
void StatsCalculator::calculateHourlyAverageOverADay()
{
    for (int i_singleDayEntry = 0; i_singleDayEntry < workingDays; i_singleDayEntry++)
    {
        //declare a pair having string date and int hourlyAverage
        pair<string, int> oneDayHourlyAverage;

        //write date in the pair.first
        oneDayHourlyAverage.first = monthlyData[i_singleDayEntry].getDate();

        //calculate round up hourly average
        //write average to the pair.second
        oneDayHourlyAverage.second = round((double)monthlyData[i_singleDayEntry].getNumberOfEntries() / working_hours);

        //push pair in the vector
        hourlyAverageOverADay.push_back(oneDayHourlyAverage);
    }
}

//convert all data in csv formatted string
string StatsCalculator::toString()
{   

    //initialize a empty string
    string allStatsData = "";

    //add Peak daily footfall in the last month data
    allStatsData = allStatsData + "Peak daily footfall in the last month\n";

    allStatsData = allStatsData + "Date" + "," + "Peak Footfall" + "\n";

    allStatsData = allStatsData + peakFootfallInLastMonth.first + "," + to_string(peakFootfallInLastMonth.second) + "\n\n";

    //add Average daily footfalls in a week data
    allStatsData = allStatsData + "Average daily footfalls in a week\n";

    allStatsData = allStatsData + "Day" + "," + "Daily Avearge" + "\n";

    for (int i_weekDay = 0; i_weekDay < 7; i_weekDay++)
    {
        allStatsData = allStatsData + dailyAverageOverAWeek[i_weekDay].first + "," + to_string(dailyAverageOverAWeek[i_weekDay].second) + "\n";
    }

    //add Average footfalls per hour shown over a day data
    allStatsData = allStatsData + "\nAverage footfalls per hour shown over a day(" + to_string(working_hours) + " working hours)\n";

    allStatsData = allStatsData + "Date" + "," + "Hourly Avearge" + "\n";

    for (int i_singleDayEntry = 0; i_singleDayEntry < workingDays; i_singleDayEntry++)
    {
        allStatsData = allStatsData + hourlyAverageOverADay[i_singleDayEntry].first + "," + to_string(hourlyAverageOverADay[i_singleDayEntry].second) + "\n";
    }

    return allStatsData;
}