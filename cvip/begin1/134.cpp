#include <iostream>
#include <string>
#include <cmath>
using namespace std;
long Bin_to_dec(string x)
{
    long res = 0;
    int hihi;
    for (int i = 0; i <= x.length(); i++)
    {
        if (x[i] == '1')
            hihi = 1;
        else
            hihi = 0;
        res += hihi * pow(2, i);
    }
    return res;
}
string Dec_to_bin(long x)
{
    string res = "";
    while (x > 0)
    {
        if (x % 2 == 1)
            res = res + "1";
        else
            res = res + "0";
        x = x / 2;
    }
    string res2 = "";
    for (int i = res.length() - 1; i >= 0; i--)
        res2 = res2 + res[i];
    return res2;
}
int main()
{
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        cout << Bin_to_dec(Dec_to_bin(n)) << endl;
    }
}
