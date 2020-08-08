//1. Fibonacci numbers
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long f[47], n;
    f[1] = f[2] = 1;
    cin >> n;
    for (int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    cout << f[n];
}