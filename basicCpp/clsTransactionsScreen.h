//
// Created by Ayman yassien on 21/12/2023 AD.
//

#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogsScreen.h"

// :: = scope resolution operator

class clsTransactionsScreen : protected clsScreen
{
private:
    enum _enTransactionsMenuOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3,
            eTransfer = 4, eTransferLog = 5, eShowMainMenu = 6 };

    static short _readTransactionsMenuOption()
    {
        cout << setw(39) << left << " " << "Choose what do you want to do? [1 to 6]? ";
        short choice = 0;
        choice = clsInputValidate::readShortNumberBetween(1,6, "\nEnterNumber Between 1, 6 : ");

        return choice;
    }

    static void _showDepositScreen()
    {
        clsDepositScreen::showDepositScreen();

    }

    static void _showWithDrawScreen()
    {
        //Scope resolution operator
        clsWithdraw::showWithdrawScreen();
    }

    static void _showTotalBalancesScreen()
    {
        clsTotalBalancesScreen::showTotalBalancesScreen();

    }

    static void _showTransferScreen()
    {
        clsTransferScreen::showTransferScreen();

    }

    static void _showTransferLosScreen()
    {
        clsTransferLogsScreen::showTransferLogsScreen();

    }

    static void _goBackToTransactionsMenu()
    {
        cout << "\n\nPress any key to go back to Transactions Menu...";

        // Clear the input buffer
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        // Wait for user input again (Enter key)
        cin.get();
        showTransactionsMenu();

    }

    static void _performTransactionsMenuOption(_enTransactionsMenuOptions transactionMenuOption)
    {
        switch (transactionMenuOption)
        {
            case eDeposit:
            {
                _showDepositScreen();
                _goBackToTransactionsMenu();
                break;
            }
            case eWithdraw:
            {
                _showWithDrawScreen();
                _goBackToTransactionsMenu();
                break;
            }
            case _enTransactionsMenuOptions::eShowTotalBalance:
            {
                _showTotalBalancesScreen();
                _goBackToTransactionsMenu();
                break;
            }
            case _enTransactionsMenuOptions::eTransfer:
            {
                _showTransferScreen();
                _goBackToTransactionsMenu();
                break;
            }
            case eTransferLog:
            {
                _showTransferLosScreen();
                _goBackToTransactionsMenu();
                break;
            }
            case _enTransactionsMenuOptions::eShowMainMenu:
            {

            }
        }

    }

public:
    static void showTransactionsMenu()
    {
        if(!checkAccessRights(clsUser::enPermissions::pTransations))
        {
            return;
        }
        clsScreen::_drawScreenHeader("\t\t Transactions Screen");
        cout << setw(39) << left << " " << "===========================================\n";
        cout << setw(39) << left << " " << "\t\tTransactions Menu\n";
        cout << setw(39) << left << " " << "===========================================\n";
        cout << setw(39) << left << " " << "\t[1] Deposit.\n";
        cout << setw(39) << left << " " << "\t[2] Withdraw.\n";
        cout << setw(39) << left << " " << "\t[3] Total Balances.\n";
        cout << setw(39) << left << " " << "\t[4] Transfer.\n";
        cout << setw(39) << left << " " << "\t[5] Transfer Logs.\n";
        cout << setw(39) << left << " " << "\t[6] Main Menu.\n";
        cout << setw(39) << left << " " << "===========================================\n";
        _performTransactionsMenuOption((_enTransactionsMenuOptions) _readTransactionsMenuOption());
    }

};