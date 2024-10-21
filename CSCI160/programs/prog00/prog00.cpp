//Christopher 'Jack' Nilssen 577990765
//Lab 0: Applied programming exercise
//Computes and displays the number of seconds in one week
//v0. 09-16-2016

#include <cstdio>

int main()
{
    //four integer constants
    const int DaysInWeek = 7; //days in a week
    const int HoursInDay = 24;//hours in a day
    const int MinutesInHour = 60; //minutes in an hour
    const int SecondsInMinute = 60; //seconds in a minute

    //result of product of consts
    int totalSecondsInWeek;
    
    //compute product
    totalSecondsInWeek = DaysInWeek * HoursInDay * MinutesInHour * SecondsInMinute;
    
    //print result to screen
    printf("\nThere are %d seconds in a week. Don't waste them.\n\n", totalSecondsInWeek);

    return 0;
}
