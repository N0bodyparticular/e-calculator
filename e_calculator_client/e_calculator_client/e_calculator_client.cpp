// e_calculator_client.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.ttmath.org/online_calculator
#include <iostream>
#include <vector>

int calculate_e_section(long int section); // Calculates a section of e. The algorithm can be extended on forever therefore 

struct e_value {
	int integer_part;
	std::vector<int> invert_factorial_parts;
};





int main()
{
	printf("Hello, World!\n");
	printf("Awaiting command to calculate digits.\n");

	e_value e;
	e.integer_part = 1;

	for (int sec = 0; sec < 100; sec++) {
		 e.invert_factorial_parts.push_back(calculate_e_section(sec));
	}
	


	printf("Calculated: %f.\n", e);
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
