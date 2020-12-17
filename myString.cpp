#include "myString.h"
#include "iostream"
using namespace std;

myString::myString(const int* str, int n) {
	this->str = new int[n + 1];
	this->n = n;
	int i = 0;
	while (i<n) {
		this->str[i] = str[i] - '0';
		i++;
	}
}

myString::myString()
{
	this->str = nullptr;
}

myString::~myString()
{
	delete[] str;
}


myString& myString::operator=(const int* origin)
{
	if (str != nullptr)
		delete[]str;

	int* str= new int[n + 1];
	
	int i = 0;
	for (int i = 0; i < n+1; i++)
	{
		str[i] = origin[i];
	}
	return *this;
}

myString& myString::operator=(const myString origin)
{
	if (str != nullptr)
		delete[]str;
	
	str = new int[n+1];
	for (int i = 0; i < n+1; i++)
	{
		str[i] = origin.str[i];
	}
	return *this;
}


istream& operator>>(istream& is, myString& str)
{
	char* buffer= new char[str.getN() + 1];
	is.getline(buffer, str.getN() + 1);
	for (int i = 0; i < str.getN(); i++)
	{
		int a= int(buffer[i]);
		str[i] = a;
	}
	return is;
}

ostream& operator<<(ostream& os, const myString& str)
{
	for(int i = 0; i< str.getN() ; i++)
		os << str[i];
	return os;
}



