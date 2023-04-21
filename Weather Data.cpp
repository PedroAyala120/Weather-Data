//This program will use a structure to store weather data for a particular month and display calculated information about the year
//Pedro Ayala
#include <iostream>

using namespace std;

struct Weather  //struct for weather
{
    int TotalRain;
    int HTemperature;
    int LTemperature;
    int AvgTemperature;
};

int main()  
{
    int nummonths = 12; //number of months
    Weather Months[12]; //array for year

    //Initialize variables
    int Total = 0;
    int LowestT = 0;
    int HighestT = 0;
    int HighestM = 0;
    int LowestM = 0;
    int TotalAvgT = 0;


    //loop for user input
    for (int i = 0; i < nummonths; i++)
    {
        cout << "Enter the total rainfall for month " << i + 1 << ": " << endl;
        cin >> Months[i].TotalRain;
        cout << "Enter the Highest Temperature for month " << i + 1<< ": " << endl;
        cin >> Months[i].HTemperature;
        if (HighestT < Months[i].HTemperature)
        {
            HighestT = Months[i].HTemperature;
            HighestM = i + 1;
        }
        cout << "Enter the lowest Temperature for month " << i + 1 << ": " << endl;
        cin >> Months[i].LTemperature;
        if (LowestT < Months[i].LTemperature)
        {
            LowestT = Months[i].LTemperature;
            LowestM = i + 1;
        }
        //input validation
        if (Months[i].LTemperature < -100 or Months[i].HTemperature > 140 or Months[i].HTemperature < -100 or Months[i].HTemperature > 140)
            i--;
        else
        {
            Months[i].AvgTemperature = (Months[i].HTemperature + Months[i].LTemperature) / 2;
            TotalAvgT = TotalAvgT + Months[i].AvgTemperature;
        }

        Total = Total + Months[i].TotalRain;    //calculate total rainfall

    }

    //////////////////////////
    ////   Display Data  ////
    ////////////////////////
    cout << endl;
    cout << "The total rainfall for the year was: " << Total << " inches" << endl;

    TotalAvgT = TotalAvgT / 12;
    cout << "The average temperature for the year was: " << TotalAvgT << " Degrees" << endl;

    int AvgRain = Total / 12;
    cout << "The average rainfall for the year was: " << AvgRain << " inches" << endl;

    cout << "The lowest temperature was: " << LowestT << " Degrees During month " << LowestM << endl;
    cout << "The Highest temperature was: " << HighestT << " Degrees During month " << HighestM << endl;

    return 0;
}
