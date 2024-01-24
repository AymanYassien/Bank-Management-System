//
// Created by Ayman yassien on 21/12/2023 AD.
//

#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsInputValidate.h"

class clsTotalBalancesScreen : protected clsScreen
{

    static void _printClientRecordBalanceLine(clsBankClient client)
    {
        cout << setw(27) << "" << "| " << setw(19) << left <<client.getAccountNumber()
        << "| " << setw(42) << left <<client.getFullName()
        << "| " << setw(12) << left <<client.getAccountBalance();
    }

public:
    static void showTotalBalancesScreen()
    {
        vector<clsBankClient> vClients = clsBankClient::getClientsList();

        string subTitle = "\t\t\t  (";
        subTitle += to_string(vClients.size());
        subTitle += ")Client(s).";

        cout << setw(10) << " ";
        clsScreen::_drawScreenHeader("\t\tBalances List Screen",  subTitle);

//        cout << setw(8) << " " << "\n\t\t\t\t\tClient List(" << vClients.size() << ")Client(s).";
        cout << '\n' << setw(20)  << " "  << "________________________________________________________________________________________________\n" << endl;
        cout << setw(27)  << " "   << "| " << setw(19) << left <<"Account Number";
        cout << "| " << setw(42) << left <<"Client name";
        cout << "| " << setw(12) << left <<"Balance";
        cout << '\n' << setw(20)  << " "  << "________________________________________________________________________________________________\n" << endl;


        if (vClients.size() == 0)
        {
            cout << "\t\t\t\t\t\t\tNo Clients Available in the System!";
        }
        else {
            for(clsBankClient c : vClients)
            {
                _printClientRecordBalanceLine(c);
                cout << endl;
            }
        }
        cout << '\n' << setw(20)  << " "   << "________________________________________________________________________________________________\n" << endl;

        double totalBalances = clsBankClient::getTotalBalances();
        cout << setw(65)  << " " << "Total Balances: " << totalBalances << '\n';
        cout << setw(45)  << " " << "(" << clsUtil::numberToText(totalBalances) << ") ";

    }

};
