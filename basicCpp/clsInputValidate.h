//
// Created by Ayman yassien on 12/12/2023 AD.
//
#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsString.h"

using namespace std;

class clsInputValidate{

    // can modify this code by template ... byt it will need modify in all project ...
    // and i am busy ... maybe do it in future ... here example of template code

    /*
     * template <typename t>
 t myMax(t number1, t number2)
 {
    return (number1 >= number2) ? number1 : number2;
 }

 template<class T>
 class calculator
{
 private:
    T _number1, _number2;
 public:
    calculator(T number1, T number2)
    {
         _number1 = number1;
         _number2 = number2;
    }

    void printResult()
    {
        cout << "Numbers: " << _number1 << " and " << _number2 << " .\n";
        cout << _number1 << " + " << _number2 << " = " << add()      << endl;
        cout << _number1 << " - " << _number2 << " = " << subtract() << endl;
        cout << _number1 << " * " << _number2 << " = " << multiply() << endl;
        cout << _number1 << " / " << _number2 << " = " << divide()   << endl;
    }

    T add ()
    {
        return _number1 + _number2;
    }

    T subtract ()
    {
        return _number1 - _number2;
    }

    T multiply()
    {
        return _number1 * _number2;
    }

    T divide()
    {
        return _number1 / _number2;
    }


};

     int main()
{
    cout << myMax<int>(4,7) << endl;
    cout << myMax<double>(4.5, 5.6) << endl;
    cout << myMax<char>('d','x') << endl;

    calculator<int> intCalc(2,4);

    calculator<float> floatCalc(2.4,4.1);

    cout << "\nInt Result: " << endl;
    intCalc.printResult();

    cout << "\nFloat Result: " << endl;
    floatCalc.printResult();

}
     */ // template class and functions
public:

    static bool isNumberBetween (short number, short from, short to)
    {
        return (number >= from && number <= to);
    }

    static bool isNumberBetween (int number, int from, int to)
    {
        return (number >= from && number <= to);
    }

    static bool isNumberBetween (float number, float from, float to)
    {
        return (number >= from && number <= to);
    }

    static bool isNumberBetween (double number, double from, double to)
    {
        return (number >= from && number <= to);
    }

    static bool isDateBetween(clsDate date, clsDate from ,clsDate to)
    {
        if((clsDate::isDate1AfterDate2(date, from) || clsDate::isDate1EqualDate2(date, from))
           && (clsDate::isDate1BeforeDate2(date, to) || clsDate::isDate1EqualDate2(date, to)))
        {
            return true;
        }

        if((clsDate::isDate1AfterDate2(date, to) || clsDate::isDate1EqualDate2(date, to))
           && (clsDate::isDate1BeforeDate2(date, from) || clsDate::isDate1EqualDate2(date, from)))
        {
            return true;
        }

        return false;

    }

    static int readIntNumber(string errorMessage = "Invalid Number, Enter again\n")
    {
        int number = 0;
        while(!(cin >> number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore max number of chars u can ignore
            cout << errorMessage;
        }
        return number;
    }

    static int readIntNumberBetween(int from, int to, string errorMessage = "Invalid Number, Enter again\n")
    {
        int number  = readIntNumber();

        while (!isNumberBetween(number, from, to))
        {
            cout << errorMessage;
            number = readIntNumber();
        }
        return number;
    }

    static short readShortNumber(string errorMessage = "Invalid Number, Enter again\n")
    {
        short number = 0;
        while(!(cin >> number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore max number of chars u can ignore
            cout << errorMessage;
        }
        return number;
    }

    static int readShortNumberBetween(short from, short to, string errorMessage = "Invalid Number, Enter again\n")
    {
        short number  = readIntNumber();

        while (!isNumberBetween(number, from, to))
        {
            cout << errorMessage;
            number = readIntNumber();
        }
        return number;
    }

    static float readFloatNumber(string errorMessage = "Number is not within range, Enter again\n")
    {
        float number = 0;
        while(!(cin >> number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << errorMessage;
        }
        return number;
    }

    static double readDblNumber(string errorMessage = "Number is not within range, Enter again\n")
    {
        double number = 0;
        while(!(cin >> number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << errorMessage;
        }
        return number;
    }

    static double readDblNumberBetween(double from, double to, string errorMessage = "Number is not within range, Enter again\n")
    {
        double number  = readIntNumber();

        while (!isNumberBetween(number, from, to))
        {
            cout << errorMessage;
            number = readIntNumber();
        }
        return number;
    }

    static bool isValidDate(clsDate date)
    {
        return clsDate::isValidDate(date);
    }

    static string readString ()
    {
        string s = "";
        getline(cin >> ws, s);

        return s;
    }


};

