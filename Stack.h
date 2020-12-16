#pragma once
#include "ItemType.h"
#include <string>

using namespace std;

class Stack {

public:
	Stack();
	~Stack();
	void MakeEmpty();
	int isEmpty();
	void Push(ItemType* item);
	ItemType* Pop();
	ItemType* Peak();

private:
	ItemType* top;
};