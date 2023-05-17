#pragma warning(disable: 4996)
#include <iostream>
using namespace std;

#include "Facebook.h"
#include "InputFunctions.h"

/*
* Created by:
* Eden Ismah-Moshe  Group Num. 12111955
* Netanel Kuchma    Group Num. 12111955
*/

int main()
{
	set_terminate(newTerminate);
	Facebook system;
	InputFunctions input;
	system.automatic_data();
	system.run_manager_interface(input);

}