#include "Q1.h"

int main()//for Q1
{
    int n;
    cout << "pls enter n" << endl;
    cin >> n;
    cin.ignore();
    if (n > 0)
    {
        char* x = new char[n + 1];
        char* y = new char[n + 1];
        cout << "pls enter x" << endl;
        int size = n + 1;
        cin.getline(x,size);
        cout << "pls enter y" << endl;
        cin.getline(y, size);
        if (inputApproved(x, n) && inputApproved(y, n))// only digits
            cout << multiply(string(x), string(y), n, n) << endl;
        else
            cout << "Ïnput is not approved" << endl;
    }
    else if (n == 0)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << "Not a valid n" << endl;// since we input n as int, if it will start with zeros, 
                                        //it wont count and therefore the input from that prespective will be OK
    }

    return 0;
}