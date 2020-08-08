//2. Ball on a ladder
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long f[47], n;
    f[1] = f[2] = 1;
    f[3] = 2;
    cin >> n;
    for (int i = 4; i <= n + 1; i++)
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    cout << f[n + 1];
}