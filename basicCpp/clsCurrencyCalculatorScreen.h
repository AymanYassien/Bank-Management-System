//
// Created by Ayman yassien on 08/01/2024 AD.
//

#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{
    static void _printCurrency(clsCurrency currency, string title)
    {
        cout << "\n" << title << "\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << currency.getCountry();
        cout << "\nCode       : " << currency.getCurrencyCode();
        cout << "\nName       : " << currency.getCurrencyName();
        cout << "\nRate(1$) = : " << currency.getRate();
        cout << "\n_____________________________\n";

    }

    static clsCurrency _getCurrency(string message)
    {
        cout << message;
        string currency1Code = clsInputValidate::readString();

        while (!clsCurrency::isCurrencyExist(currency1Code)) {
            cout << "Currency is not found, choose another one! ";
            currency1Code = clsInputValidate::readString();
        }
        clsCurrency currency = clsCurrency::findByCode(currency1Code);

        return currency;
    }

    static double _readAmount()
    {
        cout << "\nEnter amount to Exchange: ";
        double amount = clsInputValidate::readDblNumber();

        return amount;
    }

    static void _printCalculationsResults(float amount, clsCurrency from, clsCurrency to)
    {
        _printCurrency(from, "Convert From: ");
        float amountInUsd = from.convertToUSD(amount);

        cout << amount << ' ' << from.getCurrencyCode() << " = " << amountInUsd << " USD\n";

        if(to.getCurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting from USD to:\n";
        _printCurrency(to, "To: ");

        float amountInCurrency2 = from.convertToOtherCurrency(amount,to);
        cout << amount << ' ' << from.getCurrencyCode() << " = " << amountInCurrency2 << ' ' << to.getCurrencyCode();


    }
public:
    static void showCurrencyCalculator()
    {
        cout << setw(10) << " ";
        clsScreen::_drawScreenHeader("\t\tCalculate Currency Screen");

        char choice = 'y';
        while (choice == 'y' || choice == 'Y')
        {

            clsCurrency currencyFrom = _getCurrency("\nPlease Enter Currency1 Code:\n");
            clsCurrency currencyTo = _getCurrency("\nPlease Enter Currency2 Code:\n");
            double amount = _readAmount();

            _printCalculationsResults(amount,currencyFrom, currencyTo);


            cout << "\n\nDo You Want to Perform another calculation? y/n? ";
            cin >> choice;

        };

    }
};