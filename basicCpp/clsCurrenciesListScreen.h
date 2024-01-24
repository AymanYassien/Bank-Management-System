//
// Created by Ayman yassien on 08/01/2024 AD.
//
#pragma once

#include "clsScreen.h"
#include "clsCurrency.h"


class clsCurrenciesListScreen : protected clsScreen
{
private:
    static void _printCurrency(clsCurrency currency)
    {

        cout << setw(8) << " " ;
        cout << "| " << setw(30) << left << currency.getCountry();
        cout << "| " << setw(12) << left << currency.getCurrencyCode();
        cout << "| " << setw(35) << left << currency.getCurrencyName();
        cout << "| " << setw(15) << left << currency.getRate();

    }

public:

    static void showCurrenciesList()
    {
        vector<clsCurrency> vCurrencies = clsCurrency::getCurrenciesList();

        string subTitle = "\t\t\t(";
        subTitle += to_string(vCurrencies.size());
        subTitle += ")Currency(s).";

        cout << setw(10) << " ";
        clsScreen::_drawScreenHeader("\t\tCurrencies List Screen",  subTitle);


        cout << '\n' << setw(8)  << " "  << "________________________________________________________________________________________________\n" << endl;
        cout << setw(8)  << " "  << "| " << setw(30) << left <<"Country";
        cout << "| " << setw(12) << left <<"Code";
        cout << "| " << setw(35) << left <<"Name";
        cout << "| " << setw(15) << left <<"Rate/(1$)";
        cout << '\n' << setw(8)  << " "  << "________________________________________________________________________________________________\n" << endl;


        if (vCurrencies.size() == 0)
        {
            cout << "\t\t\t\t\t\t\t\t\tNo Currencies Available in the System!";
        }
        else {
            for(clsCurrency c : vCurrencies)
            {
                _printCurrency(c);
                cout << endl;
            }
        }
        cout << '\n' << setw(8)  << " "   << "________________________________________________________________________________________________\n" << endl;



    }
};