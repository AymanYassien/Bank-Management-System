// Created by Ayman yassien on 17/12/2023 AD.

#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include <vector>
#include <fstream>
#include "global.h"
#include "clsUtil.h"

using namespace std;

class clsBankClient : public clsPerson
{
public:
    struct stTransferLogRecord
    {
        string date_time   = "";
        string srcAcc      = "";
        string disAcc      = "";
        string amount      = "";
        string srcBalance  = "";
        string disBalance  = "";
        string userName    = "";
    };

private:

    enum enMode {emptyMode = 0, updateMode = 1, addNewMode = 2};
    enMode _mode;

    string _accountNumber;
    string _pinCode;
    double _accountBalance;
    bool _markForDelete = false;

    // static because static in public call only static members .
    static clsBankClient _convertLinetoClientObject(string line, string separator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::split(line, separator);

        return clsBankClient(enMode::updateMode, vClientData[0], vClientData[1],
                             vClientData[2], vClientData[3], vClientData[4], vClientData[5],
                              stod(vClientData[6]));
    }

    static clsBankClient _getEmptyClient()
    {
        return clsBankClient(enMode::emptyMode, "", "", "",
                             "", "", "", 0);
    }

    static string _convertClientObjectToLine(clsBankClient client, string separator = "#//#")
    {
        string line = "";
        line+= client.getFirstName() + separator;
        line+= client.getLastName() + separator;
        line+= client.getEmail() + separator;
        line+= client.getPhone() + separator;
        line+= client.getAccountNumber() + separator;
        line+= client.getPinCode() + separator;
        line+= to_string(client.getAccountBalance());

        return line;
    }

    static vector<clsBankClient> _loadClientsDataFromFile()
    {
        vector<clsBankClient> vClients;

        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/clients.txt", ios::in);//read Mode

        if (myFile.is_open())
        {

            string line;

            while (getline(myFile, line))
            {

                clsBankClient client = _convertLinetoClientObject(line);
                vClients.push_back(client);
            }

            myFile.close();

        }

        return vClients;
    }

    static void _saveClientsDateToFile(vector<clsBankClient> vClients)
    {
        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/clients.txt", ios::out); // overwrite

        string dataLine;

        if (myFile.is_open())
        {

            for (clsBankClient c: vClients)
            {
                if (c._markForDelete == false)
                {
                    dataLine = _convertClientObjectToLine(c);
                    myFile << dataLine << endl;
                }
            }
            myFile.close();
        }

    }

    void _update()
    {
        vector<clsBankClient> vClients;
        vClients = _loadClientsDataFromFile();

        for(clsBankClient & c : vClients)
        {
            if (c.getAccountNumber() == getAccountNumber())
            {
                c = *this;
                break;
            }
        }

        _saveClientsDateToFile(vClients);
    }

    void _addNew()
    {
        return _addDataLineToFile(_convertClientObjectToLine(*this));
    }

    void _addDataLineToFile(string dataLine)
    {

        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/clients.txt", ios::out | ios::app); // append

        if (myFile.is_open())
        {
            myFile << dataLine << endl ;
            myFile.close();
        }
    }

    string _prepareTransferRecord(double amount,clsBankClient destinationClient, string userName, string separator = "#//#")
    {
        string loginRecord = "";

        loginRecord += clsDate::getSystemDateAndTimeString() += separator;
        loginRecord += this->getAccountNumber() + separator;
        loginRecord += destinationClient.getAccountNumber() + separator;
        loginRecord += to_string(amount) + separator;
        loginRecord += to_string(this->getAccountBalance()) + separator;
        loginRecord += to_string(destinationClient.getAccountBalance()) + separator;
        loginRecord += userName ;

        return loginRecord;
    }

    void _registerTransferLog(double amount, clsBankClient destinationClient, string userName)
    {

        string stDataLine = _prepareTransferRecord(amount, destinationClient, userName);

        fstream myFile;
        myFile.open("/Users/aymanyassien/DocumentsCLionProjects/basicCpp/transferLog.txt", ios::out | ios::app);

        if (myFile.is_open())
        {

            myFile << stDataLine << endl;

            myFile.close();
        }
    }

    static stTransferLogRecord _convertTransferLoRecordToLine(string line, string separator = "#//#")
    {
        vector<string> vRecords = clsString::split(line, separator);
        stTransferLogRecord record ;

        record.date_time  = vRecords[0];
        record.srcAcc     = vRecords[1];
        record.disAcc     = vRecords[2];
        record.amount     = vRecords[3];
        record.srcBalance = vRecords[4];
        record.disBalance = vRecords[5];
        record.userName   = vRecords[6];

        return record;
    }

public:

    clsBankClient(enMode mode, string firstName, string lastName, string email, string phone,
                  string accountNumber, string pinCode, double accountBalance)
                  : clsPerson(firstName, lastName, email, phone)
    {
        _mode = mode;
        _accountNumber = accountNumber;
        _pinCode = pinCode;
        _accountBalance = accountBalance;

    }

    bool isEmpty()
    {
        return (_mode == enMode::emptyMode);
    }

    string getAccountNumber()
    {
        return _accountNumber;
    }

    void setPinCode(string pinCode)
    {
        _pinCode = pinCode;
    }
    string getPinCode()
    {
        return _pinCode;
    }

    void setAccountBalance(double accountBalance)
    {
        _accountBalance = accountBalance;
    }
    double getAccountBalance()
    {
        return _accountBalance;
    }

    /*void print()
    {
        cout << "\nClient Card:";
        cout << "\n------------------------";
        cout << "\nFirstName     : " << getFirstName();
        cout << "\nLastName      : " << getLastName();
        cout << "\nFullName      : " << getFullName();
        cout << "\nEmail         : " << getEmail();
        cout << "\nPhone         : " << getPhone();
        cout << "\nAcc. Number   : " << _accountNumber;
        cout << "\nPassword      : " << _pinCode;
        cout << "\nBalance       : " << _accountBalance ;
        cout << "\n------------------------";

    }*/

    static clsBankClient find (string accountNumber)
    {
        vector<clsBankClient> vClients;

        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/clients.txt", ios::in); // readMode

        if (myFile.is_open())
        {
            string line;
            while(getline(myFile, line))
            {
                clsBankClient client = _convertLinetoClientObject(line);
                if (client.getAccountNumber() == accountNumber)
                {
                    myFile.close();
                    return client;
                }
                vClients.push_back(client);
            }
            myFile.close();
        }

        return _getEmptyClient();
    }

    static clsBankClient find (string accountNumber, string pinCode)
    {
        vector<clsBankClient> vClients;

        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/clients.txt", ios::in); // readMode

        if (myFile.is_open())
        {
            string line;
            while(getline(myFile, line))
            {
                clsBankClient client = _convertLinetoClientObject(line);
                if (client.getAccountNumber() == accountNumber && client.getPinCode() == pinCode)
                {
                    myFile.close();
                    return client;
                }
                vClients.push_back(client);
            }
            myFile.close();
        }

        return _getEmptyClient();
    }

    static bool isClientExist (string accountNumber)
    {
        // this to access is empty();
        clsBankClient client = clsBankClient::find(accountNumber);

        return (!client.isEmpty());
    }

    enum enSaveResults {svFalidEmptyObject = 0, svSucceeded = 1, svFalidAccountNumberExist = 2};
    enSaveResults save ()
    {

        switch (_mode) {

            case enMode::emptyMode:
            {
                return enSaveResults::svFalidEmptyObject;
            }

            case enMode::updateMode:
            {
                _update();
                return enSaveResults::svSucceeded;
                break; // not execute any after return !
            }

            case enMode::addNewMode:
            {
                if (clsBankClient::isClientExist(_accountNumber))
                {
                    return enSaveResults::svFalidEmptyObject;
                }
                else
                {
                    _addNew();
                    _mode = enMode::updateMode;

                    return enSaveResults::svSucceeded;
                }
                break;
            }


        }

    }

    static clsBankClient getAddNewClientObj(string accountNumber)
    {
        return clsBankClient(enMode::addNewMode, "", "", "", "", accountNumber, "", 0);
    }

    bool Delete ()
    {
        vector<clsBankClient> vClients;
        vClients = _loadClientsDataFromFile();

        for(clsBankClient& c : vClients)
        {
            if (c.getAccountNumber() == _accountNumber)
            {
                c._markForDelete = true;
                break;
            }

        }

        _saveClientsDateToFile(vClients);
        *this = _getEmptyClient();

        return true;

    }

    static vector<clsBankClient> getClientsList()
    {
        return _loadClientsDataFromFile();
    }

    static double getTotalBalances()
    {
        vector<clsBankClient> vClients = clsBankClient::getClientsList();
        double  totalBalances = 0;

        for (clsBankClient c : vClients)
        {
            totalBalances+= c._accountBalance;
        }

        return totalBalances;
    }

    void deposit (double balance)
    {
        _accountBalance += balance;
        save();
    }

    bool withdraw (double balance)
    {
        if (balance > _accountBalance)
        {
            return false;
        }
        else
        {
            _accountBalance -= balance;
            save();
        }
        return true;
    }

    bool transfer (double amount, clsBankClient & destinationClient)
    {
        if (amount > _accountBalance)
        {
            return false;
        }
        else
        {
            withdraw(amount);
            destinationClient.deposit(amount);
            _registerTransferLog(amount, destinationClient, currentUser.getUserName()); // here best place to do log in transfer method
            return true;
        }
    }

    static vector<stTransferLogRecord> getTransferLogList()
    {
        vector<stTransferLogRecord> vLogs;

        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/transferLog.txt", ios::in);//read mode

        if (myFile.is_open())
        {
            string line ="";

            while (getline(myFile, line))
            {
                vLogs.push_back(_convertTransferLoRecordToLine(line));
            }

            myFile.close();
        }

        return vLogs;
    }
};
