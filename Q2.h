#pragma once
#include <iostream>
#include <string>
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

int recNum = 0;
int SecRecNum = 0;

using namespace std;

string karatsubaRec(string x, string y, int n);
string add(string lhs, string rhs);
string subtract(string lhs, string rhs);
