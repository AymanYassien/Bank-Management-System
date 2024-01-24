//
// Created by Ayman yassien on 01/01/2024 AD.
//
#pragma once
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "global.h"

class clsLoginScreen : protected clsScreen
{
private:
    static bool _login()
    {
        bool loginFailed = false;
        short failedLoginCounter = 0;
        string userName, password;
        do
        {
            if (loginFailed)
            {
                failedLoginCounter++;

                cout << "\nInvalid UserName/Password!\n";
                cout << "You have " << 3 -failedLoginCounter << " Trial(s) to Login.\n\n";
            }

            if (failedLoginCounter == 3)
            {
                cout << "\nYou are Locked after 3 failed trails\n";
                return false;
            }

            cout << "Enter UserName: ";
            cin >> userName;

            cout << "Enter Password: ";
            cin >> password;

            currentUser = clsUser::find(userName, password);

            if (currentUser.isEmpty())
            {
                loginFailed = true;
            }

        } while (loginFailed);

        currentUser.registerLogin();
        clsMainScreen::showMainMenu();
        return true;

    }
public:
    static bool showLoginScreen()
    {
        _drawScreenHeader("\t\t Login Screen");
        return _login();

    }

};
