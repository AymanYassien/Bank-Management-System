//
// Created by Ayman yassien on 07/01/2024 AD.
//
#include "clsTransferScreen.h"

class clsTransferLogsScreen : protected clsScreen
{
    static void _printRecordLine(clsBankClient::stTransferLogRecord record)
    {
        cout << setw(9) << " " << "| " << setw(21) << left << record.date_time;
        cout << "| " << setw(10) << left << record.srcAcc;
        cout << "| " << setw(10) << left << record.disAcc;
        cout << "| " << setw(10) << left << record.amount;
        cout << "| " << setw(11) << left << record.srcBalance;
        cout << "| " << setw(11) << left << record.disBalance;
        cout << "| " << setw(11) << left << record.userName;

    }

public:
    static void showTransferLogsScreen()
    {

        vector<clsBankClient::stTransferLogRecord> vLogs = clsBankClient::getTransferLogList();

        string subTitle = "\t\t\t(";
        subTitle += to_string(vLogs.size());
        subTitle += ")Record(s).";

        cout << setw(10) << " ";
        _drawScreenHeader("Transfer Log List Screen", subTitle);

        cout << '\n' << setw(8)  << " "  << "________________________________________________________________________________________________\n" << endl;
        cout << setw(9)  << " "  << "| " << setw(21) << left <<"Date/Time";
        cout << "| " << setw(10) << left <<"s.Acct";
        cout << "| " << setw(10) << left <<"d.Acct";
        cout << "| " << setw(10) << left <<"Amount";
        cout << "| " << setw(11) << left <<"s.Balance";
        cout << "| " << setw(11) << left <<"d.Balance";
        cout << "| " << setw(11) << left <<"UserName";
        cout << '\n' << setw(8)  << " "  << "________________________________________________________________________________________________\n" << endl;


        if (vLogs.size() == 0)
        {
            cout << "\t\t\t\t\t\t\t\t\tNo Records Available in the System!";
        }
        else {
            for(clsBankClient::stTransferLogRecord r : vLogs)
            {
                _printRecordLine(r);
                cout << endl;
            }
        }
        cout << '\n' << setw(8)  << " "   << "________________________________________________________________________________________________\n" << endl;


    }

};
