//
// Created by Ayman yassien on 11/12/2023 AD.
//
#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include <cstdlib>

using namespace std;

class clsUtil{

public:

    enum  enCharType { smallLetter = 1, capitalLetter = 2,
            digital = 3 ,mixChars = 4, specialCharacter = 5 };

    static void Srand()
    {
        srand((unsigned)time(NULL)); // call once     : technicalTips
//        :: operator is used to indicate that srand is a function in the global namespace (not
//        a member of any class or namespace).
//        we need it because the function name is same it so we set it Srand
    }

    static int randomNumber(int from, int to)
    {
        int number = rand() % (to - from + 1) + from;

        return number;
    }

    static char getRandomChar(enCharType charType)
    {

        if(charType == mixChars)
            charType = (enCharType)randomNumber(1, 3);

        switch (charType)
        {
            case enCharType(smallLetter):{
                return char (randomNumber(97, 122));
                break;
            }
            case enCharType(capitalLetter):{
                return char (randomNumber(65, 90));
                break;
            }
            case enCharType(digital):{
                return char (randomNumber(48, 57));
                break;
            }
            case enCharType(specialCharacter):{
                return char (randomNumber(33, 47));
                break;
            }
            case enCharType(mixChars):{
                //this will not be .. will redirect in last if statement
                break;
            }

            /*
             * case enCharType(mixChars):{
                return char ((randomNumber(48, 57)) ||
                             randomNumber(65, 90) || randomNumber(97, 122) );
                break;
            }*/

        }
        return 'n';
        // this return will not happen just to avoid warning
    }


    static string generateWord(enCharType charType, short length)
    {
        string word ;

        for(int i = 0; i < length; i++)
        {
            word += char((int) getRandomChar(charType));
//            word += char((int) randomNumber(65, 90));
        }
        return word;
    }

    static string generateKey(enCharType charType)
    {
        string key;

        key = generateWord(charType, 4) + "-";
        key = key + generateWord(charType, 4) + "-";
        key = key + generateWord(charType, 4) + "-";
        key = key + generateWord(charType, 4) ;

        return key;
    }

    static void generateKeys(short numberOfKeys, enCharType charType){

        for (int i = 0; i < numberOfKeys; ++i)
        {
            cout << "Key [" << i << "] : ";
            cout << generateKey(charType) << endl;
        }
    }

    static void fillArrayWithRandomNumbers(int arr[100], short arrayLength, int from, int to )
    {
        for (int i = 0; i < arrayLength; i++)
            arr[i] = randomNumber(from, to);
    }

    static void fillArrayWithRandomWords(string arr[100], short arrayLength, enCharType charType, short wordLength )
    {
        for (int i = 0; i < arrayLength; i++)
            arr[i] = generateWord(charType, wordLength);
    }

    static void fillArrayWithRandomKeys(string arr[100], short arrayLength, enCharType charType)
    {
        for (int i = 0; i < arrayLength; ++i)
            arr[i] = generateKey(charType);
    }

    static void swap( int& var1, int& var2){
        int temp = 0;

        temp = var1;
        var1 = var2;
        var2 = temp;
    }

    static void swap( double& var1, double& var2){
        double temp = 0;

        temp = var1;
        var1 = var2;
        var2 = temp;
    }

    static void swap( string& var1, string& var2){
        string temp;

        temp = var1;
        var1 = var2;
        var2 = temp;
    }

    static void swap( bool& var1, bool& var2){
        bool temp;

        temp = var1;
        var1 = var2;
        var2 = temp;
    }

    static void swap( char& var1, char& var2){
        char temp;

        temp = var1;
        var1 = var2;
        var2 = temp;
    }

    static void swap( clsDate& var1, clsDate& var2){
        clsDate temp;

        temp = var1;
        var1 = var2;
        var2 = temp;
    }

    static void shuffleArray(int arr[100], short arrayLength)
    {
        for (int i = 0; i < arrayLength; i++)
            return swap(arr[randomNumber(1, arrayLength) - 1],
                        arr[randomNumber(1, arrayLength) - 1] );
    }

    static void shuffleArray(string arr[100], short arrayLength)
    {
        for (int i = 0; i < arrayLength; i++)
            return swap(arr[randomNumber(1, arrayLength) - 1],
                        arr[randomNumber(1, arrayLength) - 1] );
    }

    static string tabs(short tabsNumber){

        string tabs = "";

        for (short i = 0; i < tabsNumber; ++i)
            tabs += '\t' ;

        return tabs;
    }

    static string EncryptText(string text, short encryptionKey)
    {
        for (int i = 0; i <= text.length(); i++)
            text[i] = char((int) text[i] + encryptionKey);

        return text;
    }

    static string DecryptText(string text, short encryptionKey)
    {
        for (int i = 0; i <= text.length(); i++)
            text[i] = char((int) text[i] - encryptionKey);

        return text;
    }

    static string numberToText(int number)
    {

        if (number == 0)
        {
            return "";
        }

        if (number >= 1 && number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
                             "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
                             "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[number] + " ";

        }

        if (number >= 20 && number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[number / 10] + " " + numberToText(number % 10);
        }

        if (number >= 100 && number <= 199)
        {
            return  "One Hundred " + numberToText(number % 100);
        }

        if (number >= 200 && number <= 999)
        {
            return   numberToText(number / 100) + "Hundreds " + numberToText(number % 100);
        }

        if (number >= 1000 && number <= 1999)
        {
            return  "One Thousand " + numberToText(number % 1000);
        }

        if (number >= 2000 && number <= 999999)
        {
            return   numberToText(number / 1000) + "Thousands " + numberToText(number % 1000);
        }

        if (number >= 1000000 && number <= 1999999)
        {
            return  "One Million " + numberToText(number % 1000000);
        }

        if (number >= 2000000 && number <= 999999999)
        {
            return   numberToText(number / 1000000) + "Millions " + numberToText(number % 1000000);
        }

        if (number >= 1000000000 && number <= 1999999999)
        {
            return  "One Billion " + numberToText(number % 1000000000);
        }
        else
        {
            return   numberToText(number / 1000000000) + "Billions " + numberToText(number % 1000000000);
        }


    }


};

