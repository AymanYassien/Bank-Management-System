//
// Created by Ayman yassien on 20/12/2023 AD.
//

#pragma once
#include "clsMainScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "global.h"

class clsAddNewClientScreen : protected clsScreen
{
private:
    static void _readClientInfo(clsBankClient& client)
    {

        cout << "Enter FirstName: ";
        client.setFirstName(clsInputValidate::readString());

        cout << "Enter LastName: ";
        client.setLastName(clsInputValidate::readString());

        cout << "Enter  Email: ";
        client.setEmail(clsInputValidate::readString());

        cout << "Enter  Phone: ";
        client.setPhone(clsInputValidate::readString());

        cout << "Enter  PinCode: ";
        client.setPinCode(clsInputValidate::readString());

        cout << "Enter  AccountBalance: ";
        client.setAccountBalance(clsInputValidate::readFloatNumber());


    }

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
    static void showAddNewClientScreen()
    {
        if(!checkAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
        clsScreen::_drawScreenHeader("\t\t Add New Client Screen");
        string accountNumber = "";

        cout << "\nplease Enter account number: ";
        accountNumber = clsInputValidate::readString();

        while(clsBankClient::isClientExist(accountNumber))
        {
            cout << "\nAccount num ber is already exist, choose another one: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient newClient = clsBankClient::getAddNewClientObj(accountNumber);

        _readClientInfo(newClient);

        clsBankClient::enSaveResults saveResult;
        saveResult = newClient.save();

        switch (saveResult)
        {
            case clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "Account updated Successfully :)\n";
                _printClient(newClient);
                break;
            }
            case clsBankClient::enSaveResults::svFalidEmptyObject:
            {
                cout <<"\nError account was not saved because it's Empty";
                break;
            }
            case clsBankClient::enSaveResults::svFalidAccountNumberExist:
            {
                cout <<"\nError account was not saved because AccountNumber is exisr";
                break;
            }

        }

    }

};
