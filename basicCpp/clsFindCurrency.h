//
// Created by Ayman yassien on 08/01/2024 AD.
//

#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"


class clsFindCurrency : protected clsScreen
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

    static void _showResult(clsCurrency currency)
    {
        if (currency.isEmpty())
        {
            cout << "\nCurrency not Found ):\n";
        }
        else
        {
            cout << "\nCurrency Found :)\n";
            _printCurrency(currency);
        }
    }
public:

    static void showFindCurrencyScreen()
    {
        cout << setw(10) << " ";
        clsScreen::_drawScreenHeader("\t\tFind Currency Screen");


        cout << "\nFind By [1] Code or [2] Country ? ";
        char choice = clsInputValidate::readShortNumberBetween(1,2);


        if (choice == 1) {
            cout << "\nPlease Enter Currency Code: ";
            clsCurrency currency = clsCurrency::findByCode(clsInputValidate::readString());
            _showResult(currency);
        }
        else {
            cout << "Please Enter Country Name: ";
            clsCurrency currency = clsCurrency::findByCountry(clsInputValidate::readString());
            _showResult(currency);
        }



    }
};