#pragma once

class myString {
public:
	myString(const int* str, int n);
	myString();
	~myString();
	int setN(int _n) { n = _n; }
	int getN() const { return n; }
	friend ostream& operator<<(ostream& os, const myString& str);
	friend istream& operator>>(istream& os, myString& str);
	myString& operator=(const int* origin);
	myString& operator=(const myString origin);
	int& operator[](int i) const { return str[i]; }
	//print operator

private:
	int* str;
	int n;
};