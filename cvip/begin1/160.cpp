#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

long Hoai_Thuong(string x, int cs)
{
    int kq = 0;
    int temp;
    for (int i = 0; i <= x.length() - 1; i++)
    {
        temp = x[i] - 48;
        kq += temp * pow(cs, x.length() - i - 1);
    }
    return kq;
}
string Dec_to_another(long x, int cs)
{
    string res = "";
    string temp;
    while (x > 0)
    {
        int i = x % cs;
        ostringstream convert;
        convert << i;
        temp = convert.str();
        res = res + temp;
        x = x / cs;
    }
    string res2 = "";
    for (int i = res.length() - 1; i >= 0; i--)
        res2 = res2 + res[i];
    return res2;
}
int main()
{
    string x;
    int a, b;
    cin>>x>>a>>b;
    cout << Dec_to_another(Hoai_Thuong(x, a), b);
}