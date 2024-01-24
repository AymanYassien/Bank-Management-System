//
// Created by Ayman yassien on 09/12/2023 AD.
//

#pragma warning(disable : 4996)
#pragma once

#include <iostream>
#include <vector>
#include <string>

//#include "clsString.h"

using namespace std;

class clsDate {

    // check code
private:
    short _day = 1;
    short _month = 1;
    short _year = 1990;

public:

    clsDate()
    {
        ::time_t t =time(0);// zero not necessary
        tm* now = ::localtime(&t);//used to convert the time stored in the time_t variable t into a tm structure,
        // which contains various fields such as year,

        _year = now->tm_year + 1900; // number of years since 1900, so add 1900 to get the actual year.
        _month = now->tm_mon + 1; // which is 0-based (0 for January), so add 1 to get the actual month.
        _day = now->tm_mday ;
    }

    clsDate(string date)
    {
        vector <string> vDate;
        vDate = splitString(date, "/");
        _day = stoi(vDate[0]);
        _month = stoi(vDate[1]);
        _year = stoi(vDate[2]);

        //_date = stringToDate(date);
    }

    clsDate(short numberOfDay, short year)
    {
//        clsDate date1 = addDaysOnCurrentDay(numberOfDay);
        clsDate date1 = getDateFromDayOrderInYear(numberOfDay, year);
        _day = date1._day;
        _month = date1._month;
        _year = date1._year;
    }

    clsDate(short day, short month, short year)
    {
        _day = day;
        _month = month;
        _year = year;
    }

    void setDay(short day )
    {
        _day = day;
    }
    short getDay()
    {
        return _day;
    }

    void setMonth (short month)
    {
        _month = month;
    }
    short getMonth()
    {
        return _month;
    }

    void setYear(short year)
    {
        _year = year;
    }
    short getYear()
    {
        return _year;
    }

    void print()
    {
        cout << convertDateStructToString() << endl;
    }

    //_________________________________________________________________________________________________________________

    static string checkLeapYear(short year){

        string isLeap = "Not Leap";

        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            isLeap = "Leap";
        return isLeap;

    }
    string checkLeapYear(){
        return checkLeapYear(_year);
    }

    static bool isLeapYear(short year){

        return (year % 4 == 0&& year % 100 != 0) || (year % 400 == 0);
    }
    bool isLeapYear(){
        return isLeapYear(_year);
    }

    static short numberOfDaysInMonth(short month, short year){

//    if (month == 2)
//        return isLeapYear(year) ? 29 : 28;
//    return (month == 4 || month == 6 || month == 9 || month == 11)  ? 30 : 31;

        // other nice solve
        int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        return (month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];

    }
    short numberOfDaysInMonth(){
        return numberOfDaysInMonth(_month, _year);
    }

    static short findDAyOrder(short day, short month, short year){
        short dayIndex, a, y, m, d;
        dayIndex = 0;
        a = (14 - month) / 12;
        y = year - a;
        m = month + 12 * a - 2;
        d = (day + y + (y / 4) - (y / 100 ) + (y / 400 ) + (31 * m / 12)) % 7 ;

        dayIndex = d;
        return dayIndex;

    }
    short findDAyOrder(){
        return findDAyOrder(_day, _month, _year);
    }

    static string convertDayIndexToDay(short dayIndex){

        string days[7] {"Sunday", "Monday", "TuesDay", "WednesdayDay", "Thursday", "Friday", "Saturday"};

        return days[dayIndex];
    }

    static void printDayCard(short day, short month, short year, short dayIndex){

        cout << "Date      :" << day << '/' << month << '/' << year << endl;
        cout << "Day Order : " << dayIndex << endl;
        cout << "Day Name  : " << convertDayIndexToDay(dayIndex) << endl;

    }
    void printDayCard(short dayIndex){
        return printDayCard(_day, _month, _year, dayIndex);
    }

    static bool isDate1BeforeDate2(clsDate date1, clsDate date2){
        return (date1._year < date2._year) || ((date1._year == date2._year) ?
                                               (date1._month < date2._month ?
                                                true :
                                                (date1._month == date2._month ?
                                                 date1._day < date2._day :
                                                 false)) :
                                               false);

        return  (date1._year < date2._year) ? true : ((date1._year == date2._year) ? (date1._month < date2._month ? true :
                                                                                      (date1._month == date2._month ? date1._day < date2._day : false)) : false);
    }
    bool isDate1BeforeDate2(clsDate date2){
        return isDate1BeforeDate2(* this, date2);
    }

    static bool isDate1EqualDate2(clsDate date1, clsDate date2){

        return (date1._year == date2._year)? ((date1._month == date2._month)? ((date1._day == date2._day) ? 1 : 0) : 0):0;

//    return (date1._year == date2._year)? ((date1._month == date2._month)? date1._day == date2._day: 0):0;
//    return (date1._year == date2._year && date1._month == date2._month && date1._day == date2._day) ;
    }
    bool isDate1EqualDate2(clsDate date2){
        return isDate1EqualDate2(* this, date2);
    }

    static string monthShortName(short monthNumber){

        string months[12] {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
                           "Aug", "Sep", "Oct", "Nov", "Dec"};

        return months[monthNumber - 1];
    }
    string monthShortName(){
        return monthShortName(_month);
    }

    static short findFirstDayInMonth(short month, short year){
        return findDAyOrder(1, month, year);
    }
    short findFirstDayInMonth(){
        return findFirstDayInMonth(_month, _year);
    }

    static void printMonthCalender(short monthNumber, short year){

        short numberOfDays = numberOfDaysInMonth(monthNumber, year);
        short firstDayIndex = findFirstDayInMonth(monthNumber, year);

//       .c_str() is used to convert the returned string from monthShortName to a C-style string,
//    which is compatible with the %s format specifier used in printf.
//       %s: This is a format specifier used to insert a string into the formatted output.
        printf("\n _______________%s_______________\n\n", monthShortName(monthNumber).c_str());

        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        short i;
        for (i = 0; i < firstDayIndex; ++i)
            printf("     "); // print sets of spaces be4 first day
        for (short j = 1; j <= numberOfDays; ++j) {
            printf("%5d", j); // %5d = book 5 spaces for int num, this num is j,, if j is float d 'll change

            if (++i == 7)
                i = 0, printf("\n");
        }

        printf("\n_________________________________\n");

// ______________________________________________________________________________________
//    bool isSetFirstDay = false;  short counter = 0;
//    for (int i = 0; i < numberOfDays; ++i) {
//        counter++;
//
//        if (i == firstDayIndex)
//            i = 0, firstDayIndex = -1, isSetFirstDay = true;
//        if (!isSetFirstDay)
//            cout << "    ";
//        if (isSetFirstDay)
//            cout << " " << setw(2) << i + 1 << " ";
//        if (counter % 7 == 0)
//            cout << '\n';
//
// ______________________________________________________________________________________

    }
    void printMonthCalender(){
        return printMonthCalender(_month, _year);
    }

    static void printYearCalender( short year){

        printf("\n____________________________________\n");
        printf("           Calender - %d ", year);
        printf("\n____________________________________\n");

        for (short i = 1; i <= 12; ++i)
            printMonthCalender(i, year);

        return;
    }
    void printYearCalender(){
        return printYearCalender(_year);
    }

    static clsDate addDaysOnCurrentDay(short day, short month, short year, short daysToAdd){

        // for each 4 years the cycle is repeat 365 - 365 - 365- 366 .. so we add this directly then handle others
        short remainder;
        if(daysToAdd > 1461)
            remainder = daysToAdd / 1461,
            daysToAdd -= 1461 * remainder,
            year += 4 * remainder;

// month < 2 || (month == 2 && day < 29 )

        while (true){
            if (daysToAdd > 365)
                if (month < 2 || (month == 2 && day < 29 ))
                    if (isLeapYear(year))
                        year++, daysToAdd -= 366;
                    else
                        year++, daysToAdd -= 365;
                else
                if (isLeapYear(year + 1))
                    year++, daysToAdd -= 366;
                else
                    year++, daysToAdd -= 365;
            else
                break;
        }

        while(day + daysToAdd > numberOfDaysInMonth(month, year)){
            short currentCanAdd = numberOfDaysInMonth(month, year) - day;
            if (currentCanAdd > daysToAdd)
                day += daysToAdd, daysToAdd -= currentCanAdd +1, day = 1, currentCanAdd = 0;
            else
                day += currentCanAdd,daysToAdd -= currentCanAdd +1, day = 1, currentCanAdd = 0;
            if (month == 12)
                month = 1, year ++;
            else
                month ++ ;
        }
        day += daysToAdd;

        clsDate newDate;
        newDate._year = year;
        newDate._month = month;
        newDate._day = day;

        return newDate;

    }
    clsDate addDaysOnCurrentDay(short daysToAdd){
        return addDaysOnCurrentDay(_day, _month, _year, daysToAdd);
    }

    static bool isLastDayInMonth(short day, short month, short year){
        return numberOfDaysInMonth(month, year) == day;
    }
    bool isLastDayInMonth(){
        return isLastDayInMonth( _day, _month, _year);
    }

    static bool isLastMonthInYear(short month){
        return month == 12;
    }
    bool isLastMonthInYear()
    {
        return isLastMonthInYear(_month);
    }

    static bool isFirstMonthInYear(short month){
        return month == 1;
    }
    bool isFirstMonthInYear (){
        return isFirstMonthInYear(_month);
    }

    static clsDate increaseDateByOne(clsDate & currentDate ){
        clsDate newDate;

        isLastDayInMonth(currentDate._day, currentDate._month, currentDate._year) ? newDate._day = 1
                                                                                  :newDate._day ++;

        isLastMonthInYear(currentDate._month) ? (newDate._month = 1, newDate._year = currentDate._year + 1)
                                              : (newDate._month++, newDate._year = currentDate._year);

        return newDate;
    }
    void increaseDateByOne(){
        increaseDateByOne(* this);
    }

    static short numberOfDaysFromTheBeginningOfTheYear( clsDate date) {
        short totalDays = 0;
        for (int i = 1; i <= date._month - 1; i++)
            totalDays += numberOfDaysInMonth(i, date._year);
        totalDays += date._day;
        return totalDays;
    }
    short numberOfDaysFromTheBeginningOfTheYear(){
        return numberOfDaysFromTheBeginningOfTheYear(* this);
    }

    static int calculateDifferenceBetweenTowDates(clsDate date1, clsDate date2){

        int different = 0;

        if (date1._year == date2._year){
            different = numberOfDaysFromTheBeginningOfTheYear(date2) - numberOfDaysFromTheBeginningOfTheYear(date1);
            return different;
        }else{
            if (isLeapYear(date1._year)){
                different = 366 - numberOfDaysFromTheBeginningOfTheYear(date1);
                date1._year++;
            }
            else{
                different = 365 - numberOfDaysFromTheBeginningOfTheYear(date1);
                date1._year++;
            }
        }

        while (date2._year > date1._year){
            different += (isLeapYear(date1._year)) ? 366 : 365;
            date1._year++;
        }

        different += numberOfDaysFromTheBeginningOfTheYear(date2);

        return different;
    }

    static clsDate getSystemDate(){
        clsDate date;

        ::time_t t =time(0);// zero not necessary
        tm* now = ::localtime(&t);//used to convert the time stored in the time_t variable t into a tm structure,
        // which contains various fields such as year,

        date._year = now->tm_year + 1900; // number of years since 1900, so add 1900 to get the actual year.
        date._month = now->tm_mon + 1; // which is 0-based (0 for January), so add 1 to get the actual month.
        date._day = now->tm_mday ;

        return date;
    }

    static string getSystemDateAndTimeString()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        short day, month, year, hour, minute, second;

        year   = now->tm_year + 1900;
        month  = now->tm_mon + 1;
        day    = now->tm_mday;
        hour   = now->tm_hour;
        minute = now->tm_min;
        second = now->tm_sec;

        return (to_string(day) + "/" + to_string(month) + "/"
                + to_string(year) + " - "
                + to_string(hour) + ":" + to_string(minute)
                + ":" + to_string(second));
    }

    static int calculateAgeInDays(clsDate dateOfBirth ){
        int different = 0;
        clsDate date2 = getSystemDate();

        if (dateOfBirth._year == date2._year){
            different = numberOfDaysFromTheBeginningOfTheYear(date2) - numberOfDaysFromTheBeginningOfTheYear(dateOfBirth);
            return different;
        }else{
            if (isLeapYear(dateOfBirth._year)){
                different = 366 - numberOfDaysFromTheBeginningOfTheYear(dateOfBirth);
                dateOfBirth._year++;
            }
            else{
                different = 365 - numberOfDaysFromTheBeginningOfTheYear(dateOfBirth);
                dateOfBirth._year++;
            }
        }

        while (date2._year > dateOfBirth._year){
            different += (isLeapYear(dateOfBirth._year)) ? 366 : 365;
            dateOfBirth._year++;
        }

        different += numberOfDaysFromTheBeginningOfTheYear(date2);

        return different;
    }

    static void swapDates(clsDate &date1, clsDate date2)
    {
        clsDate temp ;
        temp = date1;
        date1 = date2;
        date2 = temp;
    }

    //_________________________________________________________________________________________________________________

    static clsDate increaseDateByXDays(clsDate & currentDate, short daysToAdd = 10 ){
        clsDate newDate = currentDate;

        for (int i = 0; i < daysToAdd; ++i) {
            newDate = increaseDateByOne( newDate);
        }

        return newDate;
    }
    void increaseDateByXDays(short daysToAdd = 10 ){
        increaseDateByXDays(* this, daysToAdd);
    }

    static clsDate increaseDateByOneWeek(clsDate & currentDate){
        clsDate newDate; newDate = currentDate;

        if (currentDate._day + 7 <= numberOfDaysInMonth(currentDate._month, currentDate._year))
            newDate._day+=7;
        else{
            newDate._day = (numberOfDaysInMonth(currentDate._month, currentDate._year) - newDate._day) * -1 + 7;
            isLastMonthInYear(currentDate._month) ? (newDate._month = 1, newDate._year = currentDate._year + 1)
                                                  : newDate._month++;
        }


        return newDate;
    }
    void increaseDateByOneWeek(){
        increaseDateByOneWeek(* this);
    }

    static clsDate increaseDateByXWeek(clsDate & currentDate, short weeksToAdd = 10){
        clsDate newDate; newDate = currentDate;

        for (int i = 0; i < weeksToAdd; ++i) {
            newDate = increaseDateByOneWeek(newDate);
        }

        return newDate;
    }
    void increaseDateByXWeek( short weeksToAdd = 10){
        increaseDateByXWeek(* this, weeksToAdd);
    }

    static clsDate increaseDateByOneMonth(clsDate & date){

        if (isLastMonthInYear(date._month))
            date._month = 1, date._year++;
        else if (numberOfDaysInMonth(date._month + 1, date._year) < date._day)
            date._day = numberOfDaysInMonth(date._month + 1, date._year), date._month ++;
        else
            date._month ++;

        return date;
    }
    void increaseDateByOneMonth(){
        increaseDateByOneMonth(* this);
    }

    static clsDate increaseDateByXMonth(clsDate & date, short monthsToAdd = 5){

        for (int i = 0; i < monthsToAdd; ++i)

            if (isLastMonthInYear(date._month))
                date._month++, date._year++;
            else if (numberOfDaysInMonth(date._month + 1, date._year) < date._day)
                date._day = numberOfDaysInMonth(date._month + 1, date._year), date._month ++;
            else
                date._month ++;


        return date;
    }
    void increaseDateByXMonth(short monthsToAdd = 5){
        increaseDateByXMonth(*this, monthsToAdd);
    }

    static clsDate increaseDateByOneYear(clsDate & date){

        if (date._day == 29 && date._month == 2)
            date._day --, ++date._year;
        else
            ++date._year;
        return date;
    }
    void increaseDateByOneYear(){
        increaseDateByOneYear(* this);
    }

    static clsDate increaseDateByXYear(clsDate & date, short yearsToAdd = 10){

        for (int i = 0; i < yearsToAdd; ++i){
            if (date._day == 29 && date._month == 2)
                date._day --, ++date._year;
            else
                ++date._year;
        }

        return date;
    }
    void increaseDateByXYear(short yearsToAdd = 10){
        increaseDateByXYear(* this, yearsToAdd);
    }

    static clsDate increaseDateByXYear_Faster(clsDate & date, short yearsToAdd = 10){

        (!isLeapYear(date._year + yearsToAdd) && date._day == 29 && date._month == 2) ? date._day-=1,date._year += yearsToAdd
                                                                                      : date._year += yearsToAdd;
        return date;
    }
    void increaseDateByXYear_Faster(short yearsToAdd = 10){
        increaseDateByXYear_Faster(* this,yearsToAdd);
    }

    static clsDate increaseDateByOneDecade(clsDate & date){

        (!isLeapYear(date._year + 10) && date._day == 29 && date._month == 2) ? date._day-=1,date._year += 10
                                                                              : date._year += 10;
        return date;
    }
    void increaseDateByOneDecade(){
        increaseDateByOneDecade(* this);
    }

    static clsDate increaseDateByXDecade(clsDate & date, short decadesToAdd = 10){

        (!isLeapYear(date._year + 10) * decadesToAdd && date._day == 29 && date._month == 2) ?
        date._day-=1,date._year += 10 * decadesToAdd
                                                                                             : date._year += 10 * decadesToAdd;
        return date;
    }
    void increaseDateByXDecade(short decadesToAdd = 10){
        increaseDateByXDecade(* this, decadesToAdd);
    }

    static clsDate increaseDateByOneCentury(clsDate & date){

        (!isLeapYear(date._year + 100) && date._day == 29 && date._month == 2) ? date._day-=1,date._year += 100
                                                                               : date._year += 100;
        return date;
    }
    void increaseDateByOneCentury(){
        increaseDateByOneCentury(* this);
    }

    static clsDate increaseDateByOneMillennium(clsDate &date){

        (!isLeapYear(date._year + 1000) && date._day == 29 && date._month == 2) ? date._day-=1,date._year += 1000
                                                                                : date._year += 1000;
        return date;
    }
    void increaseDateByOneMillennium(){
        increaseDateByOneMillennium(* this);
    }

    static void printDatesAfterIncrement(clsDate currentDate){

        cout << "\nDate After: ";

        currentDate = increaseDateByOne(currentDate);
        cout << "\n01-Adding one Day is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = increaseDateByXDays(currentDate);
        cout << "\n02-Adding 10 Days is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = increaseDateByOneWeek(currentDate);
        cout << "\n03-Adding one Week is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = increaseDateByXWeek(currentDate);
        cout << "\n04-Adding 10 Weeks is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = increaseDateByOneMonth(currentDate);
        cout << "\n05-Adding one Month is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = increaseDateByXMonth(currentDate);
        cout << "\n06-Adding 5 Months is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = increaseDateByOneYear(currentDate);
        cout << "\n07-Adding one Year is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = increaseDateByXYear(currentDate);
        cout << "\n08-Adding 10 Years is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = increaseDateByXYear_Faster(currentDate);
        cout << "\n09-Adding 10 years (faster) is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = increaseDateByOneDecade(currentDate);
        cout << "\n10-Adding one Decade is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = increaseDateByXDecade(currentDate);
        cout << "\n11-Adding 10 Decades is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = increaseDateByXDecade(currentDate);
        cout << "\n12-Adding 10 Decades (faster)is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = increaseDateByOneCentury(currentDate);
        cout << "\n13-Adding one Century is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = increaseDateByOneMillennium(currentDate);
        cout << "\n14-Adding one Millennium is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;


    }
    void printDatesAfterIncrement(){
        return printDatesAfterIncrement(* this);
    }

    //_________________________________________________________________________________________________________________

    static clsDate decrementDateByOneDay(clsDate & currentDate){
        clsDate newDate = currentDate;

        (currentDate._day == 1) ?
        (isFirstMonthInYear(currentDate._month) ?
         newDate._month = 12, newDate._year --, newDate._day = 31
                                                : newDate._month --, newDate._day = numberOfDaysInMonth(newDate._month,newDate._year))
                                :newDate._day --;

        return newDate;
    }
    clsDate decrementDateByOneDay(){
        return decrementDateByOneDay(* this);
    }

    static clsDate decrementDateByXDays(clsDate & currentDate, short daysToSubtract = 10){
        clsDate newDate = currentDate;

        for (int i = 0; i < daysToSubtract; ++i) {
            newDate = decrementDateByOneDay(newDate);
        }

        return newDate;
    }
    void decrementDateByXDays(short daysToSubtract = 10){
        decrementDateByXDays(* this);
    }

    static clsDate decrementDateByOneWeek(clsDate & currentDate){
        clsDate newDate; newDate = currentDate;

        if (currentDate._day - 7 > 1)
            newDate._day-=7;
        else{
            isFirstMonthInYear(currentDate._month) ? (newDate._month = 12, newDate._year = currentDate._year - 1)
                                                   : newDate._month--;
            newDate._day = newDate._day - 7 + numberOfDaysInMonth(currentDate._month , currentDate._year);
        }


        return newDate;
    }
    void decrementDateByOneWeek(){
        decrementDateByOneWeek(* this);
    }

    static clsDate decrementDateByXWeek(clsDate & currentDate, short weeksToSubtract = 10){
        clsDate newDate; newDate = currentDate;

        for (int i = 0; i < weeksToSubtract; ++i) {
            newDate = decrementDateByOneWeek(newDate);
        }

        return newDate;
    }
    void decrementDateByXWeek(short weeksToSubtract = 10){
        decrementDateByXWeek(* this, weeksToSubtract);
    }

    static clsDate decrementDateByOneMonth(clsDate & date){

        if (isFirstMonthInYear(date._month))
            date._month = 12, date._year--;
        else if (numberOfDaysInMonth(date._month - 1, date._year) < date._day)
            date._day = numberOfDaysInMonth(date._month - 1, date._year), date._month --;
        else
            date._month --;

        return date;
    }
    void decrementDateByOneMonth(){
        decrementDateByOneMonth(* this);
    }

    static clsDate decrementDateByXMonth(clsDate & date, short monthsToSubtract = 5){

        for (int i = 0; i < monthsToSubtract; ++i)

            if (isLastMonthInYear(date._month))
                date._month++, date._year++;
            else if (numberOfDaysInMonth(date._month - 1, date._year) < date._day)
                date._day = numberOfDaysInMonth(date._month - 1, date._year), date._month --;
            else
                date._month --;


        return date;
    }
    void decrementDateByXMonth(short monthsToSubtract = 5){
        decrementDateByXMonth(* this);
    }

    static clsDate decrementDateByOneYear(clsDate & date){

        if (date._day == 29 && date._month == 2)
            date._day --, --date._year;
        else
            --date._year;
        return date;
    }
    void decrementDateByOneYear(){
        decrementDateByOneYear(* this);
    }

    static clsDate decrementDateByXYear(clsDate & date, short yearsToSubtract = 10){

        for (int i = 0; i < yearsToSubtract; ++i){
            if (date._day == 29 && date._month == 2)
                date._day --, --date._year;
            else
                --date._year;
        }

        return date;
    }
    void decrementDateByXYear(short yearsToSubtract = 10){
        decrementDateByXYear(* this, yearsToSubtract);
    }

    static clsDate decrementDateByXYear_Faster(clsDate & date, short yearsToSubtract = 10){

        (!isLeapYear(date._year - yearsToSubtract) && date._day == 29 && date._month == 2) ? date._day-=1,date._year -= yearsToSubtract
                                                                                           : date._year -= yearsToSubtract;
        return date;
    }
    void decrementDateByXYear_Faster(short yearsToSubtract = 10){
        decrementDateByXYear_Faster(* this, yearsToSubtract = 10);
    }

    static clsDate decrementDateByOneDecade(clsDate & date){

        (!isLeapYear(date._year - 10) && date._day == 29 && date._month == 2) ? date._day-=1,date._year -= 10
                                                                              : date._year -= 10;
        return date;
    }
    void decrementDateByOneDecade(){
        decrementDateByOneDecade(* this);
    }

    static clsDate decrementDateByXDecade(clsDate & date, short decadesToAdd = 10){

        (!isLeapYear(date._year - 10) * decadesToAdd && date._day == 29 && date._month == 2) ?
        date._day-=1,date._year -= 10 * decadesToAdd
                                                                                             : date._year -= 10 * decadesToAdd;
        return date;
    }
    void decrementDateByXDecade(short decadesToAdd = 10){
        decrementDateByXDecade(* this, decadesToAdd);
    }

    static clsDate decrementDateByOneCentury(clsDate & date){

        (!isLeapYear(date._year - 100) && date._day == 29 && date._month == 2) ? date._day-=1,date._year -= 100
                                                                               : date._year -= 100;
        return date;
    }
    void decrementDateByOneCentury(){
        decrementDateByOneCentury (* this);
    }

    static clsDate decrementDateByOneMillennium(clsDate & date){

        (!isLeapYear(date._year - 1000) && date._day == 29 && date._month == 2) ? date._day-=1,date._year -= 1000
                                                                                : date._year -= 1000;
        return date;
    }
    void decrementDateByOneMillennium(){
        decrementDateByOneMillennium(* this);
    }

    clsDate getDateFromDayOrderInYear(short dateOrderInYear, short year)
    {

        clsDate date;
        short remainingDays = dateOrderInYear;
        short monthDays = 0;

        date._year = year;
        date._month = 1;

        while (true)
        {
            monthDays = numberOfDaysInMonth(date._month, year);

            if (remainingDays > monthDays)
            {
                remainingDays -= monthDays;
                date._month++;
            }
            else
            {
                date._day = remainingDays;
                break;
            }

        }

        return date;
    }

    static void printDatesAfterDecrement(clsDate & currentDate){

        cout << "\nDate After: ";

        currentDate = decrementDateByOneDay(currentDate);
        cout << "\n01-subtracting one Day is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = decrementDateByXDays(currentDate);
        cout << "\n02-subtracting 10 Days is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = decrementDateByOneWeek(currentDate);
        cout << "\n03-subtracting one Week is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = decrementDateByXWeek(currentDate);
        cout << "\n04-subtracting 10 Weeks is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = decrementDateByOneMonth(currentDate);
        cout << "\n05-subtracting one Month is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = decrementDateByXMonth(currentDate);
        cout << "\n06-subtracting 5 Months is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = decrementDateByOneYear(currentDate);
        cout << "\n07-subtracting one Year is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = decrementDateByXYear(currentDate);
        cout << "\n08-subtracting 10 Years is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = decrementDateByXYear_Faster(currentDate);
        cout << "\n09-subtracting 10 years (faster) is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = decrementDateByOneDecade(currentDate);
        cout << "\n10-subtracting one Decade is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = decrementDateByXDecade(currentDate);
        cout << "\n11-subtracting 10 Decades is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = decrementDateByXDecade(currentDate);
        cout << "\n12-subtracting 10 Decades (faster)is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = decrementDateByOneCentury(currentDate);
        cout << "\n13-subtracting one Century is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        currentDate = decrementDateByOneMillennium(currentDate);
        cout << "\n14-subtracting one Millennium is: " << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;


    }
    void printDatesAfterDecrement(){
        return printDatesAfterDecrement(* this);
    }

    //_________________________________________________________________________________________________________________

    static short dayOfWeekOrder(clsDate date){
        return findDAyOrder(date._day, date._month, date._year);
    }
    short dayOfWeekOrder(){
        return dayOfWeekOrder(* this);
    }

    static bool isEndOfWeek(clsDate date){
        return dayOfWeekOrder(date) == 6;
    }
    bool isEndOfWeek()
    {
        return isEndOfWeek(*this);
    }

    static void printsEndOfWeek(clsDate date){
        cout << "\n\nIs it End of Week?\n" ;
        if (isEndOfWeek(date))
            cout << "Yes It is " ;
        else
            cout << "No Not ";
        cout << "end of Week.\n";

    }

    static bool isWeekEnd(clsDate date){
        return dayOfWeekOrder(date) == 6
               || dayOfWeekOrder(date) == 5;
    }
    bool isWeekEnd()
    {
        return isWeekEnd(*this);
    }

    static void printIsWeekend (clsDate date){
        cout << "Is it Weekend?\n" ;
        if (isWeekEnd(date))
            cout << "Yes It is " ;
        else
            cout << "No Not " ;
        cout << "a weekend.\n";
    }

    static bool isBusinessDay(clsDate date){
        return !(dayOfWeekOrder(date) == 6 || dayOfWeekOrder(date) == 5);
    }
    bool isBusinessDay(){
        return isBusinessDay(*this);
    }

    static void printIsBusinessDay(clsDate date ){

        cout << "Is it business day?\n" ;

        if(isBusinessDay(date))
            cout << "Yes It is " ;
        else
            cout << "No Not " ;

        cout << "a business day.\n";
    }

    static short daysToEndOfWeek(clsDate date ){

        return 6 - dayOfWeekOrder(date);
    }
    short daysToEndOfWeek(){
        return daysToEndOfWeek(*this);
    }

    static short daysToEndOfMonth(clsDate date){

        return numberOfDaysInMonth(date._month, date._year) - date._day + 1;
    }
    short daysToEndOfMonth(){
        return daysToEndOfMonth(* this);
    }

    static short daysToEndOfYear(clsDate date){
        short toEndOfCurrentMonth = daysToEndOfMonth(date);
        while (date._month + 1 <= 12){
            toEndOfCurrentMonth += numberOfDaysInMonth(date._month + 1, date._year);
            date._month ++;
        }
        return toEndOfCurrentMonth;
    }
    short daysToEndOfYear(){
        return daysToEndOfYear(* this);
    }

    static void printDatesAfterWeekStatistics(clsDate currentDate){

        short dayIndex = dayOfWeekOrder(currentDate);
        short toEndMonth = daysToEndOfMonth(currentDate);

        cout << "\nToday is " << convertDayIndexToDay(dayIndex) << " , "
             << currentDate._day << '/' << currentDate._month << '/' << currentDate._year;

        printsEndOfWeek(currentDate);
        printIsWeekend(currentDate);
        printIsBusinessDay(currentDate);

        cout << "\nDays until end of week : " << daysToEndOfWeek(currentDate) << " Day(s).";
        cout << "\nDays until end of month : " << daysToEndOfMonth(currentDate) << " Day(s).";
        cout << "\nDays until end of year : " <<   daysToEndOfYear(currentDate)<< " Day(s).";
//        daysToEndOfYear(currentDate, toEndMonth)


    }
    void printDatesAfterWeekStatistics(){
        return printDatesAfterWeekStatistics(* this);
    }

    static short calculateBusinessDays(clsDate DateFrom, clsDate DateTo)
    {

        short Days = 0;
        while (isDate1BeforeDate2(DateFrom, DateTo))
        {
            if (isBusinessDay(DateFrom))
                Days++;

            DateFrom = increaseDateByOne(DateFrom);
        }

        return Days;

    }

    static short calculateVacationDays(clsDate DateFrom, clsDate DateTo)
    {
        /*short Days = 0;
        while (IsDate1BeforeDate2(DateFrom, DateTo))
        {
            if (IsBusinessDay(DateFrom))
                Days++;

            DateFrom = AddOneDay(DateFrom);
        }*/

        return calculateBusinessDays(DateFrom, DateTo);

    }

    static clsDate calculateVacationReturnDate(clsDate dateFrom, short vacationDays)
    {

        short weekEndCounter = 0;

        for (short i = 1; i <= vacationDays; i++)
        {

            if (isWeekEnd(dateFrom))
                weekEndCounter++;

            dateFrom = increaseDateByOne(dateFrom);
        }
        //to add weekends
        for (short i = 1; i <= weekEndCounter; i++)
            dateFrom = increaseDateByOne(dateFrom);

        return dateFrom;
    }

    static void printCalculateActualVacationDays(clsDate date1, clsDate date2){

        short startIndex = dayOfWeekOrder(date1);
        short endIndex = dayOfWeekOrder(date2);
        short actualVacationDays = calculateVacationDays(date1, date2 );

        cout << "\nVacation From: " << convertDayIndexToDay(startIndex) << " , "
             << date1._day << '/' << date1._month << '/' << date1._year;
        cout << "\nVacation To: " << convertDayIndexToDay(endIndex) << " , "
             << date2._day << '/' << date2._month << '/' << date2._year;

        cout << "\nActual Vacation Days is: " << actualVacationDays ;



    }
    void printCalculateActualVacationDays(clsDate date2){
        return printCalculateActualVacationDays(* this, date2);
    }

    static bool isBusinessDay_specific(short dayOrderIndex){
        if (dayOrderIndex > 6)
            dayOrderIndex %= 6, dayOrderIndex -=1;
        return !(dayOrderIndex == 6 || dayOrderIndex == 5);
    }

    static clsDate findReturnDate(clsDate & date1, short vacationDays){

        short totalDays = 0; clsDate endDate; short idx= 0;
        if (vacationDays >= 5){
            totalDays = 7 * (vacationDays / 5);
            vacationDays = vacationDays % 5;
            endDate = increaseDateByXDays(date1, totalDays);
            idx = dayOfWeekOrder(endDate);
        }

        while (vacationDays > 0 ){
            if (isBusinessDay_specific(idx + 0)){
                vacationDays --;
                endDate = increaseDateByOne(endDate);
            }
            idx ++;
        }

        endDate = increaseDateByOne(endDate);
        return endDate;
    }
    void findReturnDate(short vacationDays){
        findReturnDate(* this, vacationDays);
    }

    static void printReturnDate(clsDate date1, short vacationDays){

        short startIndex = dayOfWeekOrder(date1);

        clsDate returnDate = findReturnDate( date1, vacationDays);
        cout << "\nReturn Date: " << convertDayIndexToDay(startIndex) << " , "
             << returnDate._day << '/' << returnDate._month << '/' << returnDate._year;

    }
    void printReturnDate(short vacationDays){
        return printReturnDate(* this, vacationDays);
    }

    static bool isDate1AfterDate2(clsDate date1, clsDate date2){

        return !(isDate1BeforeDate2(date1, date2) && isDate1EqualDate2(date1, date2));

//    return (date1._year == date2._year)? ((date1._month == date2._month)? date1._day == date2._day: 0):0;
//    return (date1._year == date2._year && date1._month == date2._month && date1._day == date2._day) ;
    }
    bool isDate1AfterDate2(clsDate date2){
        return isDate1AfterDate2(* this, date2);
    }

    enum enDateCompare {Before = -1, Equal = 0, After = 1};

    static enDateCompare compareDates(clsDate date1, clsDate date2){

        if (isDate1BeforeDate2(date1, date2))
            return enDateCompare::Before;

        if (isDate1EqualDate2(date1, date2))
            return enDateCompare::Equal;

        return enDateCompare::After;
    }
    enDateCompare compareDates(clsDate date2){
        return compareDates(* this, date2);
    }

    //__________________________________________________________________________________


    static bool isValidDate(clsDate date){
        // simple check : check only integer inputs .. no fraction .. no chars;
        if (date._year <= 0)
            return 0;
        if (date._month <= 0 || date._month > 12)
            return 0;
        if (date._day <= 0 || date._day > numberOfDaysInMonth(date._month, date._year))
            return 0;
        return 1;
    }
    bool isValidDate(){
        return isValidDate(* this);
    }

    static vector<string> splitString(string s1, string delim) {
        vector<string> vString;
        short pos = 0; string sWord; // define a string variable

        // use find() function to get the position of the delimiters
        while ((pos = s1.find(delim)) != std::string::npos)
        {
            sWord =s1.substr(0, pos); // store the word
            if (sWord !="")
                vString.push_back(sWord);
            s1.erase(0, pos + delim.length());

            if (s1 != "")
                vString.push_back(s1); // it adds last word of the string.
        }
        return vString;
    }

    static clsDate stringToDate(string dateString) {
        clsDate date;
        vector <string> vDate;
        vDate = splitString(dateString, "/");
        date._day = stoi(vDate[0]);
        date._month = stoi(vDate[1]);
        date._year = stoi(vDate[2]);

        return date;
    }

    static string readDateString(string message){
        string date = "";

        cout << message;
        getline(cin >> ws, date);

        return date;
    }

    static void printDateFromDateStruct(clsDate date){
        cout << "\nDay:" << date._day;
        cout << "\nMonth:" << date._month;
        cout << "\nYear:" << date._year << endl << '\n';
    }
    void printDateFromDateStruct(){
        return printDateFromDateStruct(* this);
    }

    static string convertDateStructToString(clsDate date){
        string stDate = "";
        stDate = to_string(date._day) + '/' + to_string(date._month) + '/' + to_string(date._year);
        // without to_string() function :: will add it as hex code

        return stDate;
    }
    string convertDateStructToString() {
        return convertDateStructToString(* this);
    }

    static void printDateFromString(string date){

        cout << "You Entered: " << date;
    }

};

//________________________________________________________________________________________________

