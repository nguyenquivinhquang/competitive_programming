#include <bits/stdc++.h>
#define maxn 100001
#define ll long long
using namespace std;

int main()
{
    ll testcase, a[maxn], n;
    cin >> testcase;
    while (testcase--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int j = 1; j <= 1000; j++)
        {
            for (int i = 2; i < n; i++)
                if (abs(a[i] - a[i - 1]) > abs(a[i] - a[i + 1]))
                    swap(a[i], a[i - 1]);
        }
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}