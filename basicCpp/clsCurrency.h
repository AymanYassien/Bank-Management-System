//
// Created by Ayman yassien on 07/01/2024 AD.
//
#pragma once
#include "iostream"
#include <vector>
#include "fstream"
#include "clsString.h"

class clsCurrency
{

private:
    enum enMode {emptyMode = 0, updateMode = 1};
    enMode _mode;

    string _country;
    string _currencyCode;
    string _currencyName;
    double _rate;

    static clsCurrency _convertLineToCurrantObject(string line, string separator = "#//#")
    {
        vector<string> vCurrencyData;
        vCurrencyData = clsString::split(line, separator);

        return clsCurrency(enMode::updateMode, vCurrencyData[0], vCurrencyData[1],
                           vCurrencyData[2], stod(vCurrencyData[3]));
    }

    static string _convertCurrencyObjectToLine(clsCurrency currency, string separator = "#//#")
    {

        string line = "";
        line += currency.getCountry() + separator;
        line += currency.getCurrencyCode() + separator;
        line += currency.getCurrencyName() + separator;
        line += to_string(currency.getRate());

        return line;

    }

    static vector<clsCurrency> _loadCurrenciesDataFromFile()
    {
        vector<clsCurrency> vCurrencies;

        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/currencies.txt", ios::in); // read mode

        if (myFile.is_open())
        {

            string line;

            while (getline(myFile, line))
            {

                clsCurrency currency = _convertLineToCurrantObject(line);

                vCurrencies.push_back(currency);
            }

            myFile.close();

        }

        return vCurrencies;

    }

    static void _saveCurrencyDataToFile(vector <clsCurrency> vCurrencies)
    {

        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/currencies.txt", ios::out);//overwrite

        string dataLine;

        if (myFile.is_open())
        {
            for (clsCurrency c : vCurrencies)
            {
                dataLine = _convertCurrencyObjectToLine(c);
                myFile << dataLine << endl;
            }
            myFile.close();
        }
    }

    void _update()
    {
        vector <clsCurrency> vCurrencies;
        vCurrencies = _loadCurrenciesDataFromFile();

        for (clsCurrency& c : vCurrencies)
        {
            if (c.getCurrencyCode() == getCurrencyCode())
            {
                c = *this;
                break;
            }
        }
        _saveCurrencyDataToFile(vCurrencies);

    }

    static clsCurrency _getEmptyCurrencyObject()
    {
        return clsCurrency(enMode::emptyMode, "", "", "", 0);
    }
public:
    clsCurrency(enMode mode, string country, string currencyCode, string currencyName, double rate)
    {
        _mode         = mode;
        _country      = country;
        _currencyCode = currencyCode;
        _currencyName = currencyName;
        _rate         = rate;

    }

    static vector <clsCurrency> getAllUSDRates()
    {

        return _loadCurrenciesDataFromFile();

    }

    bool isEmpty()
    {
        return (_mode == enMode::emptyMode);
    }

    string getCountry()
    {
        return _country;
    }

    string getCurrencyCode()
    {
        return _currencyCode;
    }

    string getCurrencyName()
    {
        return _currencyName;
    }

    void updateRate(double newRate)
    {
        _rate = newRate;
        _update();
    }

    double getRate()
    {
        return _rate;
    }

    static   clsCurrency findByCode(string currencyCode)
    {

        currencyCode = clsString::upperAllString(currencyCode);

        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/currencies.txt", ios::in);//read Mode

        if (myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsCurrency currency = _convertLineToCurrantObject(line);
                if (currency.getCurrencyCode() == currencyCode)
                {
                    myFile.close();
                    return currency;
                }
            }

            myFile.close();

        }

        return _getEmptyCurrencyObject();

    }

    static clsCurrency findByCountry(string country)
    {
        country = clsString::upperAllString(country);

        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/currencies.txt", ios::in);

        if(myFile.is_open())
        {
            string line;
            while (getline(myFile, line))
            {
                clsCurrency currency = _convertLineToCurrantObject(line);
                if (clsString::upperAllString(currency.getCountry()) == country)
                {
                    myFile.close();
                    return currency;
                }
            }

            myFile.close();
        }

        return _getEmptyCurrencyObject();
    }

    static bool isCurrencyExist(string currencyCode)
    {
        clsCurrency c1 = clsCurrency::findByCode(currencyCode);
        return (!c1.isEmpty());
    }

    static vector <clsCurrency> getCurrenciesList()
    {
        return _loadCurrenciesDataFromFile();
    }

    float convertToUSD(float amount)
    {
        return (float)(amount / _rate);
    }

    float convertToOtherCurrency(float amount, clsCurrency currency2)
    {
        float amountInUSD = convertToUSD(amount);

        if (currency2.getCurrencyCode() == "USD")
            return amountInUSD;

        return amountInUSD * currency2.getRate();
    }


};
