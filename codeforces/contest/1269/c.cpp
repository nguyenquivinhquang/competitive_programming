#include <bits/stdc++.h>
#define maxn 100

using namespace std;
int a[maxn], k, n;
string res = "1";

void pre(string x)
{
    for (int i = 0; i < x.length(); i++)
    {
        a[i + 1] = x[i] - 48;
        res = res + '0';
    }
    res.erase(res.length(), 1);
}
char convert(int i)
{
    if (i == 1)
        return '1';
    if (i == 2)
        return '2';
    if (i == 3)
        return '3';
    if (i == 4)
        return '4';
    if (i == 5)
        return '5';
    if (i == 6)
        return '6';
    if (i == 7)
        return '7';
    if (i == 8)
        return '8';
    if (i == 9)
        return '9';
    if (i == 0)
        return '0';
}
bool Hoai_Thuong(int j)
{
    for (int j=1;j<=x)
}

int main()
{
    string x;
    cin >> n >> k >> x;
}
