//
// Created by Ayman yassien on 20/12/2023 AD.
//

#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"

class clsFindClientScreen :protected clsScreen
{
private:
    static void _printClient(clsBankClient client)
    {
        cout << "\nClient Card:";
        cout << "\n------------------------";
        cout << "\nFirstName     : " << client.getFirstName();
        cout << "\nLastName      : " << client.getLastName();
        cout << "\nFullName      : " << client.getFullName();
        cout << "\nEmail         : " << client.getEmail();
        cout << "\nPhone         : " << client.getPhone();
        cout << "\nAcc. Number   : " << client.getAccountNumber();
        cout << "\nPassword      : " << client.getPinCode();
        cout << "\nBalance       : " << client.getAccountBalance();
        cout << "\n------------------------";

    }

public:
    static void showFindClientScreen()
    {
        if(!checkAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }

        clsScreen::_drawScreenHeader("\t\t Find Client Screen");

        string accountNumber = "";

        cout << "\nPlease Enter client AccountNumber: ";
        accountNumber = clsInputValidate::readString();
        while(!clsBankClient::isClientExist(accountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient client = clsBankClient::find(accountNumber);
        if (!client.isEmpty())
        {
            cout << "\nClient Found :)\n";
        }
        else
        {
            cout << "\nClient Was not Found :(\n";
        }
        _printClient(client);


    }

};