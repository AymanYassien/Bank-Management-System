//
// Created by Ayman yassien on 20/12/2023 AD.
//

#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
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

public:
    static void updateClient()
    {
        if(!checkAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }

        clsScreen::_drawScreenHeader("\t\t Update Client Screen");
        string accountNumber = "";

        cout << "\nPlease Enter client AccountNumber: ";
        accountNumber = clsInputValidate::readString();
        while(!clsBankClient::isClientExist(accountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient client = clsBankClient::find(accountNumber);
        _printClient(client);

        cout << "\n\nUpdate Client Info:";
        cout << "\n________________________\n";

        _readClientInfo(client);
        //client.setFirstName("Hammad");
//    client.setLastName(); to update specify .. not all

        clsBankClient::enSaveResults saveResult;
        saveResult = client.save();

        switch (saveResult)
        {
            case clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "Account updated Successfully :)\n";
                _printClient(client);
                break;
            }
            case clsBankClient::enSaveResults::svFalidEmptyObject:
            {
                cout <<"\nError account was not saved because it's Empty";
                break;
            }
            case clsBankClient::enSaveResults::svFalidAccountNumberExist:
            {
                cout <<"\nError account was not saved because account number is exist";
                break;
            }

        }

    }
};