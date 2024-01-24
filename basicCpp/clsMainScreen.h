//
// Created by Ayman yassien on 18/12/2023 AD.
//
#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsListClientscreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"

class clsMainScreen : protected clsScreen
{
private:
    enum _enMainMenuOptions { eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5,
        eShowTransactionsMenu = 6,eManageUsers = 7, eLoginRigester = 8, eCurrencyExchange = 9, eLogout = 10 };

    static short _readMainMenuOption()
    {
        cout << setw(39) << left << " "  << "Choose what do you want to do? [1 to 10]? ";
        short choice = 0;
        choice = clsInputValidate::readShortNumberBetween(1,10, "\nEnter Number Between 1 , 10");

        return choice;
    }

    static void _goBackToMainMenu()
    {
        cout << "\n\nPress any key to go back to Main Menu...";

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Wait for user input (Enter key)
        cin.get();

        showMainMenu();

    }

    static void _goBackToLoginScreen()
    {
        cout << "\n\nPress any key to go to Login Screen...";

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Wait for user input (Enter key)
        cin.get();

        //clsLoginScreen::showLoginScreen();
       //this do issue here : do circular reference
       // now will back to main

    }

    static void _showAllClientsScreen ()
    {
        //cout << "\nClients Screen Will be here ...\n";

        clsClientListScreen::showClientsList();
    }

    static void _showAddNewClientsScreen()
    {
        //cout << "\nAdd New Screen Will be here ...\n";
        clsAddNewClientScreen::showAddNewClientScreen();

    }

    static void _showDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here ...\n";
        clsDeleteClientScreen::shoeDeleteClientScreen();

    }

    static void _showUpdateClientScreen()
    {
        clsUpdateClientScreen::updateClient();

    }

    static void _showFindClientScreen()

    {

        //cout << "\nFind Client Screen Will be here ...\n";
        clsFindClientScreen::showFindClientScreen();


    }

    static void _showTransactionsMenu()
    {
        //cout << "\nTransactions Screen Will be here ...\n";
        clsTransactionsScreen::showTransactionsMenu();

    }

    static void _showManageUsersMenu()
    {
        //cout << "\nManage users Screen Will be here ...\n";

        clsManageUsersScreen::showManageUsersMenu();
    }

    static void _showLoginRegister()
    {
        clsLoginRegisterScreen::showLoginScreen();
    }

    static void _showCurrencyExchange()
    {
        clsCurrencyExchangeMainScreen::showCurrencyExchangeMenu();
    }

    static void _logout()
    {
        currentUser = clsUser::find("", "");

    }

    static void _performMainMenuOption(_enMainMenuOptions mainMenuOption)
    {
        switch (mainMenuOption)
        {
            // no different if _enMainMenuOptions::e... or direct e...
            case eListClients:
            {
                _showAllClientsScreen();
                _goBackToMainMenu();
                break;
            }
            case eAddNewClient:
            {
                _showAddNewClientsScreen();
                _goBackToMainMenu();
                break;
            }
            case eDeleteClient:
            {
                _showDeleteClientScreen();
                _goBackToMainMenu();
                break;
            }
            case eUpdateClient:
            {
                _showUpdateClientScreen();
                _goBackToMainMenu();
                break;
            }
            case eFindClient:
            {
                _showFindClientScreen();
                _goBackToMainMenu();
                break;
            }
            case eShowTransactionsMenu:
            {
                _showTransactionsMenu();
                _goBackToMainMenu();
                break;
            }
            case eManageUsers:
            {
                _showManageUsersMenu();
                _goBackToMainMenu();
                break;
            }
            case eLoginRigester:
            {
                _showLoginRegister();
                _goBackToMainMenu();
                break;
            }
            case eCurrencyExchange:
            {
                _showCurrencyExchange();
                _goBackToMainMenu();
                break;
            }
            case eLogout:
            {
                _logout();
                _goBackToLoginScreen();
                break;
            }
        }

    }

public:
    static void showMainMenu()
    {
        _drawScreenHeader("\t\tMain Screen");

        cout << setw(39) << left << " " << "===========================================\n";
        cout << setw(39) << left << " " << "\t\tMain Menu Screen\n";
        cout << setw(39) << left << " " << "===========================================\n";
        cout << setw(39) << left << " " << "\t[1] Show Client List.\n";
        cout << setw(39) << left << " " << "\t[2] Add New Client.\n";
        cout << setw(39) << left << " " << "\t[3] Delete Client.\n";
        cout << setw(39) << left << " " << "\t[4] Update Client Info.\n";
        cout << setw(39) << left << " " << "\t[5] Find Client.\n";
        cout << setw(39) << left << " " << "\t[6] Transactions.\n";
        cout << setw(39) << left << " " << "\t[7] Manage Users.\n";
        cout << setw(39) << left << " " << "\t[8] Login Register.\n";
        cout << setw(39) << left << " " << "\t[9] Currency Exchange.\n";
        cout << setw(39) << left << " " << "\t[10]Logout.\n";
        cout << setw(39) << left << " " << "===========================================\n";


        _performMainMenuOption((_enMainMenuOptions)_readMainMenuOption());


    }

};