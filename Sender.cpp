#include "ReadCSV.h"
#include "SendData.h"
using namespace std;

int main()
{
    string inputCSV = "inputCSV1.csv";
    ReadCSV reader(inputCSV, ",");
    vector<string> dataList = reader.readCSVData();
    SendData sender(dataList);
    vector<string> final_Output = sender.toString(dataList);
    for (int i = 0; i < int(final_Output.size()); i++)
    {
        cout << final_Output.at(i) << endl;
    }

    return 0;
}