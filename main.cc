#include <iostream>

#include "Arduino.h"
#include "beep.ino"


bool check_test_case();

int main(int argc,char **argv)
{
	setup();
	loop();

	if( check_test_case() == false)
	{
		std::cout << "TEST FAIL" << std::endl;
	}
	else
	{
		std::cout << "TEST SUCCESS" << std::endl;
	}

	return 0;
}

