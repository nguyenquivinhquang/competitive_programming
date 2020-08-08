#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
using namespace std;
bool check(int i)
{
    string temp;
    ostringstream convert;
    convert << i;
    temp = convert.str();
    int n = temp.length();
    int sl = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (temp[i] == temp[n - i - 1])
            sl++;
    }
    if (sl >= n / 2)
        return true;
    else
        return false;
}
long lat(long x)
{
    string a, temp = "";
    ostringstream convert;
    convert << x;
    a = convert.str();
    long res = 0;
    for (int i = a.length() - 1; i >= 0; i--)
        res = res * 10 + a[i] - 48;
    return res;
}
int main()
{
    long n, res = 0;
    cin >> n;
    vector<bool> trace(1000000, true);
    while (check(n) == false)
    {
        //if (trace[n]==false) break;
        //trace[n]=false;
        res++;
        n=n+lat(n);
        if(res==75) break;
    }
    cout<<res;
}