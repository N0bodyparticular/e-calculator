// e_calculator_client.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.ttmath.org/online_calculator
#include <iostream>
#include <vector>
#include "ttmath/ttmath.h"

#define SIM_ITER_COUNT 10

int calculate_e_section(long int section); // Calculates a section of e. The algorithm can be extended on forever.

int main()
{
	printf("Hello, World!\n");
	//printf("Awaiting command to calculate digits.\n");

	ttmath::Big<512, 32> e;

	typedef ttmath::Big<512, 32> Working_big;
	ttmath::Parser<Working_big> parser;

	ttmath::Conv conv;
	conv.round = 15;

	

	for (int i = 0; i < SIM_ITER_COUNT; i++) {
		//e = e + ttmath::Big<10, 10>();
		ttmath::ErrorCode err = parser.Parse(" 1 / factorial( " + std::to_string(i) + " ) ");

		if (err == ttmath::err_ok) {
			printf(parser.stack[0].value.ToString(conv).c_str());
			printf("\n");
			e = e.Add(parser.stack[0].value);
		}
		else {
			printf("Error: %i.\n", static_cast<int>(err));
		}
	}
	

	printf("Calculated: ");
	printf(e.ToString(conv).c_str());
	printf("\n");
	printf("Done!");
}


int calculate_e_section(long int section)
{
	// calculate the factorial of section. the value of e is equal to 1/0! + 1/1! + 1/2! + 1/3!...

	int factorial = 1;
	for (int i = 1; i <= section; ++i)
	{
		factorial *= i;
	}
	return factorial;
}
