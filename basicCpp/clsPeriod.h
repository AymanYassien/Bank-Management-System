#pragma warning (disable : 4996)
#pragma once

#include <iostream>
#include "clsDate.h"

using namespace std;

class clsPeriod{
public:
    clsDate startDate;
    clsDate endDate;

    clsPeriod(clsDate startDate, clsDate endDate)
    {
        this->startDate = startDate;
        this->startDate = endDate;
    }

    static bool isOverlapPeriods(clsPeriod p1, clsPeriod p2){
        if (clsDate::compareDates(p2.startDate, p1.endDate) == clsDate::enDateCompare::After
            || clsDate::compareDates(p2.endDate, p1.startDate) == clsDate::enDateCompare::Before)
            return false;
        return true;

    }
    bool isOverlapPeriods(clsPeriod p2){
        return isOverlapPeriods(*this, p2);
    }

    static int calculatePeriodLength(clsDate date1, clsDate date2, bool includeEndDay = false){

        int different = 0;

        if (date1.getYear() == date2.getYear()){
            different = clsDate::numberOfDaysFromTheBeginningOfTheYear(date2) - clsDate::numberOfDaysFromTheBeginningOfTheYear(date1);
            return different;
        }else{
            if (clsDate::isLeapYear(date1.getYear())){
                different = 366 - clsDate::numberOfDaysFromTheBeginningOfTheYear(date1);
                date1.setYear(date1.getYear()+1);
            }
            else{
                different = 365 - clsDate::numberOfDaysFromTheBeginningOfTheYear(date1);
                date1.setYear(date1.getYear() + 1);
            }
        }

        while (date2.getYear() > date1.getYear()){
            different += (clsDate::isLeapYear(date1.getYear())) ? 366 : 365;
            date1.setYear(date1.getYear() + 1);
        }

        different += clsDate::numberOfDaysFromTheBeginningOfTheYear(date2);

        return includeEndDay? ++different: different;
    }
    int calculatePeriodLength(bool includeEndDay = false){
        return calculatePeriodLength(startDate, endDate, includeEndDay);
    }

    static bool isDateWithinPeriodLength(clsPeriod period, clsDate dateToCheck){

        return (clsDate::isDate1BeforeDate2(dateToCheck, period.endDate)
                &&
                clsDate::isDate1AfterDate2(dateToCheck, period.startDate));
    }
    bool isDateWithinPeriodLength(clsDate dateToCheck){
        return isDateWithinPeriodLength(*this, dateToCheck);
    }

    static int calculateOverlapDays(clsPeriod p1, clsPeriod p2){

        int counter = 0;

        if (!isOverlapPeriods( p1, p2))
            return counter;

        if (clsDate::compareDates(p2.startDate, p1.startDate) == clsDate::enDateCompare::Equal
            && clsDate::compareDates(p2.endDate, p1.endDate) == clsDate::enDateCompare::Equal)
            return calculatePeriodLength(p1.startDate, p1.endDate);

        if (clsDate::compareDates(p2.startDate, p1.endDate) == clsDate::enDateCompare::Equal
            && clsDate::compareDates(p1.startDate, p2.endDate) == clsDate::enDateCompare::Equal)
            return counter ++;

        if (clsDate::compareDates(p1.startDate, p2.endDate) == clsDate::enDateCompare::Before){
            while (isDateWithinPeriodLength(p2, p1.startDate)){
                counter++;
                p1.startDate = clsDate::increaseDateByOne(p1.startDate);
            }
            return counter;
        }

        if (clsDate::compareDates(p2.startDate, p1.endDate) == clsDate::enDateCompare::Before){
            while (isDateWithinPeriodLength(p1, p2.startDate)){
                counter++;
                p2.startDate = clsDate::increaseDateByOne(p2.startDate);
            }
            return counter;
        }

    }
    int calculateOverlapDays(clsPeriod p2){
        return calculateOverlapDays(*this, p2);
    }

    void Print()
    {
        cout << "Period Start: ";
        startDate.print();


        cout << "Period End: ";
        endDate.print();


    }


};








