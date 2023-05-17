#ifndef __INPUTFUNCTIONS
#define __INPUTFUNCTIONS

#include "User.h"
#include "FanPage.h"
#include "Status.h"
#include <String>

class InputFunctions
{
public:
    User& getNewUser();
    int      getValidMenuChoice(int maxNumber);
    FanPage& getNewFanPage();
    Status& getNewStatus();
    string   getMemeberName();
    string   getPageName();

};
#endif