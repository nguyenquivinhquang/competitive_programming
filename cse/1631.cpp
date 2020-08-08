#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long temp, sum=0, n, m=0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        m = max(m, temp);
        sum += temp;
    }
    if (m * 2 > sum)
        cout << 2*m;
    else
        cout << sum;
}