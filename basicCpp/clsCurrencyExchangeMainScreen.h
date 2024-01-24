//
// Created by Ayman yassien on 08/01/2024 AD.
//

#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrency.h"
#include "clsUpdateRate.h"
#include "clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeMainScreen : clsScreen
{
private:
    enum _enCurrencyExchangeMenu { eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
            eCurrencyCalculator = 4, eMainMenu = 5};

    static short _readCurrencyExchangeMenuOption()
    {
        cout << setw(39) << left << " "  << "Choose what do you want to do? [1 to 5]? ";
        short choice = 0;
        choice = clsInputValidate::readShortNumberBetween(1,5, "\nEnter Number Between 1 , 5");

        return choice;
    }

    static void _goBackToCurrencyExchangeMenu()
    {
        cout << "\n\nPress any key to go back to Currency Exchange Menu...";

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Wait for user input (Enter key)
        cin.get();

        showCurrencyExchangeMenu();

    }

    static void _showListCurrenciesScreen ()
    {
        clsCurrenciesListScreen::showCurrenciesList();

    }

    static void _showFindCurrencyScreen ()
    {
        clsFindCurrency::showFindCurrencyScreen();
    }

    static void _showUpdateRateScreen ()
    {
        clsUpdateRate::showUpdateRate();
    }

    static void _showCurrencyCalculatorScreen ()
    {
        clsCurrencyCalculatorScreen::showCurrencyCalculator();

    }

    static void _performCurrencyExchangeMenuOption(_enCurrencyExchangeMenu currencyExchangeMenuOptions)
    {
        switch (currencyExchangeMenuOptions)
        {
            // no different if _enMainMenuOptions::e... or direct e...
            case eListCurrencies:
            {
                _showListCurrenciesScreen();
                _goBackToCurrencyExchangeMenu();
                break;
            }
            case eFindCurrency:
            {
                _showFindCurrencyScreen();
                _goBackToCurrencyExchangeMenu();
                break;
            }
            case eUpdateRate:
            {
                _showUpdateRateScreen();
                _goBackToCurrencyExchangeMenu();
                break;
            }
            case eCurrencyCalculator:
            {
                _showCurrencyCalculatorScreen();
                _goBackToCurrencyExchangeMenu();
                break;
            }
            case eMainMenu:
            {

            }
        }

    }

public:
    static void showCurrencyExchangeMenu()
    {
        _drawScreenHeader("\t\tCurrency Exchange Main Screen");

        cout << setw(39) << left << " " << "===========================================\n";
        cout << setw(39) << left << " " << "\t\tCurrency Exchange Menu\n";
        cout << setw(39) << left << " " << "===========================================\n";
        cout << setw(39) << left << " " << "\t[1] List Currencies.\n";
        cout << setw(39) << left << " " << "\t[2] Find Currency.\n";
        cout << setw(39) << left << " " << "\t[3] Update Rate.\n";
        cout << setw(39) << left << " " << "\t[4] Update Calculator.\n";
        cout << setw(39) << left << " " << "\t[5] Main Menu.\n";
        cout << setw(39) << left << " " << "===========================================\n";

        _performCurrencyExchangeMenuOption((_enCurrencyExchangeMenu)_readCurrencyExchangeMenuOption());


    }
};