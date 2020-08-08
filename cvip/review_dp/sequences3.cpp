//3. The last digit of the Fibonacci numbers
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long f[1001], n;
    f[1] = f[0] = 1;
    cin >> n;
    for (int i = 2; i <= n; i++)
        f[i] = (f[i - 1] + f[i - 2]) % 10;
    cout << f[n];
}