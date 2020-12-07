#include "Q1.h"

string multiply(string x, string y, int nx, int ny)
{
    vector<int> res(nx + ny, 0); // will keep the result number in vector
    int i_nx = 0;
    int i_ny = 0;
    for (int i = nx - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = x[i] - '0';
        i_ny = 0; // To shift position to left after every multiplication of a digit in y  
        for (int j = ny - 1; j >= 0; j--)
        {
            int n2 = y[j] - '0';//current digit of y 
            int sum = n1 * n2 + res[i_nx + i_ny] + carry;
            carry = sum / 10;// next carry
            res[i_nx + i_ny] = sum % 10;
            i_ny++;
        }//for
        if (carry > 0)
        {
            res[i_nx + i_ny] += carry;
        }//if
        i_nx++;//shift to left after every multiplication of a digit in x
    }//for
    int realLen = res.size() - 1;
    while (realLen >= 0 && res[realLen] == 0)
    {
        realLen--;
    }// ignore zeros
    if (realLen == -1)
    {
        return "0";
    }//it was all zeros

    string s = "";
    while (realLen >= 0)
    {
        s += std::to_string(res[realLen--]);
    }//while
    return s;
}

bool inputApproved(char* input, int size)
{
    int i = 0;
    while (i < size)
    {
        if (isdigit(input[i]))
            i++;
        else
            return false;
    }
    if (i == size)
        return true;
}
