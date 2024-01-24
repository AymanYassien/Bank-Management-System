//
// Created by Ayman yassien on 23/12/2023 AD.
//

#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{
    // 'stub function' in programming: initiate functions and print statement in body to ensure its work,
    // then update it later

    enum enManageUsersMenuOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenu = 6
    };

    static short _readManageUsersOption()
    {
        cout << setw(39) << left << " "  << "Choose what do you want to do? [1 to 6]? ";
        short choice = 0;
        choice = clsInputValidate::readShortNumberBetween(1,6, "\nEnter Number Between 1 , 6 ");

        return choice;
    }

    static void _showAllUsersScreen()
    {
        //cout << "\nUsers Screen Will be here ...\n";
        clsListUsersScreen::showUsersList();
    }

    static void _showAddNewUserScreen()
    {
        //cout << "\nAdd New User Screen Will be here ...\n";
        clsAddNewUserScreen::showAddNewUserScreen();

    }

    static void _showDeleteUserScreen()
    {
        //cout << "\nDelete User Screen Will be here ...\n";
        clsDeleteUserScreen::shoeDeleteUserScreen();

    }

    static void _showUpdateUpdateScreen()
    {
        //cout << "\nUpdate User Screen Will be here ...\n";
        clsUpdateUserScreen::showUpdateUserScreen();

    }

    static void _showFindUserScreen()
    {
        //cout << "\nFind User Screen Will be here ...\n";
        clsFindUserScreen::showFindUserScreen();

    }

    static void _goBackToManageUsers()
    {
        cout << "\n\nPress any key to go back to Manage users menu...";

        // Clear the input buffer
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        // Wait for user input again (Enter key)
        cin.get();
        showManageUsersMenu();
    }

    static void _performManageUsersMenu(enManageUsersMenuOptions manageUsersOption)
    {
        switch (manageUsersOption)
        {
            case eListUsers:
            {
                _showAllUsersScreen();
                _goBackToManageUsers();
                break;
            }
            case eAddNewUser:
            {
                _showAddNewUserScreen();
                _goBackToManageUsers();
                break;
            }
            case eDeleteUser:
            {
                _showDeleteUserScreen();
                _goBackToManageUsers();
                break;
            }
            case eUpdateUser:
            {
                _showUpdateUpdateScreen();
                _goBackToManageUsers();
                break;
            }
            case eFindUser:
            {
                _showFindUserScreen();
                _goBackToManageUsers();
                break;
            }
            case eMainMenu:
            {

            }

        }
    }

public:
    static void showManageUsersMenu()
    {
        if(!checkAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }
        _drawScreenHeader("\t\tManage Users Screen");

        cout << setw(39) << left << " " << "===========================================\n";
        cout << setw(39) << left << " " << "\t\tManage Users Menu\n";
        cout << setw(39) << left << " " << "===========================================\n";
        cout << setw(39) << left << " " << "\t[1] Show Users List.\n";
        cout << setw(39) << left << " " << "\t[2] Add New User.\n";
        cout << setw(39) << left << " " << "\t[3] Delete User.\n";
        cout << setw(39) << left << " " << "\t[4] Update User Info.\n";
        cout << setw(39) << left << " " << "\t[5] Find User.\n";
        cout << setw(39) << left << " " << "\t[6] Logout.\n";
        cout << setw(39) << left << " " << "===========================================\n";

        _performManageUsersMenu((enManageUsersMenuOptions) _readManageUsersOption());




    }

};