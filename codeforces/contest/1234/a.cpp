#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long  testcase, temp, n, sum;
    cin >> testcase;
    while (testcase--)
    {
        cin >> n;
        sum = 0;
        for (int i = 1; i <= n ; i++)
            cin >> temp, sum += temp;
        if ( sum % n == 0) cout << sum / n;
        else
            cout << sum / n + 1;

        cout << endl;
    }
}