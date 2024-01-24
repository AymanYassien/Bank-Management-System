//
// Created by Ayman yassien on 21/12/2023 AD.
//
#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsDepositScreen :protected clsScreen

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

    static string _readAccountNumber()
    {
        string accountNumber = "";
        cout << "Please Enter Client account Number: ";
        accountNumber = clsInputValidate::readString();
        return accountNumber;

    }
public:
    static void showDepositScreen()
    {
        clsScreen::_drawScreenHeader("\t\t  Deposit Screen");
        string accountNumber = _readAccountNumber();

        while (!clsBankClient::isClientExist(accountNumber))
        {
            cout << "Account Number is not found choose another one: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient client = clsBankClient::find(accountNumber);
        _printClient(client);

        cout << "\nPlease Enter Deposit amount? ";
        double amount = 0;
        amount = clsInputValidate::readDblNumber();

        cout << "Are You sure you want to perform this transaction? Y/N";
        char choice = 'n';
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            client.deposit(amount);
            cout << "\nAmount Deposit Successfully.\n";
            cout << "\nNew Balance is: " << client.getAccountBalance();
        }
        else
        {
            cout << "\nOperation was Canceled\n";
        }

    }

};