//
// Created by Ayman yassien on 01/01/2024 AD.
//

#include "clsScreen.h"
#include "clsUser.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen
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
    static void showUpdateUserScreen()
    {
        clsScreen::_drawScreenHeader("\t\t Update User Screen");
        string userName = "";

        cout << "\nPlease Enter UserName: ";
        userName = clsInputValidate::readString();
        while(!clsUser::isUserExist(userName))
        {
            cout << "\nUsername is not found, choose another one: ";
            userName = clsInputValidate::readString();
        }

        clsUser user = clsUser::find(userName);
        _printUser(user);

        cout << "\n\nUpdate User Info:";
        cout << "\n________________________\n";

        _readUserInfo(user);
        //user.setFirstName("Hammad");
//    user.setLastName(); to update specify .. not all

        clsUser::enSaveResults saveResult;
        saveResult = user.save();

        switch (saveResult)
        {
            case clsUser::enSaveResults::svSucceeded:
            {
                cout << "Account updated Successfully :)\n";
                _printUser(user);
                break;
            }
            case clsUser::enSaveResults::svFalidEmptyObject:
            {
                cout <<"\nError user was not saved because it's Empty";
                break;
            }
            case clsUser::enSaveResults::svFalidAccountNumberExist:
            {
                cout <<"\nError user was not saved because userName is exist";
                break;
            }

        }


    }

};
