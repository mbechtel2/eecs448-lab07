#ifndef TEST_H
#define TEST_H

#include "LinkedList.h"

class Test
{
public:
	int testsPassed();

	bool objExists();
	bool objGone();
	bool emptyList();
	bool nonEmptyList();
	bool getSize();
	bool rightValue();
	bool rightVector();
	bool prepend();
	bool append();
	bool unshift();
	bool pop();
	bool frontGone();
	bool backGone();
	bool frontRemoveBack();
};

#endif