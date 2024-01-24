//
// Created by Ayman yassien on 07/01/2024 AD.
//

#pragma once
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDate.h"

class clsTransferScreen : protected clsScreen
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

    static string _readSourceClientAccountNumber()
    {
        cout << "\nPlease Enter Client account Number To Transfer From: ";
        string accountNumber = "";
        accountNumber = clsInputValidate::readString();
        while(!clsBankClient::isClientExist(accountNumber))
        {
            cout << "Account Number is not found choose another one: ";
            accountNumber = clsInputValidate::readString();
        }
        return accountNumber;

    }

    static string _readDestinationClientAccountNumber(clsBankClient source)
    {
        cout << "\nPlease Enter Client account Number To Transfer to: ";
        string accountNumber = "";
        accountNumber = clsInputValidate::readString();
        while(!clsBankClient::isClientExist(accountNumber) || accountNumber == source.getAccountNumber())
        {
            cout << "Account Number is not found choose another one: ";
            accountNumber = clsInputValidate::readString();
        }

        return accountNumber;

    }

    static double _readAmount (clsBankClient sourceClient)
    {
        double amount = 0;
        cout << "\nPlease Enter Transfer amount: ";
        amount = clsInputValidate::readDblNumber();

        while(amount > sourceClient.getAccountBalance())
        {
            cout << "\nAmount Exceeds the available, Enter another amount! ";
            amount = clsInputValidate::readDblNumber();
        }

        return amount;

    }


public:
    static void showTransferScreen()
    {
        clsScreen::_drawScreenHeader("\t\t Transfer Screen\n");

        clsBankClient sourceClient = clsBankClient::find(_readSourceClientAccountNumber());
        _printClient(sourceClient);

        clsBankClient destinationClient = clsBankClient::find(_readDestinationClientAccountNumber(sourceClient));
        _printClient(destinationClient);

        double amount = _readAmount(sourceClient);

        cout << "\nAre you sure you want to perform this Operation? Y/N? ";
        char choice = 'n';
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            if (sourceClient.transfer(amount, destinationClient))
            {
                cout << "Transfer done successfully :)";
            }

            else
                cout << "TransferFailed ):\n";

        }

        _printClient(sourceClient);
        cout << endl;
        _printClient(destinationClient);

    }
};