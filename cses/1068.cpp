#include <bits/stdc++.h>
#define maxn 300009
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin >> n;
    while (n > 1)
    {
        cout << n << " ";
        if (n % 2 == 0)
            n = n / 2;
        else
            n = n * 3 + 1;
    }
    cout << 1;
}
