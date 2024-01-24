//
// Created by Ayman yassien on 23/12/2023 AD.
//

#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include <vector>
#include <fstream>
#include "clsUtil.h"

using namespace std;

class clsUser : public clsPerson
{
public:
    struct stLoginRegisterRecord
    {
        string date_time   = "";
        string userName    = "";
        string password    = "";
        string permissions = "";
    };

private:

    enum enMode {emptyMode = 0, updateMode = 1, addNewMode = 2};
    enMode _mode;

    string _userName;
    string _password;
    short _permissions;
    bool _markForDelete = false;

    // static because static in public call only static members .

    static clsUser _getEmptyUserObject()
    {
        return clsUser(enMode::emptyMode, "", "", "",
                             "", "", "", 0);
    }

    static clsUser _convertLinetoUserObject(string line, string separator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::split(line, separator);

        return clsUser(enMode::updateMode, vUserData[0], vUserData[1],
                             vUserData[2], vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5],2),
                             stod(vUserData[6]));
    }

    static string _convertUserObjectToLine(clsUser user, string separator = "#//#")
    {
        string line = "";
        line+= user.getFirstName() + separator;
        line+= user.getLastName() + separator;
        line+= user.getEmail() + separator;
        line+= user.getPhone() + separator;
        line+= user.getUserName() + separator;
        line+= clsUtil::EncryptText(user.getPassword(), 2) + separator;
        line+= to_string(user.getPermissions());

        return line;
    }

    static vector<clsUser> _loadUsersDataFromFile()
    {
        vector<clsUser> vUsers;

        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/users.txt", ios::in);//read Mode

        if (myFile.is_open())
        {

            string line;

            while (getline(myFile, line))
            {

                clsUser user = _convertLinetoUserObject(line);
                vUsers.push_back(user);
            }

            myFile.close();

        }

        return vUsers;
    }

    static void _saveUsersDateToFile(vector<clsUser> vUsers)
    {
        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/users.txt", ios::out); // overwrite

        string dataLine;

        if (myFile.is_open())
        {

            for (clsUser u: vUsers)
            {
                if (u._markForDelete == false)
                {
                    dataLine = _convertUserObjectToLine(u);
                    myFile << dataLine << endl;
                }
            }
            myFile.close();
        }

    }

    void _update()
    {
        vector<clsUser> vUsers;
        vUsers = _loadUsersDataFromFile();

        for(clsUser & u : vUsers)
        {
            if (u.getUserName() == getUserName())
            {
                u = *this;
                break;
            }
        }

        _saveUsersDateToFile(vUsers);
    }

    void _addNew()
    {
        return _addDataLineToFile(_convertUserObjectToLine(*this));
    }

    void _addDataLineToFile(string dataLine)
    {

        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/users.txt", ios::out | ios::app); // append

        if (myFile.is_open())
        {
            myFile << dataLine << endl ;
            myFile.close();
        }

    }

    string _prepareLogInRecord(string separator = "#//#")
    {
        string loginRecord = "";

        loginRecord += clsDate::getSystemDateAndTimeString() += separator;
//        loginRecord += _userName += separator; :: this is  added separator on userName == UserName#//#
        loginRecord += _userName;
        loginRecord += separator;
        loginRecord += clsUtil::EncryptText(_password, 2) ;
        loginRecord += separator;
        loginRecord += to_string(_permissions);

        return loginRecord;
    }

    static stLoginRegisterRecord _convertLoginRegisterLineToRecord(string line, string separator = "#//#")
    {
        vector<string> vSingleRegister = clsString::split(line, separator);
        stLoginRegisterRecord record;
        record.date_time   = vSingleRegister[0];
        record.userName    = vSingleRegister[1];
        record.password    = clsUtil::DecryptText(vSingleRegister[2],2);
        record.permissions = vSingleRegister[3];

        return record;

    }

public:

    enum enPermissions
    {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTransations = 32, pManageUsers = 64, pLoginRegister = 128
    };

    clsUser(enMode mode, string firstName, string lastName, string email, string phone,
                  string userName, string password, short permissions)
            : clsPerson(firstName, lastName, email, phone)
    {
        _mode = mode;
        _userName = userName;
        _password = password;
        _permissions = permissions;

    }

    bool isEmpty()
    {
        return (_mode == enMode::emptyMode);
    }

    bool markForDeleted()
    {
        return _markForDelete;
    }

    string getUserName()
    {
        return _userName;
    }
    void setUserName(string userName)
    {
         _userName = userName;
    }

    string getPassword()
    {
         //return clsUtil::DecryptText(_password, 2);
         return _password;
    }
    void setPassword(string password)
    {
        _password = password;
    }

    short getPermissions()
    {
        return _permissions;
    }
    void setPermissions(short permissions)
    {
        _permissions = permissions;
    }

    /*void print()
    {
        cout << "\nUser Card:";
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

    static clsUser find (string userName)
    {
        vector<clsUser> vUsers;

        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/users.txt", ios::in); // readMode

        if (myFile.is_open())
        {
            string line;
            while(getline(myFile, line))
            {
                clsUser user = _convertLinetoUserObject(line);
                if (user.getUserName() == userName)
                {
                    myFile.close();
                    return user;
                }
                vUsers.push_back(user);
            }
            myFile.close();
        }

        return _getEmptyUserObject();
    }

    static clsUser find (string userName, string password)
    {
        vector<clsUser> vUsers;

        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/users.txt", ios::in); // readMode

        if (myFile.is_open())
        {
            string line;
            while(getline(myFile, line))
            {
                clsUser user = _convertLinetoUserObject(line);
                if (user.getUserName() == userName && user.getPassword() == password)
                {
                    myFile.close();
                    return user;
                }
                vUsers.push_back(user);
            }
            myFile.close();
        }

        return _getEmptyUserObject();
    }

    static bool isUserExist (string userName)
    {
        // this to access is empty();
        clsUser user = clsUser::find(userName);

        return (!user.isEmpty());
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
                if (clsUser::isUserExist(_userName))
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

    static clsUser getAddNewUserObj(string accountNumber)
    {
        return clsUser(enMode::addNewMode, "", "", "", "", accountNumber, "", 0);
    }

    bool Delete ()
    {
        vector<clsUser> vUsers;
        vUsers = _loadUsersDataFromFile();

        for(clsUser& u : vUsers)
        {
            if (u.getUserName() == _userName)
            {
                u._markForDelete = true;
                break;
            }

        }

        _saveUsersDateToFile(vUsers);
        *this = _getEmptyUserObject();

        return true;

    }

    static vector<clsUser> getUsersList()
    {
        return _loadUsersDataFromFile();
    }

    bool checkAccessPermissions(enPermissions permissions)
    {
        if (this->getPermissions() == enPermissions::eAll)
            return true;

        if ((this->getPermissions() & permissions) ==  permissions)
            return true;

        return false;

    }

    void registerLogin()
    {

        string stDataLine = _prepareLogInRecord();

        fstream myFile;
        myFile.open("/Users/aymanyassien/DocumentsCLionProjects/basicCpp/loginRegister.txt", ios::out | ios::app);

        if (myFile.is_open())
        {

            myFile << stDataLine << endl;

            myFile.close();
        }
    }

    static vector<stLoginRegisterRecord> getLoginRegisterList()
    {
        vector<stLoginRegisterRecord> vLogs;

        fstream myFile;
        myFile.open("//Users/aymanyassien/DocumentsCLionProjects/basicCpp/loginRegister.txt", ios::in);//read mode

        if (myFile.is_open())
        {
            string line ="";

            while (getline(myFile, line))
            {
                vLogs.push_back(_convertLoginRegisterLineToRecord(line));
            }

            myFile.close();
        }

        return vLogs;
    }

};
