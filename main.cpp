#include "Q1.h"
#include "functionsForMain.h"

int main()
{
   //Q1//
    int n;
    cout << "pls enter n" << endl;
    cin >> n;
    cin.ignore();
    if (n > 0)
    {
		myString x, y;
		x.setN(n);
		y.setN(n);
		cout << "pls enter x" << endl;
		cin >> x;
		cout << "pls enter y" << endl;
		cin >> y;

        if (inputApproved(x, n) && inputApproved(y, n))// only digits
        {
            cout << multiply(x, y, n, n) << endl;
            runTimeFunc1();
        }
        else
            cout << "Ïnput is not approved" << endl;
    }
    else if (n == 0)
        cout << "0" << endl;
    else
        cout << "Not a valid n" << endl;

	return 0;
}

