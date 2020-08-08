//Cunning sequence
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long f[1001], n;
    f[1] = f[0] = 1;
    cin >> n;
    for (int i = 2; i <= n; i++)
        if (i % 2 == 0)
            f[i] = f[i / 2] + 1;
        else
            f[i] = f[i - 1] - f[i / 2];
    cout << f[n] << endl;
}