//
// Created by Ayman yassien on 01/01/2024 AD.
//
#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "global.h"

class clsAddNewUserScreen : protected clsScreen
{
private:
    static void _readUserInfo(clsUser& user)
    {

        cout << "Enter FirstName: ";
        user.setFirstName(clsInputValidate::readString());

        cout << "Enter LastName: ";
        user.setLastName(clsInputValidate::readString());

        cout << "Enter  Email: ";
        user.setEmail(clsInputValidate::readString());

        cout << "Enter  Phone: ";
        user.setPhone(clsInputValidate::readString());

        cout << "Enter Password: ";
        user.setPassword(clsInputValidate::readString());

        cout << "Enter permissions: ";
        user.setPermissions(_readPermissionsToSet());



    }

    static void _printUser(clsUser user)
    {
        cout << "\nUser Card:";
        cout << "\n------------------------";
        cout << "\nFirstName     : " << user.getFirstName();
        cout << "\nLastName      : " << user.getLastName();
        cout << "\nFullName      : " << user.getFullName();
        cout << "\nEmail         : " << user.getEmail();
        cout << "\nPhone         : " << user.getPhone();
        cout << "\nUSerName      : " << user.getUserName();
        cout << "\nPassword      : " << user.getPassword();
        cout << "\nPermissions   : " << user.getPermissions();
        cout << "\n------------------------";

    }

    static int _readPermissionsToSet()
    {
        int permissions = 0;
        char answer = 'n';

        cout << "Do You Want to Give Full access? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pTransations;
        }

        cout << "\nManage Users? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nLogin Registers? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y')
        {
            permissions += clsUser::enPermissions::pLoginRegister;
        }

        return permissions;
    }

public:
    static void showAddNewUserScreen()
    {
        clsScreen::_drawScreenHeader("\t\t Add New User Screen");
        string userName = "";

        cout << "\nplease Enter userName: ";
        userName = clsInputValidate::readString();

        while(clsUser::isUserExist(userName))
        {
            cout << "\nUserName is already exist, choose another one: ";
            userName = clsInputValidate::readString();
        }

        clsUser newUser = clsUser::getAddNewUserObj(userName);

        _readUserInfo(newUser);

        clsUser::enSaveResults saveResult;
        saveResult = newUser.save();

        switch (saveResult)
        {
            case clsUser::enSaveResults::svSucceeded:
            {
                cout << "User updated Successfully :)\n";
                _printUser(newUser);
                break;
            }
            case clsUser::enSaveResults::svFalidEmptyObject:
            {
                cout <<"\nError User was not saved because it's Empty";
                break;
            }
            case clsUser::enSaveResults::svFalidAccountNumberExist:
            {
                cout <<"\nError UserName was not saved because UserName is exist";
                break;
            }

        }

    }

};
