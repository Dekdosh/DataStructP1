#include "Q3.h"

string karatsubaStack(string x, string y, int n) {
	ItemType* curr = new ItemType(x, y);
	ItemType* next, *prev;
	Stack stack1;
	stack1.Push(curr);
	n = max(curr->getX().size(), curr->getY().size());
	if (n == 1) {
		return to_string((x[0] - '0')*(y[0] - '0'));
	}
	while (!stack1.isEmpty()) {
		curr = stack1.Pop(); 
		n = max(curr->getX().size(), curr->getY().size());
		if (curr->getStage() == 0) {
			if (n > 1) {
				karasubaHelper(curr, n);
				ItemType* next = new ItemType(curr->getA(), curr->getC());
				curr->setStage(1);
				stack1.Push(curr);
				stack1.Push(next);
			}
			else { //single digit - ac
				prev = stack1.Pop(); 
				string input = to_string((curr->getX()[0] - '0')*(curr->getY()[0] - '0'));
				if (prev->getStage() == 1) {
					prev->setAC(input);
				}
				else if (prev->getStage() == 2) {
					prev->setBD(input);
				}
				else if (prev->getStage() == 3) {
					prev->setTmp(input);
				}
				stack1.Push(prev);
			}
		}
		else if (curr->getStage() == 1) {
			ItemType* next = new ItemType(curr->getB(), curr->getD());
			curr->setStage(2);
			stack1.Push(curr);
			stack1.Push(next);
		}
		else if (curr->getStage() == 2) {
			ItemType* next = new ItemType(curr->getSumAB(), curr->getSumCD());
			curr->setStage(3);
			stack1.Push(curr);
			stack1.Push(next);
		}
		else if (curr->getStage() == 3) {
			string e = subtract(curr->getTmp(), add(curr->getAC(), curr->getBD()));
			for (int i = 0; i < 2 * (n - (n / 2)); i++)
				curr->setAC(curr->getAC().append("0"));
			for (int i = 0; i < n - (n / 2); i++)
				e.append("0");

			string result = add(add(curr->getAC(), curr->getBD()), e);
			if (stack1.isEmpty()) {
				return result;
			}
			prev = stack1.Pop();
			if (prev->getStage() == 1) {
				prev->setAC(result);
			}
			else if (prev->getStage() == 2) {
				prev->setBD(result);
			}
			else if (prev->getStage() == 3) {
				prev->setTmp(result);
			}
			stack1.Push(prev);
		}
	}
}

void karasubaHelper(ItemType* item, int n) {
	//item->setSingleDigit(false);
	while (item->getX().size() < n)
		item->setX(item->getX().insert(0, "0"));
	while (item->getY().size() < n)
		item->getY().insert(0, "0");
	string a = item->getX().substr(0, n / 2); //x's most significant
	string b = item->getX().substr(n / 2, n - (n / 2)); //x's least significant
	string c = item->getY().substr(0, n / 2); //y's most significant
	string d = item->getY().substr(n / 2, n - (n / 2)); //y's least significant
	item->setA(a);
	item->setB(b);
	item->setC(c);
	item->setD(d);
	item->setSumAB(add(a, b));
	item->setSumCD(add(c, d));
}



//assume strings a and b are numbers, then add them and returns the sum.
string add(string a, string b) {
	int length = max(a.size(), b.size());
	int carry = 0;
	int sum_col;  // sum of two digits in the same column
	string result;

	// pad the shorter string with zeros
	while (a.size() < length)
		a.insert(0, "0");
	while (b.size() < length)
		b.insert(0, "0");

	// build result string from right to left
	for (int i = length - 1; i >= 0; i--) {
		sum_col = (a[i] - '0') + (b[i] - '0') + carry;
		carry = sum_col / 10;
		result.insert(0, to_string(sum_col % 10));
	}

	if (carry)
		result.insert(0, to_string(carry));

	// remove leading zeros
	return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

//assume strings a and b are numbers, then subtract them and returns the difference.
string subtract(string a, string b) {
	int length = max(a.size(), b.size());
	int diff;
	string result;

	// pad the shorter string with zeros
	while (a.size() < length)
		a.insert(0, "0");
	while (b.size() < length)
		b.insert(0, "0");

	// build result string from right to left
	for (int i = length - 1; i >= 0; i--) {
		diff = (a[i] - '0') - (b[i] - '0');
		if (diff >= 0)
			result.insert(0, to_string(diff));
		else {
			// borrow from the previous column
			int j = i - 1;
			while (j >= 0) {
				a[j] = ((a[j] - '0') - 1) % 10 + '0';
				if (a[j] != '9')
					break;
				else
					j--;
			}
			result.insert(0, to_string(diff + 10));
		}
	}
	// remove leading zeros
	return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}

void main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << karatsubaStack(s1, s2, 4) << endl;
}
