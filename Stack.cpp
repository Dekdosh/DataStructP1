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
		top = top->next;
		delete tmp;
	}
}

int Stack::isEmpty() {
	return top == nullptr
}

void Stack::Push(string item) {
	top = new ItemType(item, top);
}
string Stack::Pop() {
	if (isEmpty) {
		return nullptr;
	}
	ItemType* tmp = top;
	string item = top->data;
	top = top->next;
	delete tmp;
	return item;
}