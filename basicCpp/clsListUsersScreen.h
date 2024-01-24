//
// Created by Ayman yassien on 23/12/2023 AD.
//

#pragma once
#include "clsUser.h"
#include "clsScreen.h"

class clsListUsersScreen : protected clsScreen
{
private:
    static void _printUserRecordLine(clsUser user)
    {
        cout << setw(8) << " " << "| " << setw(10) << left << user.getUserName();
        cout << "| " << setw(17) << left << user.getFullName();
        cout << "| " << setw(12) << left << user.getPhone();
        cout << "| " << setw(23) << left << user.getEmail();
        cout << "| " << setw(10) << left << user.getPassword();
        cout << "| " << setw(12) << left << user.getPermissions();
    }

public:
    static void showUsersList()
    {
        vector<clsUser> vUsers = clsUser::getUsersList();

        string subTitle = "\t\t\t(";
        subTitle += to_string(vUsers.size());
        subTitle += ")Users(s).";

        cout << setw(10) << " ";
        clsScreen::_drawScreenHeader("\t\tUsers List",  subTitle);

        cout << '\n' << setw(8)  << " "  << "________________________________________________________________________________________________\n" << endl;
        cout << setw(8)  << " "  << "| " << setw(10) << left <<"User Name";
        cout << "| " << setw(17) << left <<"Full Name";
        cout << "| " << setw(12) << left <<"Phone";
        cout << "| " << setw(23) << left <<"Email";
        cout << "| " << setw(10) << left <<"Password";
        cout << "| " << setw(12) << left <<"Permissions";
        cout << '\n' << setw(8)  << " "  << "________________________________________________________________________________________________\n" << endl;


        if (vUsers.size() == 0)
        {
            cout << "\t\t\t\t\t\t\t\t\tNo Users Available in the System!";
        }
        else {
            for(clsUser u : vUsers)
            {
                _printUserRecordLine(u);
                cout << endl;
            }
        }
        cout << '\n' << setw(8)  << " "   << "________________________________________________________________________________________________\n" << endl;


    }

};