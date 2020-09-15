#include "SendData.h"


// Parameterized constructor which takes the reference to a vector that holds the row data of a csv file as a string
SendData ::SendData(const vector<string> &data) : csvData(data) {}

// Member function which returns a vector of all the dates in the csv file
vector<string> SendData ::getDates()
{

    for (int i = 1; i < int(csvData.size()); i++)
    {
        allDates.push_back((csvData.at(i)).substr(0, 10));
    }
    return allDates;
}

// Member function which takes three inputs (date, month , year) and outputs an integer value which corresponds to the day of the week
// This function will return
// 0 - Sunday, 1 - Monday, 2 - Tuesday, .... 6 - Saturday
int SendData ::dayOfWeek(int d, int m, int y)
{

    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    int ans = (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;

    return ans;
}

// Member function which compiles all the integer values represnting the days in a vector form
vector<int> SendData ::getDays(vector<string> dates)
{
    for (int i = 0; i < int(dates.size()); i++)
    {
        vector<int> y_m_d;
        string delimiter = "-";
        size_t pos = 0;
        string token;

        while ((pos = (dates.at(i)).find(delimiter)) != string::npos)
        {
            token = (dates.at(i)).substr(0, pos);
            y_m_d.push_back(stoi(token));
            (dates.at(i)).erase(0, pos + delimiter.length());
        }

        y_m_d.push_back(stoi(dates.at(i)));
        allDays.push_back(dayOfWeek(y_m_d.at(2), y_m_d.at(1), y_m_d.at(0)));
    }

    return allDays;
}

// Member function which returns the number of working days for which data has been recorded that are present in the csv file
int SendData ::getNumberOfDays()
{
    return csvData.size() - 1;
}

// Member function that returns the summation of the elements in an integer vector
int SendData ::summation(vector<int> arr)
{
    int ans = 0;
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        ans += arr[i];
    }
    return ans;
}

// Member function which calculates the total visits per day and stores it in a vector
vector<int> SendData ::getTotalVisitsPerDay(vector<string> dates)
{

    for (int i = 1; i < int(dates.size()); i++)
    {

        int len = (dates.at(i)).length();
        string commaSeperatedEntries = dates.at(i).substr(11, len);
        vector<int> entries;
        string delimiter = ",";
        size_t pos = 0;
        string token;

        while ((pos = (commaSeperatedEntries).find(delimiter)) != string::npos)
        {
            token = (commaSeperatedEntries).substr(0, pos);
            entries.push_back(stoi(token));
            (commaSeperatedEntries).erase(0, pos + delimiter.length());
        }

        entries.push_back(stoi(commaSeperatedEntries));
        totalVisitsPerDay.push_back(summation(entries));
    }
    return totalVisitsPerDay;
}

// Member function which stores the final output that the sender will send to the pipeline. 
// The format of each string that is appended into the vector is as follows :
// "yyyy-mm-dd day_value_in_int total_visits_in_that_day"
vector<string> SendData ::toString(const vector<string> &dataList)
{
    vector<string> dates = getDates();
    vector<int> days = getDays(dates);
    vector<int> total = getTotalVisitsPerDay(dataList);

    finalOutput.push_back(to_string(getNumberOfDays()));
    for (int i = 0; i < int(dates.size()); i++)
    {
        string row = dates.at(i) + " " + to_string(days.at(i)) + " " + to_string(total.at(i));
        finalOutput.push_back(row);
    }
    return finalOutput;
}
