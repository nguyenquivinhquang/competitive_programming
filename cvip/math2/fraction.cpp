#include <bits/stdc++.h>
#define mod %
#define ll long long int
using namespace std;
ll a, b, c;
ll mau_a, mau_b, mau_c;
int la, lb, lc;
void pre(string x)
{
    a = 0, b = 0, c = 0;
    la = lb = lc = 0;
    int i, j;
    for (i = 0; i < x.length(); i++) // phan nguyen
        if (x[i] == '.')
            break;
        else
            a = a * 10 + x[i] - 48;
    j = i + 1;
    for (i = j; i < x.length(); i++)
        if (x[i] == '(')
            break;
        else
        {
            b = b * 10 + x[i] - 48;
            lb++;
        };
    j = i + 1;
    for (i = j; i < x.length(); i++)
        if (x[i] == ')')
            break;
        else
        {
            c = c * 10 + x[i] - 48;
            lc++;
        };
}
ll Gcd(ll x, ll y)
{
    ll r;
    if (x < y)
        swap(x, y);
    while (y != 0)
    {
        r = x mod y, x = y, y = r;
    }
    return x;
}
ll Lcd(ll x, ll y)
{
    if (x == 0)
        x = 1;
    if (y == 0)
        y = 1;
    return (x * y) / Gcd(x, y);
}
void Giang_bae(int j)
{

    mau_a = mau_b = 1, mau_c = 9;

    mau_a = 1;
    for (int i = 1; i <= lb; i++)
        mau_b = mau_b * 10;
    for (int i = 1; i < lc; i++)
        mau_c = mau_c * 10 + 9;
    mau_c = mau_c * mau_b;
    if (c == 0)
        mau_c = 9;
    //cout << mau_a << " " << mau_b << " " << mau_c<<endl;
    ll mau = Lcd(Lcd(mau_a, mau_b), mau_c); //cout<<"quangcute";
    ll tu = a * (mau / mau_a); 
     tu=tu + b * (mau / mau_b), tu=tu + c * (mau / mau_c);
    ll x = Gcd(tu, mau);

    //cout<<mau<<" "<<tu<<" ";

    cout << tu / x << "/" << mau / x << endl;
}
int main()
{
    int t;
    //cout<<Lcd(Lcd(0, 1000), 0);
    string x;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> x;
        pre(x);
        Giang_bae(i);
    }
}