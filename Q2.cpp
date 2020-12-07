#include "Q2.h"

//Karatsuba recursive algorithm for multipication
string karatsubaRec(string x, string y, int n) {
	recNum++;

	n = max(x.size(), y.size());
	cout << "Rec: " << recNum << " N: " << n << " X: " << x << " Y: " << y << endl;

	// pad the shorter string with zeros
	while (x.size() < n)
		x.insert(0, "0");
	while (y.size() < n)
		y.insert(0, "0");

	//stops at base case
	if (n <= 1) {
		cout << "Return: " << to_string((x[0] - '0')*(y[0] - '0')) << endl;
		return to_string((x[0] - '0')*(y[0] - '0'));
	}

	string a = x.substr(0, n / 2); //x's most significant
	string b = x.substr(n / 2, n - (n / 2)); //x's least significant
	string c = y.substr(0, n / 2); //y's most significant
	string d = y.substr(n / 2, n - (n / 2)); //y's least significant

	cout << "A: " << a << " B: " << b << " C: " << c << " D: " << d << endl;

	// Recur until base case 123 456
	string ac = karatsubaRec(a, c, n); // 4
	string bd = karatsubaRec(b, d, n); // 38
	string tmp = karatsubaRec(add(a, b), add(c, d), n); //
	string e = subtract(tmp, add(ac, bd)); //

	SecRecNum++;

	cout << "Rec: " << SecRecNum << " AC: " << ac << " BD: " << bd << " E: " << e << endl;

	// pad zeros to the end of the number
	for (int i = 0; i < 2 * (n - (n / 2)); i++)
		ac.append("0");
	for (int i = 0; i < n - (n / 2); i++)
		e.append("0");

	string result = add(add(ac, bd), e);

	cout << "Res: " << result << endl;

	// remove leading zeros
	return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
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
	cout << karatsubaRec(s1, s2, 4) << endl;
}