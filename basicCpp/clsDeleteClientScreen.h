//
// Created by Ayman yassien on 20/12/2023 AD.
//
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen
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

public:
    static void shoeDeleteClientScreen()
    {
        if(!checkAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }
        clsScreen::_drawScreenHeader("\t\t Delete Client Screen");
        string accountNumber;

        cout << "Please Enter account number: ";
        accountNumber = clsInputValidate::readString();

        while (!clsBankClient::isClientExist(accountNumber))
        {
            cout << "Account number is not exist, choose another one: ";
            accountNumber = clsInputValidate::readString();
        }

        clsBankClient client  = clsBankClient::find(accountNumber);
        _printClient(client);

        cout << "\nAre You sure you want to delete this client? Y/N";

        char choice;
        cin >> choice;

        if(choice == 'y' || choice == 'Y')
        {
            if (client.Delete())
            {
                cout << "\nClient Deleted Successfully\n";
                _printClient(client);
            }
            else
            {
                cout << "\nError, client was not deleted\n";
            }

        }

    }

};