//
// Created by Ayman yassien on 07/01/2024 AD.
//

#include "iostream"

using namespace std;

class interfaceCommunication // interface = contract or عقد || signature of contract = inherit
{
    // then u must apply all methods with same name and same parameters; else error compilation
    virtual void sendEmail (string title, string body) = 0; // override
    virtual void sendFax (string title, string body) = 0;
    virtual void sendSMS (string title, string body) = 0;
};