#include <iostream>
#include "Test.h"
#include "LinkedList.h"
#include "Node.h"

int main(int argc, char** argv[])
{
	//Create a test object
	Test tester;

	//Create an int variable to hold the number of tests passed
	int passed = 0;

	//Run the tests from the tester class
	passed = tester.testsPassed();

	//Print out the total number of tests passed
	std::cout << "Total tests passed: " << passed << "\n";

	return 0;
}

