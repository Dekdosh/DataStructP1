#include "ItemType.h"

ItemType::ItemType(string x, string y, ItemType* next) {
	this->x = x;
	this->y = y;
	this->next = next;
}

ItemType::~ItemType() {
	//delete data; ??
}


ItemType* ItemType::getNext() const {
	return next;
}

void ItemType::setNext(ItemType* next) {
	this->next = next;
}
