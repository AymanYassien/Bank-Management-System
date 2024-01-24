//
// Created by Ayman yassien on 01/01/2024 AD.
//

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
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
    static void showFindUserScreen()
    {
        clsScreen::_drawScreenHeader("\t\t Find User Screen");

        string userName = "";

        cout << "\nPlease Enter Username: ";
        userName = clsInputValidate::readString();
        while(!clsUser::isUserExist(userName))
        {
            cout << "\nUsername is not found, choose another one: ";
            userName = clsInputValidate::readString();
        }

        clsUser user = clsUser::find(userName);
        if (!user.isEmpty())
        {
            cout << "\nUser Found :)\n";
        }
        else
        {
            cout << "\nUser Was not Found :(\n";
        }
        _printUser(user);

    }

};
