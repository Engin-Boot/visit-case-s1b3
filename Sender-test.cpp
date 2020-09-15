#define CATCH_CONFIG_MAIN
#include "ReadCSV.h"
#include "SendData.h"
#include <iostream>
#include "catch.hpp"
#include <string>
#include <vector>

using namespace std;

TEST_CASE("When a CSV file is passed to the ReadCSV class, this method stores each row as a string")
{

    string inputCSV = "test-input.csv";
    ReadCSV reader(inputCSV, ",");
    vector<string> dataList = reader.readCSVData();
    REQUIRE(dataList[0] == "Date,entry1,entry2,entry3");
    REQUIRE(dataList[1] == "1998-12-21,2,2,2");
    REQUIRE(dataList[2] == "1996-11-05,3,4,5");
    REQUIRE(dataList[3] == "2020-09-13,10,23,12");
}

TEST_CASE("When we get a csv file in the format of *Date,entry1,entry2,entry3*, the function appends only the dates into the vector")
{
    string inputCSV = "test-input.csv";
    ReadCSV reader(inputCSV, ",");
    vector<string> dataList = reader.readCSVData();
    SendData sender(dataList);
    vector<string> dates = sender.getDates();

    REQUIRE(dates[0] == "1998-12-21");
    REQUIRE(dates[1] == "1996-11-05");
    REQUIRE(dates[2] == "2020-09-13");
}

TEST_CASE("When we pass a random date in the dd-mm-yyyy format, the function returns ")
{
    vector<int> day1;
    day1.push_back(21);
    day1.push_back(12);
    day1.push_back(1998);

    vector<int> day2;
    day2.push_back(5);
    day2.push_back(11);
    day2.push_back(1996);

    vector<int> day3;
    day3.push_back(13);
    day3.push_back(9);
    day3.push_back(2020);

    string inputCSV = "test-input.csv";
    ReadCSV reader(inputCSV, ",");
    vector<string> dataList = reader.readCSVData();
    SendData sender(dataList);

    REQUIRE(sender.dayOfWeek(day1[0], day1[1], day1[2]) == 1);
    REQUIRE(sender.dayOfWeek(day2[0], day2[1], day2[2]) == 2);
    REQUIRE(sender.dayOfWeek(day3[0], day3[1], day3[2]) == 0);
}

TEST_CASE("When we pass a vector of string where each string is a date of the format *yyyy-mm-dd*, we get a vector of int which have the corresponding day values")
{

    string inputCSV = "test-input.csv";
    ReadCSV reader(inputCSV, ",");
    vector<string> dataList = reader.readCSVData();
    SendData sender(dataList);
    vector<string> dates;
    dates.push_back("1998-12-21");
    dates.push_back("1996-11-05");
    dates.push_back("2020-09-13");

    vector<int> days = sender.getDays(dates);
    REQUIRE(days[0] == 1);
    REQUIRE(days[1] == 2);
    REQUIRE(days[2] == 0);
}

TEST_CASE("When we send a csv file with each row having Date,entry1,entry2,entry3 ..... , the function returns the number of working days")
{

    string inputCSV = "test-input.csv";
    ReadCSV reader(inputCSV, ",");
    vector<string> dataList = reader.readCSVData();
    SendData sender(dataList);
    REQUIRE(sender.getNumberOfDays() == 3);
}

TEST_CASE("Given a vector which contains integers, the function returns the sum of all the integers")
{

    string inputCSV = "test-input.csv";
    ReadCSV reader(inputCSV, ",");
    vector<string> dataList = reader.readCSVData();
    SendData sender(dataList);
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    REQUIRE(sender.summation(arr) == 60);
}

TEST_CASE("Given a row of the csv file, this function will calculate the sum of all the entries in that row and store it in a vector")
{
    string inputCSV = "test-input.csv";
    ReadCSV reader(inputCSV, ",");
    vector<string> dataList = reader.readCSVData();
    SendData sender(dataList);
    vector<int> total = sender.getTotalVisitsPerDay(dataList);
    REQUIRE(total[0] == 6);
    REQUIRE(total[1] == 12);
    REQUIRE(total[2] == 45);
}

TEST_CASE("Given a csv file which has a format of date, entry1, entry2, entry3 .... , this function will first append the number  of working days in that csv file and then append for each row, another string which will correspond to the *Date Day TotalVisits*")
{
    string inputCSV = "test-input.csv";
    ReadCSV reader(inputCSV, ",");
    vector<string> dataList = reader.readCSVData();
    SendData sender(dataList);
    vector<string> finalAns = sender.toString(dataList);
    REQUIRE(finalAns[0] == "3");
    REQUIRE(finalAns[1] == "1998-12-21 1 6");
    REQUIRE(finalAns[2] == "1996-11-05 2 12");
    REQUIRE(finalAns[3] == "2020-09-13 0 45");
}