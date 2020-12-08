#include "ItemType.h"

ItemType::ItemType(string data, ItemType* next = nullptr) {
	this->data = data;
	this->next = next;
}

ItemType::~ItemType() {
	//delete data; ??
}

string ItemType::getData() const {
	return data;
}
ItemType* ItemType::getNext() const {
	return next;
}
void ItemType::setData(string data) {
	this->data = data;
}
void ItemType::setNext(ItemType* next) {
	this->next = next;
}
