#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll find_absurdity(ll x)
{
    while (x % 10 == 0 && x > 0)
    {
        x /= 10;
    }
    int digit = 0, t = 0;
    if (x % 10 == 5)
        t = 1;
    while (x > 0)
        x /= 10, digit++;
    return digit * 2 - t;
}
void find_l_r(ll n, ll &l, ll &r)
{
    double check = n * 0.95;
    int temp = n * 0.95;
    double x = check - temp;
    if (x > 0.0)
        l = temp + 1;
    else
        l = temp;
    check = n * 1.05;
    temp = n * 1.05;
    r = temp;
}
void debug()
{
    freopen("out.txt", "w", stdout);
    for (int i = 1000; i <= 100000; i++)
    {
        int l = i * 0.95, r = i * 1.05;
        cout << i << " :" << l << " " << r << endl;
    }
}
int main()
{
    //freopen("out.txt", "w", stdout);
    ll testcase, n, left, right;
    //debug();
    cin >> testcase;
    while (testcase--)
    {
        cin >> n;
        find_l_r(n, left, right);
        int scs = 0, abs_n = 0, temp = right;
        abs_n = find_absurdity(n);
        /*
        while (temp % 10 == 0 && temp > 0)
        {
            temp /= 10, scs++;
        }*/
        int i = 0;
        if (abs_n == 1)
            temp = 0;
        else
            while (1 != 0)
            {
                i++;
                temp = right / pow(10, scs);
                temp = (temp / 10) * 10;
                if (i % 2 != 0)
                    temp += 5;
                temp = temp * pow(10, scs);
                if (temp > right)
                    continue;
                if (temp < left)
                    break;
                if (find_absurdity(temp) < abs_n)
                    break;
                if (i % 2 == 0)
                    scs++;
            }
        if (temp >= left)
            cout << "absurd";
        else
            cout << "not absurd";
        cout << endl;
    }
}