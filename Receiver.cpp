#include <iostream>
#include <string>
using namespace std;

#include "funR.h"

int main(){

    int x = funR(3);
    cout<<x<<endl;

    string numberOfDaysString;
    getline(cin, numberOfDaysString);
    int numberOfDays = stoi(numberOfDaysString);
    for(int i=0; i<numberOfDays; i++){
        string dailyEntry;
        getline(cin, dailyEntry);
        cout<<dailyEntry<<endl;
    }
    cout<<numberOfDays<<endl;
    return 0;
}