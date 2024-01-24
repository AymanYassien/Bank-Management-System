//
// Created by Ayman yassien on 20/12/2023 AD.
//

#pragma once
#include "clsMainScreen.h"
#include "clsBankClient.h"

class clsClientListScreen : protected clsScreen
{

private:
    static void _printClientRecordLine(clsBankClient client)
    {
        cout << setw(8) << " " << "| " << setw(15) << left <<client.getAccountNumber();
        cout << "| " << setw(20) << left <<client.getFullName();
        cout << "| " << setw(12) << left <<client.getPhone();
        cout << "| " << setw(20) << left <<client.getEmail();
        cout << "| " << setw(10) << left <<client.getPinCode();
        cout << "| " << setw(12) << left <<client.getAccountBalance();
    }

public:
    static void showClientsList()
    {
        if(!checkAccessRights(clsUser::enPermissions::pListClients))
        {
            return;
        }
        vector<clsBankClient> vClients = clsBankClient::getClientsList();

        string subTitle = "\t\t\t(";
        subTitle += to_string(vClients.size());
        subTitle += ")Client(s).";

        cout << setw(10) << " ";
        clsScreen::_drawScreenHeader("\t\tClients List",  subTitle);

//        cout << setw(8) << " " << "\n\t\t\t\t\tClient List(" << vClients.size() << ")Client(s).";
        cout << '\n' << setw(8)  << " "  << "________________________________________________________________________________________________\n" << endl;
        cout << setw(8)  << " "   << "| " << setw(15) << left <<"Account Number";
        cout << "| " << setw(20) << left <<"Client name";
        cout << "| " << setw(12) << left <<"Phone";
        cout << "| " << setw(20) << left <<"Email";
        cout << "| " << setw(10) << left <<"Pin Code";
        cout << "| " << setw(12) << left <<"Balance";
        cout << '\n' << setw(8)  << " "  << "________________________________________________________________________________________________\n" << endl;


        if (vClients.size() == 0)
        {
            cout << "\t\t\t\t\t\t\tNo Clients Available in the System!";
        }
        else {
            for(clsBankClient c : vClients)
            {
                _printClientRecordLine(c);
                cout << endl;
            }
        }
        cout << '\n' << setw(8)  << " "   << "________________________________________________________________________________________________\n" << endl;


    }

};
