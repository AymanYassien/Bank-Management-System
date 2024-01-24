//
// Created by Ayman yassien on 08/01/2024 AD.
//

#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateRate : protected clsScreen
{
private:
    static void _printCurrency(clsCurrency currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << currency.getCountry();
        cout << "\nCode       : " << currency.getCurrencyCode();
        cout << "\nName       : " << currency.getCurrencyName();
        cout << "\nRate(1$) = : " << currency.getRate();
        cout << "\n_____________________________\n";

    }

    static double _readRate()
    {
        cout << "\nEnter New Rate: ";
        float newRate = 0;

        newRate =clsInputValidate::readDblNumber(); // can validate pos number ... any way
        return newRate;
    }

public:
    static void showUpdateRate()
    {
        cout << setw(10) << " ";
        clsScreen::_drawScreenHeader("\t\tUpdate Currency Screen");

        cout << "\nPlease Enter Currency Code: ";
        string currencyCode = clsInputValidate::readString();

        while(!clsCurrency::isCurrencyExist(currencyCode))
        {
            cout << "Currency is not found, choose another one! ";
            currencyCode = clsInputValidate::readString();
        }

        clsCurrency currency = clsCurrency::findByCode(currencyCode);
        _printCurrency(currency);

        char choice = 'n';
        cout << "\nAre you sure you want to update the rate of this Currency y/n?  ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            cout << "\nUpdate Currency Rate:";
            cout << "\n________________________\n";
            cout << "Enter New Rate: ";


            currency.updateRate(_readRate());
            cout << "Currency rate updated successfully ):\n";
            _printCurrency(currency);

        }
        else
        {
            cout << "\nOperation was canceled";
        }

    }
};
