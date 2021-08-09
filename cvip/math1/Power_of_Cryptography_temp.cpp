#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <assert.h>

using namespace std;
string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return "0";

    vector<int> result(len1 + len2, 0);

    int i_n1 = 0;
    int i_n2 = 0;

    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        i_n2 = 0;

        for (int j = len2 - 1; j >= 0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
            carry = sum / 10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;

    if (i == -1)
        return "0";
    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);
    return s;
}
string gt(int a, string b)
{
    string temp = "1";
    for (int i = 1; i <= a; i++)
    {
        temp = multiply(temp, b);
    }
    return temp;
}
bool ss(string a, string b)
{

    if (a.length() > b.length())
        return true;
    if (a.length() < b.length())
        return false;
    if (a > b)
    {
        return true;
    }
    else
        false;
}
int bs(string x, int sm)
{
    long long mid;
    long long l, r;
    string temp;
    r = 1;
    l = 1000000000;
    //true la lon
    //false la nho
    while (1 != 0)
    {

        mid = (l + r) / 2;
        ostringstream convert;
        convert << mid;
        temp = convert.str();
        temp = gt(sm, temp);

        if (temp == x)
            return mid;
        bool check = ss(temp, x);
        if (check == false)
        {
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
}

int main()
{
    int a = 1;
    string x;
    string b;
    ifstream fin; // declare stream variable name

    fin.open("", ios::in); // open file
    assert(!fin.fail());

    while (!fin.eof())
    {

        fin >> a;

        fin >> b;

        cout << bs(b, a) << endl;
    }
    fin.close(); //close file
    assert(!fin.fail());
    //cout << ss("122", "123");
    //cout << bs("27", 3);
    return 0;
}