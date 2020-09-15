#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <string>
#include "../Receiver/DailyDataEntry.h"
#include "../Receiver/WriteCSV.h"
#include "../Receiver/StatsCalculator.h"
#include <fstream>

using namespace std;

// TEST_CASE("test2")
// {
//     // DailyDataEntry y;
//     // vector<DailyDataEntry> x = y.getDailyDataEntryFromSender();
//     // REQUIRE(x[0].getDate() == "1/1/2020");
//     // REQUIRE(x[0].getDay() == 0);
//     // REQUIRE(x[0].getNumberOfEntries() == 23);
// }

TEST_CASE("when a string with 4 words separated by single space is passed in splitStringBySpaces() then it returns a vector containing same 4 words")
{
    vector<string> x = splitStringBySpaces("Hi, I am Nishit");
    REQUIRE(x[0] == "Hi,");
    REQUIRE(x[1] == "I");
    REQUIRE(x[2] == "am");
    REQUIRE(x[3] == "Nishit");
}

TEST_CASE("when dailyDataEntry having one peak is used for calculation of peak by findPeakFootfallInLastMonth() method then it writes peakFootfallInLastMonth with date and peak footfall")
{
    DailyDataEntry d1("01/01/2020", 3, 23);
    DailyDataEntry d2("02/01/2020", 4, 34);
    DailyDataEntry d3("03/01/2020", 5, 25);
    DailyDataEntry d4("04/01/2020", 6, 45);

    vector<DailyDataEntry> mockDailyDataEntry = {d1, d2, d3, d4};

    StatsCalculator testStats(mockDailyDataEntry);

    testStats.findPeakFootfallInLastMonth();

    REQUIRE(testStats.getPeakFootfallInLastMonth().first == "04/01/2020");
    REQUIRE(testStats.getPeakFootfallInLastMonth().second == 45);
}

TEST_CASE("when dailyDataEntry having two or more peak is used for calculation of peak by findPeakFootfallInLastMonth() method then it write peakFootfallInLastMonth with date and first peak footfall")
{
    DailyDataEntry d1("01/01/2020", 3, 23);
    DailyDataEntry d2("02/01/2020", 4, 34);
    DailyDataEntry d3("03/01/2020", 5, 25);
    DailyDataEntry d4("04/01/2020", 6, 45);
    DailyDataEntry d5("05/01/2020", 0, 45);
    DailyDataEntry d6("06/01/2020", 1, 45);

    vector<DailyDataEntry> mockDailyDataEntry = {d1, d2, d3, d4, d5, d6};

    StatsCalculator testStats(mockDailyDataEntry);

    testStats.findPeakFootfallInLastMonth();

    REQUIRE(testStats.getPeakFootfallInLastMonth().first == "04/01/2020");
    REQUIRE(testStats.getPeakFootfallInLastMonth().second == 45);
}

TEST_CASE("when dailyDatEntry for all days of week is used for calculation of sum of footfall in each day and number of times that day is in current month by calculateWeeklyFootfallData() then it returns a vector having the same")
{
    DailyDataEntry d1("01/01/2020", 3, 22);
    DailyDataEntry d2("02/01/2020", 4, 34);
    DailyDataEntry d3("03/01/2020", 5, 25);
    DailyDataEntry d4("04/01/2020", 6, 40);
    DailyDataEntry d5("05/01/2020", 0, 55);
    DailyDataEntry d6("06/01/2020", 1, 22);
    DailyDataEntry d7("07/01/2020", 2, 34);
    DailyDataEntry d8("08/01/2020", 3, 25);
    DailyDataEntry d9("09/01/2020", 4, 40);
    DailyDataEntry d10("10/01/2020", 5, 55);
    DailyDataEntry d11("11/01/2020", 6, 22);
    DailyDataEntry d12("12/01/2020", 0, 34);
    DailyDataEntry d13("13/01/2020", 1, 25);
    DailyDataEntry d14("14/01/2020", 2, 40);
    DailyDataEntry d15("15/01/2020", 3, 55);

    vector<DailyDataEntry> mockDailyDataEntry = {d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15};

    StatsCalculator testStats(mockDailyDataEntry);

    vector<pair<int, int>> weeklyData = testStats.calculateWeeklyFootfallData();

    REQUIRE(weeklyData[0].first == 89);
    REQUIRE(weeklyData[0].second == 2);

    REQUIRE(weeklyData[1].first == 47);
    REQUIRE(weeklyData[1].second == 2);

    REQUIRE(weeklyData[2].first == 74);
    REQUIRE(weeklyData[2].second == 2);

    REQUIRE(weeklyData[3].first == 102);
    REQUIRE(weeklyData[3].second == 3);

    REQUIRE(weeklyData[4].first == 74);
    REQUIRE(weeklyData[4].second == 2);

    REQUIRE(weeklyData[5].first == 80);
    REQUIRE(weeklyData[5].second == 2);

    REQUIRE(weeklyData[6].first == 62);
    REQUIRE(weeklyData[6].second == 2);
}

TEST_CASE("when dailyDatEntry for some days of week is used for calculation of sum of footfall in each day and number of times that day is in current month by calculateWeeklyFootfallData() then it returns a vector having the same and contain zero for missing day data")
{
    DailyDataEntry d1("01/01/2020", 3, 22);
    DailyDataEntry d2("02/01/2020", 4, 34);
    DailyDataEntry d3("03/01/2020", 5, 25);
    DailyDataEntry d4("06/01/2020", 1, 22);
    DailyDataEntry d5("07/01/2020", 2, 34);
    DailyDataEntry d6("08/01/2020", 3, 25);
    DailyDataEntry d7("09/01/2020", 4, 40);
    DailyDataEntry d8("10/01/2020", 5, 55);
    DailyDataEntry d9("13/01/2020", 1, 25);
    DailyDataEntry d10("14/01/2020", 2, 40);
    DailyDataEntry d11("15/01/2020", 3, 55);

    vector<DailyDataEntry> mockDailyDataEntry = {d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11};

    StatsCalculator testStats(mockDailyDataEntry);

    vector<pair<int, int>> weeklyData = testStats.calculateWeeklyFootfallData();

    REQUIRE(weeklyData[0].first == 0);
    REQUIRE(weeklyData[0].second == 0);

    REQUIRE(weeklyData[1].first == 47);
    REQUIRE(weeklyData[1].second == 2);

    REQUIRE(weeklyData[2].first == 74);
    REQUIRE(weeklyData[2].second == 2);

    REQUIRE(weeklyData[3].first == 102);
    REQUIRE(weeklyData[3].second == 3);

    REQUIRE(weeklyData[4].first == 74);
    REQUIRE(weeklyData[4].second == 2);

    REQUIRE(weeklyData[5].first == 80);
    REQUIRE(weeklyData[5].second == 2);

    REQUIRE(weeklyData[6].first == 0);
    REQUIRE(weeklyData[6].second == 0);
}

TEST_CASE("when dailyDatEntry for all days of week is used for calculation of daily average over a week by calculateDailyAverageOverAWeek() then it write the same in the dailyAverageOverAWeek vector")
{
    DailyDataEntry d1("01/01/2020", 3, 22);
    DailyDataEntry d2("02/01/2020", 4, 34);
    DailyDataEntry d3("03/01/2020", 5, 25);
    DailyDataEntry d4("04/01/2020", 6, 40);
    DailyDataEntry d5("05/01/2020", 0, 55);
    DailyDataEntry d6("06/01/2020", 1, 22);
    DailyDataEntry d7("07/01/2020", 2, 34);
    DailyDataEntry d8("08/01/2020", 3, 25);
    DailyDataEntry d9("09/01/2020", 4, 40);
    DailyDataEntry d10("10/01/2020", 5, 55);
    DailyDataEntry d11("11/01/2020", 6, 22);
    DailyDataEntry d12("12/01/2020", 0, 34);
    DailyDataEntry d13("13/01/2020", 1, 25);
    DailyDataEntry d14("14/01/2020", 2, 40);
    DailyDataEntry d15("15/01/2020", 3, 55);

    vector<DailyDataEntry> mockDailyDataEntry = {d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15};

    StatsCalculator testStats(mockDailyDataEntry);

    testStats.calculateDailyAverageOverAWeek();

    REQUIRE(testStats.getDailyAverageOverAWeek()[0].first == "Sunday");
    REQUIRE(testStats.getDailyAverageOverAWeek()[0].second == 45);

    REQUIRE(testStats.getDailyAverageOverAWeek()[1].first == "Monday");
    REQUIRE(testStats.getDailyAverageOverAWeek()[1].second == 24);

    REQUIRE(testStats.getDailyAverageOverAWeek()[2].first == "Tuesday");
    REQUIRE(testStats.getDailyAverageOverAWeek()[2].second == 37);

    REQUIRE(testStats.getDailyAverageOverAWeek()[3].first == "Wednesday");
    REQUIRE(testStats.getDailyAverageOverAWeek()[3].second == 34);

    REQUIRE(testStats.getDailyAverageOverAWeek()[4].first == "Thrusday");
    REQUIRE(testStats.getDailyAverageOverAWeek()[4].second == 37);

    REQUIRE(testStats.getDailyAverageOverAWeek()[5].first == "Friday");
    REQUIRE(testStats.getDailyAverageOverAWeek()[5].second == 40);

    REQUIRE(testStats.getDailyAverageOverAWeek()[6].first == "Saturday");
    REQUIRE(testStats.getDailyAverageOverAWeek()[6].second == 31);
}

TEST_CASE("when dailyDatEntry for some days of week is used for calculation of daily average over a week by calculateDailyAverageOverAWeek() then it write the same in the dailyAverageOverAWeek vector keeping average as zero for missing day data")
{
    DailyDataEntry d1("01/01/2020", 3, 22);
    DailyDataEntry d2("02/01/2020", 4, 34);
    DailyDataEntry d3("03/01/2020", 5, 25);
    DailyDataEntry d4("06/01/2020", 1, 22);
    DailyDataEntry d5("07/01/2020", 2, 34);
    DailyDataEntry d6("08/01/2020", 3, 25);
    DailyDataEntry d7("09/01/2020", 4, 40);
    DailyDataEntry d8("10/01/2020", 5, 55);
    DailyDataEntry d9("13/01/2020", 1, 25);
    DailyDataEntry d10("14/01/2020", 2, 40);
    DailyDataEntry d11("15/01/2020", 3, 55);

    vector<DailyDataEntry> mockDailyDataEntry = {d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11};

    StatsCalculator testStats(mockDailyDataEntry);

    testStats.calculateDailyAverageOverAWeek();

    REQUIRE(testStats.getDailyAverageOverAWeek()[0].first == "Sunday");
    REQUIRE(testStats.getDailyAverageOverAWeek()[0].second == 0);

    REQUIRE(testStats.getDailyAverageOverAWeek()[1].first == "Monday");
    REQUIRE(testStats.getDailyAverageOverAWeek()[1].second == 24);

    REQUIRE(testStats.getDailyAverageOverAWeek()[2].first == "Tuesday");
    REQUIRE(testStats.getDailyAverageOverAWeek()[2].second == 37);

    REQUIRE(testStats.getDailyAverageOverAWeek()[3].first == "Wednesday");
    REQUIRE(testStats.getDailyAverageOverAWeek()[3].second == 34);

    REQUIRE(testStats.getDailyAverageOverAWeek()[4].first == "Thrusday");
    REQUIRE(testStats.getDailyAverageOverAWeek()[4].second == 37);

    REQUIRE(testStats.getDailyAverageOverAWeek()[5].first == "Friday");
    REQUIRE(testStats.getDailyAverageOverAWeek()[5].second == 40);

    REQUIRE(testStats.getDailyAverageOverAWeek()[6].first == "Saturday");
    REQUIRE(testStats.getDailyAverageOverAWeek()[6].second == 0);
}

TEST_CASE("when dailyDataEntry is used for calculation of hourly average by calculateHourlyAverageOverADay() method then it write hourlyAverageOverADay vector")
{
    DailyDataEntry d1("01/01/2020", 3, 22);
    DailyDataEntry d2("02/01/2020", 4, 34);
    DailyDataEntry d3("03/01/2020", 5, 25);
    DailyDataEntry d4("04/01/2020", 6, 40);
    DailyDataEntry d5("05/01/2020", 0, 55);

    vector<DailyDataEntry> mockDailyDataEntry = {d1, d2, d3, d4, d5};

    StatsCalculator testStats(mockDailyDataEntry);

    //considering 12 as the working hours
    //do roundUp and roundDown according
    testStats.calculateHourlyAverageOverADay();

    REQUIRE(testStats.getHourlyAverageOverADay()[0].first == "01/01/2020");
    REQUIRE(testStats.getHourlyAverageOverADay()[0].second == 2);

    REQUIRE(testStats.getHourlyAverageOverADay()[1].first == "02/01/2020");
    REQUIRE(testStats.getHourlyAverageOverADay()[1].second == 3);

    REQUIRE(testStats.getHourlyAverageOverADay()[2].first == "03/01/2020");
    REQUIRE(testStats.getHourlyAverageOverADay()[2].second == 2);

    REQUIRE(testStats.getHourlyAverageOverADay()[3].first == "04/01/2020");
    REQUIRE(testStats.getHourlyAverageOverADay()[3].second == 3);

    REQUIRE(testStats.getHourlyAverageOverADay()[4].first == "05/01/2020");
    REQUIRE(testStats.getHourlyAverageOverADay()[4].second == 5);
}

TEST_CASE("when all aggregates data is to be converted to csv format by toString() then it returns a string in the csv format having all the aggregate data")
{
    DailyDataEntry d1("02/01/2020", 4, 34);
    DailyDataEntry d2("03/01/2020", 5, 20);
    DailyDataEntry d3("04/01/2020", 6, 25);
    DailyDataEntry d4("05/01/2020", 0, 40);

    vector<DailyDataEntry> mockDailyDataEntry = {d1, d2, d3, d4};

    StatsCalculator testStats(mockDailyDataEntry);

    testStats.findPeakFootfallInLastMonth();
    testStats.calculateDailyAverageOverAWeek();
    testStats.calculateHourlyAverageOverADay();

    string testString = testStats.toString();

    string mockString = "";
    mockString = mockString + "Date,Peak Footfall\n";
    mockString = mockString + "05/01/2020,40\n\n";

    mockString = mockString + "Day,Daily Avearge\n";
    mockString = mockString + "Sunday,40\nMonday,0\nTuesday,0\nWednesday,0\nThrusday,34\nFriday,20\nSaturday,25\n";

    mockString = mockString + "\n";
    mockString = mockString + "Date,Hourly Avearge\n";
    mockString = mockString + "02/01/2020,3\n03/01/2020,2\n04/01/2020,2\n05/01/2020,3\n";

    REQUIRE(testString == mockString);
}

TEST_CASE("When I pass multiline string in writeDataToCSV() then it writes that string in the userdefined name file.")
{
    WriteCSV writeFile("Day,Average\nMonday,25\nTuesday,56\n");

    writeFile.writeDataToCSV("test-output.csv");

    ifstream readFile("test-output.csv");

    string l1;
    string l2;
    string l3;

    getline(readFile, l1);
    getline(readFile, l2);
    getline(readFile, l3);

    REQUIRE(l1 == "Day,Average");
    REQUIRE(l2 == "Monday,25");
    REQUIRE(l3 == "Tuesday,56");
}