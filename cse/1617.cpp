#include <bits/stdc++.h>
#define maxn 10000
#define mod %
#define ll long long
using namespace std;

int main()
{
    int n;
    ll modulo = 1e9 + 7;
    ll res = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        res = (res * 2) % (modulo);
    cout << res mod modulo;
}