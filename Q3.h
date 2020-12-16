#pragma once
#include <iostream>
#include <string>
#include "Stack.h"
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

using namespace std;

//Stack stack1, stack2, stack3;

string karatsubaStack(string x, string y, int n);
void karasubaHelper(ItemType* item, int n);
string add(string lhs, string rhs);
string subtract(string lhs, string rhs);




