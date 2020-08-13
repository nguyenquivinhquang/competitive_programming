#include <bits/stdc++.h>
#define maxn 10000
#define mod %
#define ll long long
using namespace std;

int main()
{
    int a[1000000];
    cout << "ahihi";
    ll x = 1;
    for (int i = 1; i <= 15; i++)
    {
        x *= i;
        x = x mod 100000000000;
    }
    cout << x;
}