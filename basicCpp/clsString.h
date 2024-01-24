//
// Created by Ayman yassien on 08/12/2023 AD.
#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString {

    string _value;
public:

    clsString()
    {
        _value = "";
    }
    clsString (string value)
    {
        _value = value;
    }

    void setValue(string value)
    {
        _value = value;
    }
    string getValue() {
        return _value;
    }

    static short countWords(string s1)
    {
        string delim = " "; // Delimiter

        short pos, counter = 0;
        string sWord;

        while ((pos = s1.find(delim)) != string::npos)
        {
            sWord = s1.substr(0, pos); // store the word
            if (sWord != "")
                counter ++;
            s1.erase(0, pos + delim.length());
        }
        if (s1 != "")
            counter ++;
        return counter;
    }
    short countWords()
    {
        return countWords(_value);
    }

    static vector<string> split(string s1, string delim = " ")
    {
        vector<string>vString;
        string sWrod;
        short pos;
        while((pos = s1.find(delim)) != string::npos)
        {
            sWrod = s1.substr(0, pos);
//            if (sWrod != "")
                vString.push_back(sWrod);
            s1.erase(0, pos + delim.length());
        }
        if (s1 != "")
            vString.push_back(s1);
        // modify it to read empty line .. at clsBankClient !

        return vString;
    }
    vector<string> split(){
        return split(_value, " ");
    }

    static char inverterCharCase( char c1)
    {
        return isupper(c1) ? tolower(c1) : toupper(c1);
    }
    static string invertAllCharCases(string s1)
    {
        for(char &i : s1)
            i = inverterCharCase(i);
        return s1;
    }
    string invertAllCharCases()
    {
        return invertAllCharCases(_value);
    }

    static string reverseWordsInString(string s1)
    {
        vector<string> vString;
        string S2 = "";

        vString = split(s1, " ");
        vector<string>::iterator iter = vString.end();// end + 1
        while (iter != vString.begin())
        {
            --iter;
            S2 += *iter + " ";
        }
        S2 = S2.substr(0, S2.length() - 1);// trimming the Extra Space at the End:
        return S2;
    }
    string reverseWordsInString(){
        return _value;
    }

    static string replaceWordInString(string s1, string stringToReplace, string sReplaceTo)
    {
        short pos =  s1.find(stringToReplace);

        while (pos != string :: npos)
        {
            s1 = s1.replace(pos, stringToReplace.length(), sReplaceTo);
            pos = s1.find(stringToReplace);
        }
        return s1;
    }
    string replaceWordInString(string stringToReplace, string sReplaceTo)
    {
        return replaceWordInString(_value, stringToReplace, sReplaceTo);
    }

    static string removePunctuationsFromString(string s1)
    {
        string s2 = "";

        for(char &i : s1)
            if (!ispunct(i))
                s2 += i;

        return s2;
    }
    string removePunctuationsFromString(){
        return (_value);
    }

    static void printFirstLetterOfEachWord(string s1)
    {
        bool isFirstLetter = true;

        cout << "\nFirst letters of this string: \n";

        for (char i : s1) {         // important idea
            if (i != ' ' && isFirstLetter)
                cout << i << endl;

            isFirstLetter = i == ' ';  // shorthand if  important idea
        }
    }
    void printFirstLetterOfEachWord()
    {
        return printFirstLetterOfEachWord(_value);
    }

    static void printEachWordInString(string s1)
    {
        for (char &i : s1){
            if (i != ' ')
                cout << i ;
            else
                cout << endl;
        }
        cout << endl;
    }
    void printEachWordInString()
    {
        return printFirstLetterOfEachWord(_value);
    }

    static void otherPrintEachWordInString(string s1)
    {
        string delim = " "; // Delimiter

        short Pos;
        string sWord;

        while ((Pos = s1.find(delim)) != string::npos)
        {
            sWord = s1.substr(0, Pos); // store the word
            if (sWord != "")
                cout << sWord << endl;
            s1.erase(0, Pos + delim.length());
        }
        if (s1 != "")
            cout << s1 << endl;
    }
    void otherPrintEachWordInString()
    {
        return otherPrintEachWordInString(_value);
    }

    enum  enMatch {Match = 1, Normal = 2};

    static vector<string> replaceWordInString(string s1, string delim, string stringToReplace, string sReplaceTo, enMatch enCase)
    {
        vector<string>vString;
        string sWrod;
        short pos; string emer;
        if (enCase == Normal){
            emer = tolower(stringToReplace[0]);
            for (int i = 1; i < stringToReplace.length(); ++i)
                emer +=stringToReplace[i];
        }
        while((pos = s1.find(delim)) != string::npos)
        {
            sWrod = s1.substr(0, pos);
            if (sWrod == stringToReplace || sWrod == emer )
                sWrod = sReplaceTo;
            if (sWrod != "")
                vString.push_back(sWrod);
            s1.erase(0, pos + delim.length());
        }
        if (s1 != "")
            vString.push_back(s1);

        return vString;
    }
    vector<string> replaceWordInString(string delim, string stringToReplace, string sReplaceTo, enMatch enCase)
    {
        return replaceWordInString(_value, delim, stringToReplace, sReplaceTo, enCase);
    }

    static string  readString()
    {
        string S1;
        cout << "Please Enter your string?\n";
        getline(cin, S1);
        return S1;
    }
    static char  readChar()
    {
        char ch1;
        cout << "\nPlease Enter a character?\n";
        cin >> ch1;
        return ch1;
    }

    static short countChar(char ch1, string S1)
    {
        short counter = 0;
        for (char &Ch : S1 )
            if (Ch == ch1)
                counter ++;
        return counter;
    }
    short countChar(char ch1){
        return countChar( ch1, _value);
    }

    static string joinVector(vector<string> vString, string delim)
    {
        string s1;

        for (string & i : vString) {
            s1 += i + delim;
        }
        return s1.substr(0, s1.length() - delim.length());
    }

    static short length(string s1)
    {
        return s1.length();
    };
    short length()
    {
        return _value.length();
    };

    static string  lowerFirstLetterOfEachWord(string s1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < s1.length(); i++)
        {

            if (s1[i] != ' ' && isFirstLetter)
            {
                s1[i] = tolower(s1[i]);

            }

            isFirstLetter = (s1[i] == ' ' ? true : false);

        }

        return s1;
    }
    void  lowerFirstLetterOfEachWord()
    {


        // no need to return value , this function will directly update the object value
        _value = lowerFirstLetterOfEachWord(_value);
    }

    static string  upperAllString(string s1)
    {
        for (short i = 0; i < s1.length(); i++)
        {
            s1[i] = toupper(s1[i]);
        }
        return s1;
    }
    void  upperAllString()
    {
        _value = upperAllString(_value);
    }

    static string  lowerAllString(string s1)
    {
        for (short i = 0; i < s1.length(); i++)
        {
            s1[i] = tolower(s1[i]);
        }
        return s1;
    }
    void  lowerAllString()
    {
        _value = lowerAllString(_value);
    }

    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
    static short countLetters(string s1, enWhatToCount whatToCount = enWhatToCount::All)
    {

        if (whatToCount == enWhatToCount::All)
        {
            return s1.length();
        }

        short Counter = 0;

        for (short i = 0; i < s1.length(); i++)
        {

            if (whatToCount == enWhatToCount::CapitalLetters && isupper(s1[i]))
                Counter++;


            if (whatToCount == enWhatToCount::SmallLetters && islower(s1[i]))
                Counter++;


        }

        return Counter;

    }
    static short  countCapitalLetters(string s1)
    {
        short counter = 0;
        for (short i = 0; i < s1.length(); i++)
            if (isupper(s1[i]))
                counter++;
        return counter;
    }
    short  countCapitalLetters()
    {
        return countCapitalLetters(_value);
    }

    static short  countSmallLetters(string s1)
    {

        short Counter = 0;

        for (short i = 0; i < s1.length(); i++)
        {

            if (islower(s1[i]))
                Counter++;

        }

        return Counter;
    }
    short  countSmallLetters()
    {
        return countSmallLetters(_value);
    }

    static short  countSpecificLetter(string s1, char letter, bool matchCase = true)
    {

        short counter = 0;

        for (short i = 0; i < s1.length(); i++)
        {

            if (matchCase)
            {
                if (s1[i] == letter)
                    counter++;
            }
            else
            {
                if (tolower(s1[i]) == tolower(letter))
                    counter++;
            }

        }

        return counter;
    }
    short  countSpecificLetter( char letter, bool matchCase = true)
    {
        return countSpecificLetter(_value,letter, matchCase);
    }
    static bool isVowel(char ch1)
    {
        ch1 = tolower(ch1);

        return ((ch1 == 'a') || (ch1 == 'e') || (ch1 == 'i') || (ch1 == 'o') || (ch1 == 'u'));

    }

    static short  countVowels(string s1)
    {
        short counter = 0;

        for (short i = 0; i < s1.length(); i++)
            if (isVowel(s1[i]))
                counter++;
        return counter;
    }
    short  countVowels()
    {
        return countVowels(_value);
    }

    static string trimLeft(string s1)
    {
        for (short i = 0; i < s1.length(); i++)
            if (s1[i] != ' ')
                return s1.substr(i, s1.length() - i);
        return "";
    }
    void trimLeft()
    {
        _value = trimLeft(_value);
    }

    static string trimRight(string s1)
    {
        for (short i = s1.length() - 1; i >= 0; i--)
            if (s1[i] != ' ')
                return s1.substr(0, i + 1);
        return "";
    }
    void trimRight()
    {
        _value = trimRight(_value);
    }

    static string trim(string s1)
    {
        return (trimLeft(trimRight(s1)));

    }
    void trim()
    {
        _value= trim(_value);
    }




};
