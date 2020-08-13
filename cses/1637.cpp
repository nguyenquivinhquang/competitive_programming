#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, temp, step = 0;
    cin >> n;
    while (n > 0)
    {
        temp = n, m = 1;
        while ( temp  > 0)
        {
            m = max(m, temp % 10);
            temp /= 10;
        }
        n -= m;
        step++;
    }

    cout << step;
}