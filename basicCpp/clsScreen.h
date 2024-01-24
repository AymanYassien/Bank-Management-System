//
// Created by Ayman yassien on 18/12/2023 AD.
//
#pragma once
#include <iostream>
#include "iomanip"
#include "clsUser.h"
#include "global.h"
#include "clsDate.h"


class clsScreen
{

protected:

    static void _drawScreenHeader(string title, string subTitle = "")
    {
        cout << "\n\n";
        cout << setw(39) << left << " " << "  ______________________________________\n\n";
        cout << setw(39) << left << " "  << "      " << title ;
        if (subTitle != "")
        {
            cout << "\n"<< setw(39) << left << " "  << "  " << subTitle ;
        }
        cout << "\n";
        cout << setw(39) << left << " " << "  ______________________________________";
        cout << '\n';

        cout << setw(39) << left << " " << "  User: " << currentUser.getUserName();
        cout << "\n";
        cout << setw(39) << left << " " << "  Date:" << currentDate << endl;



    }

    static bool checkAccessRights(clsUser::enPermissions permissions)
    {
        if (!currentUser.checkAccessPermissions(permissions))
        {
            cout << "\n\n";
            cout << setw(39) << left << " " << "  ______________________________________\n\n";
            cout << setw(39) << left << " "  << "   Access Denied! Contact your admin\n" ;
            cout << setw(39) << left << " " << "  ______________________________________";

            return false;
        }
        return true;
    }

};
