#include "Stack.h"

Stack::Stack() {
	top = nullptr;
}

Stack::~Stack() {
	MakeEmpty();
}
void Stack::MakeEmpty() {
	ItemType* tmp;
	while (top != nullptr) {
		tmp = top;
		top = top->getNext();
		delete tmp;
	}
}

int Stack::isEmpty() {
	return top == nullptr;
}

void Stack::Push(ItemType* item) {
	item->setNext(top);
	top = item;
}

ItemType* Stack::Pop() {
	if (isEmpty()) {
		return nullptr;
	}
	ItemType* tmp = top;
	top = top->getNext();
	return tmp;
}

ItemType* Stack::Peak() {
	if (isEmpty()) {
		return nullptr;
	}
	return top;
}