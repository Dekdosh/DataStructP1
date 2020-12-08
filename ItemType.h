#pragma once
#include <string>

using namespace std;

class ItemType
{
public:
	ItemType(string data, ItemType* next = nullptr);
	~ItemType();
	string getData() const;
	ItemType* getNext() const;
	void setData(string data);
	void setNext(ItemType* next);

private:
	string data;
	ItemType* next;

};

