#include "clsLoginScreen.h"

 //why save enum : validate if no while ?

int main()
{
   while(true)
   {
       //clsLoginScreen::showLoginScreen();
       // after logout :: go back here and start again, else u will crash in circular references.

       if (!clsLoginScreen::showLoginScreen()) {
           break;
       }
   }

    /*
     * focus code here (in main ) related to ui .. print .. objects only.
     * always any method do not need any from obj & modify any on it make it static.
     * make ui at separate pos and logic code at separation.
     * each screen has its own class.
     * build main screen ... ensure all options in this is run:: after validate all start to build another screens.
      */

    return 0;
}



