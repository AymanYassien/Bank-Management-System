//
// Created by Ayman yassien on 06/01/2024 AD.
//

#include "clsUser.h"

class clsLoginRegisterScreen : protected clsScreen
{
    static void _printRecordLine(clsUser::stLoginRegisterRecord record)
    {
        cout << setw(9) << " " << "| " << setw(35) << left << record.date_time;
        cout << "| " << setw(19) << left << record.userName;
        cout << "| " << setw(15) << left << record.password;
        cout << "| " << setw(3) << right << record.permissions;
    }

public:
    static void showLoginScreen()
    {
        if(!checkAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }
        vector<clsUser::stLoginRegisterRecord> vLogs = clsUser::getLoginRegisterList();

        string subTitle = "\t\t\t(";
        subTitle += to_string(vLogs.size());
        subTitle += ")Record(s).";

        cout << setw(10) << " ";
        _drawScreenHeader("Login Register List Screen", subTitle);

        cout << '\n' << setw(8)  << " "  << "________________________________________________________________________________________________\n" << endl;
        cout << setw(9)  << " "  << "| " << setw(35) << left <<"Date/Time";
        cout << "| " << setw(19) << left <<"UserName";
        cout << "| " << setw(15) << left <<"Password";
        cout << "| " << setw(15) << left <<"Permissions";
        cout << '\n' << setw(8)  << " "  << "________________________________________________________________________________________________\n" << endl;


        if (vLogs.size() == 0)
        {
            cout << "\t\t\t\t\t\t\t\t\tNo Records Available in the System!";
        }
        else {
            for(clsUser::stLoginRegisterRecord r : vLogs)
            {
                _printRecordLine(r);
                cout << endl;
            }
        }
        cout << '\n' << setw(8)  << " "   << "________________________________________________________________________________________________\n" << endl;


    }

};
