#include <iostream>
using namespace std;

//from main.cc
extern int button;
extern int piezo;
extern int led;

#include "Arduino.h"




bool test_case_piezo_mode=false;
bool test_case_led_mode=false;

bool test_case_digital_write=false;
bool test_case_tone=false;
bool test_case_no_tone=false;


void pinMode(uint8_t pin, uint8_t mode)
{
	if( pin == piezo && mode == OUTPUT)
	{
		test_case_piezo_mode = true;
	}
	else if ( pin == led && mode == OUTPUT)
	{
		test_case_led_mode = true;
	}
}

bool first_digital_write=false;
void digitalWrite(uint8_t pin, uint8_t val)
{
	if( first_digital_write == false )
	{
		if( pin == led && val == HIGH )
		{
			test_case_digital_write = true;
		}
		else
		{
			test_case_digital_write= false;
		}

		first_digital_write = true;
	}
	else
	{
		if( first_digital_write == true && test_case_digital_write == true)
		{
			if( pin == led && val == LOW )
			{
				test_case_digital_write = true;
			}
			else
			{
				test_case_digital_write = false;
			}
		}
	}
}

int digitalRead(uint8_t pin)
{
	if( pin == button )
	{
		return HIGH;
	}
	return LOW;
}


void delay(unsigned long ms)
{

}

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration)
{
	if ( _pin == piezo && frequency == 1000, duration == 500 )
	{
		test_case_tone = true;
	}
	else
	{
		test_case_tone = false;
	}
}

void noTone(uint8_t _pin)
{
	if( _pin == piezo )
	{
		test_case_no_tone = true;
	}
	else
	{
		test_case_no_tone = false;
	}
}

bool check_test_case()
{
	if( test_case_piezo_mode == false )
	{
		cout << __LINE__ << endl;
		return false;
	}

	if( test_case_led_mode == false )
	{
		cout << __LINE__ << endl;
		return false;
	}
	

	if( test_case_digital_write == false )
	{
		cout << __LINE__ << endl;
		return false;
	}

	if ( test_case_tone == false )
	{
		cout << __LINE__ << endl;
		return false;
	}

	if ( test_case_no_tone == false )
	{
		cout << __LINE__ << endl;
		return false;
	}

	return true;
}
