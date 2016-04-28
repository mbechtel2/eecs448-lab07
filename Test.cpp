#include <iostream>
#include <vector>
#include "Test.h"

int Test::testsPassed()
{
	int passed = 0;

	if (objExists()) { passed++; }
	if (objGone()) { passed++; }
	if (emptyList()) { passed++; }
	if (nonEmptyList()) { passed++; }
	if (getSize()) { passed++; }
	if (rightValue()) { passed++; }
	if (rightVector()) { passed++; }
	if (prepend()) { passed++; }
	if (append()) { passed++; }
	if (unshift()) { passed++; }
	if (pop()) { passed++; }
	if (frontGone()) { passed++; }
	if (backGone()) { passed++; }
	if (frontRemoveBack()) { passed++; }

	return passed;
}

bool Test::objExists()
{
	std::cout << "Test 1: Constructor creates an object -> ";

	//Create a list pointer
	LinkedList<int>* list = new LinkedList<int>();

	//Create a bool variable
	bool test = false;

	//Determine that the pointer is pointing to an object and print out the result
	if (list != nullptr)
	{
		test = true;
		std::cout << "PASS";
	}
	else
	{
		std::cout << "FAIL";
	}
	std::cout << "\n";

	//Delete list and set pointer to null
	delete list;
	list = nullptr;

	//Return bool variable
	return test;
}

bool Test::objGone()
{
	std::cout << "Test 2: Destructor removes all nodes in the list -> ";

	//Create a list pointer
	LinkedList<int>* list = new LinkedList<int>();

	//Create a bool variable
	bool test = false;
	
	//Add a value to the list
	list->addFront(1);

	//Deconstruct the list
	list->~LinkedList();

	//Determine if list is empty and print out results
	if (list->size() == 0)
	{
		test = true;
		std::cout << "PASS";
	}
	else
	{
		std::cout << "FAIL";
	}
	std::cout << "\n";

	//Delete the list and set the pointer to null
	delete list;
	list = nullptr;

	//Return the bool variable
	return test;
}

bool Test::emptyList()
{
	std::cout << "Test 3: isEmpty returns true for an empty list-> ";

	//Create a list and a bool variable
	LinkedList<int> list;
	bool test = false;

	//Determine if the list is empty and print out the result
	if (list.isEmpty())
	{
		test = true;
		std::cout << "PASS";
	}
	else
	{
		std::cout << "FAIL";
	}
	std::cout << "\n";

	//Return the bool variable
	return test;
}

bool Test::nonEmptyList()
{
	std::cout << "Test 4: isEmpty returns false for a non-empty list-> ";

	//Create a list and add an element to it
	LinkedList<int> list;
	list.addBack(1);

	//Create a bool variable
	bool test = false;

	//Determine if the list is not empty and print out the result
	if (!list.isEmpty())
	{
		test = true;
		std::cout << "PASS";
	}
	else
	{
		std::cout << "FAIL";
	}
	std::cout << "\n";

	//Return the bool variable
	return test;
}

bool Test::getSize()
{
	std::cout << "Test 5: getSize returns the correct value-> ";

	//Create a list and add three elements to it
	LinkedList<int> list;
	list.addBack(1);
	list.addBack(2);
	list.addBack(3);

	//Create a bool variable
	bool test = false;

	//Get the size of the list
	int temp = list.size();

	//Determine if the size is 3 and print out the result
	if (list.size() == 3)
	{
		test = true;
		std::cout << "PASS";
	}
	else
	{
		std::cout << "FAIL, expected 3 but got " << temp;
	}
	std::cout << "\n";

	//Return the bool variable
	return test;
}

bool Test::rightValue()
{
	std::cout << "Test 6: search returns true when value is present-> ";

	//Create a list and add an element to it
	LinkedList<int> list;
	list.addBack(1);

	//Create a bool variable
	bool test = false;

	//Determine if the given element is in the list and print out the result
	if (list.search(1))
	{
		test = true;
		std::cout << "PASS";
	}
	else
	{
		std::cout << "FAIL";
	}
	std::cout << "\n";

	//Return the bool variable
	return test;
}

bool Test::rightVector()
{
	std::cout << "Test 7: toVector returns a vector with the correct values-> ";

	//Create a list and add three elements to it
	LinkedList<int> list;
	list.addFront(0);
	list.addFront(1);
	list.addFront(2);

	//Create a bool variable
	bool test = true;

	//Create a vector that contains the list's elements
	std::vector<int> vec = list.toVector();

	//Create a vector and add the same elements to it as the list
	std::vector<int> vec2;
	vec2.push_back(2);
	vec2.push_back(1);
	vec2.push_back(0);

	//Determine if the vectors are the same and change the bool variable if they aren't
	if (vec != vec2)
	{
		test = false;
	}

	//Print out the result
	if (test)
	{
		std::cout << "PASS";
	}
	else
	{
		std::cout << "FAIL";
	}
	std::cout << "\n";

	//Return the bool variable
	return test;
}

bool Test::append()
{
	std::cout << "Test 8: addFront adds an item to the front of the list-> ";

	//Create a list and add an element to it
	LinkedList<int> list;
	list.addFront(4);

	//Create a bool variable
	bool test = false;

	//Determine if the list's size is greater than 1 and print out the result
	if (list.size() > 1)
	{
		std::cout << "PASS";
		test = true;
	}
	else
	{
		std::cout << "FAIL";
	}
	std::cout << "\n";

	//Return the bool variable
	return test;
}

bool Test::prepend()
{
	std::cout << "Test 8: addBack adds an item to the front of the list-> ";

	//Create a list and add an element to it
	LinkedList<int> list;
	list.addBack(1);

	//Create a bool variable
	bool test = true;

	//Determine if the list's size is greater than 1 and print out the result
	if (list.size() > 1)
	{
		std::cout << "PASS";
		test = true;
	}
	else
	{
		std::cout << "FAIL";
	}
	std::cout << "\n";

	//Return the bool variable
	return test;
}

bool Test::unshift()
{
	std::cout << "Test 9: removeFront removes an item from the list-> ";

	//Create a list and add 3 elements to it
	LinkedList<int> list;
	list.addBack(1);
	list.addBack(2);
	list.addBack(3);

	//Get the size of the list
	int temp = list.size();

	//Create a bool variable
	bool test = false;

	//Remove the front element
	list.removeFront();

	//Determine if the size is now 1 less and print out the result
	if (list.size() == temp - 1)
	{
		test = true;
		std::cout << "PASS";
	}
	else
	{
		std::cout << "FAIL";
	}
	std::cout << "\n";

	//Return the bool variable
	return test;
}

bool Test::pop()
{
	std::cout << "Test 10: removeBack removes an item from the list-> ";

	//Create a list and add 3 elements to it
	LinkedList<int> list;
	list.addBack(1);
	list.addBack(2);
	list.addBack(3);

	//Get the size of the list
	int temp = list.size();

	//Create a bool variable
	bool test = false;

	//Remove an element from the list
	list.removeBack();

	//Determine if tthe size is 1 less and print out the result
	if (list.size() == temp - 1)
	{
		test = true;
		std::cout << "PASS";
	}
	else
	{
		std::cout << "FAIL";
	}
	std::cout << "\n";

	//Return the bool variable
	return test;
}

bool Test::frontGone()
{
	std::cout << "Test 11: removeFront removes the front item from the list-> ";

	//Create a list and add 3 elements to it
	LinkedList<int> list;
	list.addBack(1);
	list.addBack(2);
	list.addBack(3);

	//Create a bool variable
	bool test = false;

	//Remove the front element
	list.removeFront();

	//Determine if the removed element is still in the list and print out the result
	if (!list.search(1))
	{
		test = true;
		std::cout << "PASS";
	}
	else
	{
		std::cout << "FAIL";
	}
	std::cout << "\n";

	//Return the bool variable
	return test;
}

bool Test::backGone()
{
	std::cout << "Test 12: removeBack removes the back item from the list-> ";

	//Create a list and add 3 elements to it
	LinkedList<int> list;
	list.addBack(1);
	list.addBack(2);
	list.addBack(3);

	//Create a bool variable
	bool test = false;

	//Remove the back of the list
	list.removeBack();

	//Determine if the removed element is still in the list and print out the result
	if (!list.search(3))
	{
		test = true;
		std::cout << "PASS";
	}
	else
	{
		std::cout << "FAIL";
	}
	std::cout << "\n";

	//Return the bool variable
	return test;
}

bool Test::frontRemoveBack()
{
	std::cout << "Test 13: removeFront removes the back item from the list-> ";

	//Create a list and add 3 elements to it
	LinkedList<int> list;
	list.addBack(1);
	list.addBack(2);
	list.addBack(3);

	//Create a bool variable
	bool test = false;

	//Remove an element from the list
	list.removeFront();

	//Determine if the element removed was the last element and print out the result
	if (!list.search(3))
	{
		test = true;
		std::cout << "PASS";
	}
	else
	{
		std::cout << "FAIL";
	}
	std::cout << "\n";

	//Return the bool variable
	return test;
}