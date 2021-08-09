#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    map<long long, long long> m;
    long long x = 0;
    m[x]++;

    while (n--)
    {
        long long c;
        cin >> c;
        x += c;
        ans += m[x - k];
        m[x]++;
    }
    cout << ans << '\n';
}