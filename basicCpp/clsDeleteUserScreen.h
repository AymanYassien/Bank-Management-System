//
// Created by Ayman yassien on 01/01/2024 AD.
//

#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
{
private:
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

public:
    static void shoeDeleteUserScreen()
    {
        clsScreen::_drawScreenHeader("\t\t Delete User Screen");
        string userName;

        cout << "Please Enter UserName: ";
        userName = clsInputValidate::readString();

        while (!clsUser::isUserExist(userName))
        {
            cout << "UserName is not exist, choose another one: ";
            userName = clsInputValidate::readString();
        }

        clsUser user  = clsUser::find(userName);
        _printUser(user);

        cout << "\nAre You sure you want to delete this user? Y/N";

        char choice;
        cin >> choice;

        if(choice == 'y' || choice == 'Y')
        {
            if (user.Delete())
            {
                cout << "\nUser Deleted Successfully\n";
                _printUser(user);
            }
            else
            {
                cout << "\nError, User was not deleted\n";
            }

        }

    }

};
