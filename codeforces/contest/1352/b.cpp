#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

const int maxn = 1e4 + 5;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int n, k;
        cin >> n >> k;
        if (n >= k && k % 2 == n % 2)
        {
            cout << "YES" << endl;
            for (int i = 1; i <= k - 1; i++)
            {
                cout << 1 << ' ';
            }
            cout << n - k + 1 << endl;
        }
        else if (n >= k * 2 && n % 2 == 0)
        {
            cout << "YES" << endl;
            for (int i = 1; i <= k - 1; i++)
            {
                cout << 2 << ' ';
            }
            cout << n - (k - 1) * 2 << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}